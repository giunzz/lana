#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define test "teaworld"
using namespace std;

void home(){
    #ifndef ONLINE_JUDGE
    freopen(test".inp","r",stdin);
    freopen(test".out","w",stdout);
    #endif // ONLINE_JUDGE
}

void in();
void sol();

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    home();
    in();
    sol();
}
#define int long long
struct data{
    int x,y,z,r;
};

const int N = 2050;
int n,m,k;
data a[N];
data b[20];
data s;
vector<ll> f[40000];
bool ok[40000] = {};
vector<ll> w[20];


void in(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y >> a[i].z >> a[i].r;
    for(int i = 0; i < m; ++i)
        cin >> b[i].x >> b[i].y >> b[i].z >> b[i].r;
    cin >> s.x >> s.y >> s.z;
}

int bp(data x){
    return x.x * x.x + x.y * x.y + x.z * x.z;
}

int p2(int x){
    return x*x;
}

int kc(data A,data B,data M){
    data MA = {A.x - M.x,A.y - M.y,A.z - M.z,0LL};
    data MB = {B.x - M.x,B.y - M.y,B.z - M.z,0LL};
    data AB = {B.x - A.x,B.y - A.y,B.z - A.z,0LL};
    if(bp(MB) >= bp(MA) + bp(AB))
        return bp(MA);
    if(bp(MA) >= bp(MB) + bp(AB))
        return bp(MB);
    data dt = {-AB.y,AB.x,AB.z,0};
    dt.r = dt.x * A.x + dt.y * A.y + dt.z * A.z;
    int ts = p2(M.x*dt.x + M.y *dt.y + M.z * dt.z + dt.r);
    int ms = (p2(dt.x) + p2(dt.y) + p2(dt.z));
    return ts/ms + (ts % ms > 0);
}

vector<ll> get(data x,data y){
    vector<ll> res;
    res.resize(33,0);
    for(int i = 0; i < n; i++){
        int t = kc(x,y,a[i]);
        if(kc(x,y,a[i]) <= a[i].r * a[i].r){
            res[i/64] |= (1LL << (i%64));
        }
    }
    return res;
}

void dq(int x){
    if(x == 0) return;
    dq(x/2);
    cout << x%2;
}

void sol(){
    for(int i = 0; i < m; i++)
        w[i] = get(s,b[i]);
    for(int i = 0; i < (1 << m); ++i)
        f[i].resize(33,0);
    ok[0] = 1;
    int res = 0;
    for(int i = 0; i < (1 << m); ++i){
        if(!ok[i]) continue;
        int sum = 0;
        for(int j = 0; j < m; ++ j)
            if((i & (1 << j)))
            sum += b[j].r;
        res = max(res,sum);
        for(int j = 0; j < m; ++j){
            if((i & (1 << j)) > 0) continue;
            if(ok[i | (1 << j)]) continue;
            vector<ll> tt;
            tt.resize(33,0);
            int sl = 0;
            for(int t = 0; t <= n/64; ++t){
                tt[t] = (f[i][t] | w[j][t]);
                sl += __builtin_popcount(tt[t]);
            }
            if(sl > k) continue;
            ok[i | (1 << j)] = 1;
            f[i | (1 << j)] = tt;
        }
    }
    cout << res;
}
