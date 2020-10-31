#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i<b; i++)
typedef long long ll;
const int N=1e6+5;
int n,k,dx[N],d,kt;
ll l,r,g,kq,s[N];
vector<int>v;
int main()
{
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    FOR(i,1,n)
    {
        cin >> s[i];
        s[i]+=s[i-1];
        if (i>=k) r=max(r,s[i]-s[i-k]);
    }
    l=1;
    kq=r+1;
    while (l<=r)
    {
        g=(l+r)/2;
        v.clear();
        FOR(i,k,n) if (s[i]-s[i-k]>=g) v.push_back(i);
        d=1;
        kt=v[0];
        FORD(i,1,v.size())
        {
            if (v[i]-kt>=2*k-1)
            {
                kt=v[i];
                d++;
            }
        }
        if (d>=2) l=g+1;
        else
        {
            r=g-1;
            kq=g-1;
        }
    }
    cout << kq;
}
