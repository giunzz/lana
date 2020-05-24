#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define loop(variable, valuegan, valuebehonbang) for(ll variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(ll variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(ll variable = valuegan; conditions; thaydoi) 
#define pp(type, type1) pair<type, type1>
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
const string tenfile = "giun";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
string x, ans;
vec(ii) ansvt;
ii tt;
void quaylui(int vitri)
{
    bool checkkyty[500] = {0};
    if(ansvt.empty()) tt = 0;
    else tt = ansvt.back() + 1;
    loop(i, tt, x.length() - 1)
    {
        if (checkkyty[x[i]]) continue;
        ansvt.push_back(i); ans.push_back(x[i]);
        checkkyty[x[i]] = 1;
        cout << ans << "\n";
        quaylui(vitri + 1);
        ansvt.pop_back(); ans.pop_back();
    }
}
int main()
{
    opt;
    fi;
    getline(cin, x);
    quaylui(0);
}

/*#include <iostream>
#include <string>
using namespace std;
string S, C[2000001],T="";;
bool X[20]={false};
int n=0,m=0;
bool KT()
{
    for (int i=0;i<m;i++) 
    {
        if (C[i]==T) return false;
    }
    return true;
}
void GhiNghiem(){
    int i,c=0;
    T="";
    for (i=0;i<n;i++)
    {
        if (X[i]) T+=S[i];
    }
    if (T!="" && KT(T)) {
        cout << T << endl;
        m+=1;
        C[m]=T;
    }
}
void Ttry(int i){
    for (int j=0; j<=1; j++){
        X[i]=j;
        if (i==n-1) GhiNghiem();
        else Ttry(i+1);
    }
}
int main(){
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> S;
    n=S.length();
    Ttry(0);
    return 0;
}*/