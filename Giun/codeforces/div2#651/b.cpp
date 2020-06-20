#include <bits/stdc++.h>
#define ii int
#define ll long long
#define sr string
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 <= obj3; obj1++)
#define lpd(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 >= obj3; obj1--)
#define pp(obj1, obj2) pair<obj1, obj2>
#define vec(obj1) vector<obj1>
#define vecite(obj1) vector<obj1>::iterator
#define fi first
#define se second
#define mp(obj1, obj2) map<obj1, obj2>
#define st(obj) system((obj).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll a[2003], d[2003];
// vec(ll) a;

int main(){
    opt;
    // file;
    ll t,n;
    cin >>t;
    while(t--){
        memset(d, 0, sizeof(d));
        cin>>n;
        ll cnt = 0;
        lp(i,1,n*2){cin>>a[i];}
        lp(i, 1, n*2 && cnt<n-1){
            lp(j, i+1, n*2){
                if(!(abs((a[i]%2)-(a[j]%2))) && !d[i] && !d[j]){
                    cout << i << " " << j<<endl;
                    ++cnt;
                    d[i] = 1; d[j]=1;
                    break;
                }
            }
        }
    }
}
