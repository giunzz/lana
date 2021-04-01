#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

#define point pp(ll, ll)
#define X first
#define Y second

const double EPS = 1E-9;

struct segment{
    point p, q;
    double get_y(double x) const {
        if ((double)abs(p.X - q.X) < EPS)
            return p.Y;
        return p.Y + (q.Y - p.Y) * (x - p.X) / ((q.X - p.X) * 1.0);
    }
};

cll mxn = 1e5 + 7;
ll n;
segment a[mxn];

bool cmp(const segment& a, const segment& b){
    ll x = max(a.p.X, b.p.X);
    return ((a.p.Y * (a.q.X - a.p.X) + (a.q.Y - a.p.Y) * (x - a.p.X)) * (b.q.X - b.p.X)) < ((b.p.Y * (b.q.X - b.p.X) + (b.q.Y - b.p.Y) * (x - b.p.X)) * (a.q.X - a.p.X));
}

bool operator<(const segment& a, const segment& b)
{
    double x = max(min(a.p.X, a.q.X), min(b.p.X, b.q.X));
    return a.get_y(x) < b.get_y(x) - EPS;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){
        cin >> a[i].p.X >> a[i].p.Y >> a[i].q.X >> a[i].q.Y;
        if(a[i].p.X > a[i].q.X) swap(a[i].q, a[i].p);
    }
    sort(a + 1, a + 1 + n, cmp);
    lp(i, 1, n) cerr << a[i].p.X << ' ' << a[i].p.Y << "    " << a[i].q.X << ' ' << a[i].q.Y << '\n';
}   


/*
    ham sort theo do cao cua cac dau mut
    2 truong hop
    1 la 2 duong cat nhau o giua ko co duong nao thi diem duoi or tren se ktra intersect vs nhau
    2 la 2 duong cat nhau o giua co doan thang v thi di tu diem cat nhau qua trai se cham dc diem cuoi cua doan thang o giua nhu v se kiem tra giua 2 doan thang cat nhau   
*/