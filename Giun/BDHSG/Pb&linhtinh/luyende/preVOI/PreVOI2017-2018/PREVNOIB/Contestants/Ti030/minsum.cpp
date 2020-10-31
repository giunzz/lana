#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;++i)
#define X first
#define Y second

using namespace std;
typedef pair<int,int> ii;

const int mxn=1000005;

long long r1,r2;
int tt,top,c1,c2,res;
int snt[100005];
bool nt[mxn];

vector<ii> V1,V2;

void doc();
bool check(int a);
void primee();
void solve(int a,int b);

int main()
{
   primee();
   doc();
   return 0;

}

bool check(int a)
{
   For(i,2,trunc(sqrt(a)))if(a%i==0)return false;
   return true;
}

void solve(int a,int b)
{
   int s,d;
   V1.clear();
   V2.clear();
   bool kt=0;
   if(check(a))kt=1;
   if(a>=1000003)
      if (kt)
      V1.push_back(ii(a,1));
   if(a<1000003||(a>1000003&&kt==0))
   {
      s=1;
      while(a!=1)
      {
         d=0;
         while(a%snt[s]!=0)++s;
         while(a%snt[s]==0)
         {
            ++d;
            a/=snt[s];
            if(a==1)break;
         }
         V1.push_back(ii(snt[s],d));
         ++s;
      }
   }
   kt=0;
   if (check(b))kt=1;
   if(b>=1000003)
      if(kt)
      V2.push_back(ii(b,1));
   if(b<1000003||(b>1000003&&kt==0))
   {
      s=1;
      while(b!=1)
      {
         d=0;
         while(b%snt[s]!=0)++s;
         while(b%snt[s]==0)
         {
            ++d;
            b/=snt[s];
            if(b==1)break;
         }
         V2.push_back(ii(snt[s],d));
         ++s;
      }
   }
   c1=0;c2=0;
   int t;
   while(V1.size()>=1&&V2.size()>=1&&c1<=V1.size()-1&&c2<=V2.size()-1)
   {
      if(V1[c1].X<V2[c2].X&&c1<=V1.size()-1)
      {
         V1[c1].Y%=2;
         ++c1;
      }
      if(V2[c2].X<V1[c1].X&&c2<=V2.size()-1)
      {
         V2[c2].Y%=2;
         ++c2;
      }
      if(V2[c2].X==V1[c1].X)
      {
         t=min(V2[c2].Y,V1[c1].Y);
         V2[c2].Y-=t;
         V1[c1].Y-=t;
         ++c1;
         ++c2;
      }
   }
   if(V1.size())For(i,0,V1.size()-1)V1[i].Y%=2;
   if(V2.size())For(i,0,V2.size()-1)V2[i].Y%=2;
   r1=1;r2=1;
   if(V1.size())For(i,0,V1.size()-1)if(V1[i].Y>0)
    while(V1[i].Y!=0)
      {
         r1=r1*(long long)V1[i].X;
         --V1[i].Y;
      }
   if(V2.size())For(i,0,V2.size()-1)if(V2[i].Y>0)
      while(V2[i].Y!=0)
      {
         r2=r2*(long long)V2[i].X;
         --V2[i].Y;
      }
   printf("%lld %lld\n",r1,r2);
}


void primee()
{
   memset(nt,1,sizeof(nt));
   nt[1]=0;
   int j;
   For(i,2,1000)
      if(nt[i])
      {
         j=i+i;
         if(i<=1000)j=i*i;
         while(j<=1000000)
         {
            nt[j]=0;
            j+=i;
         }
      }
   top=0;
   For(i,2,1000000)if(nt[i])
   {
      ++top;
      snt[top]=i;
   }
   ++top;
   snt[top]=1000003;
}
void doc()
{
   freopen("minsum.inp","r",stdin);
   freopen("minsum.out","w",stdout);
   scanf("%d",&tt);
   int aa,bb;
   For(i,1,tt)
   {
      scanf("%d%d",&aa,&bb);
      solve(aa,bb);
   }
}
