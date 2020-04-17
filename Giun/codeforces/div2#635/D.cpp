#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define er(variable) cerr << variable << " "
#define erl(variable) cerr << variable << "\n"
#define loop(variable, valuegan, valuebehonbang) for(long long variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(long long variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(long long variable = valuegan; conditions; thaydoi) 
#define pp(type, type1) pair<type, type1>
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
const string tenfile = "f";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

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

cii Max = 1e5 + 7;
ll t, nr, ng, nb, r[Max], g[Max], b[Max], vt,  rg[Max], ans = LLONG_MAX;
pp(ll, ii) gb[Max];

int main(){
    opt;
    fi;
    cin >> t;
    while(t--){
        cin >> nr >> ng >> nb;
        loop(i, 1, nr) cin >> r[i];
        loop(i, 1, ng) cin >> g[i];
        loop(i, 1, nb) cin >> b[i];
        //sort (r + 1, r + 1 + nr);
        sort (g + 1, g + 1 + ng);
        sort (b + 1, b + 1 + nb);
        //if(t == 4)loop(i, 1, ng) cerr << g[i] << " " ;
        b[nb + 1] = 0;
        loop(i, 1, ng){
            vt = lower_bound(b + 1, b + nb, g[i]) - b;
            if(t == 4 && i == 2) cerr << vt;
            //if (i == 1 && t == 4) cerr << vt;
            if(((g[i] - b[vt])*(g[i] - b[vt])) < (g[i] - b[vt + 1])*(g[i] - b[vt + 1]) || !((vt + 1) <= nb)) 
                gb[i].first = (g[i] - b[vt])*(g[i] - b[vt]), gb[i].second = vt;
            else gb[i].first = (g[i] - b[vt + 1])*(g[i] - b[vt + 1]), gb[i].second = vt + 1;
        }
       // if (t == 4) loop(i, 1, 2) cerr << gb[i].first << " " << gb[i].second << " " << i << endl;
        g[ng + 1] = 0;
        loop(i, 1, nr){
            vt = lower_bound(g + 1, g + ng, r[i]) - g;
            if(((r[i] - g[vt])*(r[i] - g[vt])) < (r[i] - g[vt + 1])*(r[i] - g[vt + 1]) || !((vt + 1) <= ng)){ 
                rg[i] = (r[i] - g[vt])*(r[i] - g[vt]);
                ans = min(ans, rg[i] + gb[vt].first + (r[i] - b[gb[vt].second])*(r[i] - b[gb[vt].second]));
            //if(t == 4) cerr << ans << " " << i << " " << g[vt] << endl;
            }
            else{ 
                rg[i] = (r[i] - g[vt + 1])*(r[i] - g[vt + 1]);
                ans = min(ans, rg[i] + gb[vt + 1].first + (r[i] - b[gb[vt+1].second])*(r[i] - b[gb[vt+1].second]));
                
            }
        }
        cout << ans << endl;
        ans = LLONG_MAX;
    }
}