/*
 * 需要实现的功能:
1）使用LR(1)分析方法构造识别活前缀的DFA；
2）构造文法的分析表（Action表和Goto表）；
3）输入文法：文法描述存储在文本文件中，文件名作为命令行参数输入；
4）输出文法的项目集簇（标准输出设备）；
5）输出识别活前缀的DFA（标准输出设备）；
6）输出文法的Action表和Goto表（输出到创建的指定LR分析表文件，文件名与文法描述文件同名，扩展名为lrtbl）；
7）输出文法是否是LR(1)文法的判断结果（标准输出设备）。
 */

#include <bits/stdc++.h>
#define cao const auto&
#define ao auto&
#define epsilon_show ":D"
// 产生式（候选式）中，epsilno以空表示，即vector<string>为空
// first集中以‘\0’形式出现，被封装为epsilon，注意是char类型
#define epsilon '\0'
#define FIRST unordered_set<char>
#define Candidates vector<Candidate>
#define rep(x, y, z) for(int x=y; x<=z; ++x)
using namespace std;

string filename_g = "D:\\CLionProjects\\untitled\\compile_principle\\experiment8_LR1\\g";
string filename_s = "D:\\CLionProjects\\untitled\\compile_principle\\experiment8_LR1\\sentence";

enum LR_type {
    LR0, LR1, SLR, LALR
};

class DFA_LR1;
class LR_Analyser;
class Vn {
public:
    string signal; // 非终结符号名称
    FIRST first; // 对应非终结符号的FIRST集合

    Vn(string s) : signal(s) {}
    Vn() {}
};

class Candidate {
public:
    vector<string> element; // 产生式右部元素
    int pi; // 项目编号
    FIRST first; // 产生式右部对应的FIRST集合

    friend ostream &operator<<(ostream &out, const Candidate &t) {
        for (const auto &item: t.element)
            cout << item << " ";
        return out;
    }

    void LR_show(int p) const {
        for (int i = 0; i < element.size(); i++) {
            if (i == p)
                cout << ". ";
            cout << element[i] << " ";
        }
        if (p == element.size())
            cout << ".";
    }
};

class G {
private:
    vector<Vn> vn; // 非终结符号集合
    vector<char> vt; // 终结符号集合
    unordered_map<string, Candidates > p; // 产生式集合
    string startVn; // 文法的起始符号

    inline bool is_epsilon(string &s) {
        if (s.size() != 2) return false;
        for (const auto vn_t: vn) {
            if (vn_t.signal == s)
                return false;
        }
        return true;
    };

    inline bool isVt(string s) {
        if (s.size() == 1) {
            char ch = s[0];
            if (find(vt.begin(), vt.end(), ch) != vt.end())
                return true;
        }
        return false;
    }

    inline bool isVn(string s) {
        for (auto it: vn)
            if (it.signal == s) return true;
        return false;
    }

    inline Vn &getVn(string t) {
        for (auto &item: vn)
            if (item.signal == t)
                return item;
        cout<<"Error in getVn!"<<endl;
        exit(0);
    }

    inline bool HEp_first(Vn t) {
        if (t.first.count('\0') > 0)
            return true;
        return false;
    }

public:
    // 计算文法符号的FIRST集合
    void make_first() {
        bool need_next;
        // 重复计算FIRST集合直到不再有变化
        do {
            need_next = false;
            for (auto &item_vn: vn) {
                string vn = item_vn.signal;
                Candidates &cans = p[vn];
                for (auto &item_can: cans) {
                    if(item_can.element.empty()){
                        // 若产生式为空，则加入epsilon到FIRST集合中
                        item_can.first.insert(epsilon);
                        if(item_vn.first.insert(epsilon).second)
                            need_next = true;
                        continue;
                    }
                    for (int i = 0; i < item_can.element.size(); ++i) {
                        string element = item_can.element[i];
                        if (isVt(element)) {
                            // 若为终结符号，则加入到FIRST集合中
                            item_can.first.insert(element[0]);
                            if (item_vn.first.insert(element[0]).second)
                                need_next = true;
                            break;
                        }
                        Vn &t_vn = getVn(element);
                        for (auto it: t_vn.first) {
                            if (it == '\0') continue;
                            // 加入非终结符号的FIRST集合到当前产生式的FIRST集合中
                            item_can.first.insert(it);
                            if (item_vn.first.insert(it).second)
                                need_next = true;
                        }
                        if (!HEp_first(t_vn)) break;
                        if (i == item_can.element.size() - 1) {
                            // 若最后一个符号的FIRST集合包含epsilon，则加入epsilon到当前产生式的FIRST集合中
                            item_can.first.insert('\0');
                            if (item_vn.first.insert('\0').second)
                                need_next = true;
                        }
                    }
                }
            }
        } while (need_next);

        // 输出FIRST集合（用于测试）
//        for(auto t_vn:vn){
//            cout<<t_vn.signal<<":   ";
//            for(auto item:t_vn.first)
//                if(item == 0) cout<<epsilon_show<<",";
//                else cout<<item<<",";
//            cout<<endl;
//        }
    }

    // 从文件中读取构造文法
    void get_form_file(string file_path) {
        ifstream fin(file_path); // 打开文件流用于读取文件
        if (!fin.is_open()) { // 如果文件无法打开
            cout << "please check the g file path" << endl; // 输出错误信息
            exit(0); // 退出程序
        }
        int k;
        string tvn;
        char tvt;
        // 输入非终结符Vn
        fin >> k; // 读取非终结符数量
        for (int i = 1; i <= k; ++i) { // 逐个读取非终结符并存入vn
            fin >> tvn;
            vn.push_back(tvn);
        }
        // 输入终结符Vt
        fin >> k; // 读取终结符数量
        rep(i, 1, k) { // 逐个读取终结符并存入vt
            fin >> tvt;
            vt.push_back(tvt);
        }
        // 输入产生式P
        fin >> k; // 读取产生式数量
        --k;
        rep(i, 0, k) { // 逐个读取产生式，并将其存入p
            Candidate candidate;
            candidate.pi = i;
            fin >> tvn;
            string t;
            fin >> t; // 读取产生式箭头"->
            while (fin.get() != '\n') { // 读取产生式右侧内容
                fin >> t;
                if (is_epsilon(t)) // 检查是否为ε
                    continue;
                candidate.element.push_back(t); // 将产生式右侧内容存入candidate
            }
            p[tvn].push_back({candidate}); // 将当前产生式存入p
        }
        // 输入开始符号
        fin >> startVn; // 读取开始符号
        fin.close(); // 关闭文件流

        return;
    }

    friend istream &operator>>(istream &cin, G &g) {
        int k;
        string vn;
        char vt;
        // 输入非终结符Vn
        cin >> k; // 读取非终结符数量
        for (int i = 1; i <= k; ++i) { // 逐个读取非终结符并存入g.vn
            cin >> vn;
            g.vn.push_back(vn);
        }
        // 输入终结符Vt
        cin >> k; // 读取终结符数量
        rep(i, 1, k) { // 逐个读取终结符并存入g.vt
            cin >> vt;
            g.vt.push_back(vt);
        }
        // 输入产生式P
        cin >> k; // 读取产生式数量
        --k;
        rep(i, 0, k) { // 逐个读取产生式并将其存入g.p
            Candidate candidate;
            candidate.pi = i;
            cin >> vn;
            string t;
            cin >> t; // 读取产生式箭头"->
            while (getchar() != '\n') { // 读取产生式右侧内容
                cin >> t;
                if (g.is_epsilon(t)) // 检查是否为ε
                    continue;
                candidate.element.push_back(t); // 将产生式右侧内容存入candidate
            }
            g.p[vn].push_back({candidate}); // 将当前产生式存入g.p
        }
        // 输入开始符号
        cin >> g.startVn; // 读取开始符号

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

    friend class DFA_LR1;
    friend class LR_Analyser;
};

class project_LR1 {
private:
    // 检查两个unordered_set<char>是否相等
    inline bool equal_ff(const unordered_set<char>& a, const unordered_set<char>& b) const{
        if(a.size() != b.size())
            return false;
        for(const auto & c:a){
            if(b.count(c) == 0)
                return false;
        }
        return true;
    }
public:
    string vn; // 项目的非终结符
    Candidate candidate; // 项目的候选式
    int point; // 项目中"."的位置
    unordered_set<char> forward; // 项目的前瞻符号集合

    // 重载==运算符，用于比较两个project_LR1对象是否相等
    bool operator==(const project_LR1& t) const{
        if (vn == t.vn && candidate.pi == t.candidate.pi && point == t.point && equal_ff(forward,t.forward))
            return true;
        return false;
    }

    // 重载!=运算符，用于比较两个project_LR1对象是否不相等
    bool operator!=(const project_LR1& t) const{
        return !this->operator==(t);
    }
};

class project_LR1_set {
public:
    struct relation {
        string v; // 边上的符号
        int project_set_num; // 边所指向的项目集编号
    };
    vector<project_LR1> set; // 存储project_LR1对象的集合
    int primary_num; // project_LR1集合的大小
    vector<relation> edges; // 关系

    // 查找具有特定候选式的project_LR1的前瞻符号集合
    unordered_set<char> find_pj1(const Candidate& t) const{
        unordered_set<char> res;
        for (const auto& item: set)
            if (item.point == 0 && item.candidate.pi == t.pi)
                res.insert(item.forward.begin(), item.forward.end());
        return res;
    }

    // 重载==运算符，用于比较两个project_LR1_set对象是否相等
    bool operator==(const vector<project_LR1> &t) const{
        if(t.size() != primary_num)
            return false;
        for (int i = 0; i < primary_num; ++i) {
            if (set[i] != t[i])
                return false;
        }
        return true;
    }

    // 对项目集进行压缩，合并具有相同候选式和"."位置的项目的前瞻符号集合
    void zip(){
        for(int i=0; i<set.size(); ++i){
            for(int j=i+1; j<set.size(); ++j){
                if(set[i].candidate.pi == set[j].candidate.pi && set[i].point == set[j].point){
                    set[i].forward.insert(set[j].forward.begin(), set[j].forward.end());
                    set.erase(set.begin()+j);
                    --j;
                }
            }
        }
    }
};


class DFA_LR1 {
private:
    int status_num; // DFA_LR1中状态的数量
    vector<string> characters; // DFA_LR1的字符集
    vector<project_LR1_set> cluster; // DFA_LR1的项目集族
    int start_status = 0; // 起始状态的编号
    vector<int> ends; // 终止状态的编号集合

    // 生成后面符号集的FIRST集
    inline unordered_set<char> make_first(const project_LR1& pj, G& g) const{
        unordered_set<char> res;
        for(int i=pj.point+1; i<pj.candidate.element.size(); ++i){
            string s = pj.candidate.element[i];
            if(g.isVt(s)){
                res.insert(s[0]);
                return res;
            }
            const Vn& v = g.getVn(s);
            for(const auto& c:v.first){
                if(c!=epsilon)
                    res.insert(c);
            }
            if(!g.HEp_first(v))
                return res;
        }
        res.insert(pj.forward.begin(), pj.forward.end());
        return res;
    }

    // 生成闭包项目集
    inline project_LR1_set make_closure(const vector<project_LR1>& primary_pros, G &g) const{
        project_LR1_set res = {primary_pros};
        res.primary_num = primary_pros.size();

        vector<project_LR1>& set = res.set;
        for(int i=0; i<set.size(); ++i){
            const project_LR1& pj = set[i];
            if(pj.point == pj.candidate.element.size())
                continue;
            string v = pj.candidate.element[pj.point];
            if(g.isVn(v)){
                unordered_set<char> forward = make_first(pj,g);
                for(const auto& item:g.p[v]){
                    unordered_set<char> hasd = res.find_pj1(item);
                    for(const auto& c:hasd){
                        forward.erase(c);
                    }
                    if(!forward.empty()){
                        set.push_back({v,item,0,forward});
                    }
                }
            }
        }
        return res;
    }

    // 生成特定字符ch对应的初态项目集
    inline vector<project_LR1> make_primary_pros(const vector<project_LR1> &ps, const string &ch) {
        vector<project_LR1> res;
        for (const auto &pj: ps) {
            if (pj.point < pj.candidate.element.size()) {
                string v = pj.candidate.element[pj.point];
                if (v == ch) {
                    res.push_back({pj.vn, pj.candidate, pj.point + 1,pj.forward});
                }
            }
        }
        return res;
    }

    // 查找项目集ps在cluster中的索引
    inline int find(const vector<project_LR1> &ps) const{
        for (int i = 0; i < cluster.size(); ++i) {
            if (cluster[i] == ps)
                return i;
        }
        return cluster.size();
    }

    // 对项目集族进行压缩，合并具有相同候选式和"."位置的项目的前瞻符号集合
    inline void zip(){
        for(auto & t:cluster){
            t.zip();
        }
    }

public:
    friend class G;

    // 构造函数，根据文法G创建LR(1)分析表的DFA
    DFA_LR1(G &g) {
        // 生成文法的FIRST集
        g.make_first();

        // 将非终结符和终结符放入字符集中
        for (const auto& s: g.vn)
            characters.push_back(s.signal);
        for (const auto& s: g.vt)
            characters.push_back(string(1, s));

        // 创建初始项目集
        vector<project_LR1> primary_pros;
        primary_pros.push_back({g.startVn, g.p[g.startVn][0], 0,{'#'}}); // '#' 为结束符号

        // 闭包构造元项目集作为初始项目集
        cluster.push_back(make_closure(primary_pros, g));

        // 对初始项目集进行遍历搜索，构建DFA的状态转移关系
        for (int i = 0; i < cluster.size(); ++i) {
            for (const auto& ch: characters) {
                primary_pros.clear();
                primary_pros = make_primary_pros(cluster[i].set, ch);
                if (primary_pros.empty())
                    continue;

                // 搜索-创建关系
                int relate_num = find(primary_pros);
                cluster[i].edges.push_back({ch, relate_num});

                // 闭包构造新项目集，若新项目集不在已有的项目集中，则加入
                if (relate_num == cluster.size()) {
                    cluster.push_back(make_closure(primary_pros, g));
                }
            }

            // 记录没有出边的项目集作为结束状态
            if (cluster[i].edges.empty())
                ends.push_back(i);
        }

        // 对项目集族进行压缩处理
        zip();
        status_num = cluster.size();
    }

    // 输出LR(1)项目集族
    void show_LR1_projects_cluster() {
        cout << "LR(1) projects cluster" << endl;
        int i = 0;
        for (const auto &ps: cluster) {
            cout << "  I" << i++ << " :" << endl;
            for (const auto &pj: ps.set) {
                cout << "\t" << pj.vn << " -> ";
                pj.candidate.LR_show(pj.point);
                cout<<"\t";
                for(auto i = pj.forward.begin(); true;){
                    cout<<*i<<" ";
                    if(++i != pj.forward.end())
                        cout<<"| ";
                    else break;
                }
                cout << endl;
            }
        }
    }

    // 输出LR(1)DFA状态转移表信息
    void show() {
        cout << "DFA" << endl;
        cout << "  number of status: " << status_num << endl;
        cout << "  number of characters: " << characters.size() << endl;
        cout << "  status stransform: " << endl;
        for (int i = 0; i < status_num; ++i) {
            if (!cluster[i].edges.empty()) {
                for (auto item: cluster[i].edges)
                    cout << "    (" << i << "," << item.v << ")->" << item.project_set_num << endl;
            }
        }
        cout << "  start status: " << start_status << endl;
        cout << "  final status set: " << "{ ";
        for (auto item: ends)
            cout << item << " ";
        cout << "}" << endl;
    }

    friend class LR_Analyser;
};


class LR_Analyser {
private:
    // 定义动作表(Action Table)项的结构体
    struct Action_Type {
        char s_r; // 记录Shift或Reduce或Accept
        union jump {
            int s; // 状态转移
            const project_LR1 *p; // 项目指针
        } a;

        Action_Type() : s_r('e') {} // 初始化为e（错误状态）
    };

    // 错误类型枚举
    enum error{NOT_MATCH, NOT_A_LR1_G};

    // 存储LR分析表的Action和Goto表
    unordered_map<int, unordered_map<char, Action_Type>> action;
    unordered_map<int, unordered_map<string, int>> gotoo;

    bool is = true; // 是否为LR(1)文法

    stack<int> status; // 状态栈
    stack<string> chs; // 字符串栈

    // 向前读取输入串的一个字符
    inline char advance(string& s){
        if(s.empty())
            wrong(NOT_MATCH); // 输入串为空的错误处理
        char a = s.front();
        s.erase(0,1);
        return a;
    }

    // 错误处理函数
    inline void wrong(error e){
        if(e == NOT_MATCH){
            cout<<endl<<"----------NOT_MATCH-----------"<<endl;
        }
        else if(e == NOT_A_LR1_G){
            cout<<endl<<"----------NOT_A_LL1_G-----------"<<endl;
        }
        exit(0);
    }

//    enum wrong_type{NOT_LR0_S,NOT_LR0_R};
//    void wrong(wrong_type e, int i=0){
//        if(e == NOT_LR0_S){
//            cout<<""
//        }
//    }

// 公共成员
public:
    // 构造函数，根据文法G和DFA_LR1创建LR分析器
    LR_Analyser(G &g, DFA_LR1 &d) {
        int i = 0;
        // 遍历DFA的状态集
        for (const auto &item: d.cluster) {
            // 遍历每个状态的出边，根据边类型填充Action表或Goto表
            for (const auto &t: item.edges) {
                string s = t.v;
                if (g.isVt(s)) {
                    action[i][s[0]].s_r = 's'; // Shift动作
                    action[i][s[0]].a.s = t.project_set_num;
                } else {
                    gotoo[i][s] = t.project_set_num; // Goto动作
                }
            }

            // 遍历项目集，处理规约动作
            for (const auto &t: item.set) {
                if (t.point == t.candidate.element.size() && t.candidate.pi != 0) {
                    for (const auto &k: t.forward) {
                        if (action[i][k].s_r == 's') {
                            is = false;
                            cout << "There is a shift-reduce conflict in item set" << i << " : ";
                            cout << "s" << action[i][k].a.s << "-r" << t.candidate.pi << endl;
                        } else if (action[i][k].s_r == 'r') {
                            is = false;
                            cout << "There is a reduce-reduce conflict in item set" << i << " : ";
                            cout << "r" << action[i][k].a.p->candidate.pi << "-r" << t.candidate.pi << endl;
                        } else if (action[i][k].s_r == 'e') {
                            action[i][k].s_r = 'r'; // Reduce动作
                            action[i][k].a.p = &t;
                        } else {
                            cout << "what?!" << endl;
                            exit(0);
                        }
                    }
                }
            }
            ++i;
        }

        // 判断接受状态
        if (action[1]['#'].s_r == 'r') {
            is = false;
            cout << "There is a reduce-reduce conflict in item set" << 1 << " : ";
            cout << "r" << action[1]['#'].a.p->candidate.pi << "-acc" << endl;
        } else if (action[1]['#'].s_r == 's') {
            cout << "what?!-2" << endl;
            exit(0);
        }
        action[1]['#'].s_r = 'a'; // Accept状态

        // 输出文法的LR(1)特性
        if (is)
            cout << "The grammar is an LR(1) grammar!" << endl;
        else
            cout << "The grammar is not an LR(1) grammar!" << endl;

    }

    // 写入LR分析表到文件
    void write(string filename){
        // 提取文件名部分（不包含扩展名）
        size_t lastDotPos = filename.find_last_of(".");
        if (lastDotPos != std::string::npos) {
            filename = filename.substr(0, lastDotPos);
        }
        filename += ".lrtbl"; // 添加新的扩展名
        ofstream fout(filename);

        if (fout.is_open()) {
            // 按状态编号排序Action表
            vector<pair<int, unordered_map<char, Action_Type>>> t_act(action.begin(), action.end());
            sort(t_act.begin(), t_act.end(),
                 [&](pair<int, unordered_map<char, Action_Type>> a, pair<int, unordered_map<char, Action_Type>> b) {
                     return a.first < b.first;
                 });

            int act_num = 0;
            // 写入Action表内容到文件
            for (const auto &item: t_act) {
                for (const auto &t: item.second) {
                    fout << item.first << " ";
                    fout << t.first << " " << t.second.s_r;
                    if (t.second.s_r == 's')
                        fout << t.second.a.s << endl;
                    else if (t.second.s_r == 'r')
                        fout << t.second.a.p->candidate.pi << endl;
                    else
                        fout << "cc" << endl;
                    ++act_num;
                }
            }
            fout << act_num << endl << endl;

            // 按状态编号排序Goto表
            vector<pair<int, unordered_map<string, int>>> t_go(gotoo.begin(), gotoo.end());
            sort(t_go.begin(), t_go.end(),
                 [&](pair<int, unordered_map<string, int>> a, pair<int, unordered_map<string, int>> b) {
                     return a.first < b.first;
                 });

            int go_num = 0;
            // 写入Goto表内容到文件
            for (const auto &item: t_go) {
                for (const auto &t: item.second) {
                    fout << item.first << " ";
                    fout << t.first << " " << t.second << endl;
                    ++go_num;
                }
            }
            fout << go_num << endl;

            fout.close();
        } else {
            cout << "Open file error! Failed to write." << endl;
        }
    }

// LR分析函数
    void analyse(string file_path){
        ifstream file(file_path);
        string s;

        if(file){
            // 读取文件内容并去除空格
            stringstream buf;
            buf << file.rdbuf();
            s = buf.str();
            s.erase(remove_if(s.begin(), s.end(), ::isspace),s.end());
        }
        else{
            cout<<"open file error";
            return;
        }

        // 初始化状态栈和字符串栈
        while (!status.empty())
            status.pop();
        while (!chs.empty())
            chs.pop();
        status.push(0);
        chs.push(string(1,'#'));
        char a = advance(s);
        int push_st;

        cout<<endl;
        cout<<"--+-------+-------+-------+-----------------------------+--"<<endl;
        cout<<" top\tinput   look\taction"<<endl;

        // LR分析主循环
        while(action[status.top()][a].s_r != 'a'){
            cout<<setw(2)<<setfill(' ')<<status.top()<<" "<<chs.top();
            char act = action[status.top()][a].s_r;
            cout<<"\t  "<<a<<"\t"<<act;

            if(act == 's'){ // Shift操作
                push_st = action[status.top()][a].a.s;
                chs.push(string(1,a));
                status.push(push_st);
                cout<<push_st<<"\t"<<"push  "<<push_st<<" "<<a<<endl;
                a = advance(s);
            }
            else if(act == 'r'){ // Reduce操作
                const auto* pj = action[status.top()][a].a.p;
                for(int i=1; i<=pj->point; ++i){
                    chs.pop();
                    status.pop();
                }
                chs.push(pj->vn);
                push_st = gotoo[status.top()][pj->vn];
                status.push(push_st);
                cout<<pj->candidate.pi<<'\t';
                cout<<"pop "<<pj->point<<" characters and status  ";
                cout<<"push  "<<push_st<<" "<<pj->vn<<'\t';
                cout<<pj->vn<<" -> "<<pj->candidate<<endl;
            }
            else{ // 错误处理
                wrong(NOT_MATCH);
            }
        }
        // 输出验证性信息
        cout<<setw(2)<<setfill(' ')<<status.top()<<" "<<chs.top();
        cout<<"\t  "<<a<<"\t"<<"acc\tAccept!"<<endl;
        cout<<"--+-------+-------+-------+-----------------------------+--"<<endl;

        file.close();
    }
};


int main(int argc, char* argv[]){
    //experiment8
//    if(argc != 2){
//        cout<<"please input grammer file path."<<endl;
//        return 0;
//    }
//    filename_g = argv[1];
//
//    G g;
//    g.get_form_file(filename_g);
//    cout<<g<<endl<<endl;
//
//    DFA_LR1 d(g);
//    d.show_LR1_projects_cluster();
//    cout<<endl;
//    d.show();
//    cout<<endl;
//
//    LR_Analyser l(g,d);
//    l.write(filename_g);

    // 如果命令行参数不等于3（语法文件路径和句子文件路径），则提示用户输入正确的文件路径
    if(argc != 3){
        cout<<"please input two file path."<<endl;
        return 0;
    }
    filename_g = argv[1]; // 语法文件路径
    filename_s = argv[2]; // 句子文件路径

    G g;
    g.get_form_file(filename_g); // 从语法文件中获取语法信息

    DFA_LR1 d(g); // 创建LR(1)自动机
    d.show_LR1_projects_cluster(); // 展示LR(1)自动机的项目集簇信息
    cout<<endl;
    d.show(); // 展示LR(1)自动机的状态转移信息
    cout<<endl;

    LR_Analyser l(g,d); // 创建LR分析器
    l.write(filename_g); // 将LR分析表写入文件
    l.analyse(filename_s); // 对句子文件进行LR分析

    return 0;
}
