#include<bits/stdc++.h>
#define maxn 105
using namespace std;

int F[maxn][maxn][maxn], n, delta, L[maxn], R[maxn];
pair<int,pair<int,int> > trace[maxn][maxn][maxn];

void truy(int u, int v, int hs)
{
    cout << L[hs] << " ";
    if(trace[u][v][hs].first)
    {
        truy(trace[u][v][hs].first, trace[u][v][hs].second.first, trace[u][v][hs].second.second);
    }
}

int main()
{
    freopen("LIONDANCE.inp","r",stdin);
    freopen("LIONDANCE.out","w",stdout);

    cin >> n >> delta;
    for(int i=1;i<=n;i++) cin >> L[i];
    for(int i=1;i<=n;i++) cin >> R[i];

    if(n <= 300)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    F[i][j][k] = -1000000007;
                }
            }
        }

        for(int i=n;i>=1;i--)
        {
            for(int j=n;j>=1;j--)
            {
                for(int k=n;k>i;k--)
                {
                    if(F[i+1][j][k] > F[i][j+1][k])
                    {
                        F[i][j][k] = F[i+1][j][k];
                        trace[i][j][k] = trace[i+1][j][k];
                    }
                    else
                    {
                        F[i][j][k] = F[i][j+1][k];
                        trace[i][j][k] = trace[i][j+1][k];
                    }

                }
                if(L[i] == R[j])
                {
                    F[i][j][i] = 1;
                    trace[i][j][i] = make_pair(0, make_pair(0, 0));
                    for(int k=n;k>i;k--)
                    {
                        if(abs(L[i] - L[k]) <= delta)
                        {
                            if(F[i][j][i] < F[i+1][j+1][k] + 1)
                            {
                                F[i][j][i] = F[i+1][j+1][k] + 1;
                                trace[i][j][i] = make_pair(i+1, make_pair(j+1, k));
                            }
                        }
                    }
                }
            }
        }

        int hs = 0;
        for(int k=n;k>=1;k--)
        {
            if(F[1][1][k] > F[1][1][hs])
            {
                hs = k;
            }
            else if(F[1][1][k] == F[1][1][hs] && L[k] > L[hs])
            {
                hs = k;
            }
        }
        cout << F[1][1][hs] << endl;

        truy(1, 1, hs);
    }
    else cout << 0;
}
