#include<bits/stdc++.h>
using namespace std;
long long n,a[(int) 1e6+3],k,s=0;
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
    //freopen("input.inp","r",stdin);
    //freopen("output.txt","w",stdout);
    freopen("BTMAX.INP", "r", stdin);
    freopen("BTMAX.OUT", "w", stdout);
    cin>>n>>k;
    for (int i=1; i<=n ; i++) cin>>a[i];
     sxnhanh(2,n);
    for (int i=1 ; i<=n ; i++){
        if (i<=k+1) s+=a[i];
        else s-=a[i];
}
    cout<<s;
return 0;
}
