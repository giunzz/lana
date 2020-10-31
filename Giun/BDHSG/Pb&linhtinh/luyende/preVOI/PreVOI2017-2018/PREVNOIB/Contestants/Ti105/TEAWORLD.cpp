#include <bits/stdc++.h>
#define f0(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define nmax 2002

using namespace std;
typedef long long ll;
struct data{
    int x, y, z, r, e;
};

int n, m, k, toado[nmax];
pair <int, pair <int, int> > trasua[nmax+20];
data a[nmax], pos[nmax], pvh;

bool check(int u, int v){
    if(pos[u].x==a[v].x) return 1;
    int k1 = a[v].x - a[v].r;
    if(pos[u].x>=k1 && pos[u].x<=a[v].x) return 1;
    int k2 = a[v].x + a[v].r;
    if(pos[u].x>=a[v].x && pos[u].x<=k2) return 1;
    return 0;
}

void sub1(){
    bool h = 0;
    int res = 0, dem = 0;
    f1(s, (1 << (n)) - 1){
        int val = 0;
        h = 0;
        int ma = -504, mi = 504;
        f1(i, n){
            int bit = (s >> (i - 1))&1;
            if(bit){
                val = val + pos[i].e;
                ma = max(pos[i].x, ma);
                mi = min(pos[i].x, mi);
            }
        }
        int cnt = 0;
        f1(i, m){
            if(a[i].x>=mi && a[i].x<=ma){
                ++cnt;
                continue;
            }
            int k1 = a[i].x - a[i].r, k2 = a[i].x + a[i].r;
            if(k1>=mi && k2<=ma){
                ++cnt;
                continue;
            }
            if(k2>=mi && k2<=ma){
                ++cnt;
                continue;
            }
        }
        if(pvh.x>=mi && pvh.x<=ma){
            if(cnt<=k) res = max(res, val);
            h = 1;
        }
        else{
            if(pvh.x<mi){
                f1(i, m){
                    if(a[i].x>=pvh.x && a[i].x<=mi){
                        ++cnt;
                        continue;
                    }
                    int k1 = a[i].x - a[i].r, k2 = a[i].x + a[i].r;
                    if(k1>=pvh.x && k1<=mi){
                        ++cnt;
                        continue;
                    }
                    if(k2>=pvh.x && k2<=mi){
                        ++cnt;
                        continue;
                    }
                }
                if(cnt<=k){
                    h = 1;
                    res = max(res, val);
                }
            }
            else{
                f1(i, m){
                    if(a[i].x>=ma && a[i].x<=pvh.x){
                        ++cnt;
                        continue;
                    }
                    int k1 = a[i].x - a[i].r, k2 = a[i].x + a[i].r;
                    if(k1>=ma && k1<=pvh.x){
                        ++cnt;
                        continue;
                    }
                    if(k2>=ma && k2<=pvh.x){
                        ++cnt;
                        continue;
                    }
                }
                if(cnt<=k){
                    res = max(res, val);
                    h = 1;
                }
            }
        }
        if(cnt==0){
            res = max(res, val);
        }
        cnt = 1;
        f1(i, n){
            int bit = (s >> (i-1))&1;
            if(bit==0) continue;
            f1(j, m){
                if(check(i, j)) toado[j]+=1;
            }
            if(bit) ++cnt;
        }
        f1(j, m){
            if(check(0, j)) toado[j]+=1;
        }
        bool ok = 1;
        f1(i, m){
            if(toado[i]>0 && toado[i]!=cnt) ok = 0;
        }

        bool ok1 = 1;
        f1(i, m){
            if(toado[i]!=0) ok1 = 0;
        }
        if(ok1==0 && ok){
            res = max(res, val);
        }
        fill(toado+1, toado+m+1, 0);
    }
    cout << res;
}

int main(){
    freopen("TEAWORLD.inp", "r", stdin);
    freopen("TEAWORLD.out", "w", stdout);

    bool ok1 = 1, ok2 = 1;
    cin >> m >> n >> k;
    f1(i, m){
        cin >> a[i].x >> a[i].y >> a[i].z >> a[i].r;
        if(a[i].y!=0 || a[i].z!=0) ok1 = 0;
        if(a[i].z!=0) ok2 = 0;
    }
    f1(i, n){
        cin >> pos[i].x >> pos[i].y >> pos[i].z >> pos[i].e;
        if(pos[i].y!=0 || pos[i].z!=0) ok1 = 0;
        if(pos[i].z!=0) ok2 = 0;
    }
    cin >> pvh.x >> pvh.y >> pvh.z;
    a[0] = pvh;
    if(ok1){
        sub1();
        return 0;
    }
}
