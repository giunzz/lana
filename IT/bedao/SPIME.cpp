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
const string tenfile = "SPIME";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

bool sang[(int)1e7 + 3];
int t[(int)1e7 + 3];
int n, vt = 0;

void xaydungsangsiutokhunlo(){
    sang[0] = sang[1] = true;
    for(int i = 2; i <= 1e7; i++) {
        if (!sang[i]) {
            for(int j = i*2; j <= 1e7; j+=i) {
                sang[j] = true;
            }
        }
    }
}

int main(){
    //opt;
    fi;
    xaydungsangsiutokhunlo();
    scanf("%d", &n);
    loop(i, 1, n) {
        if(!sang[i]) ++vt;
    }
    //cerr << vt;
    int x = 0, y = 0, sl = 0, c = 0;
    /* 
       0 qua phai
       1 len
       2 qua trai
       3 xuong
    */
   int i = 1;
   while (i < vt){
       // cerr << x << " " << y << " " << c << endl;
       if (!(c % 2)) ++sl;
       if(i + sl > vt){
           sl = vt - i;
       }
       i += sl;
       if(c == 0){
           x += sl; c = 1;
       }
       else if(c == 1){
           y += sl; c = 2;
       }
       else if (c == 2){
           x -= sl; c = 3;
       }
       else if(c == 3){
           y -= sl; c = 0;
       }
   }
   printf("%d %d", x, y);
}