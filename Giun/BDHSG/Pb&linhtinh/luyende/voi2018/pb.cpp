#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
using namespace std;

void file(const string file){
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

int main(){
    // file("pb");
    string s;
    cin >> s;
    system(("mkdir " + s).c_str());
    system(("copy pb " + s).c_str());
    system(("cd " + s + " && rename pb.* " + s + ".*").c_str());
    system(("cd " + s + " && rename pb_bruce.* " + s + "_bruce.*").c_str());
}