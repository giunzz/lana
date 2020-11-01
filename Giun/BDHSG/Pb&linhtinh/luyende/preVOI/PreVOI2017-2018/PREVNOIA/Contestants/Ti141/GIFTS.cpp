#include <bits/stdc++.h>

#define TASK "GIFTS"

using namespace std;

template<typename T> inline void read(T &x){
    x = 0; char ch; bool neg = 0;
    while(!isdigit(ch=getchar())&&ch!='-');
    if(ch=='-'){neg=1;ch=getchar();}
    do{x=10*x+ch-'0';} while(isdigit(ch=getchar()));
    if(neg) x = -x;
}

typedef long long ll;

const int N = 1e6+111;
const ll INF = 1e18;

int n, k;
ll A[N], F[N], L[N], R[N], res;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    read(n); read(k);
    for(int i = 1; i <= n; i++) read(A[i]);
    for(int i = 1; i <= k; i++) F[1] += A[i];
    for(int i = k+1; i <= n; i++){
        F[i-k+1] = F[i-k]-A[i-k]+A[i];
    }
    n = n-k+1;
    for(int i = 1; i <= n; i++){
        L[i] = max(L[i-1],F[i]);
    }
    for(int i = n; i >= 1; i--){
        R[i] = max(R[i+1],F[i]);
    }
    res = INF;
    for(int i = k+1; i <= n-k; i++){
        res = min(res,max(L[i-k],R[i+k]));
    }
    cout<<res<<'\n';
    return 0;
}
