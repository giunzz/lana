#include<bits/stdc++.h>

using namespace std;
#define brokenheart "SEQUENCE"
#define pb	push_back
typedef long double ld;
typedef long long ll;
const int maxn = 6e3 + 5;

int n , m , k , a[maxn] , b[maxn];

vector<int> f[maxn] , f1[maxn];

inline void Minimize(vector<int> & x , vector<int> & y)
{
    int sz;
    assert((sz = x.size()) == (int)y.size());
    for(int i = 0 ; i < sz ; ++i)
        if(x[i] > y[i])x = y;
        else if(x[i] < y[i])return;
}

struct TNode{
    int val , ab , pos;
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if(fopen(brokenheart".INP","r"))
        freopen(brokenheart".INP", "r",stdin) ,
        freopen(brokenheart".OUT", "w",stdout);
    cin >> m >> n >> k;
    for(int i = 1 ; i <= m ; ++i)cin >> a[i];
    for(int j = 1 ; j <= n ; ++j)cin >> b[j];
    for(int i = 1 ; i <= m ; ++i){
        f[i] = f[i - 1];
        f[i].pb(a[i]);
        for(int j = i - 1 ; j >= 1 ; --j)
        {
            vector<int> s = f[j - 1];
            s.pb(a[i]);
            Minimize(f[j],s);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        f1[i] = f1[i - 1];
        f1[i].pb(b[i]);
        for(int j = i - 1 ; j >= 1 ; --j)
        {
            vector<int> s = f1[j - 1];
            s.pb(b[i]);
            Minimize(f1[j],s);
        }
    }
    vector<int> res(k , (int)1e9);
    for(int i = k - n ; i <= m ; ++i){
        vector<int> s;
        int t = 0;
        for(int j = 0 ; j < i ;  ++j){
            while(true)
            {
                if(t < k - i && f[i][j] > f1[k - i][t]){
                    s.pb(f1[k - i][t]) , ++t;
                }
                else {
                    s.pb(f[i][j]);
                    break;
                }
            }
        }
        while(t < k - i)s.pb(f1[k - i][t]) ,++t;
//        for(int c : s)cout << c << " ";
//        cout << endl;
        Minimize(res,s);
    }
    for(int c : res)cout << c << " ";
}
