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
#define maxn 100005
#define maxm 10000005
#define maxc 1000000007
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int, int>
#define fort(i, a, b) for(int i = (a); i <= (b); i++)
#define ford(i, a, b) for(int i = (a); i >= (b); i--)
#define Task "arrange"
#define stop1 {cout << "-1\n"; return;}
#define stop2 {cout << "NO\n"; return;}
#define stop3 {cout << "YES\n"; return;}
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define mid (l+r)>>1

using namespace std;

ll n, a[maxn], cnt[maxn*10], maxa = 0, mina = maxn*10, res;
ll sum;

void setup()
{
    cin >> n;
    fort(i, 1, n)
    {
        cin >> a[i];
        sum += a[i];
        cnt[a[i]] ++;
        mina = min(mina, a[i]);
        maxa = max(maxa, a[i]);
    }
}

void work()
{
    if(maxa - mina <= 1)
    {
        cout << 0;
        return;
    }
    if(sum % n == 0)
    {
        ll tb = sum / n;
        int ct = 1;
        fort(i, 1, n)
            if(a[i] < tb)
            {
                ct = i;
                break;
            }
        fort(i, 1, n)
            while(a[i] > tb)
            {
                res += min(a[i] - tb, tb - a[ct]) * abs(i - ct);
                a[ct] += min(a[i] - tb, tb - a[ct]);
                a[i] -= min(a[i] - tb, tb - a[ct]);
                while(a[ct] >= tb && ct <= n) ct++;
                if(ct == n+1) break;
            }
        cout << res;
        return;
    }
    ll minx = sum / n;
    ll maxx = minx + 1;
    int maxx_cnt = sum % n;

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
