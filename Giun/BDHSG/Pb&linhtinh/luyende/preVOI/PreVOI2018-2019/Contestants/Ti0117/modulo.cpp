#include <bits/stdc++.h>
#define ll long long

using namespace std;

int a,b,n,k,ok;
ll M,p;
string res;
char A,B;

void bt(ll x,string s)
{
    if (ok) return;
    if (s.length()==n)
    {
        if (x==k)
        {
            res=s;
            ok=1;
        }
        return;
    }
    string t1=s+A;
    string t2=s+B;
    bt(((x*10)%M+a%M)%M,t1);
    bt(((x*10)%M+b%M)%M,t2);
}

int main()
{
    ios::sync_with_stdio(0);
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    cin.tie(0);cout.tie(0);
    cin>>a>>b;A=char(a+48);B=char(b+48);
    cin>>n>>k;ok=0;M=(1<<n);
    res="-1";
    bt(0,"");
    cout<<res;
    return 0;
}
