#define Link ""

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define TASK "MODULO"

using namespace std;

const int maxn = 65;
int A,B,N;
long long K,Mod,P[maxn];
vector <pair<long long,long long> > v;

void Enter()
{
    cin >> A >> B >> N >> K;
}

void Init()
{

}

void BT1(int T, long long S, long long Form)
{
    if (T == 0) {
        v.push_back({S,Form});
        return;
    }
    --T;
    BT1(T,(S+A*P[T+1])&Mod,Form);
    BT1(T,(S+B*P[T+1])&Mod,Form^(1ll<<T));
}

void BT2(int T, long long S, long long Form)
{
    if (T == N/2) {
        auto it = lower_bound(v.begin(),v.end(),pair<long long,long long>((K-S+Mod+1)&Mod,0));
        if (it != v.end() && ((it -> first + S) & Mod) == K) {
            Form ^= it -> second;
            for (int t=N-1;t>=0;--t)
                if (((Form >> t) & 1) == 0)
                    cout << A;
                else
                    cout << B;
            exit(0);
        }
        return;
    }
    --T;
    BT2(T,(S+A*P[T+1])&Mod,Form);
    BT2(T,(S+B*P[T+1])&Mod,Form^(1ll<<T));
}

void Solve()
{
    Mod = (1ll << N) - 1;
    P[0] = 0;
    P[1] = 1;
    for (int i=2;i<=N+1;++i)
        P[i] = (P[i-1] * 10) & Mod;
    BT1(N/2,0,0);
    sort(v.begin(),v.end());
    BT2(N,0,0);
    cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifdef LHL
    freopen(".INP","r",stdin);
    freopen(".OUT","w",stdout);
#else
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
#endif // LHL

    Enter();
    Init();
    Solve();
}
