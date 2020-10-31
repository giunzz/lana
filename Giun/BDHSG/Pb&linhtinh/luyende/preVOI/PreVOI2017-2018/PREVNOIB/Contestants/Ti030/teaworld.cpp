#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;++i)
#define X first
#define Y second

using namespace std;
typedef pair<int,int> ii;

const int mxn=10005;

int x[mxn],pos[mxn],root,m,n,k,r[mxn],Fl[mxn],Fr[mxn];

vector<ii> li,ri;

bool cmp(ii A,ii B){return A.Y<B.Y;}

void solve()
{
   sort(ri.begin(),ri.end());
   sort(li.begin(),li.end(),cmp);
   if(ri.size())For(i,0,ri.size()-1)
         For(j,root,ri[i].Y)
            if(pos[j])
               Fr[i]+=Fr[i-1]+pos[j];
   if(li.size())for(int i=li.size()-1;i>=0;--i)
      For(j,li[i].X,root-1)
         if(pos[j])
               Fl[i]=Fl[i+1]+pos[j];
   int res=0;
   For(i,0,k)
      res=max(res,Fr[i]+Fl[k-i]);
   cout<<res;

}

int main()
{
   freopen("teaworld.inp","r",stdin);
   freopen("teaworld.out","w",stdout);
   int xx,yy,zz,rr;
   scanf("%d%d%d",&m,&n,&k);
   For(i,1,m)
         scanf("%d%d%d%d",&x[i],&yy,&zz,&r[i]);
   For(i,1,n)
      {
         scanf("%d%d%d%d",&xx,&yy,&zz,&rr);
         pos[xx+500]=rr;
      }
   scanf("%d%d%d",&xx,&yy,&zz);
   root=xx+500;
   For(i,1,m)if(x[i]>=root)ri.push_back(ii(x[i]-r[i]+500,x[i]+r[i]+500));
      else li.push_back(ii(x[i]-r[i]+500,x[i]+r[i]+500));
   solve();



}
