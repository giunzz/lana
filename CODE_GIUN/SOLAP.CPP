#include<bits/stdc++.h>
using namespace std;
const long maxn = 10009;
long n,s=0,b[maxn]={0},t;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   freopen("SOLAP.INP","r",stdin);
   freopen("SOLAP.OUT","w",stdout);
   scanf("%ld",&n);
   for (int i=1 ; i<= n ; i++ ){
       scanf("%ld",&t);
        b[t]=1;
   }
   for (int i=0 ; i<= 1000 ; i++)
      if (b[i] == 1) s=s+1;
   printf("%ld",s);
   return 0;
}
