#include <bits/stdc++.h>

using namespace std;
const long N=64;
long long A,B,n,k,b,m,l1,l2;
typedef pair<long long,long long>ii;
vector<long long>v1,v2;
vector<ii>c;
long long n1,n2;
long gb(long x,long i)
{
    return (x>>i)&1;
}
void kt()
{
    b=(1<<n);
    n1=(n/2);
    l1=(1<<n1);
    long long res;
    for(long s=0;s<l1;++s)
    {
        res=0;
        for(long i=0;i<n1;++i)
        {
            if(gb(s,i))
                res=(1ll*res*10+A)%b;
            else
                res=(1ll*res*10+B)%b;
            while(res<0)res+=b;
        }
        v1.push_back(res);
    }
    n2=(n-n1);
    m=1;
    for(long i=1;i<=n2;++i)
        m=(1ll*m*10)%b;
    l2=(1<<n2);
    for(long s=0;s<l2;++s)
    {
        res=0;
        for(long i=0;i<n2;++i)
        {
            if(gb(s,i))
                res=(1ll*res*10+A)%b;
            else
                res=(1ll*res*10+B)%b;
            while(res<0)res+=b;
        }
        v2.push_back(res);
        c.push_back(make_pair(res,s));
    }
}
void inkq(long long x,long long y)
{
    for(long i=0;i<n1;++i)
    {
        if(gb(x,i))
            cout<<A;
        else
            cout<<B;
    }
    for(long i=0;i<n2;++i)
    {
        if(gb(y,i))
            cout<<A;
        else
            cout<<B;
    }
}
void lam()
{
    long long res;
    long pos;
    sort(v2.begin(),v2.end());
    sort(c.begin(),c.end());
    for(long i=0;i<v1.size();++i)
    {
        res=(k-1ll*v1[i]*m)%b;
        while(res<0)res+=b;
        pos=lower_bound(v2.begin(),v2.end(),res)-v2.begin();
        if(pos<l2&&res==v2[pos])
        {
            inkq(i,c[pos].second);
            return;
        }
    }
    cout<<-1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    cin>>A>>B;
    cin>>n>>k;
    kt();
    lam();
    return 0;
}
