//
// Created by xiaodian& on 2023/9/28.
//

/***
* 1.本题要求编写程序，输出整数152的个位数字、十位数字和百位数字的值。
输入格式：
本题无输入。

输出格式：
按照以下格式输出：

152 = 个位数字 + 十位数字*10 + 百位数字*100
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/
//#include "iostream"
//using namespace std;
//
//int main()
//{
//    cout<<"152 = 2 + 5*10 + 1*100";
//    return 0;
//}

/**
 * 2.本题目要求计算下列分段函数f(x)的值：
 *
输入格式：
输入在一行中给出实数x。

输出格式：
在一行中按“f(x) = result”的格式输出，其中x与result都保留一位小数。

输入样例1：
10
输出样例1：
f(10.0) = 0.1
输入样例2：
234
输出样例2：
f(234.0) = 234.0
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
 */
//#include <iomanip>
//#include "iostream"
//using namespace std;
//void f(){
//    double x;
//    cout<<fixed<<setprecision(1);
//    cin>>x;
//    if(x == 10){
//        cout<<"f(10.0) = 0.1";
//        return;
//    }
//    cout<<"f("<<x<<") = "<<x;
//}
//int main(){
//    f();
//}

/**
* 3.本题要求编写程序，计算2个正整数的和、差、积、商并输出。题目保证输入和输出全部在整型范围内。

输入格式:
输入在一行中给出2个正整数A和B。

输出格式:
在4行中按照格式“A 运算符 B = 结果”顺序输出和、差、积、商。

输入样例:
3 2
输出样例:
3 + 2 = 5
3 - 2 = 1
3 * 2 = 6
3 / 2 = 1
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/
//#include <iomanip>
//#include "iostream"
//using namespace std;
//void f(){
//    int a,b;
//    cin>>a>>b;
//    cout<<fixed<<setprecision(0);
//    cout<<a<<" + "<<b<<" = "<<a+b<<endl;
//    cout<<a<<" - "<<b<<" = "<<a-b<<endl;
//    cout<<a<<" * "<<b<<" = "<<a*b<<endl;
//    cout<<a<<" / "<<b<<" = "<<a/b;
//}
//int main(){
//    f();
//}

/**
* 4.本题要求编写程序，根据公式C
n
m
​
 =
m!(n−m)!
n!
​
 算出从n个不同元素中取出m个元素（m≤n）的组合数。

建议定义和调用函数fact(n)计算n!，其中n的类型是int，函数类型是double。

输入格式:
输入在一行中给出两个正整数m和n（m≤n），以空格分隔。

输出格式:
按照格式“result = 组合数计算结果”输出。题目保证结果在double类型范围内。

输入样例:
2 7
输出样例:
result = 21
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/
//#include "iostream"
//using namespace std;
//void f(){
//    double a=1,b=1;
//    int n,m;
//    cin>>m>>n;
//    for(int i=m+1; i<=n; i++)
//        a*=i;
//    for(int i=1; i<=n-m; i++)
//        b*=i;
//    cout<<"result = "<<a/b;
//}
//int main(){
//    f();
//}

/**
* 5.按照规定，在高速公路上行使的机动车，达到或超出本车道限速的10%则处200元罚款；若达到或超出50%，就要吊销驾驶证。请编写程序根据车速和限速自动判别对该机动车的处理。

输入格式:
输入在一行中给出2个正整数，分别对应车速和限速，其间以空格分隔。

输出格式:
在一行中输出处理意见：若属于正常行驶，则输出“OK”；若应处罚款，则输出“Exceed x%. Ticket 200”；若应吊销驾驶证，则输出“Exceed x%. License Revoked”。其中x是超速的百分比，精确到整数。

输入样例1:
65 60
输出样例1:
OK
输入样例2:
110 100
输出样例2:
Exceed 10%. Ticket 200
输入样例3:
200 120
输出样例3:
Exceed 67%. License Revoked
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/
//#include <iomanip>
//#include "iostream"
//using namespace std;
//void f(){
//    float v,sta;
//    cout<<fixed<<setprecision(0);
//    cin>>v>>sta;
//    if(v/sta>=1.5){
//        cout<<"Exceed "<<((v-sta)/sta)*100<<"%. License Revoked";
//    }
//    else if(v/sta>=1.1){
//        cout<<"Exceed "<<((v-sta)/sta)*100<<"%. Ticket 200";
//    }
//    else
//        cout<<"OK";
//}
//int main(){
//    f();
//}

/**
* 6.本题要求编写程序，计算序列 2/1+3/2+5/3+8/5+... 的前N项之和。注意该序列从第2项起，每一项的分子是前一项分子与分母的和，分母是前一项的分子。

输入格式:
输入在一行中给出一个正整数N。

输出格式:
在一行中输出部分和的值，精确到小数点后两位。题目保证计算结果不超过双精度范围。

输入样例:
20
输出样例:
32.66
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/
//#include <iomanip>
//#include "iostream"
//using namespace std;
//void f(){
//    int n;
//    cin>>n;
//    double m=1,z=2,t;
//    double sum=0;
//    for(int i=1;i<=n; i++){
//        sum += z/m;
//        t=z;
//        z=t+m;
//        m=t;
//    }
//    cout<<fixed<<setprecision(2);
//    cout<<sum;
//}
//int main(){
//    f();
//}

/**
 * 7. 本题要求编写程序，找出给定的n个数中的最大值及其对应的最小下标（下标从0开始）。

输入格式:
输入在第一行中给出一个正整数n（1<n≤10）。第二行输入n个整数，用空格分开。

输出格式:
在一行中输出最大值及最大值的最小下标，中间用一个空格分开。

输入样例:
6
2 8 10 1 9 10
输出样例:
10 2
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
 */
//#include "iostream"
//using namespace std;
//void f(){
//    int n;
//    cin>>n;
//    n--;
//    int max,t,index = 0;
//    cin>>max;
//    for(int i=1;i<=n;i++){
//        cin>>t;
//        if(t>max){
//            max=t;index=i;
//        }
//    }
//    cout<<max<<" "<<index;
//}
//int main(){
//    f();
//}

/**
 * 8.给定一个n×n的方阵，本题要求计算该矩阵除副对角线、最后一列和最后一行以外的所有元素之和。副对角线为从矩阵的右上角至左下角的连线。

输入格式:
输入第一行给出正整数n（1<n≤10）；随后n行，每行给出n个整数，其间以空格分隔。

输出格式:
在一行中给出该矩阵除副对角线、最后一列和最后一行以外的所有元素之和。

输入样例:
4
2 3 4 1
5 6 1 1
7 1 8 1
1 1 1 1
输出样例:
35
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
 */
//#include "iostream"
//using namespace std;
//void f(){
//    int n,t,sum=0;
//    cin>>n;
//    n;
//    int no=n+1;
//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=n; j++){
//            cin>>t;
//            if(i+j!=no && i!=n && j!=n)
//                sum+=t;
//        }
//    }
//    cout<<sum;
//}
//int main(){
//    f();
//}

/**
 * 9.查找书籍
给定n本书的名称和定价，本题要求编写程序，查找并输出其中定价最高和最低的书的名称和定价。

输入格式:
输入第一行给出正整数n（<10），随后给出n本书的信息。每本书在一行中给出书名，即长度不超过30的字符串，随后一行中给出正实数价格。题目保证没有同样价格的书。

输出格式:
在一行中按照“价格, 书名”的格式先后输出价格最高和最低的书。价格保留2位小数。

输入样例:
3
Programming in C
21.5
Programming in VB
18.5
Programming in Delphi
25.0
输出样例:
25.00, Programming in Delphi
18.50, Programming in VB
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
 */
//#include <iomanip>
//#include "iostream"
#include <bits/stdc++.h>
using namespace std;
void f(){
    int n;
    cin>>n;
    n--;
    getchar();
    string min_name,max_name,tn;
    double min_p,max_p,tp;
    getline(cin,min_name);
    cin>>min_p;
    getchar();
    max_name=min_name;
    max_p=min_p;
    for(int i=1; i<=n; i++){
        getline(cin,tn);
        cin>>tp;
        getchar();
        if(tp>max_p){
            max_p = tp;
            max_name = tn;
        }
        else if(tp < min_p){
            min_p = tp;
            min_name = tn;
        }
    }
    cout<<fixed<<setprecision(2);
    cout<<max_p<<", "<<max_name<<endl;
    cout<<min_p<<", "<<min_name;
}
int main(){
    f();
}

















