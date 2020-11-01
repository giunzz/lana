#include <bits/stdc++.h>
using namespace std;

int n, Delta;
int L[4008], R[4008];
int a[28];
vector < vector<int> > u;
vector < vector<int> > v;
vector <int> tmpL;
vector <int> tmpR;
vector <int> x;
int c[4008];
// map 

void _save()
{
    tmpL.clear(); tmpR.clear();
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == 1)   tmpL.push_back(L[i]), tmpR.push_back(R[i]);
        if((int)tmpL.size() > 1 && abs(tmpL[tmpL.size()-1] - tmpL[tmpL.size()-2]) > Delta) return;
        if((int)tmpR.size() > 1 && abs(tmpR[tmpR.size()-1] - tmpR[tmpR.size()-2]) > Delta) return;
    }
    u.push_back(tmpL);  v.push_back(tmpR);
}

void _try(int i)
{
    for(int j = 0; j <= 1; j++)
    {
        a[i] = j;
        if(i == n)  _save();
        else    _try(i+1);
    }
}

void _bruteForce()
{
    _try(1);
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());
    int maxx = 0;
    vector < vector <int> > res;
    for(int i = 0; i < u.size(); i++)
    {
        if(binary_search(v.begin(), v.end(), u[i]) && u[i].size() >= maxx)
        {
            if((int)u[i].size() > maxx) {res.clear(); maxx = u[i].size();}
            res.push_back(u[i]);
        }
    }
    sort(res.begin(), res.end());
    // for(int i = 0; i < res.size(); i++)
    // {
    //     for(int j = 0; j < res[i].size(); j++) cerr << res[i][j] << ' ';
    //     cerr << '\n';
    // }
    cout << (int)res[res.size()-1].size() << '\n';
    for(int i = 0; i < (int)res[res.size()-1].size(); i++)
        cout << res[res.size()-1][i] << ' ';
        // cerr << res[res.size()-1][i] << ' ';
}

int f[4008];
int Trace[4008];

void _inm(int u)
{
    if(Trace[u] != 0)   _inm(Trace[u]);
    cout << L[x[u]] << ' ';
}

void _lucky()
{
    int pos;
    vector < vector <int> > Res;
    int maxx = INT_MIN;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(L[j] == R[i] && c[j] == 0)   {x.push_back(j); c[j] = 1; break;}
    for(int i = 1; i < x.size(); i++)
        for(int j = 0; j < i; j++)
            if(x[j] < x[i] && f[j]+1 > f[i])    {f[i] = f[j]+1; Trace[i] = j; if(f[i] >= maxx){maxx = f[i]; pos = i;} }
    cout << maxx+1 << '\n';
    for(int i = 0; i <= n; i++) if(Trace[i] == 0){cout << L[x[i]] << ' '; break;}
    _inm(pos);
    // int tmp = 0;
    // for(int i = 0; i <= )
    // for(int i = 0; i < x.size(); i++)
    //     cerr << f[i] << ' ';
        // cerr << x[i] << ' ';
}

main(int argc, char const *argv[])
{
    freopen("LIONDANCE.inp", "r", stdin);
    freopen("LIONDANCE.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> Delta;
    for(int i = 1; i <= n; i++) cin >> L[i];
    for(int i = 1; i <= n; i++) cin >> R[i];
    if(n <= 20) _bruteForce();
    else    _lucky();
    // else    
    return 0;
}

/**
 * 2,1-3,4-2,3-1,2-7,8-4,6-5,7-9,5
 * 
 * 1   4   3   2   8   6   7   5
 * 2   3   2   1   7   4   5   9
 * 
    for(int i = 0; i < n; i++)
    {
        int pos = upper_bound(v.begin(), v.end(), u[i]) - v.begin();
        v[pos] = u[i]; f[i] = pos+1; maxx = max(maxx, f[i]);
    }
 * */
