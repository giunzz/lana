#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define llint long long

using namespace std;

const int MAXN  =   1000000 + 10;
int n, k, arr[MAXN];
llint sum[MAXN], L[MAXN], R[MAXN];

llint s(int i, int j)
{
    return sum[j] - sum[i - 1];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("Gifts.inp","r",stdin);
    freopen("Gifts.out","w",stdout);

    sum[0] = 0;
    cin>> n>> k;
    FOR(i, 1, n){
        cin>> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    memset(L, -1, sizeof L);
    memset(R, -1, sizeof R);
    FOR(i, k, n)
        L[i] = max(L[i - 1], s(i - k + 1, i));
    FORD(i, n - k + 1, 1)
        R[i] = max(R[i + 1], s(i, i + k - 1));//, cerr<< i <<' '<< R[i] <<'\n';

    llint ans = 0x3c3c3c3c3c3c3c3c;
    FOR(i, 1, n - k + 1){
        llint value = max(L[i - 1],R[i + k]);
        //scerr << L[i - 1] << ' ' << R[i + k] <<' ' << value <<'\n';
        ans = min(ans, value);
    }
    cout<< ans;
}
