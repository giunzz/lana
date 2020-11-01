#include<bits/stdc++.h>
#define pii pair<int, int>
#define ppii pair<pii, pii>
#define vi vector<int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define F1(i, a, b) for(int i=a; i<=b; i++)
#define F2(i, a, b) for(int i=a; i>=b; i--)
#define maxn 300
#define mod 1000000009
using namespace std;
template<typename T>
void read(T& x)
{
    x = 0; T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}
ll dp[16][11][11][11], res;
int n, mmax, a[3];
void input()
{
    cin>>n>>mmax;
    F1(i, 0, 2) cin>>a[i];
}
void solve()
{
    if(n<=15)
    {
        dp[0][a[0]][a[1]][a[2]]=1;
        F1(i, 1, n)
        {
            F1(j, 0, 2)
            {
                F1(i1, 0, mmax)
                {
                    F1(i2, 0, mmax)
                    {
                        F1(i3, 0, mmax)
                        {
                            if(j==0)
                            {
                                if(i1==0) continue;
                                dp[i][i1][i2][i3]=(dp[i][i1][i2][i3]+dp[i-1][i1-1][i2][i3])%mod;
                            }
                            if(j==1)
                            {
                                if(i2==0) continue;
                                if(i1==mmax) continue;
                                dp[i][i1][i2][i3]=(dp[i][i1][i2][i3]+dp[i-1][i1+1][i2-1][i3])%mod;
                            }
                            if(j==2)
                            {
                                if(i3==0) continue;
                                if(i1<mmax&&i2<mmax) dp[i][i1][i2][i3]=(dp[i][i1][i2][i3]+dp[i-1][i1+1][i2+1][i3-1])%mod;
                                if(i1+3<=mmax&&i2==0) dp[i][i1][i2][i3]=(dp[i][i1][i2][i3]+dp[i-1][i1+3][i2][i3-1])%mod;
                            }

                        }
                    }
                }
            }
        }
        F1(i, 0, mmax)
        {
            F1(i1, 0, mmax)
            {
                F1(i2, 0, mmax)
                {
                    res=(res+dp[n][i][i1][i2])%mod;
                }
            }
        }
        cout<<res<<endl;
    }
}
main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("ICECREAM.inp", "r", stdin);
    freopen("ICECREAM.out", "w", stdout);
    input();
    solve();
}

