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
<<<<<<< HEAD
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

int a[5][2] = {{0}};

void test(int **b){
    b[0][1] = 5;
=======
    freopen(Fname".out", "r", stdin);
    freopen(Fname".inp", "w", stdout);
>>>>>>> 43d0f7ffc84b4883841c84578fb28ffb5caa3d27
}

int main(){
    srand((int)time(0));
    giuncute();
<<<<<<< HEAD
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    test(a);
    // cerr << a[0][1];
=======
    ofstream fo("f.inp");
    lp(i, 1, 9){
        if(rand() % 2) fo << '(';
        else fo << ')';
    }
    fo.close();
    system("brackets");
    system("test1");
>>>>>>> 43d0f7ffc84b4883841c84578fb28ffb5caa3d27
}