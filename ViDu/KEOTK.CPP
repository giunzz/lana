#include<bits/stdc++.h>
using namespace std;
int n,a[1000008];
void sxnhanh(int d, int c){
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
    if (j>d) sxnhanh(d,j);
    if (i<c) sxnhanh(i,c);
    }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("KEOTK.INP", "r", stdin);
    freopen("KEOTK.OUT", "w", stdout);
    cin>>n;
    for (int i=1; i<=n ; i++) cin>>a[i];
    sxnhanh(1,n);
    for (int i=n ; i>=1 ; i--) cout<<a[i]<<" ";
    return 0;
}
