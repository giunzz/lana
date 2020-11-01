#include<bits/stdc++.h>
#define For(i,a,b) for(int i =a;i<=b;i++)
#define Forr(i,a,b) for(int i = a;i>=b;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define maxn 10005
#define INF 1e18
#define ll long long
#define Bit(x,i) ((x>>i) & 1)
using namespace std;

int m,n,k;
pii a[maxn],b[maxn],c[maxn],d[maxn];
vector<int> ans;
vector<pii> tg;

void Io()
{
    freopen("SEQUENCE.INP","r",stdin);
    freopen("SEQUENCE.OUT","w",stdout);
}

bool cmp(pii a,pii b)
{
    return a.se < b.se;
}

void Read()
{
    scanf("%d%d%d",&m,&n,&k);
    For(i,1,m) { scanf("%d",&a[i].fi); a[i].se = i;}
    For(i,1,n) { scanf("%d",&b[i].fi); b[i].se = i;}
}

void check(vector<pii> t){
    if(ans.size() == 0){
        For(i,0,k-1) ans.push_back(t[i].fi);
        return;
    }
    int vt = 0;
    bool ok = true;
    for(;vt < k;vt++){
        if(ans[vt] < t[vt].fi) break;
        if(ans[vt] > t[vt].fi){
            ok = false;
            break;
        }
    }
    if(!ok)
        For(i,vt-1,k-1) ans[i] = t[i].fi;
}

bool cmp2(pii x,pii y)
{
    return (x.fi < y.fi ||(x.fi == y.fi && x.se > y.se));
}

void Solve()
{
    sort(a+1,a+1+m,cmp2);
    sort(b+1,b+1+n,cmp2);
    if(m >= k){
        For(i,1,k) tg.push_back(a[i]);
        sort(tg.begin(),tg.end(),cmp);
        check(tg);
        tg.clear();
    }
    if(n >= k){
        For(i,1,k) tg.push_back(b[i]);
        sort(tg.begin(),tg.end(),cmp);
        check(tg);
        tg.clear();
    }
    int dem = 0;
    For(i,1,min(m,k-1)){
        if(k - i > n) continue;
        For(j,1,i) c[j] = a[j];
        For(j,1,k - i) d[j] = b[j];
        sort(c+1,c+1+i,cmp);
        sort(d+1,d+1+k-i,cmp);
        int cnt = 1;
        For(p,1,k-i){
            if(dem >= 60000000) break;
            For(vt,1,p) tg.push_back(d[vt]);
            For(vt,1,i) tg.push_back(c[vt]);
            For(vt,p+1,k-i) tg.push_back(d[vt]);
            check(tg);
            tg.clear();
            dem+=k;
        }
    }
    For(i,0,k-1) printf("%d ",ans[i]);
    return;
}

int main()
{
    Io();
    Read();
    Solve();
}
