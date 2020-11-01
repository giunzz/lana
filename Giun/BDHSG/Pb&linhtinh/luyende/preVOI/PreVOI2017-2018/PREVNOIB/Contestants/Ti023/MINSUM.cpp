#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
const int nmax = 1e6 + 50;
ll T,a,b,x[nmax],s1,s2,minn,kq1,kq2;
map <ll,ll> ma;
vector <ll> t;

void phantich(ll x)
{
    ll i = 2;
    while(x > 1)
    {
        if(x % i == 0)
        {
            ma[i]++;
            x /= i;
        }
        else i++;
    }
}

void tao()
{
    for(map <ll,ll> :: iterator it = ma.begin(); it != ma.end(); it++)
        if((it -> se) % 2 != 0)t.push_back(it -> fi);
    ma.clear();
    s1 = 1;
    s2 = 1;
    minn = 1e18 + 50;
    kq1 = a,kq2 = b;
}

void BT(int u)
{
    if(u == t.size()+1)
    {
        if(s1 + s2 < minn)
        {
            minn = s1 + s2;
            kq1 = s1;
            kq2 = s2;
        }
        return;
    }
    for(int i=0;i<=1;i++)
    {
        if(i == 1)
        {
            s1 = s1*(t[u-1]);
            BT(u+1);
            s1 = s1/(t[u-1]);
        }
        else
        {
            s2 = s2*(t[u-1]);
            BT(u+1);
            s2 = s2/(t[u-1]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MINSUM.inp","r",stdin);
    freopen("MINSUM.out","w",stdout);
    cin >> T;
    while(T--)
    {
        cin >> a >> b;
        t.clear();
        phantich(a);
        phantich(b);
        tao();
        BT(1);
        cout << kq1 << " " << kq2 << endl;
    }

    return 0;
}
