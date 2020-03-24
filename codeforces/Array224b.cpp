#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define debug(x) cout<<#x<<": "<<x<<endl
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))
#define PI 3.1415926535897932385
#define INF 1000111222
#define EPS 1e-7
#define MAXN 100005
#define MOD 1000000007
#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;

template<typename T>inline T gcd(T a, T b){if (b == 0)return a;else return gcd(b, a % b);}
template<typename T>inline T lcm(T a, T b){return (a * b) / gcd(a, b);}

int n, t, m, a[MAXN + 5], b[MAXN+5], c, k, l, r;

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    scanf("%d%d", &n, &k);
    memset(b, 0, sizeof b);
    FOR(i,1,n) scanf("%d", &a[i]);
    r = c = 0;
    l = 1;
    FOR(i,1,n){
        if(b[a[i]]){
           b[a[i]] = i;
           if(a[i] == a[l]){
                while(b[a[l]] != l) l++;    
            }  
            continue;       
        }
        b[a[i]] = i;
        c++;
        if(c==k){
            r = i;
            break;    
        }    
    }
    if(r) printf("%d %d\n",l,r);
    else printf("-1 -1\n");
    return 0;
}