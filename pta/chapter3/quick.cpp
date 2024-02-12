//
// Created by xiaodian& on 2023/11/6.
//
/*
 * 1 插座问题
分数 300
作者 吴云鹏
单位 郑州大学
体育馆内要举办一场程序设计竞赛的现场赛，需要接入服务器、路由器、打印机、电脑等电子设备（假定所有用电器的插头都是三头的）。而体育馆内的墙上只有一个三孔插座可供使用。现在组委会需要购买一批插排（插头为三头，所有插孔都为三孔），使得全部用电器都能通电。想让你帮忙算算至少需要购买多少插排？

输入格式:
输入两个整数N,K，分别表示N个用电器以及每个插排都有K个插口（1<=N<=100，2=<K<=100）

输出格式:
一个数，表示所需最少的插排数量。

输入样例:
在这里给出一组输入。例如：

10 4
输出样例:
在这里给出相应的输出。例如：

3
代码长度限制
16 KB
时间限制
500 ms
内存限制
64 MB
 */
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N=1e6+10;
//using namespace std;
//
//int nodes[111];
//int M,K;
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);cout.tie(0);
//
//    cin>>M>>K;
//    if(M == 1){
//        cout<<0;
//        return 0;
//    }
//    nodes[1]=1;
//    int f = 2;
//    while ((nodes[f]=nodes[f-1]*K) < M) ++f;
//    if(nodes[f] == M){
//        cout<<(nodes[f]-1)/(K-1);
//        return 0;
//    }
//    cout<<ceil(double(M-nodes[f-1])/(K-1))+(nodes[f-1]-1)/(K-1);
//    return 0;
//}

//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N=1e6+10;
//using namespace std;
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);cout.tie(0);
//
//    int M,K;
//    cin>>M>>K;
//    cout<<ceil(double (M-1)/(K-1));
//    return 0;
//}

/*
 * 2 办事大厅排队
分数 300
作者 吴云鹏
单位 郑州大学
在郑州大学综合办事大厅，每天陆陆续续有很多人来排队办事。现在你能否写程序帮助老师时刻了解当前办理业务的情况。

请同学们学习C++ STL中 list相关内容后，编程实践。

输入格式:
第一行一个数字N，表示排队信息或者查询信息条目的数量。

以下N行，每行的内容有以下3种情况

(1) in name 表示名字为name的人员新来到办事大厅，排在队伍的最后。（in和name间存在一个空格，name是名字对应字符串，长度不超过10）。

(2) out 表示当前排在最前面的人已经办理完业务，离开了。

(3) q 表示一次查询，请输出当前正在办理业务的人，也就是队伍的第1个人。如果当前无人办理业务，则输出“NULL”，不包括引号。

输出格式:
请根据以上信息，每次遇到查询时，对应一行输出。如果这时队伍有人，则输出第一个人的姓名，否则输出NULL。

输入样例:
5
in A
out
q
in B
q
输出样例:
在这里给出相应的输出。例如：

NULL
B
代码长度限制
16 KB
时间限制
1000 ms
内存限制
64 MB
 */
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N=1e6+10;
//using namespace std;
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);cout.tie(0);
//
//    list<string> que;
//    string str;
//    int n;
//    cin>>n;
//    rep(i,1,n){
//        cin>>str;
//        if(str == "in"){
//            cin>>str;
//            que.push_back(str);
//        }
//        else if(str == "out"){
//            que.pop_front();
//        }
//        else{
//            if(que.empty()){
//                cout<<"NULL";
//            }
//            else{
//                cout<<que.front();
//            }
//            if(i!=n)
//                cout<<endl;
//        }
//    }
//
//    return 0;
//}
/*
 * 3 字符串的全排列
分数 300
作者 吴云鹏
单位 郑州大学
给定一个全由小写字母构成的字符串，求它的全排列，按照字典序从小到大输出。

输入格式:
一行，一个字符串，长度不大于8。

输出格式:
输出所有全排列，每行一种排列形式，字典序从小到大。

输入样例:
在这里给出一组输入。例如：

abc
输出样例:
在这里给出相应的输出。例如：

abc
acb
bac
bca
cab
cba
代码长度限制
16 KB
时间限制
1000 ms
内存限制
64 MB
 */
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N=1e6+10;
//using namespace std;
//
//char alp[11];
//char show[11];
//bool visited[11];
//int n;
//int total=1;
//void showme(int step)
//{
//    if(step>n){
//        rep(i,1,n) cout<<show[i];
//        --total;
//        if(total)
//            cout<<endl;
//        return;
//    }
//    rep(i,1,n){
//        if(!visited[i]){
//            visited[i] = true; show[step] = alp[i];
//            showme(step+1);
//            visited[i] = false; show[step] = '\0';
//        }
//    }
//}
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);cout.tie(0);
//
//    cin>>(alp+1);
//    n = strlen(alp+1);
//    sort(alp+1,alp+n+1);
//
//    rep(i,1,n) total *= i;
//    showme(1);
//
//    return 0;
//}


/*
 * 4 集合的“交”与“并”
分数 300
作者 吴云鹏
单位 郑州大学
给出两个由数字组成的集合，请求这两个集合的“交”和“并”。

输入格式:
给一个n，m 代表两个数列的大小 (0 <= n,m <=2e5)

如果n>0，则接下来一行， n个数空格隔开，代表第一个集合中的数。

如果m>0，则接下来一行， m个数空格隔开，代表第二个集合中的数。

-1e9<=ai,bi<=1e9

输出格式:
第一行首先输出两个数列交的集合中元素个数，如果元素个数大于0，则紧接着在这行输出“交集”的元素，按数值大小升序排列（本行输出多个数据时，用空格隔开，如果只有一个元素个数，行末无空格）

第二行首先输出两个数列并的集合中元素个数，如果元素个数大于0，则紧接着在这行输出“并集”的元素，按数值大小升序排列（本行输出多个数据时，用空格隔开，如果只有一个元素个数，行末无空格）

如果结果为空集，输出数量后，不要有多余空格

输入样例1:
1 3
1
1 3 4
输出样例1:
1 1
3 1 3 4
输入样例2:
1 3
1
2 3 4
输出样例2:
0
4 1 2 3 4
代码长度限制
16 KB
时间限制
1000 ms
内存限制
64 MB
 */
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N=2e5+10;
//using namespace std;
//
//int n,m;
//int a[N],b[N];
//
//void show_intersection(){
//    int intersec[N];
//    int i=1,j=1;
//    while(i)
//}
//void show_union(){
//
//}
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);cout.tie(0);
//
//    cin>>n>>m;
//    rep(i,1,n) cin>>a[i];
//    rep(i,1,m) cin>>b[i];
//
//    sort(a+1,a+n+1);
//    sort(b+1,b+m+1);
//
//    show_intersection();
//    show_union();
//
//    return 0;
//}
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N=2e5+10;
//using namespace std;
//
//int n,m;
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);cout.tie(0);
//
//    set<int> a,b;
//    cin>>n>>m;
//    int k;
//    rep(i,1,n){cin>>k; a.insert(k);}
//    rep(i,1,m){cin>>k; b.insert(k);}
//    vector<int> intersec, uni;
//
//    set_intersection(a.begin(), a.end(),b.begin(), b.end(),inserter(intersec,intersec.begin()));
//    set_union(a.begin(), a.end(),b.begin(), b.end(),inserter(uni,uni.begin()));
//    sort(intersec.begin(), intersec.end());
//    sort(uni.begin(), uni.end());
//
//    int n_int = intersec.size();
//    int n_uni = uni.size();
//
//    cout<<n_int;
//    rep(i,0,n_int-1) cout<<" "<<intersec[i];
//    cout<<endl<<n_uni;
//    rep(i,0,n_uni-1) cout<<" "<<uni[i];
//
//    return 0;
//}


/*
 * 5 统计英文单词个数
分数 300
作者 吴云鹏
单位 郑州大学
给出一篇英文文章，现在需要统计文章中出现英文单词的数量。

输入格式:
第一行一个T，代表数据组数

对于每组数据，第一行一个n，代表文章中单词的个数，其后n行每行一个只包含小写字母的长度为1到10的字符串

输出格式:
每组数据输出若干行，每行输出单词以及它出现的次数（中间空格隔开），不同单词按单词字典序从小到大输出

保证单词出现的总次数<=1e5

输入样例:
1
8
it
is
a
pen
it
is
a
dog
输出样例:
a 2
dog 1
is 2
it 2
pen 1
代码长度限制
16 KB
时间限制
1000 ms
内存限制
64 MB
 */
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N=1e6+10;
//using namespace std;
//
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);cout.tie(0);
//
//    map<string,int> res;
//    int times;
//    cin>>times;
//    rep(i,1,times){
//        int n;
//        cin>>n;
//        string word;
//        rep(i,1,n){
//            cin>>word;
//            res[word]++;
//        }
//        for(auto it = res.begin(); it!=res.end();){
//            cout<<it->first<<" "<<it->second;
//            if(++it != res.end())
//                cout<<endl;
//        }
//        res.clear();
//        if(i != times)
//            cout<<endl;
//    }
//    return 0;
//}


/*
 * 6 括号匹配
分数 300
作者 吴云鹏
单位 郑州大学
给定仅包含“()[]{}”六种括号的字符串，请你判断该字符串中，括号的匹配是否是合法的，也就是对应括号的数量、嵌套顺序完全正确。

输入格式:
第一行一个整数T（T<=10）

其后T行每行一个字符串只包含[{()}]六种字符（字符串长度2e5以内）

输出格式:
对于每个字符串，匹配输出Yes,否则输出No

输入样例:
2
{()[]}
([)]
输出样例:
Yes
No
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
 */
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N=1e6+10;
//using namespace std;
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);cout.tie(0);
//
//    int n;
//    cin>>n;
//    rep(i,1,n){
//        bool res = true;
//        stack<char> stack;
//        string line;
//        cin>>line;
//        for(auto it:line){
//            if(it == '(' || it == '[' || it == '{'){
//                stack.push(it);
//                continue;
//            } else if(stack.empty()){
//                res = false;
//                break;
//            } else if(it == ')'){
//                char t = stack.top();
//                if(t != '('){
//                    res = false;
//                    break;
//                }
//            } else if(it == ']'){
//                char t = stack.top();
//                if(t != '['){
//                    res = false;
//                    break;
//                }
//            } else{
//                char t = stack.top();
//                if(t != '{'){
//                    res = false;
//                    break;
//                }
//            }
//            stack.pop();
//        }
//        if(!stack.empty()){
//            res = false;
//        }
//        if(res)
//            cout<<"Yes";
//        else cout<<"No";
//        if(i != n)
//            cout<<endl;
//    }
//
//    return 0;
//}


/*
 *7 后序+中序序列构造二叉树
分数 300
作者 王东
单位 贵州师范学院
后序+中序序列构造二叉树

输入样例：
第一行输入序列长度n，第二行输入n个字符表示二叉树后序遍历的序列，第三行输入n个字符表示二叉树中序遍历的序列

9
GHDBEIFCA
GDHBAECIF
输出样例：
输出二叉树先序遍历的序列。

ABDGHCEFI
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
 */
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N=1e6+10;
//using namespace std;
//
//int n;
//char last[N];
//char mid[N];
//char first[N];
//void solve(int step, int ls, int le, int ms, int me){
//    if(step>n){
//        first[step]='\0';
//        return;
//    }
//    if(ls>le || ms>me) return;
//    int root;
//    rep(i,ms,me) if(mid[i] == last[le]) root=i-ms+1;
//    first[step] = last[le];
//    solve(step+1,ls,ls+root-2,ms,ms+root-2);
//    solve(step+root,ls+root-1,le-1,ms+root,me);
//}
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);cout.tie(0);
//
//    cin>>n;
//    cin>>(last+1)>>(mid+1);
//    solve(1,1,n,1,n);
//    cout<<(first+1);
//
//    return 0;
//}


/*
 *8 找第k小的数
分数 300
作者 陈晓梅
单位 广东外语外贸大学
设计一个平均时间为O(n)的算法，在n(1<=n<=1000)个无序的整数中找出第k小的数。

提示：函数int partition(int a[],int left,int right)的功能是根据a[left]~a[right]中的某个元素x（如a[left])对a[left]~a[right]进行划分，划分后的x所在位置的左段全小于等于x,右段全大于等于x,同时利用x所在的位置还可以计算出x是这批数据按升非降序排列的第几个数。因此可以编制int find(int a[],int left,int right,int k)函数，通过调用partition函数获得划分点，判断划分点是否第k小，若不是，递归调用find函数继续在左段或右段查找。

输入格式:
输入有两行：

第一行是n和k，0<k<=n<=10000

第二行是n个整数

输出格式:
输出第k小的数

输入样例:
在这里给出一组输入。例如：

10 4
2 8 9 0 1 3 6 7 8 2
输出样例:
在这里给出相应的输出。例如：

2
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
 */
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N=1e6+10;
//using namespace std;
//
//int n,k;
//int a[1314];
//
//int partition(int left, int right){
//    if(left == right)
//        return left;
//    int tmp = a[left];
//    while(left < right){
//        while(left<right && a[right]>tmp) --right;
//        if(left == right) return left;
//        swap(a[right],a[left]);
//        while (left<right && a[left]<=tmp) ++left;
//        if(left == right) return left;
//        swap(a[left],a[right]);
//    }
//    return left;
//}
//void find(int left, int right){
//    int site = partition(left,right);
//    if(site == k)
//        cout<<a[k];
//    else if(site > k)
//        find(left,site-1);
//    else
//        find(site+1,right);
//
//}
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);cout.tie(0);
//
//    cin>>n>>k;
//    rep(i,1,n) cin>>a[i];
//    find(1,n);
//
//    return 0;
//}


/*
 * 9 求逆序对数目
分数 300
作者 陈晓梅
单位 广东外语外贸大学
注意：本问题算法的时间复杂度要求为O(nlogn), 否则得分无效

题目来源：http://poj.org/problem?id=1804
Background
Raymond Babbitt drives his brother Charlie mad. Recently Raymond counted 246 toothpicks spilled all over the floor in an instant just by glancing at them. And he can even count Poker cards. Charlie would love to be able to do cool things like that, too. He wants to beat his brother in a similar task.

Problem
Here's what Charlie thinks of. Imagine you get a sequence of N numbers. The goal is to move the numbers around so that at the end the sequence is ordered. The only operation allowed is to swap two adjacent numbers. Let us try an example.txt:
Start with: 2 8 0 3
swap (2 8) 8 2 0 3
swap (2 0) 8 0 2 3
swap (2 3) 8 0 3 2
swap (8 0) 0 8 3 2
swap (8 3) 0 3 8 2
swap (8 2) 0 3 2 8
swap (3 2) 0 2 3 8
swap (3 8) 0 2 8 3
swap (8 3) 0 2 3 8

So the sequence (2 8 0 3) can be sorted with nine swaps of adjacent numbers. However, it is even possible to sort it with three such swaps:
Start with: 2 8 0 3
swap (8 0) 2 0 8 3
swap (2 0) 0 2 8 3
swap (8 3) 0 2 3 8

The question is: What is the minimum number of swaps of adjacent numbers to sort a given sequence?Since Charlie does not have Raymond's mental capabilities, he decides to cheat. Here is where you come into play. He asks you to write a computer program for him that answers the question in O(nlogn). Rest assured he will pay a very good prize for it.

输入格式:
The first line contains the length N (1 <= N <= 1000) of the sequence；
The second line contains the N elements of the sequence (each element is an integer in [-1000000, 1000000]). All numbers in this line are separated by single blanks.

输出格式:
Print a single line containing the minimal number of swaps of adjacent numbers that are necessary to sort the given sequence.

输入样例:
在这里给出一组输入。例如：

6
-42 23 6 28 -100 65537
输出样例:
在这里给出相应的输出。例如：

5
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
 */
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y; x<=z; ++x)
const int N=1e6+10;
using namespace std;

int n;
int a[N];
int res;

void merge(int left, int mid, int right){
    int b[right-left+2];
    int i=left,j=mid+1,k=1;
    while(i<=mid && j<=right){
        if(a[i]<=a[j]){
            b[k++]=a[i++];
        } else{
            b[k++]=a[j++];
            res += mid+1-i;
        }
    }
    while (i<=mid) b[k++]=a[i++];
    while (j<=right) b[k++]=a[j++];
    memcpy(a+left, b+1, --k*sizeof (int));
}

void mergesort(int left, int right){
    if(left == right) return;
    if(left == right-1 && a[left]>a[right]) {
        swap(a[left],a[right]);
        ++res;
        return;
    }
    int mid = (left+right)>>1;
    mergesort(left,mid);
    mergesort(mid+1,right);
    merge(left,mid,right);
}
#define epsilon "ε"
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

//    cin>>n;
//    rep(i,1,n) cin>>a[i];
//    mergesort(1,n);
//    cout<<res;


//    cout<<epsilon;

//    vector<string> t={epsilon};
//    if(t.empty() && t.size()==0)
//        cout<<"ok";

//    unordered_map<int,string> t;
//    if(t[0].empty()) cout<<"ok";
//
//    std::string str = "This is a test string.";
//
//    // 使用 std::remove_if 和 lambda 表达式删除空格
//    str.erase(std::remove_if(str.begin(), str.end(), [](char c){ return std::isspace(c); }), str.end());
//
//    std::cout << str << std::endl;

//    int k;
//    cin>>k;
//    char a;
//    rep(i,1,k){
//        cin>>a;
//        cout<<a<<endl;
//    }

//    vector<int> a = {1,2,3,4};
//    vector<int> b(a.begin(), a.end());
//    b.push_back(5);
//    cout<<a.size();
//    cout<<endl<<b.size();

    int a = 5;
    vector<int> b;
    b.push_back(a);
    b[0] *= 2;
    cout<<b[0]<<endl<<a;
    return 0;
}



















