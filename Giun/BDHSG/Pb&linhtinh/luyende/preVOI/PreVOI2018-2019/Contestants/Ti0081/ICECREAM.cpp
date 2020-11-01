//Make_Sam^^
#include <bits/stdc++.h>
#define nmax 302
#define MAXX 15001
#define SIZE(f) int(f.size())
#define vti vector<int>
#define pii pair<int, int>
#define vtp vector<pii>
#define vtv vector<vti>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define oo 1000000009
#define MOD 1000000009
#define real double
#define Task "ICECREAM"
#define reset(f) memset(f, 0, sizeof f)
#define resetF(f) memset(f, 1, sizeof f)
#define resetM(f) memset(f, 60, sizeof f)

using namespace std;
typedef unsigned long long ull;
int n, MMAX, M50, M1, M2, nghiem[nmax];
ull gt[nmax], cnt = 0;
int d[4] = {50, 1, 2};
bool avail[MAXX];

bool check()
{
    int a = M50, b = M1, c = M2;
    for (int i = 1; i <= n; i++){
        if (nghiem[i] == 50){
            if (a < MMAX){
                a++;
                continue;
            }
            else return 0;
        }
        if (nghiem[i] == 1){
            if (a > 0 && b < MMAX){
                a--;
                b++;
                continue;
            }
            else return 0;
        }
        if (nghiem[i] == 2){
            if (b > 0 && a > 0 && c < MMAX){
                a--, b--;
                c++;
                continue;
            }
            else
                if (a >= 3 && c < MMAX){
                    a -= 3;
                    c++;
                    continue;
                }
                else return 0;
        }
    }
    return 1;
}

void backtrack(int i)
{
    if (i > n){
        if (check()) cnt = (cnt + 1) % MOD;
        return;
    }

    for (int x = 1; x <= n; x++)
        for (int j = 0; j <= 2; j++)
            if (avail[x]){
                nghiem[i] = d[j];
                avail[x] = 0;
                backtrack(i + 1);
                avail[x] = 1;
            }
}
int main()
{
    freopen(Task".INP", "r", stdin);
    freopen(Task".OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> MMAX >> M50 >> M1 >> M2;
    gt[0] = gt[1] = 1;
    for (int i = 2; i <= n; i++)
        gt[i] = (ull)i * gt[i - 1];
    resetF(avail); reset(nghiem);
    backtrack(1);
    cnt /= gt[n];
    cout << cnt;
}
