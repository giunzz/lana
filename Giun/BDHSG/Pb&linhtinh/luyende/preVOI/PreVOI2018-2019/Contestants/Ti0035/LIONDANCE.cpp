#include<bits/stdc++.h>
#define maxn 4004
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

int n;
long long t;
long long l[maxn],r[maxn], bl[2*maxn], l1[maxn], r1[maxn], kq[maxn];
pii f[maxn];
int res = 0,dem1 = 0,dem2 = 0,tt[maxn];

void check()
{
    int tr = 0, d = 0, rt;
    for(int i = 1; i <= n; i++)
        if(tt[i] && kq[++d] > l[i])return;
        else if(tt[i] && kq[++d] <l[i]){break;}
        d = 0;
        for(int i = 1; i <= n; i++)
        if(tt[i] == 1){rt = i;break;}
    for(int i = 1; i <= n; i++)
        if(tt[i] == 1)
    {
        if(abs(l[i]-l[rt]) > t)return;
        for(int j = tr + 1; j <= n; j++)
            if(l[i] == r[j]){
                    tr = j;
                    d++;
                    break;
            }
    }
    if(d == res){
            d = 0;
        for(int i = 1; i <= n; i++)
            if(tt[i])kq[++d] = l[i];
    }
}


void dq(int i)
{
    if(dem1 > res)return;
    if(dem2 > n - res) return;
    for(int j = 0 ;j < 2; j++)
    {
        tt[i] = j;
        if(j == 1)dem1++;
        else dem2++;
        if(i == n)check();
        else dq(i+1);
        if(j == 1)dem1--;
        else dem2--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("LIONDANCE.INP", "r", stdin);
    freopen("LIONDANCE.OUT", "w", stdout);

    cin >> n >> t;

    for(int i = 1; i <= n; i++)
        cin >> l[i], bl[i] = l[i];
    for(int j = 1; j <= n; j++)
        cin >> r[j], bl[n+j] = r[j];
//    sort(bl+1, bl + 1 + 2*n);
//    for(int i = 1; i <= n; i++)
//    {
//     l1[i] = lower_bound(bl+1, bl + 1 + 2*n,l[i]) - bl;
//     r1[i] = lower_bound(bl+1, bl + 1 + 2*n,r[i]) - bl;
//    }
//    for(int )
    for(int i = 1; i <= n; i++)
        {
            for(int j = i - 1; j >= 0; j--)
        {
            if(abs(l[i] - l[j]) > t)continue;
            if(f[j].f + 1 >= f[i].f)for(int p = f[j].s + 1 ; p <= n; p++)
                {
                    if(r[p] == l[i] && f[i].f < f[j].f + 1)
                    {
                        f[i].f = f[j].f + 1;
                        f[i].s = p;
//                        cerr <<f[j].f <<"\n";
                        break;
                    }
                    else if(r[p] == l[i])
                    {
                        f[i].s = min(f[i].s, p);
                        break;
                    }
                }
        }
//        cerr << f[i].f << "\n";
        }
        for(int i = 1; i <= n; i++)
            res = max(res, f[i].f);
            cout << res <<"\n";
        dq(1);
        for(int i = 1; i <= res; i++)
            cout << kq[i]<<" ";
}
