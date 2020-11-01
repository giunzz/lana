#include <bits/stdc++.h>

using namespace std;
int n,res;
int a[10000];
vector<int> t[10000];
void setup()
{
        cin >> n;
        for (int i=1;i<=n;++i)
                cin >> a[i];
        for (int i=1;i<=n;++i)
                t[i].push_back(0);
        for (int i=1;i<=n-1;++i)
        {
                int x,y;
                cin >> x >> y;
                t[x].push_back(y);
        }


}

void dfs(int i)
{

        int tg=0;
        int tmp=t[i].size()-1;
        if (tmp==0)
        {
                if (a[i]==0)
                        res+=1;
                a[i]=1;
                return;
        }
        for (int j=1;j<=tmp;++j)
        {
                dfs(t[i][j]);
                tg+=a[t[i][j]];
        }
        if (a[i]!=tg)
                res+=abs(a[i]-tg);
        a[i]=tg;
        return;

}

void solve()
{
        dfs(1);
        cout << res;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("TREE.inp","r",stdin);
    freopen("TREE.out","w",stdout);
    setup();
    solve();
    return 0;
}
