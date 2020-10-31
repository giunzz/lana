#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+3,oo=2e18;
int t,a,b,val,S,res_x,res_y,sum,g[N],pick[N],m;
vector<int> p;
int find_v(int x)
{
    int sq=sqrt(x);
    for(int i=2;i<=sq;i++)
        while(x%i==0) {p.push_back(i); x/=i;}
    if(x!=1) p.push_back(x);
}
int prepare()
{
    S=oo;
    res_x=a;
    res_y=b;
    val=1;
    p.clear();
    p.push_back(0);p.push_back(oo);
    find_v(a);
    find_v(b);
    sort(p.begin(),p.end());
    int j=1,cnt=1;
    for(int i=1;i<p.size();i++)
        if(p[i]!=p[i-1])
        {
            if((cnt%2==1) && (p[i-1]!=0)) {g[j]=p[i-1];j++; val*=p[i-1];}
            cnt=1;
        } else cnt++;
        m=j-1;
    //cout<<val<<'\n';
}
int update()
{
    int L=1;
    for(int i=1;i<=m;i++)
        if(pick[i]) L*=g[i];
    sum=val/L;
    sum+=L;
    //res=min(res,sum);
    if(sum<S)
    {
        res_x=L;
        res_y=val/L;
        S=sum;
    }
}
int backtrack(int i)
{
    if(i>m) {update();return 0;}
    for(int j=0;j<=1;j++)
    {
        pick[i]=j;
        backtrack(i+1);
    }
    return 0;
}
int process()
{
    backtrack(1);
    cout<<res_x<<' '<<res_y<<'\n';
}
main()
{
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
    cin>>t;
    while(t)
    {
        t--;
        cin>>a>>b;
        prepare();
        process();
    }
}
