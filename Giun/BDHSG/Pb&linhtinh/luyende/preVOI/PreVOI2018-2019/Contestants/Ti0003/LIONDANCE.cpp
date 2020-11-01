#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const int N = 5015;

int n, id, m, tmp, res, k;
int ss, tn, ss1, tn1;
int a[N], b[N], f[N][N], an[N][N];
struct data
{
    int gt;
    vector <int> v;
};
data F[115][115];

data cmp(data a, data b)
{
    data res = a;
    if (a.gt < b.gt) return b;
    if (b.gt < a.gt) return a;
    for (int i = 0; i < a.gt; i++)
    {
        if (a.v[i] < b.v[i]) return b;
        if (b.v[i] < a.v[i]) return a;
    }
    return a;
}


void sub2()
{
    data ss, ans;
    ss.gt = 0, ss.v.clear();
    ans = ss;
    for (int i = 1; i <= n; i++)
    {
        ss .gt = 0, ss.v.clear();
        for (int j = 1; j <= n; j++)
        {
            F[i][j] = F[i - 1][j];
            if (a[i] == b[j])
            {
                F[i][j] = ss;
                F[i][j].gt++, F[i][j].v.push_back(a[i]);
            }
            if (abs(a[i] - b[j]) <= k)
            {
                ss = cmp(ss, F[i - 1][j]);
            }
            ans = cmp(ans, F[i][j]);
            //cout << i <<" "<< j <<" "<< F[i][j].gt <<"\n";
        }
    }
    cout << ans.gt <<"\n";
    for (int i = 0; i < ans.gt; i++)
        cout << ans.v[i] <<" ";
}

int main()
{
    #define file "LIONDANCE"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    if (n <= 100) sub2();

    return 0;
}
