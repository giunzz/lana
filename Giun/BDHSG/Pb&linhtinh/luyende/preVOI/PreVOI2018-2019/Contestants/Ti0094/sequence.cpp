#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(ll i=(a);i<=(b);++i)
#define ford(i,a,b) for(ll i=(a);i>=(b);--i)
#define N 3005
#define oo 1000000000

using namespace std;

vector <ll> vc[N],vcc[N];
ll n,m,a[N],b[N],k,ri[N],r[N],kq[2*N],dif[N][N],diff[N][N];

int main()
{
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);

    cin>>n>>m>>k;
    fort(i,1,n) cin>>a[i];
    fort(i,1,m) cin>>b[i];

    ford(i,n,1){
        ri[i]=n+1;
        fort(j,i+1,n) if (a[j]<a[i]) {ri[i]=j;break;}
    }

    ford(i,m,1){
        r[i]=m+1;
        fort(j,i+1,m) if (b[j]<b[i]) {r[i]=j;break;}
    }


    fort(i,0,n){
        ll sz=i;
        ll fi=1;
        while (sz){
            while (n-ri[fi]>=sz-1) fi=ri[fi];
            vc[i].push_back(a[fi]);
            sz--;
            fi++;
        }
    }

    fort(i,0,m){
        ll sz=i;
        ll fi=1;
        while (sz){
            while (m-r[fi]>=sz-1) fi=r[fi];
            vcc[i].push_back(b[fi]);
            sz--;
            fi++;
        }
    }


    fort(i,1,n){
        fort(j,0,vc[i].size()-1){
            dif[i][j]=i;
            fort(h,j+1,vc[i].size()-1) if (vc[i][h] != vc[i][j]){dif[i][j]=h;break;}
        }
    }

    fort(i,1,m){
        fort(j,0,vcc[i].size()-1){
            diff[i][j]=i;
            fort(h,j+1,vcc[i].size()-1) if (vcc[i][h] != vcc[i][j]){diff[i][j]=h;break;}
        }
    }

    fort(i,1,k) kq[i]=oo;

    fort(i,0,n){
        ll j=k-i;
        if (j>m) continue;

        ll la=1;
        ll lb=1;
        ll len=0;
        bool ok=0;

        while (la<=i || lb<=j){
            len++;

            if (la>i){
                    if (!ok && kq[len] < vcc[j][lb-1]) break;
                    if (kq[len] > vcc[j][lb-1]) ok=1;
                    kq[len]=vcc[j][lb-1];
                    lb++;
                    continue;
            }

            if (lb>j){
                if (!ok && kq[len] < vc[i][la-1]) break;
                if (kq[len] > vc[i][la-1]) ok=1;
                kq[len]=vc[i][la-1];
                la++;
                continue;
            }


            if (vc[i][la-1] < vcc[j][lb-1]){
                if (!ok && kq[len] < vc[i][la-1]) break;
                if (kq[len] > vc[i][la-1]) ok=1;
                kq[len]=vc[i][la-1];
                la++;
                continue;
            }

            if (vc[i][la-1] == vcc[j][lb-1]){
                ll tmpa=dif[i][la-1];
                ll tmpb=diff[j][lb-1];

                ll res=oo;
                if (tmpa<i) res=min(res,vc[i][tmpa]);
                if (tmpb<j) res=min(res,vcc[j][tmpb]);

                if (tmpa<i && res==vc[i][tmpa]){
                    if (!ok && kq[len] < vc[i][la-1]) break;
                    if (kq[len] > vc[i][la-1]) ok=1;
                    kq[len]=vc[i][la-1];
                    la++;
                }
                else{
                    if (!ok && kq[len] < vcc[j][lb-1]) break;
                    if (kq[len] > vcc[j][lb-1]) ok=1;
                    kq[len]=vcc[j][lb-1];
                    lb++;
                }
                continue;
            }

            if (!ok && kq[len] < vcc[j][lb-1]) break;
            if (kq[len] > vcc[j][lb-1]) ok=1;
            kq[len]=vcc[j][lb-1];
            lb++;
        }
    }

    fort(i,1,k) cout<<kq[i]<<" ";

    return 0;
}
