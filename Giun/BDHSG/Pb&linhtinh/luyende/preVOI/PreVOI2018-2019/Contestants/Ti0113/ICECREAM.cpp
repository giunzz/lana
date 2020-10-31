#include <bits/stdc++.h>
#define f0(i, n) for(int i(0); i < (n); i++)
#define f1(i, n) for(int i(1); i <= n; i++)
#define mod 1000000009

using namespace std;
typedef long long ll;
const int N = 302;

int n, nmax, m50, m1, m2, offset50 = 150, offset1 = 50;
int f[51][201][101][51];

void fix(int &x){
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
}

int calc(int i, int s50, int s1, int s2){
    if(i > n){
        return 1;
    }
    int &ans = f[i][s50][s1][s1];
    if(ans != -1) return ans;
    ans = 0;
    int real50 = s50 - 150 + m50;
    int real1 = s1 - 50 + m1;
    int real2 = s2;
    if(real50 + 1 <= nmax){
        ans = ans + calc(i + 1, s50 + 1, s1, s2);
        fix(ans);
    }
    if(real1 + 1 <= nmax){
        if(real50 > 0){
            ans = ans + calc(i + 1, s50 - 1, s1 + 1, s2);
            fix(ans);
        }
    }
    if(real2 + 1 <= nmax){
        if(real1 >= 1 && real50 >= 1){
            ans = ans + calc(i + 1, s50 - 1, s1 - 1, s2 + 1);
            fix(ans);
        }
        else{
            if(real50 >= 3){
                ans = ans + calc(i + 1, s50 - 3, s1, s2 + 1);
                fix(ans);
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    freopen("ICECREAM.inp", "r", stdin);
    freopen("ICECREAM.out", "w", stdout);

    cin >> n >> nmax;
    cin >> m50 >> m1 >> m2;
    memset(f, -1, sizeof(f));

    cout << calc(1, 150, 50, 0);
}
