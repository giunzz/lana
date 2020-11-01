#include <bits/stdc++.h>
#define Pii pair<long long,long long>
#define Pip pair<Pii,Pii>
#define fi first
#define se second
#define pb push_back

using namespace std;

bool ok=true;
int d[2005];
long long m,n,k,gx,gy,gz,ma=0;
vector<Pip> st,ball;
vector<long long> tea[2005];
vector<long long> e;
set<long long> S;

void solve1(long long s){
    ma=max(ma,s);
    if(e.size()==k){
        return;
    }
    for(long long i=0; i<n; i++){
        long long w=st[i].se.se,cnt=0;
        vector<long long> undo;
        if(d[i]==1) continue;
        for(long long j=0; j<tea[i].size(); j++){
            long long x=tea[i][j];
            if(S.find(x)==S.end()){
                S.insert(x);
                e.pb(x);
                undo.pb(x);
                cnt++;
            }
        }
        if(e.size()>k){
            for(long long j=0; j<undo.size(); j++){
                long long x=undo[j];
                set<long long> :: iterator it=S.find(x);
                if(it!=S.end()) S.erase(it);
            }
            while(cnt--) e.pop_back();
            continue;
        }
        d[i]=1;
        solve1(s+w);
        d[i]=0;
        for(long long j=0; j<undo.size(); j++){
            long long x=undo[j];
            set<long long> :: iterator it=S.find(x);
            if(it!=S.end()) S.erase(it);
        }
        while(cnt--) e.pop_back();
    }
}

int main()
{
    ifstream cin("TEAWORLD.inp");
    ofstream cout ("TEAWORLD.out");
    cin >> m >> n >> k;
    for(long long i=0; i<m; i++){
        long long x,y,z,r;
        cin >> x >> y >> z >> r;
        if(ok && y!=0) ok=false;;
        ball.pb(Pip(Pii(x,y),Pii(z,r)));
    }
    for(long long i=0; i<n; i++){
        long long x,y,z,g;
        cin >> x >> y >> z >> g;
        if(ok && y!=0) ok=false;;
        st.pb(Pip(Pii(x,y),Pii(z,g)));
    }
    cin >> gx >> gy >> gz;
    if(ok){
        for(long long i=0; i<n; i++){
            long long a=st[i].fi.fi;
            for(long long j=0; j<m; j++){
                long long u=ball[j].fi.fi, v=ball[j].se.se;
                long long l=u-v, r=u+v;
                if(l<=gx && gx<=a && a<=r) continue;
                else if(l<=a && a<=gx && gx<=r) continue;
                else if(gx<=l && l<=a) tea[i].pb(j);
                else if(gx<=r && r<=a) tea[i].pb(j);
                else if(gx<=l && l<=r && r<=a) tea[i].pb(j);
                else if(a<=l && l<=gx) tea[i].pb(j);
                else if(a<=r && r<=gx) tea[i].pb(j);
                else if(a<=l && l<=r && r<=gx) tea[i].pb(j);
            }
        }
        if(k==0){
            for(int i=0; i<n; i++){
                if(tea[i].size()==0) ma=max(ma,st[i].se.se);
            }
        }
        else solve1(0);
        cout << ma;
    }
    else cout << 0;
    return 0;
}
