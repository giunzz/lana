#include <bits/stdc++.h>
#define _pb push_back
#define _mp make_pair
#define st first
#define nd second 
#define Pii pair <int, int>
using namespace std;

int m, n, k, x;
int a[3180], b[3180];
int c[3180], d[3180];
// vector < Pii > a, b; 
vector < Pii > u; 

bool cmp(Pii &u, Pii &v)
{
    return u.st < v.st || (u.st == v.st && u.nd >= v.nd);
}
// bool cmp(Pii &u, Pii &v)
// {
//     return u.nd > v.nd || (u.nd == v.nd && u.nd <= v.nd);
// }

main(int argc, char const *argv[])
{
    freopen("SEQUENCE.inp", "r", stdin);
    freopen("SEQUENCE.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++) cin >> x, u._pb(_mp(i, x));
    for(int i = 1; i <= n; i++) cin >> x, u._pb(_mp(i, x));
    // for(int i = 1; i <= n; i++) 
    // {
    //     cin >> b[i];//, a._pb(_mp(x, i));
    //     // for(int j = m; j >= 1; j--)    

    // }
    sort(u.begin(), u.end(), cmp);
    for(int i = 0 ; i < u.size(); i++)  cerr << u[i].nd << ' ';
    // sort(a.begin(), a.end(), cmp);
    // // sort(b.begin(), b.end(), cmp);
    // for(int i = 0; i < m+n; i++) cerr << a[i].st << ',' << a[i].nd << " - ";
    // cerr << '\n';
    // for(int i = 0; i < n; i++) cerr << b[i].st << ',' << b[i].nd << " - ";

    return 0;
}
/**
 * 1 2 1 1 2 1
 * 1 2 1
 * */