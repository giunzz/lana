#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define LL long long
using namespace std;
const int N = 4009;
int n,delta ;
string a[N] , b[N] ,c[N];
set<string> S;
void sub1()
{
    int sz = 0;
    int sl = (1<<n)-1;
    FOR(mask,1,sl){
        int cnt = 0;
        string tmp="";
        FOR(i,0,n-1) if( (mask>>i)&1) c[++cnt] = a[i+1] ;
        int L = 0;
        bool ok = true;
        FOR(i,1,cnt){
            while(b[L+1]!=c[i]&& L<n) L++;
            L++;
            if(b[L]!=c[i]) {ok = false; break;}
        }
        if(ok){
            if(cnt<sz) continue;
            if(cnt>sz) sz = cnt,S.clear();
            FOR(i,1,cnt) tmp = tmp + c[i]+" ";
            S.insert(tmp) ;
        }

    }
    cout << sz <<'\n';
    if(sz==0) return ;
    cout << *(--S.end()) ;
}
int main()
{
     ios::sync_with_stdio(0) ;
     cin.tie(0) ; cout.tie(0) ;
     freopen("LIONDANCE.INP","r",stdin);
     freopen("LIONDANCE.OUT","w",stdout);
     cin >> n >> delta;
     FOR(i,1,n) cin >> a[i] ;
     FOR(i,1,n) cin >> b[i] ;
     if(n<=20){
           sub1();
           return 0;
     }
     cout << 0;
}
