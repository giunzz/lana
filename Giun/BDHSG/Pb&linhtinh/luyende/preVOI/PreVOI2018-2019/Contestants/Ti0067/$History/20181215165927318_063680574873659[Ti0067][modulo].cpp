#include <bits/stdc++.h>
#define LL unsigned long long
#define NUM first.first
#define MODULO first.second
#define COUNT second

using namespace std;
typedef pair <int, LL> II;
typedef pair <II, int> III;

const III Null = III(II(0, 0), 0);
int A[3], N, M, ans[65];
map <III, III> prv;
LL MOD, K;

void BFS()
{
    deque <III> Q;
    for(int i = 1; i <= M; ++i) Q.push_back(III(II(A[i], A[i] % MOD), 1));
    while(!Q.empty())
    {
        III u = Q.front(); Q.pop_front();
        LL m = u.MODULO;
        int cnt = u.COUNT;
        //cerr << cnt << '\n';
        if(cnt == N && m == K) return;
        if(cnt > N) return;
        for(int i = 1; i <= M; ++i)
        {
            III v = III(II(A[i], (m * 10 + A[i]) % MOD), cnt + 1);
            if(cnt + 1 <= N) Q.push_front(v);
            else Q.push_back(v);
            prv[v] = u;
        }
    }
}

#define DU "modulo"
int main()
{
    freopen(DU".inp", "r", stdin);
    freopen(DU".out", "w", stdout);
    scanf("%d%d", &A[1], &A[2]);
    scanf("%d%I64d", &N, &K);
    MOD = 1;
    for(int i = 1; i <= N; ++i) MOD *= 2;
    //cerr << MOD << '\n';
    sort(A + 1, A + 3);
    M = unique(A + 1, A + 3) - A - 1;
    prv.clear();
    BFS();
    III u1 = III(II(A[1], K), N), u2 = (A[2]) ? III(II(A[2], K), N) : Null;
    if(prv[u1] == Null && prv[u2] == Null)
    {
        printf("-1");
        return 0;
    }
    if(prv[u1] == Null)
    {
        int cnt = 0;
        while(u2 != Null)
        {
            ans[++cnt] = u2.NUM;
            u2 = prv[u2];
        }
        for(int i = cnt; i > 0; --i) printf("%d", ans[i]);
        return 0;
    }
    int cnt = 0;
    while(u1 != Null)
    {
        ans[++cnt] = u1.NUM;
        u1 = prv[u1];
    }
    for(int i = cnt; i > 0; --i) printf("%d", ans[i]);
}
