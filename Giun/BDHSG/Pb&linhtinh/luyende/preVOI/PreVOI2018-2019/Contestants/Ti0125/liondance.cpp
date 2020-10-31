#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
typedef int64_t ll;
using namespace std;

ll l[10001], r[10001], b[1001], n, d;
vector<ll> res;
void check()
{
    vector<ll> rr;
    int tg = 0;
    For(i, 1, n)
    {
        if(b[i] == 1)
        {
            tg++;
            rr.push_back(l[i]);
        }
    }
    for(int j = 1; j < rr.size(); j++) if(rr[j] - rr[j - 1] > d) return;
    int pos = 1;
    for(int j = 0; j < rr.size(); j++)
    {
        bool ok = false;
        For(k, pos, n)
        {
            if(rr[j] == r[k])
            {
                ok = true;
                pos = k + 1;
                break;
            }
        }
        if(!ok) return;
    }
    if(tg > res.size())
    {
        res.clear();
        For(i, 1, n)
        {
            if(b[i] == 1) res.push_back(l[i]);
        }
    }
    else
    {
        if(tg == res.size())
        {
            vector<ll> res1;
            For(i, 1, n)
            {
                if(b[i] == 1) res1.push_back(l[i]);
            }
            if(res1 > res)
            {
                res.clear();
                for(int i = 0; i < res1.size(); i++)
                {
                    res.push_back(res1[i]);
                }
            }
        }
    }
}

void Try(int k)
{
    if(k > n)
    {
        check();
        return;
    }
    For(i, 0, 1)
    {
        b[k] = i;
        Try(k + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("liondance.inp", "r", stdin);
    freopen("liondance.out", "w", stdout);
    cin >> n >> d;
    For(i, 1, n) cin >> l[i];
    For(i, 1, n) cin >> r[i];
    Try(1);
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
}
