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
const string tenfile = "SOLO";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

int t, n, num, k, q;

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

int main(){
    //opt;
    fi;
    fastscan(t);
    int ans;
    for (int i = 1; i <= t; i++){
        fastscan(n); 
        fastscan(k);
        fastscan(q);
        if (!q){
            ans = -1;
            loop(j, 1, n){
                fastscan(num);
                ans = max(ans, num);
            }
        }
        else{
            ans = INT_MAX;
            loop(j, 1, n){
                fastscan(num);
                ans = min(ans, num);
            }
        }
        printf("%d\n", ans);
    }
}