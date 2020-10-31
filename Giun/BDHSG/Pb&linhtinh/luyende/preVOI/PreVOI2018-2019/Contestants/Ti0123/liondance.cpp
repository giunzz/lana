#include <bits/stdc++.h>
#define NaMe "liondance"
#define pii pair<int,int>
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define gb(i,j) ((i>>j)&1)
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define fdto(i,a,b) for(int i=a; i>=b; --i)
#define piii pair<int, pii>
using namespace std;
set<piii> s;
int n,k, a[4009],b[4009],l[4009][4009];
pii lv[4009][4009];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(NaMe".inp","r", stdin);
    freopen(NaMe".out","w", stdout);
    cin >> n >> k;
    fdto(i,n,1) cin >> a[i];
    fdto(i,n,1) cin >> b[i];
    int s1=0,s2=0;
    fto(i,1,n)
        fto(j,1,n)
        if(a[i]==b[j]){
            l[i][j]=1;
            lv[i][j]=mp(0,0);
            for(set<piii> :: iterator it=s.upper_bound(mp(a[i]-k,mp(0,0)));
            it!=s.upper_bound(mp(a[i]+k+1,mp(0,0))); ++it){
                piii x=*it;
                if(x.se.fi<i && x.se.se <j){
                if(l[i][j]<l[x.se.fi][x.se.se]+1){
                    l[i][j]=l[x.se.fi][x.se.se]+1;
                    lv[i][j]=x.se;
                }
                else if(l[i][j]==l[x.se.fi][x.se.se]+1){
                    if(a[x.se.fi]>a[lv[i][j].fi])lv[i][j]=x.se;
                }
                }
            }
            if(l[i][j]>l[s1][s2]){s1=i;s2=j;}
            else if(l[i][j]==l[s1][s2] && a[s1]<a[i]){s1=i;s2=j;}
            s.insert(mp(a[i],mp(i,j)));
        }
    cout << l[s1][s2] <<'\n';
    while(s1!=0 && s2!=0){
        cout << a[s1] <<' ';
        pii x=lv[s1][s2];
        s1=x.fi;
        s2=x.se;
    }
    return 0;
}
