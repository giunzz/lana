#include <bits/stdc++.h>
#define pii pair<int, int>
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
using namespace std;
int t, a, b, p, q, dd[1005][1005], d = 0;
priority_queue<pii> pe;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MINSUM.inp", "r", stdin);
    freopen("MINSUM.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        d++;
        cin >> a >> b;
        pe.push(mp(-a-b, a));
        p = q = 1e9;
        while(!pe.empty())
        {
            int x = pe.top().sd, y = -pe.top().ft - x;
            pe.pop();
            dd[x][y] = d;
            for(int i = 2; i <= max(x, y); ++i)
            {
                if(!(x%i) && !(y%i) && dd[x/i][y/i] < d) pe.push(mp(-x/i-y/i, x/i));
                if(!(x%i) && x/i+y*i <= x+y && dd[x/i][y*i] < d) pe.push(mp(-x/i-y*i, x/i));
                if(!(y%i) && x*i+y/i <= x+y && dd[x*i][y/i] < d) pe.push(mp(-x*i-y/i, x*i));
            }
            if(p+q > x+y) p = x, q = y;
        }
        cout << p << " " << q << "\n";
    }
}
