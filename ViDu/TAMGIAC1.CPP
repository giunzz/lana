#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e8+3;
int  n,d=0;
long a[maxn],ma=-maxn,z;
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
    freopen("TAMGIAC.INP", "r", stdin);
    freopen("TAMGIAC.OUT", "w", stdout);
    cin>>n;
    for ( long i=1; i<=n ; i++) cin>>a[i];
    sxnhanh(1,n);
    for (long i=1 ; i<= n ; i++) cout << a[i] <<" ";
    cout<< endl;
    long i=1;
    while ((i<=n-2) ){
        if (a[i+2]+a[i+1]>=a[i]) {
            cout<<a[i]<<" "<<a[i+1]<<" "<<a[i+2];
            d++;
            break;
        }
        i++;
    }
    if (d==0) cout<<-1;
    return 0;
}
