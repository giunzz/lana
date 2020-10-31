// KHAz
#include<bits/stdc++.h>
#define maxn
#define F first
#define S second
#define PB push_back
#define mp make_pair
#define reset(x) memset(x,0,sizeof(x))
#define Task "modulo"
#define pii pair < int , int >
#define ll long long
using namespace std;
int n,a,b;
ll mu[21];
int mu1[22];
ll k;
int ge(int i,int j)
{
    return (i>>j)&1;
}
void sub1()
{
    ll v=(1<<n);
    vector < int > l;
    for(int x=0; x<(1<<n); x++)
    {
        l.clear();
        ll z=0,z1=0,cnt=0;
        for(int i=n-1; i>=n/2; i--)
        {
            if(ge(x,i)==0) z=z*10+a,l.PB(a);
            else z=z*10+b,l.PB(b);
        }
        for(int i=n/2-1; i>=0; i--)
        {
            if(ge(x,i)==0) z1=z1*10+a,l.PB(a);
            else z1=z1*10+b,l.PB(b);
            cnt++;
        }
        //   cout<<z*mu[cnt]<<endl;
        ll xx=(z+v)%v,xy=(v+mu[cnt])%v;
        xx=(xx*xy+v)%v;
        if((xx+z1+v)%v==k)
        {
            for(int i=0;i<l.size();i++) cout<<l[i];
            return ;
        }
    }
    cout<<-1;
    // cout<<v;
}
void sub2()
{
    ll v=1<<n;
    int c=n/2,c1=n-c;
    vector < pair < int , vector < int > > > v1,v2;
    int cnt=0;
    for(int x=0; x<(1<<c); x++)
    {
        vector < int > l;
        ll z=0,z1=0;
        for(int i=c-1; i>=c/2; i--)
        {
            if(ge(x,i)==0) z=z*10+a,l.PB(a);
            else z=z*10+b,l.PB(b);
        }
        for(int i=c/2-1; i>=0; i--)
        {
            if(ge(x,i)==0) z1=z1*10+a,l.PB(a);
            else z1=z1*10+b,l.PB(b);
            if(x==0) cnt++;
        }
        //   cout<<z*mu[cnt]<<endl;
        ll xx=(z+v)%v,xy=(v+mu[cnt])%v;
        xx=(xx*xy+v)%v;
        ll fx=(xx+z1+v)%v;
       // ll fy=mu
        fx=(fx*mu1[c1]+v)%v;
        v1.PB(mp(fx,l));
    }
   cnt=0;
     for(int x=0; x<(1<<c1); x++)
    {
        vector < int > l;
        ll z=0,z1=0;
        for(int i=c1-1; i>=c1/2; i--)
        {
            if(ge(x,i)==0) z=z*10+a,l.PB(a);
            else z=z*10+b,l.PB(b);
        }
        for(int i=c1/2-1; i>=0; i--)
        {
            if(ge(x,i)==0) z1=z1*10+a,l.PB(a);
            else z1=z1*10+b,l.PB(b);
            if(x==0) cnt++;
        }
        //   cout<<z*mu[cnt]<<endl;
        ll xx=z%v,xy=mu[cnt]%v;
        xx=(xx*xy)%v;
        ll fx=(xx+z1)%v;
        v2.PB(mp(fx,l));
    }
    sort(v2.begin(),v2.end());
    vector < int > v3;
    for(int i=0;i<v2.size();i++) v3.PB(v2[i].F);
    for(int i=0;i<v1.size();i++)
    {
        ll x=v1[i].F;
        ll hh;
        if(k>=x) hh=k-x;
        else hh=k+v-x;
            int d=lower_bound(v3.begin(),v3.end(),hh)-v3.begin();
            int d1=upper_bound(v3.begin(),v3.end(),hh)-v3.begin();
            if(d!=d1)
            {
                for(int j=0;j<v1[i].S.size();j++) cout<<v1[i].S[j];
                for(int j=0;j<v2[d].S.size();j++) cout<<v2[d].S[j];
                return ;
            }
         //   cout<<hh<<endl;
    }
   // cout<<v;
   cout<<"-1";
    // cout<<v;
 //   for(int j=0;j<v1[0].S.size();j++) cout<<v1[0].S[j];

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin>>a>>b>>n>>k;
    mu[0]=1;
    mu1[0]=1;
    for(int i=1; i<=10; i++) mu[i]=mu[i-1]*10;
    for(int i=1;i<=20;i++) mu1[i]=(mu[i-1]*10)%(1<<n);
    if(n<=20) sub1();
    else if(n<=40) sub2();
         else cout<<"-1";
    //  cout<<mu[1];
   // sub2();
   // cout<<c

}
