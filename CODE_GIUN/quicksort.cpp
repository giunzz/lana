#include<bits/stdc++.h>
using namespace std;
long n,a[1000008],b[1000008],k;
void sxtang(int d, int c){
        int i,j,m,x;
        m=(d+c)/2;
        x=a[m];
        i=d;
        j=c;
        do {
            while (a[i]<x) i++ ;
            while (a[j]>x) j-- ;
            if (i<=j) swap(a[i],a[j]), i++,j--;
        }
    while (i<=j);
    if (j>d) sxtang(d,j);
    if (i<c) sxtang(i,c);
    }
void sxgiam(int d, int c){
        int i,j,x;
        x=a[(d+c)/2];
        i=d;
        j=c;
        do {
            while (a[i]>x) i++ ;
            while (a[j]<x) j-- ;
            if (i<=j) swap(a[i],a[j]), i++ , j--;
        }
    while (i<=j);
    if (j>d) sxgiam(d,j);
    if (i<c) sxgiam(i,c);
    }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("QUICKSORT.INP", "r", stdin);
    freopen("QUICKSORT.OUT", "w", stdout);
    cin>>n;
    for (int i=1; i<=n ; i++) cin>>a[i];
    sxtang(1,n);
     for (int i=1 ; i<=n ; i++ ) cout<< a[i]<<" ";
    /*cout<< endl;
    sort(a + 1,aN+1+n);
    for (int i=1 ; i<=n ; i++) cout<< a[i]<<" ";
    cout<< endl;
    sxgiam(1,n);
    for (int i=1 ; i<=n ; i++) cout<< a[i]<<" ";*/
    return 0;
}
