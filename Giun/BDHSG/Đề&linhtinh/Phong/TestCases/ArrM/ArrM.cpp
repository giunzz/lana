#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,w;
long long rest;
long long a1[10000001]={};

int main() {
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
     cin>>a>>b>>w;
     a1[a]+=w;
     a1[b+1]-=w;
    }
    for(int i=2;i<=n;i++) a1[i]+=a1[i-1];
    rest=a1[1];
    for(int i=2;i<=n;i++) 
        if(rest<a1[i]) rest=a1[i];
    cout<<rest<<endl;    
    return 0;
}
