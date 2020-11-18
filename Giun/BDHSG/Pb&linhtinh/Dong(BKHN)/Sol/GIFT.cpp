#include <bits/stdc++.h>
using namespace std;

#define lint long long
#define pii pair<int, int> 
#define ld long double
#define TASK "gift" 

string n;
const int oo = 1e6;
int f[18][4][2][2][2];
lint A[18][4][2][2][2];
lint B[18][4][2][2][2];
lint C[18][4][2][2][2];

bool maxi(int &a, int b)
{
    if (b > a) 
    {
        a = b;
        return true;
    }
    return false;   
}

lint P10[18];
#define _V [i][carry][ok1][ok2][ok3]
#define _U [i-1][cur/10][n1][n2][n3]

int F(int i, int carry, bool ok1, bool ok2, bool ok3)  
{
    if (i < 0) 
        return (carry == 0 && ok1 && ok2 && ok3) ? 0 : -oo;
    int &ans = f[i][carry][ok1][ok2][ok3];
    if (ans != -1) 
        return ans;
    ans = -oo;
    int cur, a,b,c;
    bool n1, n2, n3;
    for ( a=0; a<=9 ;++a) 
    for ( b=0; b<=9; ++b) 
    for ( c=0; c<=9; ++c) 
    {
        cur = a + b + c + carry;
        n1 = ok1 | a;
        n2 = (b < a) ? false : (b > a || ok2);
        n3 = (c < b) ? false : (c > b || ok3);
        if (cur % 10 == n[i])
            if (maxi(ans, F(i - 1, cur / 10, n1, n2, n3) + a + b + c)) 
            {
                A _V = ((i > 0) ? (A _U) * 10 : 0) + a;
                B _V = ((i > 0) ? (B _U) * 10 : 0) + b;
                C _V = ((i > 0) ? (C _U) * 10 : 0) + c;
            }
    }
    return ans;
}

vector<pii> ntr (lint x) 
{
    if (x == 0) 
        return {};
    if (x % 2 == 0) 
    {
        auto v = ntr(x / 2);
        for (auto &p : v) 
            p.first++;
        return v;
    }
    else 
    {
        lint k = 1; 
        int f = 0;
        while (k * 3 <= x) 
        {
            k *= 3;
            ++f;
        }
        auto v = ntr(x - k);
        v.push_back({0, f});
        return v;
    }
    return {};
}

vector<lint> getList (vector<pii> x) 
{
    vector<lint> a;
    for (auto h : x) 
    {
        lint k = 1;
        for (int i=0; i<h.first; ++i) 
            k *= 2;
        for (int i=0; i<h.second;++i) 
            k *= 3;
        a.push_back(k);
    }
    return a;
}

void driver()
{
    //freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);
    P10[16] = 1;
    for (int i=15; i>=0; --i) 
        P10[i] = P10[i+1] * 10;
    int T; cin >> T;
    while (T--) 
    {
        cin >> n;
        n = string (17 - n.size(), '0') + n;
        for (char &c : n) 
            c -= '0';
        memset(f, -1, sizeof(f));
        int res = F(16, 0, 0, 0, 0);
        if (res <0)
            res = -1;
        cerr<<res << '\n';
        if (res == -1) 
        {
            cout << -1 << endl;
            continue;
        }
        lint a = A[16][0][0][0][0];
        lint b = B[16][0][0][0][0];
        lint c = C[16][0][0][0][0];

        //cerr << a << " " << b << " " << c << endl;
        auto ta = getList(ntr(a));
        auto tb = getList(ntr(b));
        auto tc = getList(ntr(c));
        cout << ta.size() << ' ' << tb.size() << ' ' << tc.size() << ' ';
        for (auto i : ta) cout << i << ' ';
        for (auto i : tb) cout << i << ' ';
        for (auto i : tc) cout << i << ' ';
        cout << '\n';
    }   
}

int main()
{
    ios_base::sync_with_stdio(false);
    driver();
}
