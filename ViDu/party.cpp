#include <bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
<<<<<<< HEAD
#define ballolo freopen("giun.inp","r",stdin),freopen("giun.out","w",stdout);
#pragma GCC optimize("Ofast")
ll n,  d[25]={0};
string x[25];
vector <ll> v;

void giun (int vt)
{
    if (vt == n + 1 ) 
    {
        for (int i = 0 ; i < v.size(); i++) cout << v[i] << endl;
    }
    else 
    {
        for (int i = 1 ; i <= n ; i++)
        {
            if ( i == vt ) continue;
            else if (d[i] <= 2)
            {
                if (x[vt].find(x[i])  != string::npos) 
                {
                    v.push_back(vt); 
                    v.push_back(i);
                    d[i]++;
                    d[vt]++;
                    cerr << i << " " << vt << endl;
                }
                 giun(vt+1);
            }
           
            //cerr << x[i] << " " << x[vt] << endl;
        }
    }
}


int main()
{
    giuncute;
    ballolo;
    cin >> n;
    for (ll i = 1 ; i <= n ; i++) cin >> x[i];
    giun(1);    
    
=======
#define ballolo freopen("tongarr.inp","r",stdin),freopen("tongarr.out","w",stdout);
#pragma GCC optimize("Ofast")
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define vec(a) vector<a>
using namespace std;

string a[22];
ll ans[22] = {0}, n;
bool d[22] = {0};
vector<ll> pos[200];
bool ok = 0;

void ql(ll vt){
  if(ok) return;
  if(vt == 1){
    lp(i, 1, n){
      ans[vt] = i, d[i] = 1;
      ql(vt + 1);
      d[i] = 0;
    }
  }
  else if(vt <= n){
    lp(i, 1, n){
      if(d[i]) continue;
      for(char &c : a[i]){
        ll k = binary_search(pos[c].begin(), pos[c].end(), ans[vt - 1]);
        if(k){
          ans[vt] = i, d[i] = 1;
          ql(vt + 1);
          d[i] = 0;
          break;
        }
      }
    }
  }
  else{
    for(char &c : a[ans[1]]){
      ll k = binary_search(pos[c].begin(), pos[c].end(), ans[vt - 1]);
      if(k) {
        lp(i, 1, n) cout << a[ans[i]] << '\n';
        ok = 1;
        break;
      }
    }
  }
>>>>>>> bcdcdbe... sync
}

int main(){
    giuncute;
    ballolo;
  cin >> n;
  lp(i, 1, n){
    cin >> a[i];
    for(char &c : a[i]){
      pos[c].push_back(i);
    }
  }
  ql(1);
  if(!ok) cout << "NO SOLUTION";
}
