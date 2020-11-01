#include<bits/stdc++.h>
using namespace std;
const int base =1e9+7;
int n,nmax;
int m[3];
int res=0;
int x[156];
void sub1(int i)
{
   for(int j=0;j<=2;j++)
   {
       if(m[j]==nmax)continue;
       int ok=0,ok1=0,ok2=0,ok3=0;
       if(j==0){m[j]++;ok=1;}
       if(j==1)
       {
           if(m[0]>0){m[j]++;m[0]--;ok3=1;ok=1;}
       }
       if(j==2)
       {
           if(m[1]>0&&m[0]>0)
           {
               m[1]--;
               m[0]--;
               m[2]++;
               ok1=1;
               ok=1;
           }
           else
            if(m[0]>=3)
           {
               m[0]-=3;
               m[2]++;
               ok2=1;
               ok=1;
           }
       }
       if(i==n&&ok==1)res++;
       else if(ok==1)sub1(i+1);
       if(j==2)
       {
           if(ok1==1)
               {m[1]++;
               m[0]++;
               m[2]--;
               }
            if(ok2==1)
           {
               m[0]+=3;
               m[2]--;
           }
       }
       if(j==1)
       {
        if(ok3==1){m[j]--;m[0]++;}
       }
       if(j==0)m[j]--;
   }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);
    cin>>n>>nmax;
    cin>>m[0]>>m[1]>>m[2];
    if(n<=21){sub1(1);cout<<res%base;return 0;}
    int s=1;
    for(int i=1;i<=n;i++)s=(s*2)%base;
    cout<<(s-nmax+base)%base;
    return 0;
}
