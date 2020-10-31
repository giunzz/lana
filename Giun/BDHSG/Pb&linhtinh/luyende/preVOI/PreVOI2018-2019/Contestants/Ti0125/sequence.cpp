#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
typedef int64_t ll;
using namespace std;

vector<ll> res;
ll n, m, k, a[10001], b[100001];
pair<ll, ll> b1[100001], b2[100001];
bool cmp1(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second < b.second;
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if(a.first == b.first) return a.second  > b.second;
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("sequence.inp", "r", stdin);
    freopen("sequence.out", "w", stdout);
    cin >> m >> n >> k;
    For(i, 1, m)
    {
        cin >> a[i];
        b1[i].first = a[i];
        b1[i].second = i;
    }
    res.push_back(100000000000);
    For(i, 1, n)
    {
        cin >> b[i];
        b2[i].first = b[i];
        b2[i].second = i;
    }
    sort(b1 + 1, b1 + m + 1, cmp);
    sort(b2 + 1, b2 + n + 1, cmp);
    For(i, 0, min(k, m))
    {
        if(k - i > n) continue;
        vector<pair<ll, ll> > gg;
        vector<pair<ll, ll> > gg1;
        For(j, 1, i) gg.push_back(b1[j]);
        For(j, 1, k - i) gg1.push_back(b2[j]);
        sort(gg.begin(), gg.end(), cmp1);
        sort(gg1.begin(), gg1.end(), cmp1);
        int pos = 0, pos1 = 0;
        vector<ll> aa;
        while(pos < gg.size() || pos1 < gg1.size())
        {
            if(pos >= gg.size())
            {
                aa.push_back(gg1[pos1].first);
                pos1++;
                continue;
            }
            if(pos1 >= gg1.size())
            {
                aa.push_back(gg[pos].first);
                pos++;
                continue;
            }
            if(gg[pos].first <= gg1[pos1].first)
            {
                aa.push_back(gg[pos].first);
                pos++;
                continue;
            }
            else
            {
                aa.push_back(gg1[pos1].first);
                pos1++;
                continue;
            }
        }
        if(aa < res)
        {
            res.clear();
            for(int j = 0; j < aa.size(); j++)
            {
                res.push_back(aa[j]);
            }
        }
    }
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
}
