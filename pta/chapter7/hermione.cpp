//
// Created by xiaodian& on 2023/12/27.
//

/*
 * 0 n个数的全排列
 */
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N = 1e6+10;
//using namespace std;
//int n=4;
//int a[N];
//// 从第几个数开始参与全排列
//// 我觉得这种写法并不应该归为搜索，而应该是递归
//// 这种应该属于搜索--n个格子填数，利用不相等性剪枝，不过还是底下的更优，没有剪枝判等的时间浪费（剪枝太多）
//void ouou(int k){
//    if(k == n){
//        rep(i,1,n) cout<<a[i]<<" ";
//        cout<<endl;
//        return;
//    }
//    rep(i,k,n){
//        swap(a[k],a[i]);
//        ouou(k+1);
//        swap(a[k],a[i]);
//    }
//}
//void ouou2(int k){
//    if(k == 1){
//        rep(i,1,n) cout<<a[i]<<" ";
//        cout<<endl;
//        return;
//    }
//
//    for(int i=k; i>=1; --i){
//        swap(a[k],a[i]);
//        ouou2(k-1);
//        swap(a[k],a[i]);
//    }
//}
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    rep(i,1,n) a[i]=i;
//    ouou(1);
//    cout<<"-------------------"<<endl;
//    ouou2(4);
//
//    return 0;
//}


/*
 * 1 自然数拆分问题
分数 300
作者 吴云鹏
单位 郑州大学
一个整数N(N > 1)可以拆分成若干个大于等于1的自然数之和，请你输出所有不重复的拆分方式。

所谓拆分方式的重复性判定如下：给定N=a
1
​
 +a
2
​
 +...a
m1
​
  和 N=b
1
​
 +b
2
​
 +...b
m2
​
  表示整数N的两种拆分方式。对于∀a
i
​
 ,b
j
​
 ≥1，令集合A={a
i
​
 ∣1≤i≤m
1
​
 },B={b
j
​
 ∣1≤j≤m
2
​
 }。若满足集合A=B，则称这两种拆分方式是重复的。

例如 6 = 3 + 2 和 6 = 2 + 3, 就是重复的拆分方式。

输入格式:
一个正整数N（1≤N≤52）。

注意：本题N的上限52，是经过PTA平台服务器测试后得到的上限，能够保证较好的搜索策略在PTA提交，在1s内求解。本地PC机上，即使较好方法运行时间也可能大于1s，如果觉得方法没问题，可以先提交试试。

输出格式:
按照拆分方案的字典序由小大到大，输出所有方案，请参考输出样例

输入样例:
在这里给出一组输入。例如：

6
输出样例:
在这里给出相应的输出。例如：

6=1+1+1+1+1+1
6=1+1+1+1+2
6=1+1+1+3
6=1+1+2+2
6=1+1+4
6=1+2+3
6=1+5
6=2+2+2
6=2+4
6=3+3
6=6
代码长度限制
16 KB
时间限制
1000 ms
内存限制
64 MB
 */
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N = 1e6+10;
//using namespace std;
//int n;
//int a[60];
//void fb(int k, int r){
//    if(r == 0){
//        cout<<n<<"=";
//        rep(i,1,k-2) cout<<a[i]<<"+";
//        cout<<a[k-1];
//        if(k!=2) cout<<endl;
//        return;
//    }
//    rep(i,a[k-1],r){
//        a[k] = i; r -= i;
//        fb(k+1,r);
//        a[k] = 0; r += i;
//    }
//}
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    cin>>n;
//    a[0] = 1;
//    fb(1,n);
//
//    return 0;
//}

/*
 * 2 自然数拆分的方案数
分数 300
作者 吴云鹏
单位 郑州大学
给定一个自然数N，要求把N拆分成若干个正整数相加的形式，参与加法运算的数可以重复。与“自然数拆分问题”类似，同样需要满足方案的不重复。

所谓拆分方式的重复性判定如下：给定N=a
1
​
 +a
2
​
 +...a
m1
​
  和 N=b
1
​
 +b
2
​
 +...b
m2
​
  表示整数N的两种拆分方式。对于∀a
i
​
 ,b
j
​
 ≥1，令集合A={a
i
​
 ∣1≤i≤m
1
​
 },B={b
j
​
 ∣1≤j≤m
2
​
 }。若满足集合A=B，则称这两种拆分方式是重复的。

例如 6 = 3 + 2 和 6 = 2 + 3, 就是重复的拆分方式。

现在需要你求满足条件的拆分有多少种？

输入格式:
第一行自然整数T，表示之后测试数据组数，
以后T行，每行一个自然数N，（1<N<=4000）

注意：本题规模为4000，回溯法还合适吗？仔细思考应该如何设计算法

建议自行学习完全背包相关知识

输出格式:
T行，每行输出一个整数，表示拆分的方案数，结果对2147483648取模。

输入样例:
在这里给出一组输入。例如：

2
6
7
输出样例:
在这里给出相应的输出。例如：

11
15
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
 */
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N = 1e6+10;
//using namespace std;
//unsigned int a[4040];
//int b[N];
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    int k; cin>>k;
//    int mmax = INT_MIN;
//    rep(i,1,k) {
//        cin >> b[i];
////        mmax = max(mmax,b[i]);
//    }
//    rep(i,0,4000) a[i] = 1;
//    rep(i,2,4000){
//        rep(j,i,4000) a[j] = (a[j]+a[j-i])%2147483648;
//    }
//    rep(i,1,k-1) cout<<a[b[i]]<<endl;
//    cout<<a[b[k]];
//
//    return 0;
//
////    rep(i,0,4000) a[1][i] = 1;
////    rep(i,2,4000){
////        rep(j,0,i-1) a[i][j] = a[i-1][j];
////        rep(j,i,4000) a[i][j] = (a[i-1][j] + a[i][j-i])%2147483648;
////    }
////    int n; cin>>n;
////    rep(i,1,n){
////        int k; cin>>k;
////        cout<<a[k][k];
////        if(i!=n) cout<<endl;
////    }
////
////    return 0;
//}

/*
 * 3 子集和问题
分数 300
作者 陈晓梅
单位 广东外语外贸大学
设集合S={x1,x2,…,xn}是一个正整数集合，c是一个正整数，子集和问题判定是否存在S的一个子集S1，使S1中的元素之和为c。试设计一个解子集和问题的回溯法，并输出利用回溯法在搜索树（按输入顺序建立）中找到的第一个解。

输入格式:
输入数据第1行有2个正整数n和c，n表示S的大小，c是子集和的目标值。接下来的1行中，有n个正整数，表示集合S中的元素。
是子集和的目标值。接下来的1 行中，有n个正整数，表示集合S中的元素。

输出格式:
输出利用回溯法找到的第一个解，以空格分隔，最后一个输出的后面有空格。当问题无解时，输出“No Solution!”。

输入样例:
在这里给出一组输入。例如：

5 10
2 2 6 5 4
输出样例:
在这里给出相应的输出。例如：

2 2 6
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
 */
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N = 1e6+10;
//using namespace std;
//int a[N];
//bool b[N];
//int n,tar,r;
//bool df(int k, int c){
//    if(c == tar){
//        rep(i,1,k-1) if(b[i]) cout<<a[i]<<" ";
//        return true;
//    }
//    if(k == n+1) return false;
//
//    r -= a[k];
//    b[k] = true;
//    if(c+a[k]<=tar){
//        if(df(k+1,c+a[k])) return true;
//    }
//    b[k] = false;
//    if(c+r>=tar){
//        if(df(k+1,c)) return true;
//    }
//    r += a[k];
//    return false;
//}
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    cin>>n>>tar;
//    rep(i,1,n) {
//        cin>>a[i]; r += a[i];
//    }
//    if(!df(1,0)) cout<<"No Solution!";
//
//    return 0;
//}

/*
 * 4 数独游戏
分数 300
作者 吴云鹏
单位 郑州大学
微信截图_20200510171112.png

输入格式:
The input test file will contain multiple cases. Each test case consists of a single line containing 81 characters, which represent the 81 squares of the Sudoku grid, given one row at a time. Each character is either a digit (from 1 to 9) or a period (used to indicate an unfilled square). You may assume that each puzzle in the input will have exactly one solution. The end-of-file is denoted by a single line containing the word “end”.

注意： 本题输入数据量较大，cin, getline可能会超时，建议使用scanf。

输出格式:
For each test case, print a line representing the completed Sudoku puzzle.

输入样例:
在这里给出一组输入。例如：

.2738..1..1...6735.......293.5692.8...........6.1745.364.......9518...7..8..6534.
......52..8.4......3...9...5.1...6..2..7........3.....6...1..........7.4.......3.
end
输出样例:
在这里给出相应的输出。例如：

527389416819426735436751829375692184194538267268174593643217958951843672782965341
416837529982465371735129468571298643293746185864351297647913852359682714128574936
代码长度限制
16 KB
时间限制
1000 ms
内存限制
64 MB
 */
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N = 1e6+10;
//using namespace std;
//
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//
//}

/*
 * 8 幸福小镇的故事！（简单）
分数 300
作者 章立晨
单位 浙大城市学院
在一个很远很远的地方，有一个幸福小镇！

幸福小镇的治安很不好，所以生活在镇上很不幸福！

新来的保安队队长小Z决心改变这一切，第一步要解决的是任何两个小镇之间的距离问题！

我们需要解决这个问题的简化版本：

幸福小镇可以划分为N个小小镇，从1到N编号！这些小小镇由N-1条道路连通，我们把每条道路的长度简化为1！只要在每个小小镇增派人手，就可以让小镇的治安情况变得越来越好！（题目保证两个小镇之间的道路只有一条！）

每次小Z会询问你两个小小镇的编号，请你计算出这两个小镇之间的最短路径长度！

输入格式:
第一行包含一个正整数（N<=1000），表示小小镇的个数！

接下来N-1行，每行包含两个1到N之间的整数，表示这两个编号的小小镇之间有一条路！

接下来一行包含一个整数q（q<=100)，表示询问数！

接下来q行，每行包含两个小小镇的编号，请在一行中输出这两个小小镇的最短路径长度！

输出格式:
输出答案即可！

输入样例:
在这里给出一组输入。例如：

10
1 2
2 3
1 4
4 5
4 6
3 7
3 8
1 9
9 10
5
3 8
9 3
1 1
1 7
1 9
输出样例:
在这里给出相应的输出。例如：

1
3
0
3
1
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
 */
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N = 1e6+10;
//using namespace std;
//bool a[1010][1010];
//int k;
//
//int bfs(int l, int j){
//    if(l == j) return 0;
//    queue<int> q; q.push(l);
//    set<int> s;
//    rep(i,1,1010){
//        queue<int> pq;
//        while (!q.empty()){
//            int e = q.front();
//            rep(p,1,k){
//                if(a[e][p]){
//                    if(p == j) return i;
//                    if(s.count(p) == 0) pq.push(p);
//                }
//            }
//            q.pop(); s.insert(e);
//        }
//        q = pq;
//    }
//}
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    cin>>k;
//    int e,f;
//    rep(i,1,k-1){
//        cin>>e>>f;
//        a[e][f] = a[f][e] = true;
//    }
//    int n; cin>>n;
//    rep(i,1,n){
//        cin>>e>>f;
//        cout<<bfs(e,f);
//        if(i!=n)
//            cout<<endl;
//    }
//
//    return 0;
//}

/*
 * 6 最短路径
分数 300
作者 DS课程组
单位 临沂大学
给定一个有N个顶点和E条边的无向图，顶点从0到N−1编号。请判断给定的两个顶点之间是否有路径存在。如果存在，给出最短路径长度。
这里定义顶点到自身的最短路径长度为0。
进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。

输入格式:
输入第1行给出2个整数N(0<N≤10)和E，分别是图的顶点数和边数。
随后E行，每行给出一条边的两个顶点。每行中的数字之间用1空格分隔。
最后一行给出两个顶点编号i，j（0≤i,j<N）,i和j之间用空格分隔。

输出格式:
如果i和j之间存在路径，则输出"The length of the shortest path between i and j is X."，X为最短路径长度，
否则输出"There is no path between i and j."。

输入样例1:
7 6
0 1
2 3
1 4
0 2
1 3
5 6
0 3
输出样例1:
The length of the shortest path between 0 and 3 is 2.
输入样例2:
7 6
0 1
2 3
1 4
0 2
1 3
5 6
0 6
输出样例2:
There is no path between 0 and 6.
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
 */
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N = 1e6+10;
//using namespace std;
//bool a[14][14];
//bool v[14];
//int n;
//int p,q;
//int res = INT_MAX;
//void dfs(int k,int c){
//    if(c == q){
//        res = min(res,k);
//        return;
//    }
//    v[c] = true;
//    rep(i,0,n-1){
//        if(!v[i] && a[c][i])
//            dfs(k+1,i);
//    }
//    v[c] = false;
//}
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    int e; cin>>n>>e;
//    rep(i,1,e){
//        cin>>p>>q; a[p][q] = a[q][p] = true;
//    }
//    cin>>p>>q;
//    dfs(0,p);
//    if(res == INT_MAX) cout<<"There is no path between "<<p<<" and "<<q<<".";
//    else cout<<"The length of the shortest path between "<<p<<" and "<<q<<" is "<<res<<".";
//
//    return 0;
//}


/*
 * 9 BFS
分数 300
作者 李曲
单位 浙江工业大学
Vjekoslav狼正在逃离一群嗜血的猎人。猎人们很聪明，躲在树后。维耶科斯拉夫知道这一点，但不知道是哪棵树。他想跑到他舒适、文明的小屋（而不是猎人们相当不文明的巢穴，是的，我在这里支持狼）尽可能远离任何树木。

森林可以用N乘M的网格表示。让我们用“.”标记空旷的草地，中间有一棵树，中间有“+”，维吉科斯拉夫的当前位置是“V”，他的小屋的位置是“J”。Vjekoslav可以从当前的补丁运行到任何其他补丁北部，东部，南部或西部从他，即使它包含一棵树。

如果Vjekoslav站在网格的第R行和第C列，并且在第a行和第B列中有一棵树，那么Vjekoslav和该树之间的距离为：

∣R−A∣+∣C−B∣

帮助Vjekoslav找到通往他的小屋的最佳路线。最佳路线是在任何给定时刻使Vjekoslav和所有树之间的最小距离最大化的任何路线。

请注意，Vjekoslav的小屋并不占据整个地块，因此该地块也必须包含在路线中。

输入格式:
第一行输入包含整数N和M（1≤N、M≤500），表示网格尺寸。

接下来的N行包含M个字符：'.', '+', 'V', 'J'

输入将只包含一个字符“V”和“J”，以及至少一个字符“+”。

输出格式:
输出一个整数，即在最佳路径中与树的最小距离

输入样例1:
4 4
+...
....
....
V..J
输出样例1:
3
输入样例2:
4 5
.....
.+++.
.+.+.
V+.J+
输出样例2:
0
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
 */

//即便是改进了cost的计算，bfs还是很高，因为会有后效性的原因
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
////const int N = 1e6+10;
//using namespace std;
//struct point{
//    int x,y;
//}mo[4] = {{0,-1},{0,1},{-1,0},{1,0}};
//struct abc{
//    int x,y,c;
//};
//char ma[510][510];
//int N,M;
//int res = INT_MIN;
//int vi,vj,ji,jj;
//int cost[510][510];
//bool pd(int x, int y) {
//    return (x > 0) && (x <= N) && (y > 0) && (y <= M);
//}
//queue<point> qt;
//void ds(){
////    cost[i][j] = 0;
////    set<int> s; s.insert(i*1000+j);
////    queue<point> q({{i,j}});
////    point p;
////    while(!q.empty()){
////        p = q.front(); q.pop();
////        cost[p.x][p.y] = min(cost[p.x][p.y],abs(p.x-i)+abs(p.y-j));
////        rep(i,0,3){
////            if(p.x+mo[i].x>=1 && p.x+mo[i].x<=N && p.y+mo[i].y>=1 && p.y+mo[i].y<=M){
////                if(s.count((p.x+mo[i].x)*1000+p.y+mo[i].y) == 0) {
////                    q.push({p.x+mo[i].x,p.y+mo[i].y});
////                    s.insert((p.x+mo[i].x)*1000+p.y+mo[i].y);
////                }
////            }
////        }
////    }
//
//    while (!qt.empty()) {
//        point k = qt.front();
//        qt.pop();
//        rep(i,0,3){
//            int x1 = k.x + mo[i].x;
//            int y1 = k.y + mo[i].y;
//            if (!pd(x1, y1)) continue;
//            if (cost[x1][y1] != -1) continue;
//            cost[x1][y1] = cost[k.x][k.y] + 1;
//            point zr;
//            zr.x = x1;
//            zr.y = y1;
//            qt.push(zr);
//        }
//    }
//}
//void bfs(){
//    map<int,int> s; s[vi*1000+vj] = cost[vi][vj];
//    queue<abc> q({{vi,vj,cost[vi][vj]}});
//    abc p; int pi,pj;
//    while(!q.empty()){
//        p = q.front(); q.pop();
//        if(p.x == ji && p.y == jj){
//            res = max(p.c,res);
//            continue;
//        }
//        rep(i,0,3){
//            pi = p.x+mo[i].x; pj = p.y+mo[i].y;
//            if(pi>=1 && pi<=N && pj>=1 && pj<=M){
//                int ct = min(p.c,cost[pi][pj]);
//                if(ct<res) {
//                    s[pi*1000+pj] = ct;
//                    continue;
//                }
//                if(s.count((pi)*1000+pj) == 0){
//                    q.push({pi,pj,ct});
//                }
//                else if(s[pi*1000+pj] < ct){
//                    s.erase(pi*1000+pj);
//                    q.push({pi,pj,min(p.c,cost[pi][pj])});
//                }
//                s[pi*1000+pj] = ct;
//            }
//        }
//    }
//}
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    memset(cost,0xff,sizeof cost);
//    cin>>N>>M;
//    rep(i,1,N)
//        rep(j,1,M) cin>>ma[i][j];
//    rep(i,1,N)
//        rep(j,1,M){
//        if(ma[i][j] == '+'){
//            qt.push({i,j});
//            cost[i][j] = 0;
//        }
//        else if(ma[i][j] == 'V'){
//            vi = i; vj = j;
//        }
//        else if(ma[i][j] == 'J'){
//            ji = i; jj = j;
//        }
//    }
//    ds();
////    rep(i,1,N){
////        rep(j,1,M){
////            cout<<cost[i][j]<<" ";
////        }
////        cout<<endl;
////    }
//    bfs();
//    cout<<res;
//
//    return 0;
//}

#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

struct node {
    int x, y;
};

int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, 1, 0, -1, 0};
int st_x, st_y, ed_x, ed_y;
int n, m, l = 0, r = 0;
int e_map[600][600], vis[600][600];
char s[600];

int min1(int p, int q) { return p < q ? p : q; }
int max1(int p, int q) { return p > q ? p : q; }
int abs1(int p) { return p > 0 ? p : -p; }

queue<node> q;

bool pd(int x, int y) {
    return (x > 0) && (x <= n) && (y > 0) && (y <= m);
}

bool check(int mid) {
    memset(vis, false, sizeof(vis));
    node ht;
    ht.x = st_x;
    ht.y = st_y;
    q.push(ht);

    if (e_map[st_x][st_y] < mid) return false;

    vis[st_x][st_y] = true;
    while (!q.empty()) {
        node k = q.front();
        q.pop();
        for (int i = 1; i <= 4; i++) {
            int x1 = k.x + dx[i];
            int y1 = k.y + dy[i];
            if (!pd(x1, y1)) continue;
            if (vis[x1][y1] == true) continue;
            if (e_map[x1][y1] >= mid) {
                vis[x1][y1] = true;
                node zk;
                zk.x = x1;
                zk.y = y1;
                q.push(zk);
            }
        }
    }
    return vis[ed_x][ed_y];
}

void init() {
    while (!q.empty()) {
        node k = q.front();
        q.pop();
        for (int i = 1; i <= 4; i++) {
            int x1 = k.x + dx[i];
            int y1 = k.y + dy[i];
            if (!pd(x1, y1)) continue;
            if (e_map[x1][y1] != -1) continue;
            e_map[x1][y1] = e_map[k.x][k.y] + 1;
            r = max1(r, e_map[x1][y1]);
            node zr;
            zr.x = x1;
            zr.y = y1;
            q.push(zr);
        }
    }
}

int main() {
    memset(e_map, -1, sizeof(e_map));
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        for (int j = 1; j <= m; j++) {
            if (s[j - 1] == 'V') {
                st_x = i;
                st_y = j;
            }
            if (s[j - 1] == 'J') {
                ed_x = i;
                ed_y = j;
            }
            if (s[j - 1] == '+') {
                e_map[i][j] = 0;
                node rs;
                rs.x = i;
                rs.y = j;
                q.push(rs);
            }
        }
    }

    init();

    // 二分查找
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }

    printf("%d", l);
    return 0;
}












