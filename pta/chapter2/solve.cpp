//
// Created by xiaodian& on 2023/10/17.
//
/**
* 1.已知斐波那契数列 F
n
​
 =F
n−1
​
 +F
n−2
​
 (n>=3),F
1
​
 =1,F
2
​
 =1
用递归的方法求解该数列的第n项。

输入格式:
输入一个正整数n (1<=n<=40)。

输出格式:
输出一个数，数列的第n项

输入样例1:
1
输出样例1:
1
输入样例2:
3
输出样例2:
2
代码长度限制
16 KB
时间限制
1000 ms
内存限制
128 MB
*/
//#include "iostream"
//using namespace std;
//long long int f(int n){
//    if(n <= 2)
//        return 1;
//    else
//        return f(n-1)+f(n-2);
//}
//int main(){
//    int n;
//    cin>>n;
//    cout<<f(n);
//}


/*
 * 2.已知斐波那契数列 F
n
​
 =F
n−1
​
 +F
n−2
​
 (n>=3),F
1
​
 =1,F
2
​
 =1

求解该数列的第n项，结果对998244353取模。

输入格式:
输入一个正整数n (1<=n<=10000000)。

输出格式:
输出一个数，数列的第n项

输入样例1:
1
输出样例1:
1
输入样例2:
3
输出样例2:
2
代码长度限制
16 KB
时间限制
1000 ms
内存限制
128 MB
 */
//#include "iostream"
//using namespace std;
//int f(int n){
//    if(n<=2)
//        return 1;
//    int a = 1,b=1,c;
//    for(int i=3; i<=n; i++){
//        c = (a+b)%998244353;
//        a = b;
//        b = c;
//    }
//    return c;
//}
//int main(){
//    int n;
//    cin>>n;
//    cout<<f(n);
//}

/*
 * 3.已知斐波那契数列 F
n
​
 =F
n−1
​
 +F
n−2
​
 (n>=3),F
1
​
 =1,F
2
​
 =1

求解该数列的第n项，结果对998244353取模。

提示：矩阵快速幂，unsigned long long的最大值：1844674407370955161（1.8e18）

输入格式:
输入一个正整数n (1<=n<=1e18)。

输出格式:
输出一个数，数列的第n项

输入样例1:
1
输出样例1:
1
输入样例2:
3
输出样例2:
2
代码长度限制
16 KB
时间限制
1000 ms
内存限制
128 MB
 */
//#include <cstring>
//#include "iostream"
//#define ull unsigned long long
//using namespace std;
//class matrix{
//public:
//    ull a[2][2] = {{1,1},{1,0}};
//    matrix operator*(matrix b){
//        matrix res;
//        memset(res.a,0,sizeof res.a);
//        for(int i=0; i<2; i++){
//            for(int j=0; j<2; j++){
//                for(int k=0; k<2; k++)
//                    res.a[i][j] += (a[i][k]*b.a[k][j])%998244353;
//            }
//        }
//        return res;
//    }
//    matrix mul(ull n){
//        matrix res,t;
//        n--;
//        while(n){
//            if(n&1)  res = res*t;
//            t = t*t;
//            n >>= 1;
//        }
//        return res;
//    }
//};
//int main(){
//    ull n;
//    cin>>n;
//    if(n<=2){
//        cout << 1;
//        return 0;
//    }
//    matrix res;
//    res = res.mul(n-2);
//    cout<< (res.a[0][0]+res.a[1][0])%998244353;
//    return 0;
//}

/*
 * 4 分形的递归输出
分数 300
作者 吴云鹏
单位 郑州大学
分形，具有以非整数维形式充填空间的形态特征。通常被定义为“一个粗糙或零碎的几何形状，可以分成数个部分，且每一部分都（至少近似地）是整体缩小后的形状”，即具有自相似的性质。

一个盒状分形定义如下：
度为1的盒分形为：

X
度为2的盒分形为：

X X
 X
X X
依次类推，如果B(n-1)表示n-1度的盒分形，则n度的盒分形递归定义如下：

B(n - 1)        B(n - 1)

        B(n - 1)

B(n - 1)        B(n - 1)
请画出度为n的盒分形的图形

输入格式:
输入一系列度，每行给出一个不大于7的正整数。输入的最后一行以-1表示输入结束

输出格式:
对于每个用例，输出用'X'标记的盒状分形。在每个测试用例后输出包含一个短划线“-”的一行。

输入样例:
1
2
3
4
-1
输出样例:
注意：每行的空格请输出完整。

X
-
X X
 X
X X
-
X X   X X
 X     X
X X   X X
   X X
    X
   X X
X X   X X
 X     X
X X   X X
-
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
   X X               X X
    X                 X
   X X               X X
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
         X X   X X
          X     X
         X X   X X
            X X
             X
            X X
         X X   X X
          X     X
         X X   X X
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
   X X               X X
    X                 X
   X X               X X
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
-
代码长度限制
16 KB
时间限制
1000 ms
内存限制
64 MB
 */
//#include <cstring>
//#include "iostream"
//#include "cmath"
//
//#define MAX 729
//char picture[MAX][MAX];
//using namespace std;
//
//void draw(int n, int sr, int sl) {
//    if (n == 1) {
//        picture[sr][sl] = 'X';
//        return;
//    }
//    draw(n - 1, sr, sl);
//    draw(n - 1, sr, sl + 2 * pow(3, n - 2));
//    draw(n - 1, sr + pow(3, n - 2), sl + pow(3, n - 2));
//    draw(n - 1, sr + 2 * pow(3, n - 2), sl);
//    draw(n - 1, sr + 2 * pow(3, n - 2), sl + 2 * pow(3, n - 2));
//}
//
//int main() {
//    memset(picture, ' ', sizeof picture);
//    draw(7, 0, 0);
//    int n;
//    cin >> n;
//    while (n != -1) {
//        int end = pow(3, n - 1);
//        for (int i = 0; i < end; i++) {
//            for (int j = 0; j < end; j++) {
//                cout << picture[i][j];
//            }
//            cout << endl;
//        }
//        cout << "-" << endl;
//        cin >> n;
//    }
//    return 0;
//}

/*
 * 5 子序列的平均值
分数 300
作者 吴云鹏
单位 郑州大学
给定一个长度为n的非负序列A，请你找出一个长度不小于L的子段（子段是序列A中一些连续的元素构成的集合），使得子段中数值的平均值最大。最终输出这个最大的平均值。

输入格式:
第一行两个整数n,L(1<=L<=n<=100,000)

以下n行，每行一个非负整数，表示序列A中每个元素的值。

输出格式:
一个整数，欲求的最大平均值乘以1000后的结果（注意不要四舍五入，直接输出）。

输入样例:
10 6
6
4
2
10
3
8
5
9
4
1
输出样例:
6500
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
 */
//#include "iostream"
//using namespace std;
//int n,l;
//double maybe;
//const double pre = 1e-6;
//bool check(int a[]){
//    int i=0;
//    double sumr = 0, suml=0,min=0;
//    for(;i<l;i++)
//        sumr += a[i]-maybe;
//    if(sumr-min >= 0)
//        return true;
//    for(; i<n; i++){
//        sumr += a[i]-maybe;
//        suml += a[i-l]-maybe;
//        min = std::min(min,suml);
//        if(sumr-min >= 0)
//            return true;
//    }
//    return false;
//}
//int main(){
//    cin>>n>>l;
//    int a[n];
//    for(int i=0; i<n; i++)
//        cin>>a[i];
//    double min=a[0],max=a[0];
//    for(int i=1; i<n; i++){
//        if(a[i]>max)
//            max = a[i];
//        else if(a[i] < min){
//            min = a[i];
//        }
//    }
//    while(max-min > pre){
//        maybe = (max+min)/2.0;
//        if(check(a)){
//            min = maybe;
//        } else max = maybe;
//    }
//    cout<<int(max*1000);
//    return 0;
//}
/*
 * 6 谁没有完成实验？
分数 300
作者 吴云鹏
单位 郑州大学
一个学期结束了，老师想知道一些同学是否一次上机实验都没进行，也就是没提交过一次程序。现在老师从平台导出了所有同学的提交记录，并已经按照学生的编号从小到大排好序了，现在给你一些同学的编号，帮老师看看这些同学是否有提交记录。

输入格式:
第一行一个整数N，表示所有提交的次数(0<N<=2000000)。

以下N行，表示每次提交对应的学生编号A
i
​
 ,(0<A
i
​
 <=1000000)。

接下来一行，一个整数M，表示要查询学生的数量M(0<M<=10000)。

接下来M行，每行一个学生编号（编号在int范围内）。

输出格式:
输出“Yes”或者“No”表示该编号学生是否有过提交记录。（输出不包括引号）

输入样例1:
5
1
1
2
3
4
1
1
输出样例1:
Yes
输入样例2:
5
1
1
2
2
4
2
6
1
输出样例2:
No
Yes
代码长度限制
16 KB
时间限制
500 ms
内存限制
128 MB
 */
//#include <vector>
//#include "iostream"
//using namespace std;
//bool find(vector<int> &list,int t,int begin, int end){
//    if(begin > end)
//        return false;
//    int mid = (begin+end)/2;
//    if(list[mid] == t)
//        return true;
//    else if(list[mid] > t)
//        return find(list,t,begin,mid-1);
//    else
//        return find(list,t,mid+1,end);
//}
//int main(){
//    int m,i=0,t;
//    cin>>m;
//    vector<int> list;
//    cin>>t;
//    list.push_back(t);
//    m--;
//    while(m--){
//        cin>>t;
//        if(t!=list[i]){
//            list.push_back(t);
//            i++;
//        }
//    }
//    int n;
//    cin>>n;
//    while (n--){
//        cin>>t;
//        if(find(list,t,0,i))
//            cout<<"Yes";
//        else
//            cout<<"No";
//        if(n!=0)
//            cout<<endl;
//    }
//    return 0;
//}

/*
 * 7 士兵排队
分数 300
作者 吴云鹏
单位 郑州大学
在一个划分成网格的操场上，n个士兵散乱地站在网格点上。网格点用整数坐标(x,y)表示。士兵们可以沿网格边往上、下、左、右移动一步，但在同一时刻任一网格点上只能有一名士兵。按照军官的命令，士兵们要整齐地列成一个水平队列，即排列成(x,y),(x+1,y),…,(x+n-1,y)。如何选择x和y的值才能使士兵们以最少的总移动步数排成一行。

编程计算使所有士兵排成一行需要的最少移动步数。

题目引自POJ

输入格式:
第1行是士兵数n，1≤n≤10000。接下来n行是士兵的初始位置，每行有2个整数x和y，-10000≤x，y≤10000。

输出格式:
一个数据，即士兵排成一行需要的最少移动步数。

输入样例:
5
1  2
2  2
1  3
3  -2
3  3
输出样例:
8
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
 */
//#include <algorithm>
//#include "iostream"
//using namespace std;
//int Random(int a, int b){
//    return a+rand()%(b-a);
//}
//template<class t>
//int partition(t a[],int s,int e){
//    t k = a[s];
//    while (s < e){
//        while (s<e && a[e]>=k) --e;
//        if(s == e)
//            return s;
//        swap(a[s],a[e]);
//        while (s<e && a[s]<=k) ++s;
//        if(s == e)
//            return s;
//        swap(a[s],a[e]);
//    }
//    return s;
//}
//template<class t>
//int randomPartition(t a[], int s, int e){
//    if(s == e)
//        return s;
//    int r = Random(s,e);
//    swap(a[s],a[r]);
//    return partition(a,s,e);
//}
//template<class t>
//t makeMid(t a[], int s, int e, int k){
//    if(s == e)
//        return a[s];
//    int i = randomPartition(a,s,e);
//    int j = i-s;
//    if(j == k)
//        return a[i];
//    else if(j>k)
//        return makeMid(a,s,i-1,k);
//    else
//        return makeMid(a,i+1,e,k-j-1);
//}
//
//
//int main(){
//    int n,t;
//    cin>>n;
//    int a[n],b[n];
//    for(int i=0; i<n; i++)
//        cin>>a[i]>>b[i];
//    sort(a,a+n);
//    for(int i=0; i<n; i++)
//        a[i]-=i;
//    int mida = makeMid(a,0,n-1,(n-1)/2);
//    int midb = makeMid(b,0,n-1,(n-1)/2);
//    int res=0;
//    for(int i=0; i<n; i++)
//        res += abs(mida-a[i]) + abs(midb-b[i]);
//    cout<<res;
//    return 0;
//}

/*
 * 8 输油管道问题
分数 300
作者 吴云鹏
单位 郑州大学
某石油公司计划建造一条由东向西的主输油管道。该管道要穿过一个有n 口油井的油田。从每口油井都要有一条输油管道沿最短路经(或南或北)与主管道相连。如果给定n口油井的位置,即它们的x 坐标（东西向）和y 坐标（南北向）,应如何确定主管道的最优位置,即使各油井到主管道之间的输油管道长度总和最小的位置? 证明可在线性时间内确定主管道的最优位置。

给定n口油井的位置, 计算各油井到主管道之间的输油管道最小长度总和。

输入格式:
输入的第1 行是油井数n，1<=n<=10000。接下来n 行是
油井的位置，每行2个用空格割开的整数 x和 y，-10000<=x，y<=10000。

输出格式:
输出油井到主管道之间的输油管道最小长度总和。

输入样例:
5
1 2
2 2
1 3
3 -2
3 3
输出样例:
6
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
 */
#include "iostream"
using namespace std;
int Random(int a, int b){
    return a+rand()%(b-a);
}
template<class t>
int partition(t a[],int s,int e){
    t k = a[s];
    while (s < e){
        while (s<e && a[e]>=k) --e;
        if(s == e)
            return s;
        swap(a[s],a[e]);
        while (s<e && a[s]<=k) ++s;
        if(s == e)
            return s;
        swap(a[s],a[e]);
    }
    return s;
}
template<class t>
int randomPartition(t a[], int s, int e){
    if(s == e)
        return s;
    int r = Random(s,e);
    swap(a[s],a[r]);
    return partition(a,s,e);
}
template<class t>
t makeMid(t a[], int s, int e, int k){
    if(s == e)
        return a[s];
    int i = randomPartition(a,s,e);
    int j = i-s;
    if(j == k)
        return a[i];
    else if(j>k)
        return makeMid(a,s,i-1,k);
    else
        return makeMid(a,i+1,e,k-j-1);
}


int main(){
    int n,t,i=0;
    cin>>n;
    int a[n];
    while(n--){
        cin>>t>>a[i++];
    }
    int mid = makeMid(a,0,i-1,(i-1)/2);
    int res=0;
    while (i--){
        res += abs(mid-a[i]);
    }
    cout<<res;
    return 0;
}
/*
 * 9 哪两个点之间的距离最近[增强版]
分数 300
作者 李军
单位 陕西理工大学
设P={(x
1
​
 ,y
1
​
 ),(x
2
​
 ,y
2
​
 ),⋯,(x
n
​
 ,y
n
​
 )}是平面上散列的n个点的集合。请编写程序找出集合中距离最近的点对。严格地说，相同距离的最近点对可能不止一对，为了简单期间只找出第一对最近点对即可。题目保证输入的所有数据均按照横坐标值进行升序排列。

输入格式:
输入第一行给出一个正整数n，表示平面上点的数数量。随后n行，每行给出一个实数对，每个实数对表示一个点的坐标值，其中第1数表示横坐标，第2数表示纵坐标。

输出格式:
输出最近点对中两个点的坐标和它们之间的距离。如果 x1+y1<=x2+y2则按
  (x1,y1),(x2,y2),miniDist=Distance
输出结果，否则按
  (x2,y2),(x1,y1),miniDist=Distance
输出结果。
  其中x1,y1,x2,y2是保留两位小数的实数，Distance是保留3位小数的实数

输入样例:
5
-1.00 2.00
0.00 2.00
0.50 0.60
1.00 1.00
2.00 0.00
输出样例:
(0.50,0.60),(1.00,1.00),miniDist=0.640
代码长度限制
16 KB
时间限制
15 ms
内存限制
64 MB
 */

/*
 * 我的
 */
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y; x<z; ++x)
const int N=1e6+10;
using namespace std;

struct point{
    double x,y;
    double sum(){return x+y;}
}p[N];
double dist(int i, int j){
    double dx=p[i].x-p[j].x, dy = p[i].y-p[j].y;
    return sqrt(dx*dx+dy*dy);
}
int p1,p2,n;
double mind = INFINITY;
void minDist(int s, int e);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);


    scanf("%d",&n);
    rep(i,0,n)
        scanf("%lf%lf",&p[i].x,&p[i].y);
//    sort(p,p+n,[&](point x,point y){return x.x < y.x;});
    minDist(0,n-1);
    if(p[p1].sum() > p[p2].sum())
        swap(p1,p2);
    printf("(%.2lf,%.2lf),(%.2lf,%.2lf),miniDist=%.3lf",p[p1].x,p[p1].y,p[p2].x,p[p2].y,mind);

    return 0;
}
void minDist(int s, int e){
    if(s == e)
        return;
    if(s == e-1){
        double dt = dist(s,e);
        if(dt < mind){
            mind = dt;
            p1=s; p2=e;
        }
        return;
    }

    int midPoint = (s+e)/2;
    minDist(s,midPoint);
    minDist(midPoint+1,e);
    int llist[midPoint-s+1],lk=0;
    rep(i,s,midPoint+1) if(p[midPoint].x - p[i].x<=mind) llist[lk++]=i;
    rep(i,0,lk){
        int lp = llist[i];
        rep(j,midPoint+1,e+1)
            if(p[j].x-p[midPoint].x<=mind)
                if(abs(p[j].y-p[lp].y)<=mind){
                    double dt = dist(lp,j);
                    if(dt<mind){
                        mind = dt;
                        p1=lp; p2=j;
                    }
                } else continue;
            else break;
    }
}

/*
 * 蔡星旖
 */
//#include <valarray>
//#include "stdio.h"
//#define rep(x,y,z) for(int x=y; x<z; ++x)
//const int N=1e6+10;
//using namespace std;
//int p1,p2,n;
//double mind = INFINITY;
//struct point{
//    double x,y;
//    double sum(){return x+y;}
//}p[N];
//double dist(int i, int j){
//    double dx=p[i].x-p[j].x, dy = p[i].y-p[j].y;
//    return sqrt(dx*dx+dy*dy);
//}
//double minDist(int s, int e);
//int main(){
//    scanf("%d",&n);
//    rep(i,0,n)
//        scanf("%lf%lf",&p[i].x,&p[i].y);
//    double res = minDist(0,n-1);
//    if(p[p1].sum() > p[p2].sum())
//        swap(p1,p2);
//    printf("(%.2lf,%.2lf),(%.2lf,%.2lf),miniDist=%.3lf",p[p1].x,p[p1].y,p[p2].x,p[p2].y,res);
//
//    return 0;
//}
//double minDist(int s, int e){
//    if(s == e)
//        return INFINITY;
//    int midPoint = (s+e)>>1;
//    double d = min(minDist(s,midPoint),minDist(midPoint+1,e));
//    int plist[e-s+1],kt=0;
//    rep(i,s,e+1) if(abs(p[i].x-p[midPoint].x)<=d) plist[kt++]=i;
//    sort(plist,plist+kt,[&](int a,int b){return p[a].y<p[b].y;});
//    rep(i,0,kt-1){
//        int lp = plist[i];
//        rep(j,i+1,kt){
//            int hp = plist[j];
//            if(p[hp].y-p[lp].y<d){
//                double dt = dist(lp,hp);
//                d = min(d,dt);
//                if(d<mind){
//                    mind = d; p1=lp; p2=hp;
//                }
//            }
//        }
//    }
//    return d;
//}

/*
 * 峰哥
 */
//#include<bits/stdc++.h>
//#define _ 0
//#define endl '\n'
//#define db double
//#define rep(x,y,z) for(int x=y;x<=z;++x)
//using namespace std;
//const int N=1e6+10;
//const db qwq=1e18;
//int n,s1,s2,t[N];
//db sur=1e18;
//struct point{db x,y;}d[N];
//
//inline db dis(int x,int y)
//{
//    db dx=d[x].x-d[y].x,dy=d[x].y-d[y].y;
//    return sqrt(dx*dx+dy*dy);
//}
//
//inline db run(int l,int r)
//{
//    if(l==r) return qwq;
//    int mid=(l+r)>>1;
//    db d=min(run(l,mid),run(mid+1,r));
//    int temp=0;
//    rep(i,l,r)
//        if(dis(i,mid)<d) t[++temp]=i;
//    rep(i,1,temp) rep(j,i+1,temp)
//        {
//            db dist=dis(t[i],t[j]);
//            d=min(d,dist);
//            if(dist<sur)
//            {
//                sur=dist;
//                s1=t[i];s2=t[j];
//            }
//        }
//    return d;
//}
//
//int main()
//{
////	freopen("1.in","r",stdin);
//    ios::sync_with_stdio(0);
//    cin.tie(0);cout.tie(0);
//    cin>>n;
//    rep(i,1,n) cin>>d[i].x>>d[i].y;
//    sort(d+1,d+n+1,[&](point x,point y){return x.x<y.x;});
//    db ans=run(1,n);
//    if(d[s1].x+d[s1].y>d[s2].x+d[s2].y) swap(s1,s2);
//    cout<<'('<<fixed<<setprecision(2)<<d[s1].x<<','<<d[s1].y<<"),("<<d[s2].x<<','<<d[s2].y<<"),miniDist="<<fixed<<setprecision(3)<<ans<<endl;
//    return (0^_^0);
//}




















