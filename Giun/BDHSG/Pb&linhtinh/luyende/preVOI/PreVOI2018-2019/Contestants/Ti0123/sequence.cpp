#include <bits/stdc++.h>
#define NaMe "sequence"
#define pii pair<int,int>
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define gb(i,j) ((i>>j)&1)
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define fdto(i,a,b) for(int i=a; i>=b; --i)

using namespace std;
vector<int> v[102][102][202];
int n,m,k,a[3009],b[3009];
vector<int> maxx(const vector<int> &a ,const vector<int> &b){
    if(a.size()!=b.size()){
        if(a.size()<b.size()) return b;
        else return a;
    }
    for(int i=0; i<a.size();++i){
        if(a[i]!=b[i]){
            if(a[i]<b[i]) return a;
            else return b;
        }
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(NaMe".inp","r", stdin);
    freopen(NaMe".out","w", stdout);
    cin >> n >> m >> k;
    fto(i,1,n) cin >> a[i];
    fto(j,1,m) cin >> b[j];
    fto(i,0,n)
        fto(j,0,m)
            fto(t,1,k){
                int ok=0;
                vector<int> tg;
                if(i!=0){tg=v[i-1][j][t-1];tg.pb(a[i]);v[i][j][t]=maxx(v[i][j][t],tg);v[i][j][t]=maxx(v[i][j][t],v[i-1][j][t]);}
                if(j!=0){tg=v[i][j-1][t-1];tg.pb(b[j]);v[i][j][t]=maxx(v[i][j][t],tg);v[i][j][t]=maxx(v[i][j][t],v[i][j-1][t]);}
            }
    for(int i=0; i<v[n][m][k].size(); ++i){
        cout << v[n][m][k][i] <<' ';
    }
    return 0;
}
