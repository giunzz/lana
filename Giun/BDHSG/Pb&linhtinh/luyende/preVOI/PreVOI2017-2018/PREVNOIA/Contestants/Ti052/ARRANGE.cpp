#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 100015;
int n, tmp, res, i, j, t, k;
ll a[N];
ll sum, m;

void sub1()
{
    int t = 1;
    for(int i = 1; i <= n; i ++)
        while(a[i] < m)
    {
        while(t <= n && a[t] <= m) t ++;
        if(a[t] + a[i] < m*2)
        {
//            cout << i << "  " << t << "  " << a[i] << "  " << a[t] << "\n";
            res += abs(t - i) * (a[t] - m);
            a[i] += a[t] - m; a[t] = m;
//            cout << i << "  " << t << "  " << a[i] << "  " << a[t] << "  mn\n";
//            cout << res << "\n";
        }
        else
        {
//            cout << i << "  " << t << "  " << a[i] << "  " << a[t] << "\n";
            res += abs(t - i) * (m - a[i]);
            a[t] -= m - a[i]; a[i] = m;
//            cout << i << "  " << t << "  " << a[i] << "  " << a[t] << "  op\n";
//            cout << res << "\n";
        }
    }
}

void solve()
{
//    cout << res << "  1\n";
    stack<int> pp;
    int vt = 1;
    for(int i = 1; i <= n; i ++)
    {
        if(a[i] >= m + 1) pp.push(i); vt = max(vt, i);
        while(a[i] < m)
        {
            while(vt <= n && a[vt] <= m) vt ++;
            if(pp.empty())
            {
                while(a[i] < m)
                {
                    while(vt <= n && a[vt] <= m) vt ++;
                    res += vt - i; vt ++;
                    a[i] ++;
                }
                continue;
            }
            if(vt > n)
            {
                while(!pp.empty() && a[i] < m)
                {
                    res += i - pp.top();
                    pp.pop(); a[i] ++;
                }
                continue;
            }
            if(vt - i < i - pp.top())
            {
                res += vt - i; a[vt] = m;
                vt ++; a[i] ++;
            }
            else
            {
                res += i - pp.top(); pp.pop();
                a[i] ++;
            }
        }
    }
//    cout << res << "  2\n";
}

int main()
{
//#define file "r"
#define file "ARRANGE"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n ; i ++) cin >> a[i], sum += a[i];
    if(sum % n == 0)
    {
        m = sum / n; sub1();
        cout << res << "\n";
        return 0;
    }
    m = sum / n; t = 1;
    for(int i = 1; i <= n; i ++)
        if(a[i] < m)
    {
        while(t <= n && a[t] <= m + 1) t ++;
        if(t > n)
        {
            solve();
            cout << res << "\n";
            return 0;
        }
        k = m - a[i];
        while(k > 0)
        {
            while(t <= n && a[t] <= m + 1) t ++;
//            cout << t << "  " << i << "  " << a[t] << "  " << a[i] << "\n";
            if(t > n)
            {
                solve();
                cout << res << "\n";
                return 0;
            }
            if(k <= a[t] - m - 1)
            {
                res += k * abs(t - i);
                a[t] -= k;
                k = 0;
            }
            else
            {
                res += (a[t] - m - 1) * abs(t - i);
                k -= a[t] - m - 1;
                a[t] = m + 1; t ++;
            }
        }
    }
    cout << res << "\n";
    return 0;
}
