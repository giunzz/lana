#include <bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
const long long oo=1e18;
long long A,B,M,g;
long long sum;
vector<ii> fat;
int cnt;
void factorize(int S)
{
    if(S%2==0)
    {
        while(S%2==0)
        {
            S/=2;
            cnt++;
        }
        fat.push_back(ii(2,cnt));
    }
    for(int i=3;i*i<=S;i+=2)
    {
        if(S%i==0)
        {
            cnt=0;
            while(S%i==0)
            {
                S/=i;
                cnt++;
            }
            fat.push_back(ii(i,cnt));
        }
    }
    if(S>1)
        fat.push_back(ii(S,1));
}
void dedupe()
{
    for(int i=1;i<fat.size();++i)
    {
        if(fat[i].first==fat[i-1].first)
        {
            fat[i].second+=fat[i-1].second;
            fat[i-1].first=1;
            fat[i-1].second=0;
        }
    }
}
long long Power(long long X,int n)
{
    if(n==0)
        return 1;
    long long tp=Power(X,n>>1);
    if(n&1)
        tp*=X;
    return tp;
}
bool cmp(ii a,ii b)
{
    return a.second>b.second||(a.second==b.second and a.first>b.first);
}
void greedy()
{
    factorize(A);
    factorize(B);
    sort(fat.begin(),fat.end());
    dedupe();
    M=1;
    for(int i=0;i<=fat.size();++i)
    {
        fat[i].second%=2;
        if(fat[i].second)
            M*=fat[i].first;
    }
    sort(fat.begin(),fat.end(),cmp);
    while(fat.back().second==0)
        fat.pop_back();
    long long A_=1;
    for(int i=0,j=fat.size()-1;i<fat.size();++i)
    {
        A_*=fat[i].first;
        if(sum>M/A_+A_)
        {
            sum=M/A_+A_;
            A=A_;
            B=M/A_;
        }

        if(j<=i)
            break;
        A_/=fat[i].first;
        A_*=fat[j].first;
        if(sum>M/A_+A_)
        {
            sum=M/A_+A_;
            A=A_;
            B=M/A_;
        }
        A_*=fat[i].first;
        if(sum>M/A_+A_)
        {
            sum=M/A_+A_;
            A=A_;
            B=M/A_;
        }
        --j;
    }
}
void execute()
{
    sum=oo;
    fat.clear();
    scanf("%lld%lld",&A,&B);
    if(A==0 and B!=0)
    {
        cout<<0<<' '<<1<<'\n';
        return ;
    }
    if(A!=0 and B==0)
    {
        cout<<1<<' '<<0<<'\n';
        return ;
    }
    if(!A and !B)
    {
        cout<<0<<' '<<0<<'\n';
        return ;
    }
    g=__gcd(A,B);
    A/=g;
    B/=g;
    M=A*B;
    if(sqrt(M)>2e5)
    {
        greedy();
        cout<<A<<' '<<B<<'\n';
        return ;
    }
    factorize(A);
    factorize(B);
    M=1;
    dedupe();
    for(int i=0;i<fat.size();++i)
    {
        fat[i].second%=2;
        //cout<<fat[i].first<<' '<<fat[i].second<<'\n';
        M*=Power(fat[i].first,fat[i].second);
    }
    //cout<<M<<'\n';
    sum=oo;
    for(int i=1;i*i<=M;++i)
    {
        if(M%i)continue;
        if(i+M/i<sum)
        {
            A=i;
            B=M/i;
            sum=A+B;
        }
    }
    cout<<A<<' '<<B<<'\n';
}
int T;
#define filename "MINSUM"
void io()
{
    freopen(filename".INP","r",stdin);
    freopen(filename".OUT","w",stdout);
}
main()
{
    io();
    scanf("%d",&T);
    for(;T;--T)
        execute();
}
