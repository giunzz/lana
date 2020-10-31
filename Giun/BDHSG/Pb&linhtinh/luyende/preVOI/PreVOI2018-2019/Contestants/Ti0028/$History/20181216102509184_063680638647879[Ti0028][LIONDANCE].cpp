#include <bits/stdc++.h>
#define x first
#define y second
#define ii pair <int, pair<int, int> >
#define pb push_back
#define mp make_pair
using namespace std;

const int N=10000;
int n, k, a[N], b[N], dem, kq, f[N], id[N], tree[4*N], ht[N], s[N], tam[N];
pair<int, int> luu[4*N], tr[4005][4005];

void Init(int xx, int u, int v)
{
    if(u==v) { id[u]=xx; return; }
    int mid=(u+v)/2;
    Init(2*xx, u, mid);
    Init(2*xx+1, mid+1, v);
}

void update(int xx, int i, int j, int cs)
{
    xx=id[xx];
    tree[xx]=cs;
    luu[xx].x=i;
    luu[xx].y=j;
    xx/=2;
    while(xx) {
        if(tree[2*xx]>tree[2*xx+1]) { tree[xx]=tree[2*xx]; luu[xx]=luu[2*xx]; }
        else { tree[xx]=tree[2*xx+1]; luu[xx]=luu[2*xx+1]; }
        xx/=2;
    }
}

ii get(int xx, int u, int v, int l, int r)
{
    if(u>r || v<l) return mp(0, mp(0, 0));
    if(u<=l && r<=v) return mp(tree[xx], luu[xx]);
    int mid=(u+v)/2;
    ii x1=get(2*xx, u, mid, l, r);
    ii x2=get(2*xx+1, mid+1, v, l, r);
    if(x1.x>x2.x) return x1;
    return x2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("LIONDANCE.inp", "r", stdin);
    freopen("LIONDANCE.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i) { scanf("%d", &a[i]); f[++dem]=a[i]; }
    for(int i=1; i<=n; ++i) { scanf("%d", &b[i]); f[++dem]=b[i]; }
    sort(f+1, f+dem+1);
    Init(1, 1, dem);
    for(int i=1; i<=n; ++i){
        memset(tree, 0, sizeof(tree));
        memset(luu, 0, sizeof(luu));
        memset(tam, 0, sizeof(tam));
        for(int j=1; j<=n; ++j){
            if(a[i]==b[j]){
                int x1=lower_bound(f+1, f+dem+1, a[i]-k)-f;
                int x2=upper_bound(f+1, f+dem+1, a[i]+k)-f-1;
                ii kt=get(1, 1, dem, x1 ,x2);
                tam[j]=kt.x+1;
                tr[i][j]=kt.y;

            }
            int u=lower_bound(f+1, f+dem+1, b[j])-f;
            int uu= ht[j] ? j : 0;
            update(u, ht[j], uu, s[j]);
        }
        for(int j=1; j<=n; ++j) if(tam[j]) { s[j]=tam[j]; ht[j]=i; }
    }
    int in=0;
    for(int i=1; i<=n; ++i) in=max(in, s[i]);
    printf("%d\n", in);
    stack <int> hanh;
    for(int i=1; i<=n; ++i)
    {
        if(s[i]==in){
            pair <int, int> u=mp(ht[i], i);
            while(u.x){
                hanh.push(a[u.x]);
                u=tr[u.x][u.y];
            }
            while(hanh.size()) { printf("%d ", hanh.top()); hanh.pop(); }
            return 0;
        }
    }
    return 0;
}
