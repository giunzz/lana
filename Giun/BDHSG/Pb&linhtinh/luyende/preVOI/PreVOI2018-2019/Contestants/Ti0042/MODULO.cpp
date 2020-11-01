#include<bits/stdc++.h>
#define pii pair<int, int>
#define ppii pair<pii, pii>
#define vi vector<int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define F1(i, a, b) for(int i=a; i<=b; i++)
#define F2(i, a, b) for(int i=a; i>=b; i--)
using namespace std;
template<typename T>
void read(T& x)
{
    x = 0; T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}
int N, a[2], b[2];
ll mod=1, foo=1, K;
bool ok=0;
string s, res;
map<ll, string> m;
map<ll, string>::iterator it;
void input()
{
    cin>>b[0]>>b[1];
    cin>>N>>K;
}
void duyet(int i, int j, ll x)
{
    if(ok) return;
    if(i==a[j]+1)
    {
        if(j==0) m.insert({(x*foo)%mod, s});
        if(j==1)
        {
            it=m.find((mod-(x-K+mod)%mod)%mod);
            if(it!=m.end())
            {
                res=it->se+s;
                ok=1; return;
            }
        }
        return;
    }
    F1(i1, 0, 1)
    {
        s[i-1]=(char)(b[i1]+48);
        duyet(i+1, j, (x*10+(ll)b[i1])%mod);
    }
}
void duyet1(int i, ll x)
{
    if(ok) return;
    if(i==N+1)
    {
        if(x==K)
        {
            ok=1;
            res=s;
        }
        return ;
    }
    F1(i1, 0, 1)
    {
        s[i-1]=(char)(b[i1]+48);
        duyet1(i+1, (x*10+(ll)b[i1])%mod);
    }
}
void solve()
{
    F1(i, 1, N)
    if(N==1)
    {
        if(b[0]%2==K)
        {
            cout<<b[0]<<endl;
            return;
        }
        if(b[1]%2==K)
        {
            cout<<b[1]<<endl;
            return;
        }
        cout<<-1<<endl;
        return;
    }
    if(N<=20)
    {
        F1(i, 1, N) mod=mod*2;
        F1(i, 1, N) s+='0';
        duyet1(1, 0);
        if(!ok) cout<<-1<<endl;
        else cout<<res<<endl;
        return ;
    }
    if(N<=40)
    {
        F1(i, 1, N) mod=mod*2;
        a[0]=N/2; a[1]=N;
        F1(i, 1, a[1]-a[0]) foo=(foo*10)%mod;
        F1(i, 1, N/2) s=s+'0';
        duyet(1, 0, 0);
        if(N%2==1) s=s+'0';
        duyet(N/2+1, 1, 0);
        if(ok==0) cout<<-1<<endl;
        else cout<<res<<endl;
        return;
    }
}
main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("MODULO.inp", "r", stdin);
    freopen("MODULO.out", "w", stdout);
    input();
    solve();
}

