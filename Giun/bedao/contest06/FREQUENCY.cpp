//Mo Algorithm
//it
//rmq
#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define err(variable) cerr << variable << " "
#define errl(variable) cerr << variable << "\n"
#define loop(variable, valuegan, valuebehonbang) for(long long variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(long long variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(long long variable = valuegan; conditions; thaydoi) 
#define pp(type) pair<type, type>
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
const string tenfile = "f";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
const int maxn = 5e5 + 7;

int n, q, a[maxn];
vec(vec(int)) st;

void fastscan(int &number) 
{ 
    bool negative = false; 
    register int c; 

    number = 0; 
    c = getchar(); 
    if (c == ' ') fastscan(number);
    if (c=='-') 
    { 
        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
} 

void init(int id, int l, int r){
    if (l == r) {
        st[id].push_back(a[i]);
        return;
    }
    int m = (l + r) / 2;
    init(id * 2, l, m);
    init(id * 2 + 1, m + 1, r);
}

int main(){
    //opt;
    fi;
    fastscan(n);
    for (int i = 1 ; i <= n; i++){
        fastscan(a[i]);
    }
    st.resize(4*n + 7);
    init(1, 1, n);
}