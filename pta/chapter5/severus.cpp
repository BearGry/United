//
// Created by xiaodian& on 2023/12/25.
//
/*
 * 1 拦截导弹
分数 300
作者 吴云鹏
单位 郑州大学
某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。

输入导弹依次飞来的高度（雷达给出的高度数据是不大于30000的正整数，导弹数不超过1000），计算这套系统最多能拦截多少导弹？

扩展思考：如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。

输入格式:
输入只有一行，为若干个正整数（用空格隔开），依次为导弹的高度。

输出格式:
一行，为最多能拦截的导弹数。

输入样例:
389 207 155 300 299 170 158 65
输出样例:
6
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
//int a[1010],b[1010];
//int res = 1;
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    string line;
//    getline(cin,line);
//    stringstream ss(line);
//    int k=1;
//    while (ss>>a[k]) ++k;
//    k--;
////    ATTENTION b[1] = 1;
//    rep(i,1,k) b[i] = 1;
//    rep(i,2,k){
//        rep(j,1,i-1)
//            if(a[j]>=a[i])
//                b[i] = max(b[i],b[j]+1);
//        res = max(res,b[i]);
//    }
//    // SECOND
////    rep(i,1,k){
////        if(b[i]>res) res = b[i];
////        rep(j,i+1,k)
////            if(a[j]<=a[i]) b[j] = max(b[j],b[i]+1);
////    }
//    cout<<res;
//
//    return 0;
//}

/*
 * 2 分弹珠
分数 300
作者 吴云鹏
单位 郑州大学
把M个弹珠放到N个盘子里面（我们允许有的盘子为空），你能求出有多少种分法吗？（请注意，例如有三个盘子，我们将5,1,1和1,1,5，视为同一种分法）

输入格式:
输入包含多组测试样例。每组输入的第一行是一个整数t。
接下来t行，每行输入两个整数M和N，代表有M个弹珠和N个盘子。（0=<M<=20; 0<N<=20）

输出格式:
对于每对输入的M和N，输出有多少种方法。

输入样例:
在这里给出一组输入。例如：

1
7 3
输出样例:
在这里给出相应的输出。例如：

8
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
//int dp[21][21];
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    rep(i,0,20) dp[i][1] = 1;
//    rep(i,1,20) dp[0][i] = dp[1][i] = 1;
//    rep(i,2,20){
//        rep(j,2,20){
//            dp[i][j] = i<j? dp[i][i]: dp[i-j][j]+dp[i][j-1];
//        }
//    }
//
//    int k; cin>>k;
//    int m,n;
//    rep(i,1,k){
//        cin>>m>>n;
//        cout<<dp[m][n];
//        if(i != k) cout<<endl;
//    }
//
//    return 0;
//}

/*
 * 3 让人头疼的“双十一”
分数 300
作者 吴云鹏
单位 郑州大学
双十一就这样轰轰烈烈的来了，网购宅男小明磨拳霍霍！理想是丰满的，现实是骨感的。小明虽然在购物车添加了不少物品，但是他低头看了下口袋却是叹声连连。小明想要购买的商品中，每件商品都有其价格和期待值，小明只能利用有限的资金，购买能让自己期待值总和达到最大的一系列物品了。

输入格式:
第一行一个整数T表示有T组测试数据（T<=50）。

接下来的T组测试数据：

第一行包含两个整数N和M，N表示小明有多少钱，M表示有多少件物品（1<=M<=100）。

再二行包含M个整数，表示对应每个物品的价格。

第三行包含M个整数，表示小明对每个物品的期待值。

其中，小明兜里的钱N、每个物品的价格、每个物品的期待值的值域均为(0, 3000)。

输出格式:
每组样例一行，输出最大期待值的总和。假设第i组样例最大期待值为e，则输出格式为“Case #i: e”

输入样例:
4
10 5
2 3 7 7 3
4 3 5 6 4
10 8
5 6 4 2 3 7 1 8
5 3 5 3 5 7 5 7
20 7
10 15 4 5 6 8 5
15 14 9 2 2 6 7
10 3
7 4 5
16 7 10
输出样例:
Case #1: 11
Case #2: 18
Case #3: 31
Case #4: 17
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
//int dp[3010];
//int p[110];
//int w[110];
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    int k; cin>>k;
//    rep(q,1,k){
//        int m,t; cin>>m>>t;
//        rep(i,1,t) cin>>w[i];
//        rep(i,1,t) cin>>p[i];
//        memset(dp,0,sizeof dp);
////        rep(i,w[1],m) dp[i] = p[1];
////        rep(i,2,t){
////      TODO  上面个两行代码修改为下面这行，不知道为什么这个初始化会让代码产生错误
//        rep(i,1,t){
//            for(int j=m; j>=w[i]; --j)
//                dp[j] = max(dp[j],dp[j-w[i]]+p[i]);
//        }
//        cout<<"Case #"<<q<<": "<<dp[m];
//        if(q!=k) cout<<endl;
//    }
//
//    return 0;
//}

/*
 * 4 石子合并
分数 300
作者 吴云鹏
单位 郑州大学
有N堆石子排成一排(n<=100),现要将石子有次序地合并成一堆，规定每次只能选相邻的两堆合并成一堆，并将新的一堆的石子数，记为该次合并的得分，编一程序，给出堆数n及每堆石子数(<=200)；

（1）选择一种合并石子的方案，使得做n-1次合并，得分的总和最少

（2）选择一种合并石子的方案，使得做n-1次合并，得分的总和最多

输入格式:
第一行为石子堆数n

第二行为每堆石子数，每两个数之间用一空格分隔。

输出格式:
第一行为最小合并得分，第二行是最大的合并得分。

输入样例:
在这里给出一组输入。例如：

4
4 5 9 4
输出样例:
在这里给出相应的输出。例如：

44
54
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
 */
//！暴力求解过不了
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N = 1e6+10;
//using namespace std;
//int a[110];
//int b[110];
//int c[110];
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    int k; cin>>k;
//    rep(i,1,k) cin>>a[i];
//    memcpy(b,a, sizeof(int)*(k+4));
//
//    int sum = 0;
//    rep(i,1,k-1){
//        int min = INT_MAX;
//        int index;
//        memset(c,0, sizeof c);
//        rep(j,1,k-i){
//            c[j] = a[j]+a[j+1];
//            if(c[j]<min){
//                min = c[j];
//                index = j;
//            }
//        }
//        sum += min; a[index] = min;
////        cout<<min<<"-"<<sum<<"-"<<index<<endl;
//        rep(j,index+1,k-i+1) a[j] = a[j+1];
//    }
//    cout<<sum<<endl;
//
//    sum = 0;
//    rep(i,1,k-1){
//        int max = INT_MIN;
//        int index;
//        memset(c,0, sizeof c);
//        rep(j,1,k-i){
//            c[j] = b[j]+b[j+1];
//            if(c[j]>max){
//                max = c[j];
//                index = j;
//            }
//        }
//        sum += max; b[index] = max;
////        cout<<min<<"-"<<sum<<"-"<<index<<endl;
//        rep(j,index+1,k-i+1) b[j] = b[j+1];
//    }
//    cout<<sum;
//
//    return 0;
//}

//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N = 1e6+10;
//using namespace std;
//int a[110][110],b[110][110];
//int s[110],c[110];
//
//int smin(int l,int j){
//    if(a[l][j] != -1) return a[l][j];
//    if(l == j) return a[l][l] = 0;
//    int res = INT_MAX;
//    rep(k,l,j-1){
//        res = min(res, smin(l,k)+ smin(k+1,j));
//    }
//    return a[l][j] = res+c[j]-c[l-1];
//}
//int smax(int l,int j){
//    if(b[l][j] != -1) return b[l][j];
//    if(l == j) return b[l][l] = 0;
//    int res = INT_MIN;
//    rep(k,l,j-1){
//        res = max(res, smax(l,k)+ smax(k+1,j));
//    }
//    return b[l][j] = res+c[j]-c[l-1];
//}
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    memset(a,0xff,sizeof a);
//    memset(b,0xff,sizeof b);
//    int k; cin>>k;
//    rep(i,1,k){
//        cin>>s[i];
//        c[i] = c[i-1]+s[i];
//    }
//    cout<<smin(1,k)<<endl;
//    cout<<smax(1,k);
//
//    return 0;
//}

/*
 * 5 矩阵取数游戏
分数 300
作者 吴云鹏
单位 郑州大学
小明经常玩一个矩阵取数游戏：对于一个给定的n x n的矩阵，矩阵中的每个元素aij表示该格子的价值，均为非负整数。游戏规则如下：

小明从左上角走到右下角，只能向下向右走，经过某个格子，就能获得格子相应价值的奖励，

请你帮忙写一个程序，对于任意矩阵，可以求出取数后的最大奖励值。

输入格式:
输入包括n+1行：

第1行为一个整数n。(2 <= n <= 500)

第2~n+1行为nxn矩阵，其中每行有n个用单个空格隔开的非负整数。（0 <= aij <= 10000)

输出格式:
仅包含1行，为一个整数，即输入矩阵取数后的最大得分

输入样例:
在这里给出一组输入。例如：

3
1 3 3
2 1 3
2 2 1
输出样例:
在这里给出相应的输出。例如：

11
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
 */
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y; x<=z; ++x)
const int N = 1e6+10;
using namespace std;
int a[510][510];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k; cin>>k;
    rep(i,1,k)
        rep(j,1,k) cin>>a[i][j];
    for(int i=k-1; i>=1; --i){
        a[k][i] += a[k][i+1];
        a[i][k] += a[i+1][k];
    }
    for(int i=k-1; i>=1; --i){
        for(int j=k-1; j>=1; --j)
            a[i][j] += max(a[i+1][j],a[i][j+1]);
    }
    cout<<a[1][1];

    return 0;
}


















