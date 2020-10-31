#include <bits/stdc++.h>
#define MAXN 100000
#define pb push_back
#define Pii pair<long long,long long>
#define fi first
#define se second
#define m_p make_pair

using namespace std;

long long t,a,b;
vector<long long> uoc[MAXN];
vector<long long > UC;
long long mi=1e15,k1,k2;

void LKuoc(){
    for(long long i=1; i<=MAXN; i++){
        for(long long j=i; j<=MAXN; j+=i){
            uoc[j].pb(i);
        }
    }
}

vector<long long> uocchung(int u, int v){
    vector<long long> e;
    for(int i=0; i<uoc[u].size(); i++){
        long long x=uoc[u][i];
        int y=lower_bound(uoc[v].begin(), uoc[v].end(), x) - uoc[v].begin();
        if(y!=uoc[v].size() && uoc[v][y]==x) e.pb(x);
    }
    return e;
}

void loang(){
    queue<Pii> Q;
    map<Pii,long long> S;
    Q.push(Pii(a,b));
    S.insert(m_p(Pii(a,b),1));
    while(!Q.empty()){
        long long x=Q.front().fi, y=Q.front().se;
        if(mi>x+y) {mi=x+y;k1=x;k2=y;}
        Q.pop();
        UC=uocchung(x,y);
        for(int i=0; i<UC.size(); i++){
            long long e=UC[i];
            long long u=x/e, v=y/e;
            map<Pii,long long> :: iterator it=S.find(Pii(u,v));
            if(it!=S.end()){
                if(S[Pii(u,v)]>=2) continue;
                S[Pii(u,v)]++;
            }
            else{
                Q.push(Pii(u,v));
                S.insert(m_p(Pii(u,v),1));
            }
        }
        for(int i=0; i<uoc[x].size(); i++){
            long long e=uoc[x][i];
            long long u=x/e, v=y*e;
            map<Pii,long long> :: iterator it=S.find(Pii(u,v));
            if(it!=S.end()){
                if(S[Pii(u,v)]>=2) continue;
                S[Pii(u,v)]++;
            }
            else{
                Q.push(Pii(u,v));
                S.insert(m_p(Pii(u,v),1));
            }
        }
        for(int i=0; i<uoc[y].size(); i++){
            long long e=uoc[y][i];
            long long u=x*e, v=y/e;
            map<Pii,long long> :: iterator it=S.find(Pii(u,v));
            if(it!=S.end()){
                if(S[Pii(u,v)]>=2) continue;
                S[Pii(u,v)]++;
            }
            else{
                Q.push(Pii(u,v));
                S.insert(m_p(Pii(u,v),1));
            }
        }
    }
}

int main()
{
    ifstream cin("MINSUM.inp");
    ofstream cout("MINSUM.out");
    cin >> t;
    LKuoc();
    while(t--){
        cin >> a >> b;
        if(a>100 && b>100){
            long long x=__gcd(a,b);
            cout << a/x << ' ' << b/x << '\n';
        }
        k1=k2=1e9;
        loang();
        cout << k1 << ' ' << k2 << '\n';
    }
    return 0;
}
