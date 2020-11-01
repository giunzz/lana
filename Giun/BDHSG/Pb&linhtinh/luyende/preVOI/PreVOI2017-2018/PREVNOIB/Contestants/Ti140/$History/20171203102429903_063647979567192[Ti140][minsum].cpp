#include <bits/stdc++.h>
using namespace std;
#define se second
#define fi first
typedef pair<int,int> ii;
int T,num_prime,a,b;
bool prime[1000002];
int p[800001];
vector<ii> v;
void SangNT()
{
    prime[1] = 0;
    for (int i = 2; i < 1000; i++)
        if (prime[i] == 0)
        {
            p[++num_prime] = i;
            for (int j = i*i; j <= 1000000; j += i) prime[i] = 1;
        }
    for (int i = 2; i < 1000000; i++) if (prime[i] == 0) p[++num_prime] = i;
}
void Solve()
{
    scanf("%d%d",&a,&b);
    v.clear();
    for (int i = 1; i <= num_prime; i++)
    {
        if ((a % p[i] == 0) || (b % p[i] == 0))
        {
            v.push_back(ii(p[i],0));
            while (a % p[i] == 0) {a /= p[i]; v.back().se++;}
            while (b % p[i] == 0) {v.back().se++; b /= p[i];}
        }
    }
    if (a > 1) v.push_back(ii(a,1));
    if (b > 1) v.push_back(ii(b,1));
    long long x = 1, y = 1;
    for (int i = 0; i < v.size(); i++)
        if (v[i].se % 2 == 1)
            x *= v[i].fi;
    y = sqrt(x);
    while (x % y != 0) y--;
    cout<<y<<' '<<x/y<<"\n";
}
int main()
{
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
    scanf("%d",&T);
    SangNT();
    for (int i = 1; i <= T; i++) Solve();
}
