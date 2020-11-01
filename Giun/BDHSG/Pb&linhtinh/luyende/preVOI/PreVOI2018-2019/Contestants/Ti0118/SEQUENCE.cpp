#define Link ""

#include <iostream>
#include <cstdio>

#define TASK "SEQUENCE"

using namespace std;

const int oo = 1e9 + 1;
const int maxn = 1e4 + 100;
int m,n,k,a[maxn],b[maxn],Log[maxn],mna[maxn][21],mnb[maxn][21];
int s1[maxn],s2[maxn],s[maxn],res[maxn];

void Enter()
{
    cin >> a[0] >> b[0] >> k;
    for (int i=1;i<=a[0];++i)
        cin >> a[i];
    for (int j=1;j<=b[0];++j)
        cin >> b[j];
}

void Init()
{
    Log[1] = 0;
    for (int i=2;i<maxn;++i)
        Log[i] = Log[i/2] + 1;
    for (int i=1;i<=a[0];++i)
        mna[0][i] = a[i];
    for (int i=1;i<=b[0];++i)
        mnb[0][i] = b[i];
    for (int k=1;k<=20;++k)
        for (int i=1;i<=a[0];++i)
            if (i + (1 << (k-1)) <= a[0])
                mna[k][i] = min(mna[k-1][i],mna[k-1][i+(1<<(k-1))]);
            else
                mna[k][i] = mna[k-1][i];
    for (int k=1;k<=20;++k)
        for (int i=1;i<=b[0];++i)
            if (i + (1 << (k-1)) <= b[0])
                mnb[k][i] = min(mnb[k-1][i],mnb[k-1][i+(1<<(k-1))]);
            else
                mnb[k][i] = mnb[k-1][i];
}

void Combine(int s1[], int s2[], int s[])
{
    for (int i=1,j=1,freze_i=0,freze_j=0;i<=s1[0] || j<=s2[0];) {
        while (freze_i != 0 && s1[freze_i] < min(s1[i],s2[j])) {
            s[++s[0]] = s1[freze_i];
            ++freze_i;
            ++freze_j;
            if (freze_i == i)
                freze_i = freze_j = 0;
        }
        if (s1[i] != s2[j])
            if (s1[i] < s2[j]) {
                s[++s[0]] = s1[i++];
                if (freze_j != 0) {
                    j = freze_j;
                    freze_i = freze_j = 0;
                }
            }
            else {
                s[++s[0]] = s2[j++];
                if (freze_i != 0) {
                    i = freze_i;
                    freze_i = freze_j = 0;
                }
            }
        else {
            if (freze_i == 0) {
                freze_i = i;
                freze_j = j;
            }
            s[++s[0]] = s1[i];
            ++i;
            ++j;
        }
    }
}

void Solve()
{
    for (int chosea=0;chosea<=min(a[0],k);++chosea) {
        int choseb = k - chosea;
        if (choseb < 0 || b[0] < choseb)
            continue;
        s1[0] = 0;
        for (int i=1,j=a[0]-chosea+1;j<=a[0];++i,++j) {
            int mn = min(mna[Log[j-i+1]][i],mna[Log[j-i+1]][j-(1<<Log[j-i+1])+1]);
            s1[++s1[0]] = mn;
            while (a[i] != mn)
                ++i;
        }
        s1[s1[0]+1] = +oo;
        s2[0] = 0;
        for (int i=1,j=b[0]-choseb+1;j<=b[0];++i,++j) {
            int mn = min(mnb[Log[j-i+1]][i],mnb[Log[j-i+1]][j-(1<<Log[j-i+1])+1]);
            s2[++s2[0]] = mn;
            while (b[i] != mn)
                ++i;
        }
        s2[s2[0]+1] = +oo;
        Combine(s1,s2,s);
        if (res[0] == 0)
            swap(res,s);
        else
            for (int i=1;i<=res[0];++i)
                if (res[i] != s[i]) {
                    if (res[i] > s[i])
                        swap(res,s);
                    break;
                }
    }
    for (int i=1;i<=res[0];++i)
        cout << res[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifdef LHL
    freopen(".INP","r",stdin);
    freopen(".OUT","w",stdout);
#else
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
#endif // LHL

    Enter();
    Init();
    Solve();
}
