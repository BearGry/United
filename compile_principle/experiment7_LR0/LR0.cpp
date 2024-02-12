/*
 * 需要实现的功能:
1）使用LR(0)分析方法构造识别活前缀的DFA；
2）构造文法的分析表（Action表和Goto表）；
3）输入文法：文法描述存储在文本文件中，文件名作为命令行参数输入；
4）输出文法的项目集簇（标准输出设备）；
5）输出识别活前缀的DFA（标准输出设备）；
6）输出文法的Action表和Goto表（输出到创建的指定LR分析表文件，文件名与文法描述文件同名，扩展名为lrtbl）；
7）输出文法是否是LR(0)文法的判断结果（标准输出设备）；
 */
#include <bits/stdc++.h>
#define epsilon_show "\0"
#define Candidates vector<Candidate>
#define rep(x,y,z) for(int x=y; x<=z; ++x)
using namespace std;

//string filename_g = "D:\\CLionProjects\\untitled\\compile_principle\\experiment7_LR0\\g";
string filename_g;

enum LR_type{LR0, LR1, SLR, LALR};
class DFA_LR0;
class LR_Analyser;
class Vn{
public:
    string signal;
    Vn(string s):signal(s){}
    Vn(){}
};
class Candidate{
public:
    vector<string> element;
    int pi;
    friend ostream & operator<<(ostream &out, const Candidate& t){
        for(const auto &item:t.element)
            cout<<item<<" ";
        return out;
    }
    void LR0_show(int p)const{
        for(int i=0; i<element.size(); i++){
            if(i == p)
                cout<<". ";
            cout<<element[i]<<" ";
        }
        if(p == element.size())
            cout<<".";
    }
};
class G{
private:
    vector<Vn> vn;
    vector<char> vt;
    unordered_map<string,Candidates> p;
    string startVn;

    inline bool is_epsilon(string &s){
        if(s.size()!=2) return false;
        for(const auto vn_t:vn){
            if(vn_t.signal == s)
                return false;
        }
        return true;
    };
    inline bool isVt(string s){
        if(s.size() == 1){
            char ch = s[0];
            if(find(vt.begin(), vt.end(),ch) != vt.end())
                return true;
        }
        return false;
    }
    inline bool isVn(string s){
        for(auto it:vn)
            if(it.signal == s) return true;
        return false;
    }
    inline Vn& getVn(string t){
        for(auto & item:vn)
            if(item.signal == t)
                return item;
    }

public:
    void get_form_file(string file_path){
        ifstream fin(file_path);
        if(!fin.is_open()) {
            cout<<"please check the g file path"<<endl;
            exit(0);
        }
        int k;
        string tvn;
        char tvt;
//        输入非终结符Vn
        fin>>k;
        for(int i=1; i<=k; ++i){
            fin>>tvn;
            vn.push_back(tvn);
        }
//        输入终结符Vt
        fin>>k;
        rep(i,1,k){
            fin>>tvt;
            vt.push_back(tvt);
        }
//        输入产生式P
        fin>>k;
        --k;
        rep(i,0,k){
            Candidate candidate;
            candidate.pi=i;
            fin>>tvn;
            string t;
            fin>>t; //输入箭头->
            while (fin.get()!='\n'){
                fin>>t;
                if(is_epsilon(t))
                    continue;
                candidate.element.push_back(t);
            }
            p[tvn].push_back({candidate});
        }
//        输入开始符号
        fin>>startVn;
        fin.close();

        return;
    }

    friend istream & operator>>(istream & cin, G & g){
        int k;
        string vn;
        char vt;
//        输入非终结符Vn
        cin>>k;
        for(int i=1; i<=k; ++i){
            cin>>vn;
            g.vn.push_back(vn);
        }
//        输入终结符Vt
        cin>>k;
        rep(i,1,k){
            cin>>vt;
            g.vt.push_back(vt);
        }
//        输入产生式P
        cin>>k;
        --k;
        rep(i,0,k){
            Candidate candidate;
            candidate.pi=i;
            cin>>vn;
            string t;
            cin>>t; //输入箭头->
            while (getchar()!='\n'){
                cin>>t;
                if(g.is_epsilon(t))
                    continue;
                candidate.element.push_back(t);
            }
            g.p[vn].push_back({candidate});
        }
//        输入开始符号
        cin>>g.startVn;

        return cin;
    }

    friend ostream &operator<<(ostream &cout, const G& g) {
        cout<<" CFG=(VN,VT,P,S)"<<endl;
        cout<<" VN: ";
        for(const auto& t:g.vn)
            cout<<t.signal<<" ";
        cout<<endl<<" VT: ";
        for(const auto& t:g.vt)
            cout<<t<<" ";
        cout<<endl<<" Production: "<<endl;
        for (const auto& item: g.p) {
            for (const auto &can: item.second) {
                cout<<"    "<<can.pi<<": ";
                cout << item.first << " -> ";
                if (can.element.empty()) {
                    cout << epsilon_show << endl;
                    continue;
                }
                for (auto &element: can.element) {
                    cout << element << " ";
                }
                cout << endl;
            }
        }
        cout<<" StartSymbol: "<<g.startVn;
        return cout;
    }

    friend class DFA_LR0;
    friend class LR_Analyser;
};

class project_LR0{
public:
    string vn;
    Candidate candidate;
    int point;

    bool operator==(project_LR0 t){
        if(vn == t.vn && candidate.pi == t.candidate.pi && point == t.point)
            return true;
        return false;
    }
    bool operator!=(project_LR0 t){
        return !this->operator==(t);
    }
};
class project_LR0_set{
public:
    struct relation{
        string v;
        int project_set_num;
    };
    vector<project_LR0> set;
    int primary_num;
    vector<relation> edges;

    bool find(const project_LR0 t){
        for(auto item:set)
            if(item == t)
                return true;
        return false;
    }

    bool operator==(const vector<project_LR0>& t){
        if(t.size() != primary_num)
            return false;
        for(int i=0; i<primary_num; ++i){
            project_LR0& pj = set[i];
            if(pj != t[i])
                return false;
        }
        return true;
    }
};
class DFA_LR0{
private:
    int status_num;
    vector<string> characters;
    vector<project_LR0_set> cluster;
    int start_status = 0;
    vector<int> ends;

    inline project_LR0_set make_closure(vector<project_LR0> primary_pros, G & g){
        project_LR0_set res = {primary_pros};
        res.primary_num = primary_pros.size();
        int i=0;
        while(i<res.set.size()){
            project_LR0 pj = res.set[i];
            if(pj.point == pj.candidate.element.size()){
                ++i;
                continue;
            }
            string v = pj.candidate.element[pj.point];
            if(g.isVn(v)){
                for(auto & item:g.p[v]){
                    project_LR0 t = {v,item,0};
                    if(!res.find(t)){
                        res.set.push_back(t);
                    }
                }
            }
            ++i;
        }
        return res;
    }

    inline vector<project_LR0> make_primary_pros(const vector<project_LR0>& ps, const string& ch){
        vector<project_LR0> res;
//        cout<<ps.size()<<endl;
        for(const auto& pj:ps){
            if(pj.point < pj.candidate.element.size()){
                string v = pj.candidate.element[pj.point];
                if(v == ch){
                    res.push_back({pj.vn,pj.candidate,pj.point+1});
                }
            }
        }
        return res;
    }

    inline int find(const vector<project_LR0>& ps){
        for(int i=0; i<cluster.size(); ++i){
            project_LR0_set& t = cluster[i];
            if(t == ps)
                return i;
        }
        return cluster.size();
    }
public:

    friend class G;
    DFA_LR0(G& g){
        for(auto s:g.vn)
            characters.push_back(s.signal);
        for(auto s:g.vt)
            characters.push_back(string(1,s));
        // 创建元项目集
        vector<project_LR0> primary_pros;
        primary_pros.push_back({g.startVn,g.p[g.startVn][0],0});
        // 搜寻
        // 闭包构造新项目集
        cluster.push_back(make_closure(primary_pros,g));

        for(int i=0; i<cluster.size(); ++i){
//            project_LR0_set& pjs = cluster[i];
            for(auto ch:characters){
                primary_pros.clear();
                // 创建元项目集
                primary_pros = make_primary_pros(cluster[i].set,ch);
                if(primary_pros.empty())
                    continue;
                // 搜索-创建关系
                int relate_num = find(primary_pros);
                cluster[i].edges.push_back({ch,relate_num});
                // 闭包构造新项目集
                if(relate_num == cluster.size()){
                    cluster.push_back(make_closure(primary_pros,g));
                }
            }
            if(cluster[i].edges.empty())
                ends.push_back(i);
        }
        status_num = cluster.size();
    }
    void show_LR0_projects_cluster(){
        cout<<"LR(0) projects cluster"<<endl;
        int i=0;
        for(const auto & ps:cluster){
            cout<<"  I"<<i++<<" :"<<endl;
            for(const auto & pj:ps.set){
                cout<<"\t"<<pj.vn<<" -> ";
                pj.candidate.LR0_show(pj.point);
                cout<<endl;
            }
        }
    }
    void show(){
        cout<<"DFA"<<endl;
        cout<<"  number of status: "<<status_num<<endl;
        cout<<"  number of characters: "<<characters.size()<<endl;
        cout<<"  status stransform: "<<endl;
        for(int i=0; i<status_num; ++i){
            if(!cluster[i].edges.empty()){
                for(auto item:cluster[i].edges)
                    cout<<"    ("<<i<<","<<item.v<<")->"<<item.project_set_num<<endl;
            }
        }
        cout<<"  start status: "<<start_status<<endl;
        cout<<"  final status set: "<<"{ ";
        for(auto item:ends)
            cout<<item<<" ";
        cout<<"}"<<endl;
    }

    friend class LR_Analyser;
};
class LR_Analyser{
private:
    struct Action_Type{
        char s_r;
        union jump{
          int s;
          const project_LR0* p;
        }a;
        Action_Type():s_r('e'){}
    };
    unordered_map<int,unordered_map<char,Action_Type>> action;
    unordered_map<int,unordered_map<string,int>> gotoo;
    bool is = true;

//    enum wrong_type{NOT_LR0_S,NOT_LR0_R};
//    void wrong(wrong_type e, int i=0){
//        if(e == NOT_LR0_S){
//            cout<<""
//        }
//    }
public:
    LR_Analyser(G& g, DFA_LR0& d){
        vector<char> t_vt(g.vt.begin(), g.vt.end());
        t_vt.push_back('#');
        int i=0;
        for(const auto & item:d.cluster){
            for(const auto & t:item.edges){
                string s = t.v;
                if(g.isVt(s)){
                    action[i][s[0]].s_r = 's';
                    action[i][s[0]].a.s = t.project_set_num;
                }
                else{
                    gotoo[i][s] = t.project_set_num;
                }
            }

            for(const auto& t:item.set){
                if(t.point == t.candidate.element.size() && t.candidate.pi != 0){
                    for(const auto &k:t_vt){
                        if(action[i][k].s_r == 's'){
                            is = false;
                            cout<<"There is a shift-reduce conflict in item set"<<i<<" : ";
                            cout<<"s"<<action[i][k].a.s<<"-r"<<t.candidate.pi<<endl;
                        }
                        else if(action[i][k].s_r == 'r'){
                            is = false;
                            cout<<"There is a reduce-reduce conflict in item set"<<i<<" : ";
                            cout<<"r"<<action[i][k].a.p->candidate.pi<<"-r"<<t.candidate.pi<<endl;
                        }
                        else if(action[i][k].s_r == 'e'){
                            action[i][k].s_r = 'r';
                            action[i][k].a.p = &t;
                        }
                        else{
                            cout<<"what?!"<<endl;
                            exit(0);
                        }
                    }
                }
            }
            ++i;
        }
        if(action[1]['#'].s_r == 'r'){
            is = false;
            cout<<"There is a reduce-reduce conflict in item set"<<1<<" : ";
            cout<<"r"<<action[1]['#'].a.p->candidate.pi<<"-acc"<<endl;
        }
        else if(action[1]['#'].s_r == 's'){
            cout<<"what?!-2"<<endl;
            exit(0);
        }
        action[1]['#'].s_r = 'a';
        if(is)
            cout<<"The grammar is an LR(0) grammar!"<<endl;
        else
            cout<<"The grammar is not an LR(0) grammar!"<<endl;

    }
    void write(string filename){
        size_t lastDotPos = filename.find_last_of(".");
        if (lastDotPos != std::string::npos) { // 如果找到了点
            filename = filename.substr(0, lastDotPos);
        }
        filename += ".lrtbl";
        ofstream fout(filename);
        if(fout.is_open()){
            vector<pair<int,unordered_map<char,Action_Type>>> t_act(action.begin(), action.end());
            sort(t_act.begin(), t_act.end(),[&](pair<int,unordered_map<char,Action_Type>>a,pair<int,unordered_map<char,Action_Type>>b){
                return a.first<b.first;
            });
            int act_num = 0;
            for(const auto& item:t_act){
                for(const auto& t:item.second){
                    fout<<item.first<<" ";
                    fout<<t.first<<" "<<t.second.s_r;
                    if(t.second.s_r == 's')
                        fout<<t.second.a.s<<endl;
                    else if(t.second.s_r == 'r')
                        fout<<t.second.a.p->candidate.pi<<endl;
                    else
                        fout<<"cc"<<endl;
                    ++act_num;
                }
            }
            fout<<act_num<<endl<<endl;

            vector<pair<int,unordered_map<string,int>>> t_go(gotoo.begin(), gotoo.end());
            sort(t_go.begin(), t_go.end(),[&](pair<int,unordered_map<string,int>>a, pair<int,unordered_map<string,int>>b){
                return a.first<b.first;
            });
            int go_num = 0;
            for(const auto & item:t_go){
                for(const auto &t:item.second){
                    fout<<item.first<<" ";
                    fout<<t.first<<" "<<t.second<<endl;
                    ++go_num;
                }
            }
            fout<<go_num<<endl;

            fout.close();
        }
        else{
            cout<<"Open file error! Failed to write."<<endl;
        }
    }
};

int main(int argc, char* argv[]){
    if(argc != 2){
        cout<<"please input grammar file path."<<endl;
        return 0;
    }
    filename_g = argv[1];

    G g;
    g.get_form_file(filename_g);
//    cout<<g<<endl;
    DFA_LR0 dfaLr0(g);
    dfaLr0.show_LR0_projects_cluster();
    dfaLr0.show();
    LR_Analyser lrAnalyser(g,dfaLr0);
    lrAnalyser.write(filename_g);

    return 0;
}