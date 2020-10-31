#include <bits/stdc++.h>
#define f0(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define nmax 102

using namespace std;
typedef long long ll;

pair <int, int> f[nmax][nmax];

bool check(int x){
    if(x==1) return 0;
    if(x==2) return 1;
    for(int i=2; i<=sqrt(x); i++){
        if(x%i==0) return 0;
    }
    return 1;
}

void solve(int x, int y){
    vector <int> save1, save2;
    int k1 = x, k2 = y;
    int m = 2;
    while(m*m<=x){
        while(x%m==0){
            x/=m;
            save1.push_back(m);
        }
        ++m;
    }
    if(x!=1) save1.push_back(x);

    m = 2;
    while(m*m<=y){
        while(y%m==0){
            y/=m;
            save2.push_back(m);
        }
        ++m;
    }
    if(y!=1) save2.push_back(y);
    int cnt = 0;
    int t1 = 1, t2 = 1;
    for(int i=0; i<save1.size(); i++){
        if(i==0) ++cnt;
        else{
            if(save1[i]!=save1[i-1]){
                if(cnt%2==0){
                    cnt = 1;
                    continue;
                }
                else{
                    t1 = t1*save1[i-1];
                }
                cnt = 1;
            }
            else ++cnt;
        }
    }
    if(cnt%2==1){
        t1 = t1*save1[save1.size() - 1];
    }
    cnt = 0;
    for(int i=0; i<save2.size(); i++){
        if(i==0) ++cnt;
        else{
            if(save2[i]!=save2[i-1]){
                if(cnt%2==0){
                    cnt = 1;
                    continue;
                }
                else{
                    t2 = t2*save2[i-1];
                }
                cnt = 1;
            }
            else ++cnt;
        }
    }
    if(cnt%2==1){
        t2 = t2*save2[save2.size() - 1];
    }
    int r = __gcd(k1, k2);
    k1 = k1/r, k2 = k2/r;
    r = __gcd(t1, t2);
    t1/=r; t2/=r;
    if(k1+k2 < t1 + t2){
        cout << k1 << " " << k2 << endl;
    }
    else{
        cout << t1 << " " << t2 << endl;
    }
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("MINSUM.inp", "r", stdin);
    freopen("MINSUM.out", "w", stdout);

    int te; cin >> te;
    while(te--){
        int x, y; cin >> x >> y;
        solve(x, y);
    }
}
