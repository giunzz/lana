// ILTH
// PreVNOI 2018 ^^
// VietNamVoDich
#include<bits/stdc++.h>
using namespace std;
const int PMTH = 1005;
long long A, B, N, K, n;
struct data
{
    long long u, mod, sl;
    data(long long _u, long long _mod, long long _sl)
    {
        u = _u;
        mod = _mod;
        sl = _sl;
    }
};
int Tenter()
{
    cin >> A >> B;
    cin >> N >> K;
    n = N;
    N = (1<<N);
    return 0;
}

int BFS()
{
    queue<data> q;
    q.push(data(A,A%N,1));
    q.push(data(B,B%N,1));
    while (!q.empty())
    {
        long long u = q.front().u, mod = q.front().mod, sl = q.front().sl; q.pop();
        if (sl>n) continue;
        if (mod==K&&sl==n)
        {
            cout << u;
            return 0;
        }
        q.push(data(u*10+A, (u*10+A)%N, sl+1));
        q.push(data(u*10+B, (u*10+B)%N, sl+1));
    }
    cout << -1;
    return 0;
}

int Tsolve()
{
    BFS();
    return 0;
}

int main()
{
    freopen("MODULO.INP","r",stdin);
    freopen("MODULO.OUT","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Tenter();
    Tsolve();

    return 0;
}
