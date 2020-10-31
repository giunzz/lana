#include <bits/stdc++.h>
#define task "SEQUENCE"
#define nmax 3001
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef pair <int,int> pii;
int n,m,k,c[2*nmax],b[nmax];
pii a[nmax];
vector<pii> res;
vector<string> ans;
bool cmp(pii a, pii b)
{
    return a.second < b.second;
}
bool cmp1(pii a, pii b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}
bool checkmax(string x)
{
    for (int i = 0; i < ans.size() ; i++)
    {
        string s = ans[i];
        for (int j = 0 ; j < x.length(); j++)
            if ((x[j] - '0') > (s[j] - '0')) return false;
    }
    return true;
}
string sa ="" , sb ="";
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a+1,a+m+1,cmp1);
    for (int i = 1; i <= (k - n); i++)
        res.push_back(a[i]);
    sort(res.begin(),res.end(),cmp);
    for (auto x : res)
        sa = sa + char(x.first +'0');

    for (int i = 1; i <= n; i++) cin >> b[i],sb = sb +char(b[i] + '0');
    for (int i = 0; i < sb.length(); i++)
    {
        string tmp1 = sb.substr(0,i) , tmp2 = sb.substr(i, sb.length() - i);
        ans.push_back(tmp1+sa+tmp2);
    }
    cout << ans[0];


}
