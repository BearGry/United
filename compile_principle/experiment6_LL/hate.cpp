/*
 * 需要实现的功能:
1）构造文法的LL预测分析表;
2）构造LL语法分析器的总控程序;
3）输入文法:文法描述存储在文本文件中（编码格式ANSI）,文件名作为命令行参数输入;
4）输入待分析的符号串:符号串存储在文本文件中（编码格式ANSI）,文件名作为命令行参数输入。
5）输出文法的LL预测分析表到标准输出设备;
6）输出分析结果:输出待分析符号串是否为该文法正确句子的判断,并输出文本形式的分析过程（标准输出设备）。
 */
#include <bits/stdc++.h>
#define epsilon_show "\0"
#define epsilon "\0"
#define FIRST unordered_set<char>
#define FOLLOW unordered_set<char> //这里的非终结符用的char类型,存不了epsilon,所以epsilon在G中的存法为‘\0’!!!
#define Candidates vector<Candidate>
#define rep(x,y,z) for(int x=y; x<=z; ++x)
using namespace std;

class Vn{
public:
    string signal;
    FIRST first;
    FOLLOW follow;
    Vn(string s):signal(s){}
    Vn(){}
};
class Candidate{
public:
    vector<string> element;
    int pi;
    FIRST first;
};
class G{
private:
    vector<Vn> vn;
    vector<char> vt;
    map<string,Candidates> p;
    string startVn;
    // 预测分析表
    unordered_map<string,unordered_map<char,const Candidate*>> analyse_table;

    enum error{NOT_MATCH,NOT_A_LL1_G};

    inline bool is_epsilon(string s){
        if(s.size()!=2) return false;
        for(auto vn_t:vn){
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
    inline bool HEp_cans(Vn t){
        Candidates cans = p[t.signal];
        for(auto it:cans){
            if(std::find(it.element.begin(), it.element.end(),epsilon)!=it.element.end())
                return true;
        }
        return false;
    }
    inline bool HEp_first(Vn t){
        if(t.first.count('\0') > 0)
            return true;
        return false;
    }
    inline bool CIEp(Vn t){
        if(t.first.count('\0')>0)
            return true;
        return false;
    }
    inline Vn& getVn(string t){
        for(auto & item:vn)
            if(item.signal == t)
                return item;
    }
    inline char advance(string& s){
        if(s.empty())
            wrong(NOT_MATCH);
        char a = s.front();
        s.erase(0,1);
        return a;
    }
    inline void wrong(error e){
        if(e == NOT_MATCH){
            cout<<endl<<"----------NOT_MATCH-----------"<<endl;
        }
        else if(e == NOT_A_LL1_G){
            cout<<endl<<"----------NOT_A_LL1_G-----------"<<endl;
        }
        exit(0);
    }
public:
    void make_first(){
        bool need_next;
        do{
            need_next = false;
            for(auto &item_vn:vn){
                string vn=item_vn.signal;
                Candidates& cans = p[vn];
                for(auto &item_can:cans){
                    for(int i=0; i<item_can.element.size(); ++i){
                        string element = item_can.element[i];
                        if(isVt(element)){
                            item_can.first.insert(element[0]);
                            if(item_vn.first.insert(element[0]).second)
                                need_next = true;
                            break;
                        }
                        if(element == epsilon){
                            item_can.first.insert('\0');
                            if(item_vn.first.insert('\0').second)
                                need_next = true;
                            break;
                        }
                        if(isVn(element)){
                            Vn& t_vn = getVn(element);
                            for(auto it:t_vn.first){
                                if(it == '\0') continue;
                                item_can.first.insert(it);
                                if(item_vn.first.insert(it).second)
                                    need_next = true;
                            }
                            if(!HEp_first(t_vn)) break;
                            if(i == item_can.element.size()-1){
                                item_can.first.insert('\0');
                                if(item_vn.first.insert('\0').second)
                                    need_next = true;
                            }
                        }
                    }
                }
            }
        } while (need_next);

//        for(auto t_vn:vn){
//            cout<<t_vn.signal<<":   ";
//            for(auto item:t_vn.first)
//                if(item == 0) cout<<epsilon<<",";
//                else cout<<item<<",";
//            cout<<endl;
//        }
    }
    void make_follow(){
        getVn(startVn).follow.insert('#');
        for(auto & item_vn:vn){
            string s_vn = item_vn.signal;
            FOLLOW& follow_vn = item_vn.follow;
            for(auto item_can:p[s_vn]){
                for(int i=0; i<item_can.element.size()-1; ++i){
                    string element = item_can.element[i];
                    if(isVn(element)){
                        Vn& t_vn = getVn(element);
                        int j=i+1;
                        while(j<=item_can.element.size()-1){
                            element = item_can.element[i+1];
                            if(isVt(element)){
                                t_vn.follow.insert(element[0]);
                                break;
                            }
                            for(auto vt_t: getVn(element).first)
                                if(vt_t!='\0')
                                    t_vn.follow.insert(vt_t);
                            if(HEp_first(element) == false)
                                break;
                        }
                    }
                }
            }
        }
        bool need_next;
        do{
            need_next = false;
            for(auto & vn_item:vn){
                for(auto & can_item:p[vn_item.signal]){
                    for(int i=can_item.element.size()-1; i>=0; --i){
                        string cha = can_item.element[i];
                        if(isVn(cha)){
                            Vn& vn_t = getVn(cha);
                            for(auto vt_t:vn_item.follow){
                                if(vn_t.follow.insert(vt_t).second)
                                    need_next = true;
                            }
                            if(!CIEp(vn_t))
                                break;
                        } else break;
                    }
                }
            }
        } while (need_next);

//        for(auto it:vn){
//            cout<<it.signal<<":  ";
//            for(auto item:it.follow)
//                if(item == '\0') cout<<epsilon<<",";
//                else cout<<item<<",";
//            cout<<endl;
//        }
    }

    void make_analyse_table(){
        // 这个其实原本没有必要的,但是为了留住NOT_A_LL1_G,这里把预测分析表指针全置空
        // 这个似乎真的没必要了,因为发现他会默认置nullptr;
        vector<char> t(vt.begin(), vt.end());
        t.push_back('#');
        for(auto vn_item:vn){
            for(auto ch:t){
                analyse_table[vn_item.signal][ch] = nullptr;
            }
        }

        for(auto vn_item:vn){
            for(const auto& can:p[vn_item.signal]){
                for(auto first_ch:can.first){
                    if(first_ch == '\0') {
                        for(auto follow_ch:vn_item.follow){
                            if(analyse_table[vn_item.signal][follow_ch] != nullptr)
                                wrong(NOT_A_LL1_G);
                            analyse_table[vn_item.signal][follow_ch] = &can;
                        }
                        // 预测分析表中不需要M[Vn,ε]的,因为后面的总控程序也用不到,所以这里略去,
                        // 加上只会占用一些空间,没有价值但对结果也无影响。
                        continue;
                    };
                    if(analyse_table[vn_item.signal][first_ch] != nullptr)
                        wrong(NOT_A_LL1_G);
                    analyse_table[vn_item.signal][first_ch] = &can;
                }
            }
        }
    }
    void show_analyse_table(){
//        vector<char> vt_t(vt.begin(), vt.end());
//        vt_t.push_back('#');
//        cout<<"预测分析表:"<<endl;
//        cout<<"\t\t\t";
//        for_each(vt_t.begin(), vt_t.end(),[](char c){cout<<c<<"\t\t\t";});
//        cout<<endl;
//        rep(i,1,vt_t.size()) cout<<"----------+" ;
//        cout<<"----------+----------"<<endl;
//        for(auto vn_item: vn){
//            cout<<vn_item.signal<<"\t\t\t";
//            for(auto c:vt_t){
//                if(!analyse_table[vn_item.signal][c].empty()){
//                    cout<<vn_item.signal<<"->";
//                    for_each(analyse_table[vn_item.signal][c].begin(), analyse_table[vn_item.signal][c].end(),[](string s){cout<<s;});
//                }
//                cout<<"\t\t";
//            }
//            cout<<endl;
//        }

        vector<char> vt_t(vt.begin(), vt.end());
        vt_t.push_back('#');
        cout<<endl<<"analyse table:"<<endl;
        cout<<"\t";
        for_each(vt_t.begin(), vt_t.end(),[](char c){cout<<c<<"\t";});
        cout<<endl<<"+";
        rep(i,1,vt_t.size()) cout<<"-------+" ;
        cout<<"-------+"<<endl;
        for(auto vn_item: vn){
            cout<<vn_item.signal<<"\t";
            for(auto c:vt_t){
                if(analyse_table[vn_item.signal][c] != nullptr){
                    cout<<"p"<<analyse_table[vn_item.signal][c]->pi;
                }
                cout<<"\t";
            }
            cout<<endl;
        }
        cout<<"+";
        rep(i,1,vt_t.size()) cout<<"-------+" ;
        cout<<"-------+"<<endl;
    }

    void LL_analyse(string str){
        cout<<endl<<str<<"#analyse:"<<endl;
        cout<<"initial:# push,S push;"<<endl;
//        token串不应该有间隔符的,测试样例李有空格,所以先消除。
//        在文件导入字符串的时候我就把空格清除了,所以这里也注释掉了。
//        str.erase(remove_if(str.begin(), str.end(),[&](char a){return isspace(a);}),str.end());
//        str.erase(std::remove_if(str.begin(), str.end(), [](char c){ return std::isspace(c); }), str.end());
        str.push_back('#');
        stack<string> stack;
        stack.push("#");
        stack.push(startVn);
        char a = advance(str);
        for(int i=1; true; ++i){
            cout<<setw(2)<<setfill('0')<<i<<":";
            string elem = stack.top(); stack.pop();
            cout<<"pop X="<<elem<<",\t";
            cout<<"input "<<"c="<<a<<",";
            if(isVt(elem)){
                if(elem[0] == a){
                    a = advance(str);
                    cout<<"match,advance;"<<endl;
                }
                else wrong(NOT_MATCH);
            }
            else if(elem[0] == '#'){
                if(a == '#'){
                    cout<<"match,success.";
                    break;
                }
                wrong(NOT_MATCH);
            }
            else{
                if(analyse_table[elem][a] == nullptr)
                    wrong(NOT_MATCH);
                const vector<string>& can = analyse_table[elem][a]->element;
                if(can.empty())
                    wrong(NOT_MATCH);
                if(can[0] == epsilon){
                    cout<<"select,M[X,c]="<<elem<<"->"<<epsilon_show<<";"<<endl;
                    continue;
                }
                for(int i=can.size()-1; i>=0; --i)
                    stack.push(can[i]);
                cout<<"select,M[X,c]="<<elem<<"->";
                for_each(can.begin(), can.end(),[](string s){cout<<s;});
                cout<<",generator reverce pushed in"<<endl;
            }
        }
    }

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
                    t = epsilon;
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
                if(t == epsilon_show)
                    t = epsilon;
                candidate.element.push_back(t);
            }
            g.p[vn].push_back({candidate});
        }
//        输入开始符号
        cin>>g.startVn;

        return cin;
    }
};
string input_str(string file_path){
    ifstream file(file_path);
    stringstream buf;
    if(file){
        buf << file.rdbuf();
        string t = buf.str();
        t.erase(remove_if(t.begin(), t.end(), ::isspace),t.end());
        return t;
    }
    cout<<"open file error";
    exit(0);
}
int main(int argc, char* argv[]){
    if(argc != 3){
        cout<<"please input two file path."<<endl;
        return 0;
    }
    string g_file_path = argv[1];
    string str_file_path = argv[2];
    G g;
    g.get_form_file(g_file_path);
    g.make_first();
    g.make_follow();
    g.make_analyse_table();
    g.show_analyse_table();
    string s = input_str(str_file_path);
    g.LL_analyse(s);

//    cout<<"ε"<<endl;
//    G g;
//    g.get_form_file("D:\\CLionProjects\\untitled\\compile_principle\\experiment6_LL\\test_g.txt");
//    g.make_first();
//    g.make_follow();
//    g.make_analyse_table();
//    g.show_analyse_table();
//    string s = input_str("D:\\CLionProjects\\untitled\\compile_principle\\experiment6_LL\\test_string.txt");
//    g.LL_analyse(s);
    return 0;
}