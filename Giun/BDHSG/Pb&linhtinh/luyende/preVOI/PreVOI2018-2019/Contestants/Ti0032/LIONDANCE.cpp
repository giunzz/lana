//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 105
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "LIONDANCE"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m= 0, del, a[mn], b[mn], l[mn], r[mn], h[4* mn], ROOT[4* mn];
typedef vector< int> data;
data v[mn][mn][4* mn], res;


data cmp(data A, data B)
{
    if(A.size()> B.size()) return A;
    if(A.size()< B.size()) return B;
    if(B.size())
        forr(i, 0, A.size()- 1)
        {
            if(A[i]> B[i]) return A;
            if(A[i]< B[i]) return B;
        }
    return A;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> del;

    forr(i, 1, n)
    {
        cin>> a[i];
        l[i]= a[i]- del, r[i]= a[i]+ del;
        h[++m]= a[i], h[++m]= a[i]- del, h[++m]= a[i]+ del;
    }

    forr(i, 1, n)
    {
        cin>> b[i];
        h[++m]= b[i];
    }

    sort(h+ 1, h+ m+ 1);

    forr(i, 1, n)
    {
        int id= lower_bound(h+ 1, h+ m+ 1, a[i])- h;
        ROOT[id]= a[i], a[i]= id;
        b[i]= lower_bound(h+ 1, h+ m+ 1, b[i])- h;
        l[i]= lower_bound(h+ 1, h+ m+ 1, l[i])- h;
        r[i]= lower_bound(h+ 1, h+ m+ 1, r[i])- h;
    }

    forr(i, 1, n)
        forr(j, 1, n)
        {
            forr(k, 1, m){
                data ans;
                ans.clear();
                for(auto z: v[i- 1][j][k]) v[i][j][k].pb(z);
                for(auto z: v[i][j- 1][k]) ans.pb(z);
                v[i][j][k]= cmp(v[i][j][k], ans);
            }
            if(a[i]== b[j]){
                forr(k, l[i], r[i])
                {
                    v[i- 1][j- 1][k].pb(a[i]);
                    v[i][j][a[i]]= cmp(v[i][j][a[i]], v[i- 1][j- 1][k]);
                    v[i- 1][j- 1][k].pop_back();
                }
//                cout<< i<< " "<< j<< " ";
//                    for(auto z: v[i][j][a[i]]) cout<< z<< " ";
//                    cout<< "\n";
            }
        }

    res= v[n][n][a[1]];
    forr(i, 2, n) res= cmp(res, v[n][n][a[i]]);

    cout<< res.size()<< "\n";
    for(auto z: res) cout<< ROOT[z]<< " ";

    return 0;
}
