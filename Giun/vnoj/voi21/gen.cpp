#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "pb"

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string name;
    cin >> name;
    system(("mkdir " + name + " && copy pb " + name + " && cd " + name + " && rename pb.* " + name + ".*" + " && rename pb_bruce.* " + name + "_bruce.*").c_str());
}
