#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define For(i,a,b) for(int i=a;i<=b;i++)
int m,n,k;
int a[3001],b[3001];
int main(){
     freopen("SEQUENCE.INP","r",stdin);
    freopen("SEQUENCE.OUT","w",stdout);
    cin>>m>>n>>k;
    For(i,1,m)
        scanf("%d",&a[i]);
    For(i,1,n)
        scanf("%d",&b[i]);
    if(m<n){
        For(i,1,k-1){
            cout<<a[i]<<' ';
        }
        cout<<a[k-1];
    }
    else {
         For(i,1,k-1){
            cout<<b[i]<<' ';
        }
        cout<<b[k-1];
    }
}

