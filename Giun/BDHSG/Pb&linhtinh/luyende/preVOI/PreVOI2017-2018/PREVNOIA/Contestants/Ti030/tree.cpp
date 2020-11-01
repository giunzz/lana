#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;++i)

using namespace std;
const int mxn=5005;

int n,a[mxn],cha[mxn],F[mxn],res=1e7,rs;
int x[25];

vector<int> con[mxn];
vector <int> V;



void doc();
void solve();
void sol(int u);
void sinh(int i);

int main()
{
   doc();
   solve();
   return 0;
}



void trace(int u)
{

   if(con[u].size()==0)
   {
      rs+=abs(F[u]-a[u]);
      return;
   }
   trace(con[u][0]);
   trace(con[u][1]);
   F[u]=F[con[u][0]]+F[con[u][1]];
   rs+=abs(a[u]-(F[con[u][0]]+F[con[u][1]]));

}

void sol()
{
   memset(F,0,sizeof(F));
   rs=0;
   For(i,0,V.size()-1)
            F[V[i]]=x[i];
   trace(1);
   res=min(res,rs);

}


void sinh(int i)
{
   if(i>V.size()-1)
   {
      sol();
      return;
   }
   x[i]=0;
   sinh(i+1);
   x[i]=1;
   sinh(i+1);
}

void solve()
{

   For(i,1,n)if(con[i].size()==0)V.push_back(i);
   sinh(0);
   cout<<res;

}

void doc()
{
   freopen("tree.inp","r",stdin);
   freopen("tree.out","w",stdout);
   scanf("%d",&n);
   For(i,1,n)scanf("%d",&a[i]);
   int aa,bb;
   For(i,1,n-1)
   {
      scanf("%d%d",&aa,&bb);
      cha[bb]=aa;
      con[aa].push_back(bb);
   }
}
