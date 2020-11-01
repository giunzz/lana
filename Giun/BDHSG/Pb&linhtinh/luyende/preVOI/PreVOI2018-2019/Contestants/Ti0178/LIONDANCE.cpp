// ILTH
// PreVnoi 2018 ^^

#include<bits/stdc++.h>

using namespace std;
const int PMTH = 4005;
vector<long long> BIT[PMTH];
string ans;
long long n, delta, a[PMTH], b[PMTH], nn, mm, aa[PMTH], bb[PMTH], bestconfig;

int Tenter()
{
    cin >> n >> delta;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    return 0;
}

string to_str(long long num)
{
    string ans = "";
    while (num>0)
    {
        ans = char(num%10+48) + ans;
        num /= 10;
    }
    return ans;
}

int upd()
{
    if (nn>=bestconfig) bestconfig = nn;
    else return 0;
    string tmp = "";

    for(int i=1; i<=nn; i++) tmp = tmp + to_str(aa[i]) + " " ;
    if (tmp.size()>ans.size()) ans = tmp;
    else
        ans = tmp;
    return 0;
}

int getbit(int pos, long long n)
{
    return (n>>(pos-1))&1;
}

int check()
{
    for(int i=2; i<=nn; i++) if (abs(aa[i]-aa[i-1])>delta) return false;
    for(int i=2; i<=mm; i++) if (abs(bb[i]-bb[i-1])>delta) return false;
    for(int i=1; i<=nn; i++) if (aa[i]!=bb[i]) return false;
    return true;
}

int Tsolve()
{

    for(int i=1; i<(1<<n); i++)
    {
        int cnt = 0;
        for(int pos=1; pos<=n; pos++)
            if (getbit(pos,i)) cnt++;
        BIT[cnt].push_back(i);
    }
    for(int k=1; k<=n; k++)
    {
        for(int i=0; i<BIT[k].size(); i++)
            for(int j=0; j<BIT[k].size(); j++)
            {
                nn = 0; mm = 0;
                long long x = BIT[k][i], y = BIT[k][j];
                for(int pos=1; pos<=n; pos++)
                {
                    if (getbit(pos,x)) aa[++nn] = a[pos];
                    if (getbit(pos,y)) bb[++mm] = b[pos];
                }
                if ((mm==nn)&&check()) upd();
            }
    }
    cout << bestconfig << "\n" << ans;

    return 0;
}

int main()
{
    freopen("LIONDANCE.INP","r",stdin);
    freopen("LIONDANCE.OUT","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Tenter();
    Tsolve();

    return 0;
}
