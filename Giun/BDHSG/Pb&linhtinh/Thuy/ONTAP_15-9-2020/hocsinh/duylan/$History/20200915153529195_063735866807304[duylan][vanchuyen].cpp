#include <bits/stdc++.h>
using namespace std;
#define MAX (int)3e5+2
struct hang
{
    int kg,v;
}a[MAX];
int n,m,c,res=0;
set <int> s;
set <int> ::iterator it;
bool cmp(hang x,hang y)
{
    return x.v>y.v;
}
int main()
{
    freopen("vanchuyen.inp","r",stdin);
    freopen("vanchuyen.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        cin >> a[i].kg >> a[i].v;
    for (int i=1;i<=m;i++)
    {
        cin >> c;
        s.insert(c);
    }
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<=n;i++)
    {
        it=s.lower_bound(a[i].kg);
        if (it!=s.end())
        {
            res+=a[i].v;
            s.erase(it);
        }
    }
    cout << res;
    return 0;
}
