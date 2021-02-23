#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "rel"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

#define x first
#define y second
#define dg first
#define tu second

#define point pp(ll, ll)
#define mp make_pair
cll maxn = 1e5 + 7;
ll n, m, tg[2], rooty = 1e18, rootx = 1e18; 
point sh[maxn], cp[maxn];
pp(ll, ll) opt[2]; // 0 is right, 1 is left
bool res[maxn] = {0};

void change(){
    lp(i, 1, n) sh[i].y -= rooty, sh[i].x -= rootx;
    lp(i, 0, m - 1) cp[i].y -= rooty, cp[i].x -= rootx;
}

inline ll area(point &a, point &b, point &c){
    point vecab = mp(b.x - a.x, b.y - a.y), vecbc = mp(c.x - b.x, c.y - b.y);
    return vecab.x * vecbc.y - vecbc.x *  vecab.y;
}

inline ll ccw(point a, point b, point c){
    ll s = area(a, b, c);
    if(s > 0) return 1;
    if(!s) return 0;
    return -1;
}

void prc(){
    lp(i, 0, m - 1){
        ll pre = ccw(sh[1], cp[i], cp[(i - 1 + m) % m]), next = ccw(sh[1], cp[i], cp[(i + 1) % m]);
        if(pre * -1 == next) continue;
        if(next == 1) tg[0] = i; //tg0 is the right tangent
        else if(pre == -1) tg[1] = i; //tg1 is the left tangent
    }
}

inline bool checkpoint(ll pos, ll t){
    ll tmp = ccw(sh[1], cp[tg[t]], sh[pos]);
    if(!tmp) return 1;
    if(t) return tmp == 1;
    else return tmp == -1;
}

void fpfromtg0(ll t){
    ll j = opt[t].dg;
    lp(i, 2, n){
        if(checkpoint(i, t)){
            // cerr << sh[i].x << ' ' << sh[i].y << '\n';
            res[i] = 1;
            ll next = (j + 1) % m, tmp;
            while(ccw(sh[i], cp[j], cp[next]) < 1) j = next, next = (j + 1) % m;
            ll pre = (j - 1 + m) % m;
            if((tmp = ccw(sh[i], cp[j], cp[pre])) == -1) continue;
            if(j != opt[t].dg)
                opt[t] = mp(j, i);
            else
                if(ccw(sh[opt[t].tu], cp[j], sh[i]) == -1) opt[t].tu = i;
        }
    }
}

void fpfromtg1(ll t){
    // cerr << tg[t] << '\n';
    ll j = opt[t].dg;
    lp(i, 2, n){
        if(checkpoint(i, t)){
            res[i] = 1;
            ll next = (j - 1 + m) % m, tmp;
            while(ccw(sh[i], cp[j], cp[next]) > -1) j = next, next = (j - 1 + m) % m;
            ll pre = (j + 1) % m;
            if((tmp = ccw(sh[i], cp[j], cp[pre])) == 1) continue;
            if(j != opt[t].dg)
                opt[t] = mp(j, i);
            else
                if(ccw(sh[opt[t].tu], cp[j], sh[i]) == 1) opt[t].tu = i;
        }
    }
}

inline bool checkpint(point &a, point &b, point &c, point &d){
    ll abd = ccw(a, b, d), bcd = ccw(b, c, d), cad = ccw(c, a, d);
    return abd == bcd && bcd == cad;
}

void getres0(ll t){
    lp(i, 2, n) if(ccw(sh[opt[t].tu], cp[opt[t].dg], sh[i]) < 1 || checkpint(sh[opt[t].tu], cp[opt[t].dg], cp[tg[t]], sh[i])) res[i] = 1;
}

void getres1(ll t){
    lp(i, 2, n) if(ccw(sh[opt[t].tu], cp[opt[t].dg], sh[i]) > -1 || checkpint(sh[opt[t].tu], cp[opt[t].dg], cp[tg[t]], sh[i])) res[i] = 1;
}

void getrestg(){
    lp(i, 2, n) if(checkpint(cp[opt[0].dg], cp[opt[1].dg], sh[1], sh[i])) res[i] = 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    // res[1] = 1;
    cin >> n;
    lp(i, 1, n){
        ll x, y;
        cin >> x >> y;
        sh[i] = mp(x, y);
        // if(y < rooty) rooty = y, rootx = x;
        // else if(y == rooty && x < rootx) rootx = x;
    }
    // cerr << sh[n].x << ' ' << sh[n].y << '\n';
    cin >> m;
    lp(i, 0, m - 1){
        ll x, y;
        cin >> x >> y;
        cp[i] = mp(x, y);
        // if(y < rooty) rooty = y, rootx = x;
        // else if(y == rooty && x < rootx) rootx = x;
    }
    // change();
    prc(); // find 2 tangent of sh1 to convex polygon
    opt[0] = mp(tg[0], 1), opt[1] = mp(tg[1], 1);
    getrestg();
    // lp(i, 0, 1) cerr << "island: " << cp[opt[i].dg].x << ' ' << cp[opt[i].dg].y << "    ship: " << sh[opt[i].tu].x << ' ' << sh[opt[i].tu].y << '\n';
    // cerr << "Processing....\n";
    fpfromtg0(0); fpfromtg1(1);
    // lp(i, 0, 1) cerr << "island: " << cp[opt[i].dg].x << ' ' << cp[opt[i].dg].y << "    ship: " << sh[opt[i].tu].x << ' ' << sh[opt[i].tu].y << '\n';
    getres0(0); getres1(1);
    ll ans = 0;
    lp(i, 1, n) if(res[i]) ++ans;
    cout << ans;
}   

/*
https://geogebra.org/classic/rjhvxukk
https://developer.mozilla.org/en-US/docs/Learn/Server-side/Express_Nodejs
https://nodejs.dev/learn
*/