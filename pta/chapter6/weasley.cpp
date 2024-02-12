//
// Created by xiaodian& on 2023/12/26.
//
/*
 * 1 月饼
分数 300
作者 陈越
单位 浙江大学
月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。

注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有 3 种月饼，其库存量分别为 18、15、10 万吨，总售价分别为 75、72、45 亿元。如果市场的最大需求量只有 20 万吨，那么我们最大收益策略应该是卖出全部 15 万吨第 2 种月饼、以及 5 万吨第 3 种月饼，获得 72 + 45/2 = 94.5（亿元）。

输入格式：
每个输入包含一个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N 表示月饼的种类数、以及不超过 500（以万吨为单位）的正整数 D 表示市场最大需求量。随后一行给出 N 个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出 N 个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。

输出格式：
对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后 2 位。

输入样例：
3 20
18 15 10
75 72 45
输出样例：
94.50
代码长度限制
16 KB
时间限制
150 ms
内存限制
64 MB
 */
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N = 1e6+10;
//using namespace std;
//struct yb{
//    double w,p;
//    double e;
//}a[1010];
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    int k,s; cin>>k>>s;
//    rep(i,1,k) cin>>a[i].w;
//    rep(i,1,k) cin>>a[i].p;
//    rep(i,1,k) a[i].e = double (a[i].p)/a[i].w;
//    sort(a+1, a+k+1,[](yb a,yb b){return a.e>b.e;});
//
////    double res = 0;
////    while (s>0 && k>0){
////        int t = min(s,a[k].w);
////        res += t*a[k].e;
////        s -= t; --k;
////    }
//    double res = 0;
//    rep(i,1,k){
//        if(a[i].w<s){
//            res += a[i].p;
//            s -= a[i].w;
//        }
//        else{
//            res += double (s)*a[i].p/a[i].w;
//            break;
//        }
//    }
//    cout<<setprecision(2)<<fixed<<res;
//
//    return 0;
//}

/*
 * 2 汽车加油问题
分数 300
作者 陈晓梅
单位 广东外语外贸大学
题目来源：王晓东《算法设计与分析》

一辆汽车加满油后可行驶 n公里。旅途中有若干个加油站。设计一个有效算法，指出应
在哪些加油站停靠加油，使沿途加油次数最少。

输入格式:
第一行有 2 个正整数n和 k（k<=1000 )，表示汽车加满油后可行驶n公里，且旅途中有 k个加油站。
第二行有 k+1 个整数，表示第 k 个加油站与第k-1 个加油站之间的距离。
第 0 个加油站表示出发地，汽车已加满油。
第 k+1 个加油站表示目的地。

输出格式:
输出最少加油次数。如果无法到达目的地，则输出“No Solution!”。

输入样例:
7 7
1 2 3 4 5 1 6 6
输出样例:
4
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
//int a[1010];
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    int n,k; cin>>n>>k;
//    rep(i,1,k+1){
//        cin>>a[i];
//        if(a[i]>n){
//            cout<<"No Solution!";
//            return 0;
//        }
//    }
//    int res = 0,s=n;
//    rep(i,1,k){
//        s -= a[i];
//        if(s<a[i+1]){
//            s = n;
//            res++;
//        }
//    }
//    cout<<res;
//
//    return 0;
//}

/*
 * 3 会场安排问题
分数 300
作者 陈晓梅
单位 广东外语外贸大学
题目来源：王晓东《算法设计与分析》

假设要在足够多的会场里安排一批活动，并希望使用尽可能少的会场。设计一个有效的
贪心算法进行安排。（这个问题实际上是著名的图着色问题。若将每一个活动作为图的一个
顶点，不相容活动间用边相连。使相邻顶点着有不同颜色的最小着色数，相应于要找的最小
会场数。）

输入格式:
第一行有 1 个正整数k，表示有 k个待安排的活动。
接下来的 k行中，每行有 2个正整数，分别表示 k个待安排的活动开始时间和结束时间。时间
以 0 点开始的分钟计。

输出格式:
输出最少会场数。

输入样例:
5
1 23
12 28
25 35
27 80
36 50
输出样例:
在这里给出相应的输出。例如：

3
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
//multiset<int> res;
//struct act{
//    int l,j;
//}a[N];
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    int k; cin>>k;
//    rep(i,1,k) cin>>a[i].l>>a[i].j;
//    sort(a+1,a+k+1,[](act a, act b){return a.l<b.l;});
//
//    res.insert(a[1].j);
//    rep(i,2,k){
//        auto it = res.begin();
//        if(*it <= a[i].l){
//            res.erase(it);
//        }
//        res.insert(a[i].j);
//    }
//    cout<<res.size();
//
//    return 0;
//}

/*
 * 4 程序存储问题
分数 300
作者 陈晓梅
单位 广东外语外贸大学
设有n 个程序{1,2,…, n }要存放在长度为L的磁带上。程序i存放在磁带上的长度是 li，1≤i≤n。 程序存储问题要求确定这n 个程序在磁带上的一个存储方案， 使得能够在磁带上存储尽可能多的程序。 对于给定的n个程序存放在磁带上的长度，计算磁带上最多可以存储的程序数。

输入格式:
第一行是2 个正整数，分别表示文件个数n和磁带的长度L。接下来的1行中，有n个正整数，表示程序存放在磁带上的长度。

输出格式:
输出最多可以存储的程序数。

输入样例:
在这里给出一组输入。例如：

6 50
2 3 13 8 80 20
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
const int N = 1e6+10;
using namespace std;
int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k,s; cin>>k>>s;
    rep(i,1,k) cin>>a[i];
    sort(a+1,a+k+1);
    rep(i,1,k){
        if(s<a[i]){
            cout<<i-1;
            return 0;
        }
        s -= a[i];
    }
    cout<<k;

    return 0;
}

/*
 * 5 工厂机器安排
分数 300
作者 吴云鹏
单位 郑州大学
题目来源：HDOJ

Today the company has m tasks to complete. The ith task need xi minutes to complete. Meanwhile, this task has a difficulty level yi. The machine whose level below this task’s level yi cannot complete this task. If the company completes this task, they will get (500xi+2yi) dollars.

The company has n machines. Each machine has a maximum working time and a level. If the time for the task is more than the maximum working time of the machine, the machine can not complete this task. Each machine can only complete a task one day. Each task can only be completed by one machine.

The company hopes to maximize the number of the tasks which they can complete today. If there are multiple solutions, they hopes to make the money maximum.

输入格式:
The input contains several test cases.

The first line contains two integers N and M. N is the number of the machines.M is the number of tasks(1 < =N <= 100000,1<=M<=100000).

The following N lines each contains two integers xi(0<xi<1440),yi(0=<yi<=100).xi is the maximum time the machine can work.yi is the level of the machine.

The following M lines each contains two integers xi(0<xi<1440),yi(0=<yi<=100).xi is the time we need to complete the task.yi is the level of the task.

输出格式:
For each test case, output two integers, the maximum number of the tasks which the company can complete today and the money they will get.

输入样例:
在这里给出一组输入。例如：

1 2
100 3
100 2
100 1
输出样例:
在这里给出相应的输出。例如：

1 50004
代码长度限制
16 KB
时间限制
2000 ms
内存限制
64 MB
 */
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y; x<=z; ++x)
const int N = 1e6+10;
using namespace std;
struct act{
    int t,s;
    // haha
    bool operator<(act b){
        if(t != b.t) return t>b.t;
        return s>b.s;
    }
}ma[N],ta[N];
int s[110];
long long res;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m,n; cin>>m>>n;
    rep(i,1,m) cin>>ma[i].t>>ma[i].s;
    rep(i,1,n) cin>>ta[i].t>>ta[i].s;
    sort(ma+1,ma+m+1);
    sort(ta+1,ta+n+1);

    int j=1,c=0;
    rep(i,1,n){
        while (j<=m && ma[j].t>=ta[i].t){
            s[ma[j].s]++; ++j;
        }
        rep(p,ta[i].s,100){
            if(s[p]){
                --s[p];
                res += 500*ta[i].t+2*ta[i].s;
                ++c;
                break;
            }
        }
    }
    cout<<c<<" "<<res;

    return 0;
}
















