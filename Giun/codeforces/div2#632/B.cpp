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

cii maxn = 1e5 + 7;
int t, n, a[maxn], b[maxn], c[maxn], k;

void fs(int &number) 
{ 
    bool negative = false; 
    register int c; 
  
    number = 0; 
    c = getchar(); 
    if (c == ' ') fs(number);
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
// 0 ko tang
// 1 tang
//-1 giam
//2 tang + giam + ko tang
bool xuly(){
    bool kt = 1;
    loop(i, 1, n) {
        scanf("%d", &a[i]);
        //fs(a[i]);
        if (i == 1) k = a[i], c[i] = 0;
        else{
            c[i] = k;
            if (k == 0) k = a[i];
            else if(k != a[i] && a[i] != 0) k = 2;
        }
    }
    //loop(i, 1, n) cerr << c[i] << " ";
    loop(i, 1, n) {
        scanf("%d", &b[i]);
        //fs(b[i]);
        if(a[i] != b[i] && c[i] == 0) kt = 0;
        if(a[i] < b[i] && c[i] == -1) kt = 0;
        if(a[i] > b[i] && c[i] == 1) kt = 0;
    }
    return kt;
}

int main(){
    //opt;
    //fi;
    scanf("%d", &t);
    //fs(t);
    loop(i, 1, t){
        scanf("%d", &n);
        //fs(n);
        if(xuly()) printf("YES\n");
        else printf("NO\n");
    }
}