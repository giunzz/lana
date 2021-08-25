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

//date gene 30/7/2021
mt19937 rng(30072021);

ll randll(ll a, ll b){
    return uniform_int_distribution<ll>(a, b)(rng);
}

double randb(double a, double b){
    return uniform_real_distribution<double>(a, b)(rng);
}

double sigmoid(double x){
    return 1.0 / (1 + exp(-x));
}

const ll mxlen = 2e9;

// vec(ll) cases(ll l, ll ratio){
//     vec(ll) seg;
//     seg.push_back({})
// }

// void gen_big(ostream &cout, ll n, double threshold){

// }

void gen_small(ostream &cout, ll n, ll l, ll mr, double threshold){
    vec(pp(ll, ll)) segment;
    bool ok = 0;
    ll seg = (mr - l) / n;
    if(seg & 1) -- seg;
    lp(i, 1, n){
        ll len = randll(max(seg / 2, 2LL), seg);
        if(len & 1) --len;
        ll r = l + len;
        segment.push_back({l, r});
        if(len > 10 && i != n && randb(0, 1) < threshold){
            ll nlen = randll(2, len - 1);
            if(nlen & 1) --nlen;
            ll nl = randll(l + 1, r - 1 - nlen);
            segment.push_back({nl, nl + nlen});
            ++i;
        }
        l = r + randll(0, 10);
    }
    assert(segment.size() == n);
    // for(pp(ll, ll) s : segment){
    //     cerr << s.first << ' ' << s.second << '\n';
    // }
    // cerr << '\n';
    cout << n <<'\n';
    shuffle(segment.begin(), segment.end(), rng);
    for(auto i : segment){
        cout << (i.second + i.first) / 2 << ' ' << (i.second - i.first) / 2 << '\n';
    }
}

#define maxtest 15

int main(){
    // giuncute();

    gen_small(cout, 10, -1e3, 5e3, 0.5);

    lp(i, 0, maxtest - 1){
        char filename[128];
        ll n;
        sprintf(filename, "tests/input.%03d", i);
        ofstream co(filename);
        if(i < 4){
            gen_small(co, n = randll(1, 16), -100, 500, sigmoid(randb(-1.0, 1.0)));
        } else if(i < 7){
            gen_small(co, randll(17, 1000), -1e6, 5e6, sigmoid(randb(-1.0, 1.0)));
        } else if(i < 10){
            gen_small(co, randll(1000, 5e4), -1e8, 5e8, sigmoid(randb(-1.0, 1.0)));
        } else{
            gen_small(co, randll(5e4, 1e5), -1e8, 5e8, sigmoid(randb(-1.0, 1.0)));
        }
        cout << filename << '\n';
    }
    lp(i, 0, 24){
        char command[128];
        sprintf(command, "/usr/bin/time -p ./CIRCLE < ./tests/input.%03d > ./tests/output.%03d", i, i);
        cout << command << '\n';
        system(command);
    }
}
