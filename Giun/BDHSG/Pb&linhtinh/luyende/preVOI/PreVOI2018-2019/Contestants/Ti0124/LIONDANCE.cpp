#include <bits/stdc++.h>
using namespace std;

const int maxn = 4010;

long long n, d, a[maxn], b[maxn], c[maxn], cnt, res;
vector < vector < int > > kq[maxn];

bool check()
{
    if(cnt == 0) return false;
    for(int i = 2; i <= cnt; i++)
        if(abs(c[i] - c[i - 1]) > d) return false;
    int j = 1;
    for(int i = 1; i <= n; i++)
    {
        if(j == cnt + 1) return true;
        if(b[i] == c[j]) j++;
    }
    if(j <= cnt) return false;
}

void Try(int x)
{
    if(x > n)
    {
        if(check())
        {
            vector < int > v;
            res = max(res, cnt);
            for(int i = 1; i <= cnt; i++) v.push_back(c[i]);
            kq[cnt].push_back(v);
        }
        return;
    }
    for(int i = 0; i <= 1; i++)
    {
        if(i)
        {
            cnt++;
            c[cnt] = a[x];
        }
        Try(x + 1);
        if(i) cnt--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("LIONDANCE.inp","r",stdin); freopen("LIONDANCE.out","w",stdout);
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    Try(1);
    cout << res << '\n';
    sort(kq[res].begin(), kq[res].end());
    for(int j = 0; j < kq[res][kq[res].size() - 1].size(); j++)
        cout << kq[res][kq[res].size() - 1][j] << ' ';
}
