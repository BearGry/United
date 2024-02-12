//
// Created by xiaodian& on 2024/1/7.
//
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y; x<=z; ++x)
const int N = 1e6+10;
using namespace std;
//0.N!末尾0的个数
//int a[10];
//
//int main(){
//    a[1] = 1;
//    rep(i,2,9){
//        a[i] = a[i-1]*i;
//    }
//    cout<<a[9]<<endl;
//    cout<<floor(9.0/5);
//
//    return 0;
//}




// A.递归
// 划分成子问题/（或者说）分治，产生一种递归的形式，我觉得递归是一种形式，划分子问题是思想
// 1.子问题独立
//1.全排列
//int a[N];
//const int n = 4;
//void perm(int k){
//    if(k == n){
//        rep(i,1,n) cout<<a[i]<<" ";
//        cout<<endl;
//        return;
//    }
//    rep(i,k,n){
//        swap(a[k],a[i]);
//        perm(k+1);
//        swap(a[k],a[i]);
//    }
//}
//int main(){
//    rep(i,1,n) a[i]=i;
//    perm(1);
//
//    return 0;

//}

//2.二分搜索
//int a[N];
//const int n = 13;
//int binarySearch(int k,int l,int r){
//    int m;
//    while(r>=l){
//        m = (l+r)>>1;
//        if(a[m] == k) return m;
//        if(a[m] < k) l = m+1;
//        else r = m-1;
//    }
//    return -1;
//}
//int main(){
//    rep(i,1,n) a[i] = i;
//    cout<<binarySearch(14,1,n);
//
//    return 0;
//}
//TODO：下面的有些可以选择等价的pta上的题

//TODO：合并排序
//int a[N];
//int b[N];
//const int n = 7;
//void mergeSort(int l,int j){
//    if(l >= j) return;
//    if(l == j-1){
//        if(a[l] > a[j]) swap(a[l],a[j]);
//        return;
//    }
//    int m = (l+j)>>1;
//    mergeSort(l,m);
//    mergeSort(m+1,j);
//    int i = m+1,k=1;
//    while(l<=m && i<=j){
//        if(a[l]<=a[i]){
//            b[k++] = a[l++];
//        }
//        else{
//            b[k++] = a[i++];
//        }
//    }
//    while(l<=m) b[k++] = a[l++];
//    while(i<=j) b[k++] = a[i++];
//
//    for(--k;k>0;--k) a[j--] = b[k];
//}
//int main(){
//    srand(time(0));
//    rep(i,1,n) a[i] = rand()%200;
//    rep(i,1,n) cout<<a[i]<<" ";
//    cout<<endl;
//    mergeSort(1,n);
//    rep(i,1,n) cout<<a[i]<<" ";
//    cout<<endl;
//
//    return 0;
//}

//TODO：快速排序
//int a[N];
//const int n = 14;
//int partition(int l, int j){
//    // 平常练习，我建议你多去尝试一些，学习一些优秀的策略
//    // 但这是考试，我希望你稳一些，写自己会写的、平常写的、不容易出错的写法
////    srand(time(0));
////    int t = rand()%(j-l+1); swap(a[l],a[l+t]);
//    int t = a[l];
//    while(l < j){
//        while(l<j && a[j]>=t) --j;
//        a[l] = a[j];
//        while(l<j && a[l]<=t) ++l;
//        a[j] = a[l];
//    }
//    a[l] = t;
//    return l;
//}
//void quicksort(int l, int j){
//    if(l >= j) return;
//    int m = partition(l,j);
//    quicksort(l,m-1);
//    quicksort(m+1,j);
//}
//int main(){
//    srand(time(0));
//    rep(i,1,n) a[i] = rand()%200;
//    rep(i,1,n) cout<<a[i]<<" ";
//    cout<<endl;
//    quicksort(1,n);
//    rep(i,1,n) cout<<a[i]<<" ";
//    cout<<endl;
//
//    return 0;
//}

//TODO：第k小(pta3-8)
//int a[N];
//int partition(int l, int j){
//    if(l == j) return l;
//    srand(time(0));
//    int t = rand()%(j-l+1)+l; swap(a[t],a[l]);
//    t = a[l];
//    while(l < j){
//        while(l<j && a[j]>=t) --j;
//        a[l] = a[j];
//        while(l<j && a[l]<=t) ++l;
//        a[j] = a[l];
//    }
//    a[l] = t;
//    return l;
//}
//int kmin(int l, int j, int k){
//    int m = partition(l,j);
//    if(m == k) return a[m];
//    if(m < k) return kmin(m+1,j,k);
//    return kmin(l,m-1,k);
//}
//int main(){
//    int n,k; cin>>n>>k;
//    rep(i,1,n) cin>>a[i];
//    cout<<kmin(1,n,k);
//
//    return 0;
//}

//TODO：最接近点对
//typedef long long ll;
//struct point{
//    int x,y;
//}a[N];
//int n;
//ll res = INT_MAX;
//ll dist(int i, int j){
//    return pow(a[i].x-a[j].x,2)+pow(a[i].y-a[j].y,2);
//}
//ll mindist(int l, int j){
//    if(l >= j) return INT_MAX;
//    if(l == j-1) return dist(l,j);
//    int m = (l+j)>>1;
//    ll d1 = mindist(l,m);
//    ll d2 = mindist(m+1,j);
//    res = min(d1,d2);
//    int tl=m-1,tr=m+1;
//    while((a[m].x-a[tl].x)<res) --tl;
//    ++tl;
//    sort(a+tl,a+m+1,[](point a,point b){return a.y<b.y;});
//    while((a[tr].x-a[m].x)<res) ++tr;
//    --tr;
//    sort(a+m+1,a+tr+1,[](point a,point b){return a.y<b.y;});
//    int tj = m+1;
//    rep(i,tl,m){
//        int t = tj;
//        while(t>=m+1 && abs(a[i].y-a[t].y)<res) {
//            res = min(res,dist(i,t)); --t;
//        }
//        t = tj;
//        while(t<=tr && abs(a[i].y-a[t].y)<res) {
//            res = min(res,dist(i,t)); ++t;
//        }
//        tj = t;
//
//    }
//
//    return res;
//}
//
//int main(){
//    cin>>n;
//    rep(i,1,n) cin>>a[i].x>>a[i].y;
//    sort(a+1,a+n+1,[](point a,point b){return a.x<b.x;});
//    cout<<mindist(1,n);
//
//    return 0;
//}

//TODO：循环赛程


//TODO：邮政选址





// 2.子问题重叠、推导过程无后效性——动态规划
//TODO：矩阵连乘问题（推荐pta）

//TODO：最长公共子序列（pta）

//TODO：最大子段和（pta）

//TODO：0-1背包



// 由元解决向上解决的过程是否容易描述，容易的话递推（不需要知到记不记忆）
// 不容易描述的话使用递归，并考虑求解的过程子问题是否会被重复解决，是的话记忆化分治





// B.搜索
//明确的解空间树（子集树——填盒子， 排列树——排列模板（见1.1））
//！在可行解中选择，减去不可行或者达不到最优解的选择
//TODO：船舶装载问题（pta上有类似）

//TODO：*作业调度问题（5-22）（k是层数，i是选择，选择的内容自然就是a[i](不是要与他交换嘛，其实就是选择它啊)a[i]前面的也就是选择过的当前情况）
int a[N];
int b[N];
int c[N];
int f,f1,f2[N];
int n;
int res = INT_MAX;
void perm(int k){
    if(k > n){
        res = f;
        return;
    }
    rep(i,k,n){
        f1 += a[c[i]];
        f2[k] = max(f2[k-1],f1)+b[c[i]];
        f += f2[k];
        if(f<res){
            swap(c[i],c[k]);
            perm(k+1);
            swap(c[i],c[k]);
        }
        f1 -= a[c[i]];
        f -= f2[k];
    }
}
int main(){
    cin>>n;
    rep(i,1,n) cin>>a[i]>>b[i];
    rep(i,1,n) c[i] = i;
    perm(1);
    cout<<res;

    return 0;
}

//int b[N];
//int f,f1,f2[N];
//int n;
//int res = INT_MAX;
//int a[N];
//bool vis[N];
//void perm(int k){
//    if(k > n){
//        res = f;
//        return;
//    }
//    rep(i,1,n){
//        if(!vis[i]){
//            f1 += a[i];
//            f2[k] = max(f2[k-1],f1)+b[i];
//            f += f2[k];
//            if(f<res) {
//                vis[i] = true;
//                a[k] = i;
//                perm(k + 1);
//                vis[i] = false;
//            }
//            f1 -= a[i];
//            f -= f2[k];
//        }
//
////        bool ok = true;
////        rep(j,1,k-1){
////            if(i == a[j]){
////                ok = false; break;
////            }
////        }
////        if(ok){
////            a[k] = i;
////            perm(k+1);
////        }
//    }
//}
//int main(){
//    cin>>n;
//    rep(i,1,n) cin>>a[i]>>b[i];
//    perm(1);
//    cout<<res;
//
//    return 0;
//}
//TODO：图的M着色问题（5-26）

//盒子数不明确的搜索（即搜索规模未知），需要使用bfs，bfs中注意是如果队列的就为visited
//在两种搜索都可是，建议使用盒子搜索，其空间复杂度会低一些
// BFS
//在分支限界法中，每一个活结点只有一次机会成为扩展结点（即只有一次机会进队列，所以入过队列就应该记录一下）。
//分支限界法常以广度优先或以最小耗费（最大效益）优先的方式搜索问题的解空间树。
// 优先队列中优先函数的选取是非常重要的
//TODO：pta上的那几道还不错，幸福小镇、最短距离、狼回家可以做一做
//TODO：最短距离

//TODO：幸福小镇

//TODO：狼回家



//TODO：布线问题



//TODO：非必须
//TODO：船舶装载问题（队列式）
//TODO：船舶装载问题（优先队列式）




// C。贪心算法
//当贪心算法的有效性显而易见时使用，或者其他的准确算法想不出来（可以试试嘛）（削减问题规模、搜索）
//TODO：加油问题（pta）

//TODO：活动安排问题（pta）













//TODO：最接近点对

//TODO：*作业调度问题（5-22）（k是层数，i是选择，选择的内容让然就是a[i](不是要与他交换嘛，其实就是选择它啊)a[i]前面的也就是选择过的当前情况）

//TODO：循环赛程

//TODO：最大子段和（pta）

//TODO：布线问题

//TODO：船舶装载问题（pta上有类似）

//TODO：邮政选址

//TODO：图的M着色问题（5-26）

//TODO：pta上的那几道还不错，幸福小镇、最短距离、狼回家可以做一做

//TODO：船舶装载问题（优先队列式）

//TODO：最短距离

//TODO：0-1背包

//TODO：幸福小镇

//TODO：狼回家

//TODO：矩阵连乘问题（推荐pta）

//TODO：加油问题（pta）

//TODO：非必须

//TODO：船舶装载问题（队列式）

//TODO：最长公共子序列（pta）

//TODO：活动安排问题（pta）









