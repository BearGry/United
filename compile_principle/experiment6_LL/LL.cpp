/*
 * 需要实现的功能：
1）构造文法的LL预测分析表；
2）构造LL语法分析器的总控程序；
3）输入文法：文法描述存储在文本文件中（编码格式ANSI），文件名作为命令行参数输入；
4）输入待分析的符号串：符号串存储在文本文件中（编码格式ANSI），文件名作为命令行参数输入。
5）输出文法的LL预测分析表到标准输出设备；
6）输出分析结果：输出待分析符号串是否为该文法正确句子的判断，并输出文本形式的分析过程（标准输出设备）。
 */
#include <bits/stdc++.h>
#define epsilon "ε"
#define FIRST unordered_set<char>
#define FOLLOW unordered_set<char> //这里的非终结符用的char类型，存不了epsilon，所以epsilon在G中的存法为‘\0’!!!
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
        // 一直循环修改FIRST集，直到某一轮每个非终结符的FIRST集不再改变
        bool need_next;
        do{
            need_next = false;
            // 遍历每一个非终结符vn
            for(auto &item_vn:vn){
                string vn=item_vn.signal;
                Candidates& cans = p[vn];
                // 遍历vn候选式集中的每一个候选式can(candidate的简写)
                for(auto &item_can:cans){
                    // 遍历can中的每一个元素element
                    // （文法在输入进来的时候，将产生式右部的每一个元素，不论终结符还是非终结符还是epsilon，
                    // 都作为一个string类型的值，单独存到vector<string>里，作为can的一个属性）
                    for(int i=0; i<item_can.element.size(); ++i){
                        string element = item_can.element[i];
                        // 如果element是非终结符，则将其加入vn和can的FIRST集中，并去搜索下一个can
                        // 没有重复加入的话，则置need_next为true.
                        if(isVt(element)){
                            item_can.first.insert(element[0]);
                            if(item_vn.first.insert(element[0]).second)
                                need_next = true;
                            break;
                        }
                        // 如果element为epsilon，则将其加入vn和can的FIRST集中，并去搜索下一个can
                        // 没有重复加入的话，则置need_next为true.
                        // FIRST集中，epsilon用‘\0’来表示
                        if(element == epsilon){
                            item_can.first.insert('\0');
                            if(item_vn.first.insert('\0').second)
                                need_next = true;
                            break;
                        }
                        // 如果element为非终结符，将其FIRST集中除epsilon外的元素加入vn和can的FIRST集中
                        // 如果该非终结符的FIRST中不包含epsilon，则取搜索下一个can
                        // 如果该元素为产生式右部的最后一个元素且其FIRST集中包含epsilon，将epsilon加入vn和can的FIRST集中
                        // 该过程中如果出现非重复加入，则置need_next为true.
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

//         测试输出
        for(auto t_vn:vn){
            cout<<t_vn.signal<<":   ";
            for(auto item:t_vn.first)
                if(item == 0) cout<<epsilon<<",";
                else cout<<item<<",";
            cout<<endl;
        }
    }
    void make_follow(){
        // 开始符号的FOLLOW集中加入‘#’
        getVn(startVn).follow.insert('#');
        // 先来一次遍历，把A->aBc这样形式的产生式，把c的FIRST集中除epsilon的元素加入到B的FOLLOW集中
        // 因为FIRST集在FOLLOW集的构造过程中不会再改变，所以只需一遍。
        // 遍历每一个非终结符vn
        for(auto & item_vn:vn){
            string s_vn = item_vn.signal;
            FOLLOW& follow_vn = item_vn.follow;
            // 遍历vn的每一个产生式can
            for(auto item_can:p[s_vn]){
                // 遍历can中的每一个元素
                for(int i=0; i<item_can.element.size()-1; ++i){
                    string element = item_can.element[i];
                    // 如果是非终结符
                    if(isVn(element)){
                        Vn& t_vn = getVn(element);
                        // 去下一个元素
                        int j=i+1;
                        // 一直遍历，直到最后一个，中途如果遇到终结符或者非终结符first中不含epsilon退出
                        while(j<=item_can.element.size()-1){
                            element = item_can.element[i+1];
                            if(isVt(element)){
                                t_vn.follow.insert(element[0]);
                                break;
                            }
                            // 把first-{epsilon}加入
                            for(auto vt_t: getVn(element).first)
                                if(vt_t!='\0')
                                    t_vn.follow.insert(vt_t);
                            // 如果含epsilon则继续考察下一个，如果不含直接退出
                            if(HEp_first(element) == false)
                                break;
                        }
                    }
                }
            }
        }

        // 下面的针对若A->aB或A->aBc，epsion属于c的FIRST集时，将FOLLOW（A）中的元素加至FOLLOW（B）中，
        // 一直循环，直至某一轮所有非终结符的FOLLOW集不再变化。
        bool need_next;
        do{
            need_next = false;
            // 遍历每一个非终结符vn
            for(auto & vn_item:vn){
                // 遍历vn的每一个候选式can
                for(auto & can_item:p[vn_item.signal]){
                    // 遍历can中每一个元素
                    // 这里有个小技巧：逆序遍历can中的每一个元素，
                    // 这样有助于A->aBc，epsion属于c的FIRST集时，将FOLLOW（A）中的元素加至FOLLOW（B）中的情况
                    // 推导终结符的操作是显而易见的————直接结束，搜索下一个候选式
                    // 问题在于推到一个非终结符是否要往前推，
                    // 通过该遍历方式，若某一非终结符FIRST集中不包含epsilon则停止，否则继续
                    for(int i=can_item.element.size()-1; i>=0; --i){
                        string cha = can_item.element[i];
                        // 如果是非终结符，则将FOLLOW（vn）中的元素加入到该非终结符的FOLLOW集中
                        // 如果未重复插入，则置need_next为true
                        if(isVn(cha)){
                            Vn& vn_t = getVn(cha);
                            for(auto vt_t:vn_item.follow){
                                if(vn_t.follow.insert(vt_t).second)
                                    need_next = true;
                            }
                            // 当前非终结符推不出epsion（与其FIRST集中不包含epsilon等价），则退出搜索下一个候选式
                            if(!CIEp(vn_t))
                                break;
                        } else break;
                    }
                }
            }
        } while (need_next);

        // 测试输出
//        for(auto it:vn){
//            cout<<it.signal<<":  ";
//            for(auto item:it.follow)
//                if(item == '\0') cout<<epsilon<<",";
//                else cout<<item<<",";
//            cout<<endl;
//        }
    }

    void make_analyse_table(){
        // 这个其实原本没有必要的，但是为了留住NOT_A_LL1_G，这里把预测分析表指针全置空
        // 这个似乎真的没必要了，因为发现他会默认置nullptr;
        vector<char> t(vt.begin(), vt.end());
        t.push_back('#');
        for(auto vn_item:vn){
            for(auto ch:t){
                analyse_table[vn_item.signal][ch] = nullptr;
            }
        }
        // 遍历每一个非终结符vn
        for(auto vn_item:vn){
            // 遍历vn的每一个候选式can(candidate的简写)
            for(const auto& can:p[vn_item.signal]){
                // 遍历can的每一个首符元素
                for(auto first_ch:can.first){
                    // 如果为epsilon，则将vn的follow集中的元素添加进来
                    if(first_ch == '\0') {
                        for(auto follow_ch:vn_item.follow){
                            // 出现重复则说明不满足LL1——若FIRST（vn）包含epsilon，怎FIRST（vn）交FOLLOW（vn）为空
                            if(analyse_table[vn_item.signal][follow_ch] != nullptr)
                                wrong(NOT_A_LL1_G);
                            analyse_table[vn_item.signal][follow_ch] = &can;
                        }
                        // 预测分析表中不需要M[Vn,ε]的，因为后面的总控程序也用不到，所以这里略去，
                        // 加上只会占用一些空间，没有价值但对结果也无影响。
                        continue;
                    };
                    // 如果该首符元素不是epsilon，则M[vn][ch_first]=can
                    // 这里也是检查文法是不是LL1的，如果出现重复则违反LL1文法中 vn的任意两个候选式首符集交集为空 的规则
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
//        cout<<"预测分析表："<<endl;
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
        cout<<endl<<"预测分析表："<<endl;
        cout<<"\t\t";
        for_each(vt_t.begin(), vt_t.end(),[](char c){cout<<c<<"\t";});
        cout<<endl<<"-";
        rep(i,1,vt_t.size()) cout<<"---+" ;
        cout<<"---+----"<<endl;
        for(auto vn_item: vn){
            cout<<vn_item.signal<<"\t\t";
            for(auto c:vt_t){
                if(analyse_table[vn_item.signal][c] != nullptr){
                    cout<<"p"<<analyse_table[vn_item.signal][c]->pi;
                }
                cout<<"\t";
            }
            cout<<endl;
        }
        cout<<"-";
        rep(i,1,vt_t.size()) cout<<"---+" ;
        cout<<"---+----"<<endl;
    }

    void LL_analyse(string str){
        cout<<endl<<str<<"#分析过程："<<endl;
        cout<<"初始化：#入栈，S入栈；"<<endl;
//        token串不应该有间隔符的，测试样例中有空格，所以先消除。
//        在文件导入字符串的时候我就把空格清除了，所以这里也注释掉了。
//        str.erase(remove_if(str.begin(), str.end(),[&](char a){return isspace(a);}),str.end());
//        str.erase(std::remove_if(str.begin(), str.end(), [](char c){ return std::isspace(c); }), str.end());
        str.push_back('#'); // 待分析的符号串末尾加‘#’
        // 将‘#’，开始符号顺序压入栈中
        stack<string> stack;
        stack.push("#");
        stack.push(startVn);
        // 第一个输入符号读进a
        char a = advance(str);
        for(int i=1; true; ++i){
            cout<<setw(2)<<setfill('0')<<i<<":";
            string elem = stack.top(); stack.pop();
            cout<<"出栈X="<<elem<<",\t";
            cout<<"输入"<<"c="<<a<<",";
            // 如果是终结符，判断X=a？
            // 相等则输出匹配，病毒如下一个输入字符到a；不等则说明待分析的字符串不是该文法的句子
            if(isVt(elem)){
                if(elem[0] == a){
                    a = advance(str);
                    cout<<"匹配，输入指针后移;"<<endl;
                }
                else wrong(NOT_MATCH);
            }
            // 如果是‘#’，则判断a=‘#’？若等则匹配完毕是句子，若不等则不是该文法的句子
            else if(elem[0] == '#'){
                if(a == '#'){
                    cout<<"匹配，成功。";
                    break;
                }
                wrong(NOT_MATCH);
            }
            // 是非终结符的情况
            else{
               // 预测分析表中M[X,a]是否为空，为空则说明不是该文法的句子
                if(analyse_table[elem][a] == nullptr)
                    wrong(NOT_MATCH);
                const vector<string>& can = analyse_table[elem][a]->element;
                if(can.empty())
                    wrong(NOT_MATCH);
                // 不为空的情况下判断是否为{epsilon}
                // 若是则什么也不做，进行下一次出栈操作；
                // 若不是，则将M[X,a]中元素逆序压入栈中
                if(can[0] == epsilon){
                    cout<<"查表，M[X,c]="<<elem<<"->"<<epsilon<<";"<<endl;
                    continue;
                }
                for(int i=can.size()-1; i>=0; --i)
                    stack.push(can[i]);
                cout<<"查表，M[X,c]="<<elem<<"->";
                for_each(can.begin(), can.end(),[](string s){cout<<s;});
                cout<<"，产生式右部逆序入栈；"<<endl;
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
//                if(t == epsilon)
//                    t = "\0";
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
//                if(t == epsilon)
//                    t = "\0";
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
    cout<<"打开文件失败";
    exit(0);
}
int main(int argc, char* argv[]){
//    if(argc != 3){
//        cout<<"please input two file path."<<endl;
//        return 0;
//    }
//    string g_file_path = argv[1];
//    string str_file_path = argv[2];
//    G g;
//    g.get_form_file(g_file_path);
//    g.make_first();
//    g.make_follow();
//    g.make_analyse_table();
//    g.show_analyse_table();
//    string s = input_str(str_file_path);
//    g.LL_analyse(s);

    G g;
//    g.get_form_file("D:\\CLionProjects\\untitled\\compile_principle\\experiment6_LL\\test_g.txt");
    cin>>g;
    g.make_first();
    g.make_follow();
    g.make_analyse_table();
    g.show_analyse_table();
    string s = input_str("D:\\CLionProjects\\untitled\\compile_principle\\experiment6_LL\\test_string.txt");
    g.LL_analyse(s);
}