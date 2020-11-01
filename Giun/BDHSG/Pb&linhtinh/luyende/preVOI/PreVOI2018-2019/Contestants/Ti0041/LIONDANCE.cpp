#include <bits/stdc++.h>
#define task "LIONDANCE"
#define nmax 4001
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
int n,k,fa[nmax],l[nmax],r[nmax],fb[nmax];
bool ok = 0;
vector<string> res;
bool check(string s)
{
    for (int i = 1; i < s.length(); i++)
        if (abs((s[i] - '0') - (s[i - 1] - '0')) > k) return false;
    return true;
}
bool khop(string s,int len)
{
    int j = 0;
    for (int i = 1; i <= n; i++)
        if (r[i] == (s[j] - '0')) j++;
    return (j == len);
}
void backtrack(string s, int i , int n, int len)
{
    if (i > n)
    {
        if (check(s) && s.length() == len && khop(s,len)) ok = 1, res.push_back(s);
        return;
    }
    backtrack(s + char(l[i]+'0') , i + 1 , n, len);
    backtrack(s , i + 1, n, len);
}
bool checkmax(string x)
{
    for (int i = 0; i < res.size() ; i++)
    {
        string s = res[i];
        for (int j = 0 ; j < x.length(); j++)
            if ((x[j] - '0') < (s[j] - '0')) return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> l[i];
    for (int i = 1; i <= n; i++) cin >> r[i];
    for (int i = n; i >= 1; i--)
    {
        backtrack("",1,n,i);
        if (ok)
        {
            for (auto x : res)
                if (checkmax(x))
                {
                    cout << x.length() <<'\n';
                    for (int i = 0 ; i < x.length() ; i++)
                        cout << x[i] <<' ';
                    exit(0);
                }
        }
    }
}
