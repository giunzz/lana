#include<bits/stdc++.h>
using namespace std;

int t;
int a,b,c;
int m[1000006];
long long res;
int x,y;
int u,v;
bool ok;
void pt(int n,int &d)
{
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)
    {
        while(n%i==0) {m[i]++;n/=i;}
    }
    if(n!=1) d=n;
}
int main()
{
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
    cin>>t;//cout<<t;
    for(int h=1;h<=t;h++)
    {
        cin>>a>>b;
        u=0;v=0;
        pt(a,u);
        pt(b,v);
        //if(u>v) swap(u,v);
        //cout<<u<<' '<<v<<'\n';
        res=1;
        if(u!=0) res*=u;
        if(v!=0) res*=v;
        if(u>v) swap(u,v);

        //cout<<res<<"------\n";


        c=max(a,b);

       // res=1;
        for(int i=1;i<=sqrt(c);i++)
            if(m[i]%2!=0)

                res=res*i;


        int sqr=sqrt(res);
        x=1;y=1;
        if(v!=0&&x*v<=sqr)
        {
            x=x*v;
            if(u!=0&&x*u<=sqr) x=x*u;
        }
        for(int i=sqrt(c);i>1;i--)
            if(m[i]%2!=0)
        {
            if(x*i<=sqr) x=x*i;
            else break;

        }
        for(int i=1;i<=sqrt(c);i++)
            if(m[i]%2!=0)
        {
            if(x*i<=sqr) x=x*i;
            else break;

        }
        y=res/x;
        cout<<x<<' '<<y<<'\n';
        for(int i=1;i<=sqrt(c);i++) m[i]=0;


    }


}
