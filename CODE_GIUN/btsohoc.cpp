#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
int n;
string s ;
vector<pair<char, ll>> a;
int pri (char o)
{
    if (o == 'x' || o == ':') return 2;
    else if ( o == '+' || o == '-') return 1;
    else if ( o == '(') return 0;
}
bool OPT (string c)
{
    if (c == "(" || c == ")" || c == "x" || c == ':' || c == '+' || c == '-') return true;
    return false;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> s ;
    for (int i = 0 ; i < s.length() ; i++)
    {
        if(s[i] < '0' || s[i] > '9') a.emplace_back(s[i], -1);
        else{
            if(a.empty() || a.back().second == -1) a.emplace_back('.', s[i] - '0');
            else a.back().second = a.back().second * 10 + s[i] - '0';
        }
    }
    for(pair<char, ll> x : a) cerr << x.first << ' ' << x.second << '\n';
    stack<char> st;
    string rpn;
    for(pair<char, ll> x : a){
        
    }
}

