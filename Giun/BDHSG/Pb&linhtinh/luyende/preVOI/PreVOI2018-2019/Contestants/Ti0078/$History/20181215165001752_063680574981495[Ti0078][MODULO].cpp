#include<bits/stdc++.h>
using namespace std;

int a,b,n,pos[70],mid;
long long k,p,Po10[70];
struct X
{
    int v[70];
};
map<long long,X> chk1;
map<long long,X> chk2;
vector<long long> existval;

void Get1()
{
    long long val=0;

    X res;

    for(int i=1;i<=n;++i)res.v[i]=0;

    for(int i=1;i<=mid;++i)
    {
        val=(val+pos[i]*Po10[i-1]%p)%p;
        res.v[i]=pos[i];
    }

    chk1[val]=res;

    existval.push_back(val);
}

void QL1(int i)
{
    for(int v=1;v<=2;++v)
    {
        if(v==1)pos[i]=a;
        else pos[i]=b;

        if(i==mid)Get1();
        else QL1(i+1);
    }
}

void Get2()
{
    long long val=0;

    X res;

    for(int i=1;i<=n;++i)res.v[i]=0;

    for(int i=mid+1;i<=n;++i)
    {
        val=(val+pos[i]*Po10[i-1]%p)%p;
        res.v[i]=pos[i];
    }

    chk2[val]=res;
}

void QL2(int i)
{
    for(int v=1;v<=2;++v)
    {
        if(v==1)pos[i]=a;
        else pos[i]=b;

        if(i==n)Get2();
        else QL2(i+1);
    }
}

int main()
{
    freopen("MODULO.INP","r",stdin);
    freopen("MODULO.OUT","w",stdout);

    cin>>a>>b>>n>>k;

    p=1;

    for(int i=1;i<=n;++i)p*=2;

    Po10[0]=1;

    for(int i=1;i<n;++i)
        Po10[i]=(Po10[i-1]*10)%p;

    mid=n/2;

    QL1(1);

    QL2(mid+1);

    for(int i=0;i<existval.size();++i)
    {
        long long t=existval[i];

        if(t<=k)
        {
            if(chk2[k-t].v[n]!=0)
            {
                for(int j=n;j>mid;--j)cout<<chk2[k-t].v[j];
                for(int j=mid;j>0;--j)cout<<chk1[t].v[j];
                exit(0);
            }
        }

        else
        {
            if(chk2[p+k-t].v[n]!=0)
            {
                for(int j=n;j>mid;--j)cout<<chk2[p+k-t].v[j];
                for(int j=mid;j>0;--j)cout<<chk1[t].v[j];
                exit(0);
            }
        }
    }

    cout<<-1;
}
