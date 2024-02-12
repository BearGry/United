//
// Created by xiaodian& on 2023/12/7.
//
/*
 * 1 数字三角形
分数 300
作者 陈晓梅
单位 广东外语外贸大学
给定一个由 n行数字组成的数字三角形如下图所示。试设计一个算法，计算出从三角形
的顶至底的一条路径(每一步可沿左斜线向下或右斜线向下)，使该路径经过的数字总和最大。

QQ截图20170929023616.jpg

输入格式:
输入有n+1行：

第 1 行是数字三角形的行数 n，1<=n<=100。

接下来 n行是数字三角形各行中的数字。所有数字在0..99 之间。

输出格式:
输出最大路径的值。

输入样例:
在这里给出一组输入。例如：

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
输出样例:
在这里给出相应的输出。例如：

30
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
 */
//!搜索方法
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N=1e6+10;
//using namespace std;
//short a[101][101];
//int res = 0;
//int line;
//void solve(int l,int j,int sum){
//    if(l>line){
//        if(sum>res)
//            res = sum;
//        return;
//    }
//    sum += a[l++][j];
//    rep(i,0,1) solve(l,j+i,sum);
//}
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);cout.tie(0);
//
//    cin>>line;
//    rep(i,1,line)
//        rep(j,1,i)
//            cin>>a[i][j];
//    solve(1,1,0);
//    cout<<res;
//
//    return 0;
//}

//带记忆的搜索
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N=1e6+10;
//using namespace std;
//short a[101][101];
//int b[101][101];
//int res = 0;
//int line;
//int solve(int l,int j){
//    if(l == line)
//        return b[l][j] = a[l][j];
//    if(b[l][j] != -1)
//        return b[l][j];
//    return b[l][j] = max(solve(l+1,j), solve(l+1,j+1))+a[l][j];
//}
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);cout.tie(0);
//
//    memset(b,-1, sizeof b);
//    cin>>line;
//    rep(i,1,line)
//        rep(j,1,i)
//            cin>>a[i][j];
//    solve(1,1);
//    cout<<b[1][1];
//
//    return 0;
//}

// 消除递归写法
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N=1e6+10;
//using namespace std;
//int a[101][101];
//int line;
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);cout.tie(0);
//
//    cin>>line;
//    rep(i,1,line)
//        rep(j,1,i)
//            cin>>a[i][j];
//
//    for(int i=line-1; i>=1; --i)
//        for(int j=1; j<=i; ++j)
//            a[i][j] += max(a[i+1][j],a[i+1][j+1]);
//    cout<<a[1][1];
//
//    return 0;
//}

/*
 * 现在给你两个由AGCT四个字母构成的字符串，请你求出两个DNA序列的最长公共子序列。

输入格式:
两行，每行一个字符串，分别表示一个DNA序列（每个字符串长度不超过1000）。

输出格式:
一个数，最长公共子序列元素的个数。

输入样例:
在这里给出一组输入。例如：

AGCT
ATT
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
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);cout.tie(0);
//
//    string a,b;
//    cin>>a>>b;
//    int lena = a.size(), lenb = b.size();
//    int dp[lena+1][lenb+1];
//    memset(dp,0,sizeof dp);
//    rep(i,1,lena)
//        rep(j,1,lenb)
//            dp[i][j] = a[i-1] == b[j-1]? dp[i-1][j-1]+1:max(dp[i-1][j],dp[i][j-1]);
//    cout<<dp[lena][lenb];
//
//    return 0;
//}

/*
 * 3 单调递增最长子序列
分数 300
作者 陈晓梅
单位 广东外语外贸大学
设计一个O(n2)时间的算法，找出由n个数组成的序列的最长单调递增子序列。

输入格式:
输入有两行：
第一行：n，代表要输入的数列的个数
第二行：n个数，数字之间用空格格开

输出格式:
最长单调递增子序列的长度

输入样例:
在这里给出一组输入。例如：

5
1 3 5 2 9
输出样例:
在这里给出相应的输出。例如：

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
//int res = 1;
//int a[N];
//int b[N];
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    int k;
//    cin>>k;
//    rep(i,1,k) cin>>a[i];
//!!!!不行    b[1] = 1;
//    rep(i,1,k) b[i] = 1;
//    rep(i,1,k){
//        if(b[i]>res) res = b[i];
//        rep(j,i+1,k)
//            if(a[j]>a[i]) b[j] = max(b[j],b[i]+1);
//    }
//    cout<<res;
//
//    return 0;
//}

/*
 * 4 最大子段和
分数 300
作者 陈晓梅
单位 广东外语外贸大学
给定n个整数（可能为负数）组成的序列a[1],a[2],a[3],…,a[n]，求该序列如a[i]+a[i+1]+…+a[j]的子段和的最大值。当所给的整数均为负数时，定义子段和为0。

要求算法的时间复杂度为O(n)。

输入格式:
输入有两行：

第一行是n值（1<=n<=10000)；

第二行是n个整数。

输出格式:
输出最大子段和。

输入样例:
在这里给出一组输入。例如：

6
-2 11 -4 13 -5 -2
输出样例:
在这里给出相应的输出。例如：

20
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
//int res = 0;
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    int k; cin>>k;
//    rep(i,1,k) cin>>a[i];
//    rep(i,1,k){
//        res = res>a[i]? res:a[i];
//        a[i+1] += a[i]>0? a[i]:0;
//    }
//    cout<<res;
//
//    return 0;
//}

/*
 * 最大子矩阵和问题。给定m行n列的整数矩阵A，求矩阵A的一个子矩阵，使其元素之和最大。

输入格式:
第一行输入矩阵行数m和列数n（1≤m≤100，1≤n≤100），再依次输入m×n个整数。

输出格式:
输出第一行为最大子矩阵各元素之和，第二行为子矩阵在整个矩阵中行序号范围与列序号范围。

输入样例1:
5 6
60 3 -65 -92 32 -70
-41 14 -38 54 2 29
69 88 54 -77 -46 -49
97 -32 44 29 60 64
49 -48 -96 59 -52 25
输出样例1:
输出第一行321表示子矩阵各元素之和，输出第二行2 4 1 6表示子矩阵的行序号从2到4，列序号从1到6

321
2 4 1 6
代码长度限制
16 KB
时间限制
2200 ms
内存限制
64 MB
 */
//#include <bits/stdc++.h>
//#define rep(x,y,z) for(int x=y; x<=z; ++x)
//const int N = 1e6+10;
//using namespace std;
//int a[104][104];
//int b[104];
//int res = INT32_MIN;
//int x1,yy1,x2,y2;
//bool mss(int k){
//    int e=1,s[k+4];
//    s[1]=1;
//    int mmax = INT32_MIN;
//    rep(i,1,k){
//        if(b[i]>mmax){
//            mmax = b[i];
//            e=i;
//        }
//        if(b[i]>0){
//            s[i+1] = s[i];
//            b[i+1] += b[i];
//        }else s[i+1] = i+1;
//    }
//    if(mmax>res){
//        res = mmax;
//        yy1 = s[e]; y2=e;
//        return true;
//    }
//    return false;
//}
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    int m,n; cin>>m>>n;
//    rep(i,1,m)
//        rep(j,1,n)
//            cin>>a[i][j];
//    rep(i,1,m)
//        rep(j,i,m){
//            memset(b,0,(n+2)*sizeof i);
//            rep(k,1,n)
//                rep(p,i,j)
//                    b[k] += a[p][k];
//            if(mss(n)){
//                x1 = i; x2 = j;
//            }
//        }
//    cout<<res<<endl;
//    cout<<x1<<" "<<x2<<" "<<yy1<<" "<<y2;
//
//    return 0;
//}










































