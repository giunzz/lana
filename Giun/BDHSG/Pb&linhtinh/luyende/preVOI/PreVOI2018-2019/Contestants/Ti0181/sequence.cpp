#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(),x.end()
#define rep(i,x) for(int _x=x,i=0;i<_x;++i)
#define finc(i,a,b) for(int _b=b,i=a;i<=_b;++i)
#define fdec(i,a,b) for(int _b=b,i=a;i>=_b;--i)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define pb push_back
typedef pair<int,int> ii;
#define x first
#define y second
// -----------------------------------------------------------
const int N=3000,lim=N;
int m,n,k,A[N+2],B[N+2];
vector<int> SA[N+2],SB[N+2],res;
void input(){
    cin >> m >> n >> k;
    finc(i,1,m) cin >> A[i];
    finc(i,1,n) cin >> B[i];
}
vector<int> get(vector<int> A,vector<int> B){
    int pa=0,pb=0,la=A.size(),lb=B.size();
    vector<int> ans;
    while (pa<la&&pb<lb){
        if (B[pb]>A[pa]){
            ans.pb(A[pa]);
            ++pa;
            continue;
        }
        if (B[pb]<A[pa]){
            ans.pb(B[pb]);
            ++pb;
            continue;
        }
        ans.pb(A[pa]);
        ++pa;
    }
    finc(i,pa,la-1) ans.pb(A[i]);
    finc(i,pb,lb-1) ans.pb(B[i]);
    return ans;
}
vector<int> get2(vector<int> A,vector<int> B){
    int pa=0,pb=0,la=A.size(),lb=B.size();
    vector<int> ans;
    while (pa<la&&pb<lb){
        if (B[pb]>A[pa]){
            ans.pb(A[pa]);
            ++pa;
            continue;
        }
        if (B[pb]<A[pa]){
            ans.pb(B[pb]);
            ++pb;
            continue;
        }
        ans.pb(B[pb]);
        ++pb;
    }
    finc(i,pa,la-1) ans.pb(A[i]);
    finc(i,pb,lb-1) ans.pb(B[i]);
    return ans;
}
void solve(){
    finc(i,1,m){
        finc(j,1,i) SA[i].pb(A[j]);
        fdec(j,i-2,0){
            SA[j].pb(A[i]);
            if (SA[j]<SA[j+1]) finc(k,0,j) SA[j+1][k]=SA[j][k];
            SA[j].pop_back();
        }
    }
    finc(i,1,n){
        finc(j,1,i) SB[i].pb(B[j]);
        fdec(j,i-2,0){
            SB[j].pb(B[i]);
            if (SB[j]<SB[j+1]) finc(k,0,j) SB[j+1][k]=SB[j][k];
            SB[j].pop_back();
        }
    }
    finc(i,1,k) res.pb(lim);
    finc(i,0,min(m,k))
        if (k-i<=n) {
            vector<int> ans=get(SA[i],SB[k-i]);
            if (res>ans) res=ans;
            ans=get2(SA[i],SB[k-i]);
            if (res>ans) res=ans;
        }
    for(auto &v:res) cout << v << ' ';
}
int main(){
    fast_io;
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    input();
    solve();
    return 0;
}







