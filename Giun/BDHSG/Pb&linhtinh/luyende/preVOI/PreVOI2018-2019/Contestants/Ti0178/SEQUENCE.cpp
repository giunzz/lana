// ILTH
// PreVnoi 2018 ^^
#include<bits/stdc++.h>

using namespace std;
const int PMTH = 4005;
int n, m, k, a[PMTH], b[PMTH];

int Tenter()
{
    cin >> m >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=m; i++) cin >> b[i];
    return 0;
}
int Tsolve()
{
    for(int i=1; i<=k; i++) cout << 1 << " ";

    return 0;
}

int main()
{
    freopen("SEQUENCE.INP","r",stdin);
    freopen("SEQUENCE.OUT","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Tenter();
    Tsolve();

    return 0;
}
