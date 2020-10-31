#include <bits/stdc++.h>
#define crys "liondance"

using namespace std;

int n, delta, a[5001], b[5001], xd[100], phu[5001], lv[5001], kq = 0, nexta[1001][1001], nextb[1001][1001], ta[1001], tb[1001];
int l[303][303][303], tx[303][303][303], ty[303][303][303], dd[5005];
map <int, int> luu;

inline void read(int &n) {
    n = 0;
    int ch = getchar(), sign=1;
    while( ch < '0' || ch > '9' ){
        if (ch == '-') sign = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    n *= sign;
}

void ktra()
{
    int sl = 0;
    for (int i=1; i<=n; ++i) if (xd[i]) phu[++sl] = a[i];
    if (sl<kq || !sl) return;
    for (int i=2; i<=sl; ++i) if (abs(phu[i]-phu[i-1])>delta) return;
    int dem = 1;
    for (int i=1; i<=n; ++i) if (b[i]==phu[dem]) ++dem;
    if (dem<=sl) return;
    if (sl>kq)
    {
        kq = sl;
        for (int i=1; i<=sl; ++i) lv[i]=phu[i];
    } else if (sl==kq)
    {
        for (int i=1; i<=sl; ++i) if (lv[i]<phu[i])
        {
            for (int j=1; j<=sl; ++j) lv[j] = phu[j];
            return;
        } else if (lv[i]>phu[i]) return;
    }
}

void di(int i)
{
    for (int j=0; j<=1; ++j)
    {
        xd[i] = j;
        if (i==n) ktra(); else di(i+1);
    }
}

void xuli()
{
    for (int i=1; i<=n; ++i) phu[i] = a[i];
    sort(phu,phu+n+1);
    phu[0]=phu[1]-1;
    int nmax = 1; luu[0]=1;
    for (int i=1; i<=n; ++i) if (phu[i]!=phu[i-1])
    {
        ++nmax;
        luu[phu[i]]=nmax;
        dd[nmax]=phu[i];
    }
    for (int i=n; i>=1; --i)
    {
        for (int j=0; j<=nmax; ++j) nexta[i][j]=ta[j];
        for (int j=0; j<=nmax; ++j) nextb[i][j]=tb[j];
        ta[luu[a[i]]]=i; tb[luu[b[i]]]=i;
    }
    l[0][0][0]=1;
    kq = n;
    for (int k=1; k<=n; ++k)
    {
        bool ok = false;
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j) if (a[i]==b[j])
            {
                for (int h=nmax; h>=1; --h)
                {
                    if (abs(a[i]-dd[h])>delta && k>1) continue;
                    int u = nexta[i][h], v = nextb[j][h];
                    if (h>1 && (!u || !v)) continue;
                    if (!l[u][v][k-1]) continue;
                    l[i][j][k]=1;
                    ok = true;
                    tx[i][j][k]=u; ty[i][j][k]=v;
                    break;
                }
            }
        if (ok==false) {kq = k-1; break;}
    }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j) if (l[i][j][kq])
        {
            int u = i, v = j, dem = kq;
            while (u && v)
            {
                phu[kq-dem+1]=a[u];
                int uu = tx[u][v][dem], vv = ty[u][v][dem];
                --dem; u = uu; v = vv;
            }
            for (int k=1; k<=kq; ++k) if (lv[k]<phu[k])
            {
                for (int h=1; h<=kq; ++h) lv[h]=phu[h];
                break;
            } else if (lv[k]>phu[k]) break;
        }
    cout << kq << '\n';
    for (int i=1; i<=kq; ++i) cout << lv[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(crys".inp", "r", stdin);
    freopen(crys".out", "w", stdout);
    read(n); read(delta);
    for (int i=1; i<=n; ++i) read(a[i]);
    for (int i=1; i<=n; ++i) read(b[i]);
    if (n<=20)
    {
        di(1);
        cout << kq << '\n';
        for (int i=1; i<=kq; ++i) cout << lv[i] << " ";
    } else
    xuli();
    return(0);
}
