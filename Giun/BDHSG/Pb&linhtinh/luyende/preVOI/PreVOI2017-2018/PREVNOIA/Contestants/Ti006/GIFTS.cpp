    /*Design by Dinh Viet Anh(JOKER)*/
//___________________________________$$$$$$$$$
//___________________________________$$$___$
//___________________________$$$____$$$$
//_________________________$$$$$$$__$$$$$$$$$$$
//_______________________$$$$$$$$$___$$$$$$$$$$$
//_______________________$$$___$______$$$$$$$$$$
//________________$$$$__$$$$_________________$$$
//_____________$__$$$$__$$$$$$$$$$$_____$____$$$
//__________$$$___$$$$___$$$$$$$$$$$__$$$$__$$$$
//_________$$$$___$$$$$___$$$$$$$$$$__$$$$$$$$$
//____$____$$$_____$$$$__________$$$___$$$$$$$
//__$$$$__$$$$_____$$$$_____$____$$$_____$
//__$$$$__$$$_______$$$$__$$$$$$$$$$
//___$$$$$$$$$______$$$$__$$$$$$$$$
//___$$$$$$$$$$_____$$$$___$$$$$$
//___$$$$$$$$$$$_____$$$
//____$$$$$$$$$$$____$$$$
//____$$$$$__$$$$$___$$$
//____$$$$$___$$$$$$
//____$$$$$____$$$
//_____$$$$
//_____$$$$
//_____$$$$
#include <bits/stdc++.h>
#define maxn 1000005
#define maxm 10000005
#define maxc 1000000007
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int, int>
#define fort(i, a, b) for(int i = (a); i <= (b); i++)
#define ford(i, a, b) for(int i = (a); i >= (b); i--)
#define Task "gifts"
#define stop1 {cout << "-1\n"; return;}
#define stop2 {cout << "NO\n"; return;}
#define stop3 {cout << "YES\n"; return;}
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

using namespace std;

int n, k;
int a[maxn];
ll s[maxn], res, truoc[maxn], sau[maxn];

void setup()
{
    cin >> n >> k;
    fort(i, 1, n)
    {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    ford(i, n - k + 1, 1)
        sau[i] = max(sau[i+1], s[i+k-1] - s[i-1]);
    fort(i, 1, n-k+1)
        truoc[i] = max(truoc[i-1], s[i+k-1] - s[i-1]);
}

void work()
{
    ll ans = 1ll*maxc*maxc;
    fort(i, 1, n-k+1)
    {
        ll res = max(truoc[i-1], sau[i+k]);
        ans = min(ans, res);
    }
    cout << ans;
}

int main()
{
    fast
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    work();
    return 0;
}
