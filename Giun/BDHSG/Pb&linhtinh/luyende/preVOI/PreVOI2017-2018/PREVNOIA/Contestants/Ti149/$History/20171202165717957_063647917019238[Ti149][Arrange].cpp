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

const int MAXN  =   100000 + 10;
int n;
llint dp[2000 + 10][2000 + 10], arr[MAXN];//, L[MAXN], R[MAXN];
llint sum = 0,  value, x, y;

void Read()
{
    cin>> n;
    FOR(i, 1, n){
        cin>> arr[i];
        sum+= arr[i];
    }
    value = sum/ n ;
    y = sum - value * n;
    x = n - y;
}

int sp()
{
    llint ans = 0;
    FOR(i, 1, n)
        ans+= abs(arr[i] -  value);
    return ans/2;
}
llint Buff()
{
    llint ans = 0;
    for(int len = 1; len <= n; len++){
        for(int i = 1; i <= n; i++){
            int L = i, R = i + len;
            if (R > n) continue;
            if (arr[L] < value && arr[R] > value + 1){
                if ((value - arr[L]) >= abs((value + 1) - arr[R])){
                    ans+= len * (value + 1) - arr[R];
                    arr[L] += (value + 1) - arr[R];
                    arr[R] = value + 1;
                }
            }
            if (arr[R] < value && arr[L] > value + 1){
                if ((value - arr[L]) >= abs((value + 1) - arr[R])){
                    ans+= len * (value + 1) - arr[R];
                    arr[L] += (value + 1) - arr[R];
                    arr[R] = value + 1;
                }
            }

        }
    }
    return ans;
}
int main()
{
    freopen("Arrange.inp","r",stdin);
    //freopen("Arrange.out","w",stdout);

    Read();
    if (y == 0){
        cout<< sp();
        return 0;
    }
    cout<< Buff();
    return 0;
}
