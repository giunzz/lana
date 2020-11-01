//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 105
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "SEQUENCE"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m, k, a[mn], b[mn], c[mn];
typedef vector< int> data;
data u[mn][mn], v[mn][mn], res;

data cmp(data A, data B, int C)
{
    if(B.size())
    forr(i, 0, B.size()- 1)
    {
        if(A[i]< B[i]) return A;
        if(A[i]> B[i]){
            B.pb(C);
            return B;
        }
    }
    int E= A[A.size()- 1];
    if(E< C) return A;
    B.pb(C);
    return B;
}

data ans(data D, data B, data C)
{
    data A[mn][mn];

    int N= B.size(), M= C.size();

//    for(auto z: B) cout<< z<< " ";
//    cout<< "\n";
//    for(auto z: C) cout<< z<< " ";
//    cout<< "\n";

    forr(i, 0, N)
        forr(j, 0, M)
            A[i][j].clear();

    forr(i, 1, N){
        for(auto z: A[i- 1][0]) A[i][0].pb(z);
        A[i][0].pb(B[i- 1]);
    }

    forr(i, 1, M)
    {
        for(auto z: A[0][i- 1]) A[0][i].pb(z);
        A[0][i].pb(C[i- 1]);
    }

    forr(i, 1, N)
        forr(j, 1, M)
        {
            A[i- 1][j].pb(B[i- 1]);
            A[i][j]= cmp(A[i- 1][j], A[i][j- 1], C[j- 1]);
//            cout<< i<< " "<< j<< " ";
//            for(auto z: A[i][j]) cout<< z<< " ";
//            cout<< "\n";
            A[i- 1][j].pop_back();
        }

    //for(auto z: A[N][M]) cout<< z<< " ";

    int E= A[N][M][A[N][M].size()- 1];
    A[N][M].pop_back();
    return cmp(D, A[N][M], E);
    //return A[0][0];
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> m>> k;

    forr(i, 1, n)
    {
        cin>> a[i];
        //v[i][i].pb()
        forr(j, 1, i) v[i][i].pb(a[j]);

        forr(j, 0, i- 1)
        {
            for(auto z: v[i- 1][j])
               v[i][j].pb(z);
            if(j) v[i][j]= cmp(v[i][j], v[i- 1][j- 1], a[i]);
        }
    }

    forr(i, 1, m)
    {
        cin>> b[i];
        forr(j, 1, i) u[i][i].pb(b[j]);

        forr(j, 0, i- 1)
        {
            for(auto z: u[i- 1][j])
                u[i][j].pb(z);
            if(j) u[i][j]= cmp(u[i][j], u[i- 1][j- 1], b[i]);
        }
    }

    //for(auto z: u[m][0]) cout<< z<<" ";

    forr(i, 1, k) res.pb(oo);
    forr(i, max(0, k- m), min(n, k))
        res= ans(res, v[n][i], u[m][k- i]);

    //res= ans(res, v[n][5], u[m][4]);

    for(auto z: res) cout<< z<< " ";
    return 0;
}
