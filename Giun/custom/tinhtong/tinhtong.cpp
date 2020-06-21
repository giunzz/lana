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
const string tenfile = "tinhtong";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

vec(ll) a[2], ans;
bool d[2]={0}, da=0;
void fastscan(ll n) 
{ 
    register int c; 
    a[n].clear();
    c = getchar(); 
    if (c == ' ') fastscan(n);
    if (c=='-') 
    { 
        d[n] = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        a[n].push_back(c-48);
} 
void xl(vec(ll)&n, bool &dg){
    while(!n.empty()&&!n.back())n.pop_back();
    if(n.empty()){n.push_back(0);dg=0;}
}
bool check(){
    if(a[0].size()==a[1].size())
        lpd(i,a[0].size()-1,0){
            if(a[0][i]>a[1][i]) return 0;
            else if(a[0][i]<a[1][i]) return 1;
        }    
    return 0;
}
void cg(){
    ll n=0;
    lp(i,0,a[1].size()-1){
        ans.push_back((a[0][i]+a[1][i]+n)%10);
        n=(a[0][i]+a[1][i]+n)/10;
    }
    if(n)ans.push_back(n);
}
void tr(){
    ll n=0,tmp;
    lp(i,0,a[0].size()-1){
        tmp=a[0][i]-a[1][i]-n;
        if(tmp<0){ans.push_back(tmp+10);n=1;}
        else{ans.push_back(tmp);n=0;}
    }
}

int main(){
    opt;
    file;
    fastscan(0); fastscan(1);
    reverse(a[0].begin(), a[0].end());
    reverse(a[1].begin(), a[1].end());
    xl(a[0], d[0]); xl(a[1], d[1]);
    if(a[0].size()<a[1].size() || check()){a[0].swap(a[1]); swap(d[0],d[1]);}
    while(a[1].size()<a[0].size())a[1].push_back(0);
    if(d[0]==d[1]){
        cg();
        while(!ans.empty()&&!ans.back())ans.pop_back();
        if(ans.empty()){ans.push_back(0);d[1]=0;}
        if(d[1])cout<<"-";
        while(!ans.empty()){cout<<ans.back();ans.pop_back();}
    }
    else{
        tr();
        if(d[0])cout<<"-";
        xl(ans,da);
        while(!ans.empty()){cout<<ans.back();ans.pop_back();}
    }
}
