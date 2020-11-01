#include <bits/stdc++.h>
#define ii pair<long long,long long>
#define fi first
#define se second
using namespace std;
int A,B,N;
long long K;
long long mod=1;
long long mu[47];
ii du1[(1<<20)+7];
ii du2[(1<<20)+7];
int cnt1=0;
int cnt2=0;
void sub1(int i,long long du,string s)
{
    if (i==N)
    {
        if (du==K)
        {
            cout<<s;
            exit(0);
        }
        return;
    }
    sub1(i+1,(du+A*mu[i])%mod,char(A+48)+s);
    sub1(i+1,(du+B*mu[i])%mod,char(B+48)+s);
}
void Try1(int i,long long du,int j)
{
    if (i==(N+1)/2)
    {
        du1[++cnt1].fi=du;
        du1[cnt1].se=j;
        return ;
    }
    Try1(i+1,(du+A*mu[i])%mod,j);
    Try1(i+1,(du+B*mu[i])%mod,j+(1<<i));
}
void Try2(int i,long long du,int j)
{
    if (i==N)
    {
        du2[++cnt2].fi=du;
        du2[cnt2].se=j;
        return ;
    }
    Try2(i+1,(du+A*mu[i])%mod,j);
    Try2(i+1,(du+B*mu[i])%mod,j+(1<<(i-(N+1)/2)));
}
int cnp(long long w)
{
    int l=1,r=cnt1;
    while (l<r)
    {
        int mid=(l+r)/2;
        if (du1[mid].fi==w) return mid;
        else
        if (du1[mid].fi>w) r=mid-1;
        else l=mid+1;
    }
    return -1;
}
void inkq(int bitmask1,int bitmask2)
{
    string s1="";
    while (bitmask2>0)
    {
        if (bitmask2%2==0) s1=char(A+48)+s1;
        else s1=char(B+48)+s1;
        bitmask2/=2;
    }
    while (s1.size()<N-(N+1)/2) s1=char(A+48)+s1;
    string s2="";
    while (bitmask1>0)
    {
        if (bitmask1%2==0) s2=char(A+48)+s2;
        else s2=char(B+48)+s2;
        bitmask1/=2;
    }
    while (s2.size()<(N+1)/2) s2=char(A+48)+s2;
    cout<<s1<<s2;
}
void sub2()
{
    Try1(0,0,0);
    Try2((N+1)/2,0,0);
    sort(du1+1,du1+cnt1+1);
    for (int i=1;i<=cnt2;i++)
    {
        long long w=du2[i].fi;
        int man;
        if (w<=K) man=cnp(K-w);
        else man=cnp(K-w+mod);
        if (man!=-1)
        {
            inkq(du1[man].se,du2[i].se);
            exit(0);
        }
    }
    cout<<-1;
}
int main()
{
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B>>N>>K;
    if (N<=20)
    {
        for (int i=1;i<=N;i++) mod=(mod<<1);
        mu[0]=1;
        for (int i=1;i<=N;i++) mu[i]=(mu[i-1]*10)%mod;
        sub1(0,0,"");
        cout<<-1;
        return 0;
    }
    else
    if (N<=40)
    {
        for (int i=1;i<=N;i++) mod=(mod<<1);
        mu[0]=1;
        for (int i=1;i<=N;i++) mu[i]=(mu[i-1]*10)%mod;
        sub2();
        return 0;
    }
    else cout<<-1;
    return 0;
}
