//小辉机:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct Point{
    double x;
    double y;
};
struct Point p[10000];
double fun(double p1[], double p2[]){
    return sqrt((p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]));
}

void init_(double a[][2],int n){
    for(int i=0;i<n;i++){
        a[i][0] = 0;
        a[i][1] = 0;
    }
}

void merge(double a[][2], int l, int mid, int r){
    int n = r-l+1;
    double tmp[n][2];
    // init_(tmp,n);
    int i = l;
    int j = mid+1;
    int k = 0;
    while(i <= mid && j <= r){
        if(a[i][0]<a[j][0]){
            tmp[k][0] = a[j][0];
            tmp[k++][1] = a[j++][1];

        } else {
            tmp[k][0] = a[i][0];
            tmp[k++][1] = a[i++][1];
        }
    }

    while(i <= mid){
        tmp[k][0] = a[i][0];
        tmp[k++][1] = a[i++][1];
    }
    while(j <= r){
        tmp[k][0] = a[j][0];
        tmp[k++][1] = a[j++][1];
    }

    for(i=0;i<k;i++){
        a[l+i][0] = tmp[i][0];
        a[l+i][1] = tmp[i][1];
    }

}

void merge_sort(double arr[][2], int l, int r){
    if(arr == NULL || l >= r) return;
    int mid = (l+r)/2;
    merge_sort(arr,l,mid);
    merge_sort(arr,mid+1,r);
    merge(arr,l,mid,r);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    double minx = 999999999;
    double x1,x2,y1,y2;
    double pp[10000][2];
    for(int i=0;i<n;i++){
        pp[i][0] = p[i].x;
        pp[i][1] = p[i].y;
    }

    merge_sort(pp,0,n-1);
    // for(int i=0;i<n;i++){
    //     printf("%.2lf %.2lf\n",pp[i][0],pp[i][1]);
    // }

    for(int i=0;i<n-1;i++){
       double d = fun(pp[i],pp[i+1]);
            if(d<minx) {
                minx = d;
                x1 = pp[i][0];
                y1 = pp[i][1];
                x2 = pp[i+1][0];
                y2 = pp[i+1][1];
            }
    }

    for(int i=0;i<n;i++){
        pp[i][0] = p[i].y;
        pp[i][1] = p[i].x;
    }
    merge_sort(pp,0,n-1);
    for(int i=0;i<n-1;i++){
       double d = fun(pp[i],pp[i+1]);
            if(d<minx) {
                minx = d;
                x1 = pp[i][0];
                y1 = pp[i][1];
                x2 = pp[i+1][0];
                y2 = pp[i+1][1];
            }
    }
    if(x1+y1<=x2+y2)
        printf("(%.2lf,%.2lf),(%.2lf,%.2lf),miniDist=%.3lf",x1,y1,x2,y2,minx);
    else
        printf("(%.2lf,%.2lf),(%.2lf,%.2lf),miniDist=%.3lf",x2,y2,x1,y1,minx);
}

