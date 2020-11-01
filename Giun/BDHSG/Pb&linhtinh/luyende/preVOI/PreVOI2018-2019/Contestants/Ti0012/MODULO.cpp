#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define fs first
#define sd second
long long mod=1,dacbiet=0;
int A,B,n;
long long k;
vector<int> res;
map<long long,int> q;
void sinh1(int so)
{
    for (int state=0;state<(1<<so);state++)
    {
        long long du=0;
        for (int j=0;j<so;j++) if ((state>>j)&1) du=(du*10+A)%mod; else du=(du*10+B)%mod;
        q[du]=state;
    }
}
void sinh2(int so)
{
    long long Pow=1;
    for (int i=1;i<=n/2;i++) Pow=(Pow*10)%mod;
    for (int state=0;state<(1<<so);state++)
    {
        long long du=0;
        for (int j=0;j<so;j++) if ((state>>j)&1) du=(du*10+A)%mod; else du=(du*10+B)%mod;
        long long tmp=(k-(du*Pow)%mod+mod)%mod;
        long long g=q[tmp];
        if (g!=0 || (g==0 && dacbiet==tmp))
        {
            for (int j=0;j<=so-1;j++) if ((state>>j)&1) res.push_back(A); else res.push_back(B);
            for (int j=0;j<=n/2-1;j++) if ((g>>j)&1) res.push_back(A); else res.push_back(B);
            return;
        }
    }
}
int main()
{
	freopen("MODULO.inp","r",stdin);
	freopen("MODULO.out","w",stdout);
    cin>>A>>B>>n>>k;
    for (int i=1;i<=n;i++) mod*=2;
    for (int i=1;i<=n/2;i++) dacbiet=(dacbiet*10+B)%mod;
    sinh1(n/2);
    sinh2(n-n/2);
    if (res.size()==0) cout<<-1; else for (int i=0;i<res.size();i++) cout<<res[i];
	return 0;
}
