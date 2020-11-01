#include <bits/stdc++.h>

using namespace std;

const int maxN = 4004;
int N, Delta, Left[maxN], Right[maxN];

int Count, x[maxN], Ans[maxN], A[maxN];
void Try()
{
    int pos = 1, cnt = 0, prv = 0;
    for(int i = 1; i <= N; ++i) if(x[i])
    {
        if(i > 1 && Left[i] - Left[prv] > Delta) return;
        while(pos <= N && Left[i] != Right[pos]) ++pos;
        if(pos > N) return;
        A[++cnt] = Left[i];
        ++pos;
        prv = i;
    }
    //for(int i = 1; i <= cnt; ++i) cerr << A[i] << ' '; cerr << '\n';
    if(cnt > Count)
    {
        Count = cnt;
        for(int i = 1; i <= cnt; ++i) Ans[i] = A[i];
    }
    else if(cnt == Count)
    {
        for(int i = 1; i <= cnt; ++i)
            if(Ans[i] < A[i]) break;
            else if(Ans[i] > A[i]) return;
        for(int i = 1; i <= cnt; ++i) Ans[i] = A[i];
    }
}

void BackTrack(int i)
{
    if(i > N)
    {
        Try();
        return;
    }
    x[i] = 1, BackTrack(i + 1);
    x[i] = 0, BackTrack(i + 1);
}

void sub1()
{
    Count = 0;
    BackTrack(1);
    printf("%d\n", Count);
    for(int i = 1; i <= Count; ++i) printf("%d ", Ans[i]);
}

#define ft first
#define sd second
typedef pair <int, int> II;
typedef pair <II, int> III;
III prv[maxN][maxN];
int dp[maxN][maxN];
void sub2()
{
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= N; ++i)
    for(int j = 1; j <= N; ++j) if(Left[i] == Right[j])
    {
        dp[i][j] = 1; prv[i][j] = III(II(0, 0), 0);
        for(int k = 1; k < i; ++k)
        for(int l = 1; l < j; ++l) if(Left[k] == Right[l] && Left[i] - Left[k] <= Delta)
        {
            if(dp[k][l] + 1 > dp[i][j]) dp[i][j] = dp[k][l] + 1, prv[i][j] = III(II(k, l), Left[k]);
            else if(dp[k][l] + 1 == dp[i][j] && prv[i][j].sd < Left[k]) prv[i][j] = III(II(k, l), Left[k]);
        }
    }
    Count = 0;
    for(int i = 1; i <= N; ++i)
    for(int j = 1; j <= N; ++j)
    {
        int u = i, v = j,res = 0;
        while(u && v)
        {
            A[++res] = Left[u];
            II T = prv[u][v].ft;
            u = T.ft, v = T.sd;
        }
        if(Count < res) for(int i = 1; i <= res; ++i) Ans[i] = A[i], Count = res;
        else if(Count == res)
        {
            int u = Count;
            while(u && Ans[u] == A[u]) --u;
            if(u && Ans[u] > A[u]) continue;
            for(; u; --u) Ans[u] = A[u];
        }
    }
    printf("%d\n", Count);
    for(int i = Count; i; --i) printf("%d ", Ans[i]);
}

#define DU "liondance"
int main()
{
    freopen(DU".inp", "r", stdin);
    freopen(DU".out", "w", stdout);
    scanf("%d%d", &N, &Delta);
    for(int i = 1; i <= N; ++i) scanf("%d", &Left[i]);
    for(int i = 1; i <= N; ++i) scanf("%d", &Right[i]);
    if(N <= 20) sub1();
    else sub2();
}
