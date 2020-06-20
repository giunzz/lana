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

bool checknt(ll n){
    for(ll i=2;i*i<=n;i++)if(!(n%i))return 0;
    return 1;
}

int main(){
    opt;
    // file;
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1)cout<< "FastestFinger"<<endl;
        else if(n%2) cout <<  "Ashishgup"<<endl;
        else {
            ll c=0,b=n;
            while(b/2>=1&&!(b%2)){++c;b/=2;}
            // cerr << b << " " << c << endl;
            if(n==2) cout <<  "Ashishgup"<<endl;
            else if(b==1){
                cout<< "FastestFinger"<<endl;
            }
            else{
                //c*2chan
                if(checknt(b)) 
                    if(c > 1)
                        cout <<  "Ashishgup"<<endl;
                    else
                    {
                        cout<< "FastestFinger"<<endl;
                    }
                    
                else{
                    cout <<  "Ashishgup"<<endl;
                }
            }
        }
    }
}
