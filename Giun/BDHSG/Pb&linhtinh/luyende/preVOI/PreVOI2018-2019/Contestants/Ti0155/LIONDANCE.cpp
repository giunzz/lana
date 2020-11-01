#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
#define maxN 4001
#define Bit(x,i) ((x>>i)&1)
using namespace std;
const ll mod=1e9+2277;
const ll base=256;
map<pair<ll,int>,ll>mp;
int n,d,l[maxN],r[maxN],maxBit=0,a[21],b[21];
ll ans;
void Io()
{
    freopen("LIONDANCE.inp","r",stdin);
    freopen("LIONDANCE.out","w",stdout);
}
void Read()
{
    scanf("%d%d",&n,&d);
    For(i,1,n)scanf("%d",&l[i]);
    For(i,1,n)scanf("%d",&r[i]);
}
void Init()
{
    For(x,0,(1<<n)-1)
    {
        bool ok=true;
        int trc=-1,cnt=0;
        ll h=0,p=1;
        For(i,1,n)
            if(Bit(x,i-1)==1)
            {
                if(trc==-1)trc=l[i];
                if(abs(trc-l[i])<=d)
                {
                    h=(h*base+l[i])%mod;
                    cnt++;
                    trc=l[i];
                }
                else
                {
                    ok=false;
                    break;
                }
            }
        if(ok&&mp[{h,cnt}]==0)mp[{h,cnt}]=x;
    }
}
bool Check(ll x,ll y)
{
    int cnt1=0,cnt2=0;
    For(i,1,n)
        if(Bit(x,i-1)==1)
        {
            cnt1++;
            a[cnt1]=l[i];
        }
    For(i,1,n)
        if(Bit(y,i-1)==1)
        {
            cnt2++;
            b[cnt2]=l[i];
        }
    For(i,1,cnt1)
        if(a[i]>b[i])return true;
    return false;
}
void Check()
{
    For(x,0,(1<<n)-1)
    {
        int trc=-1,cnt=0;
        bool ok=true;
        ll h=0,p=1;
        For(i,1,n)
            if(Bit(x,i-1)==1)
            {
                if(trc==-1)trc=r[i];
                if(abs(trc-r[i])<=d)
                {
                    h=(h*base+r[i])%mod;
                    cnt++;
                    trc=r[i];
                }
                else
                {
                    ok=false;
                    break;
                }
            }
        if(ok&&mp[{h,cnt}]!=0)
        {
            ll cur=mp[{h,cnt}];
            if(cnt>maxBit)
            {
                maxBit=cnt;
                ans=cur;
            }
            else
                if(cnt==maxBit&&Check(cur,ans))
                        ans=cur;
        }
    }
}
void Sub1()
{
    Init();
    Check();
    bool ok=false;
    printf("%d\n",maxBit);
    For(i,1,n)
        if(Bit(ans,i-1)==1)
        {
            if(ok)printf(" ");
            printf("%d",l[i]);
            ok=true;
        }
}
int main()
{
    Io();
    Read();
    if(n<=20)Sub1();
    else
        cout<<0;
}
