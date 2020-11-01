#include<bits/stdc++.h>
#define maxn 100005
using namespace std ;
int n,a[maxn];
int main(){
   freopen("ARRANGE.inp","r",stdin);
   freopen("ARRANGE.out","w",stdout);
   scanf("%d",&n);
   for(int i=1;i<=n;i++)scanf("%d",&a[i]);
   long long tong=0;
   for(int i=1;i<=n;i++)tong+=a[i];
   cout<<tong/2;
}
