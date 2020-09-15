#include<bits/stdc++.h>
using namespace std;
int ok[7];
int a[1000009];
vector<int> b[7];
//int dem[7];
int main()
{
    freopen("MANGDEP.inp","r",stdin);
    freopen("MANGDEP.out","w",stdout);
    int n;
    cin>>n;
    ok[4]=1;
    ok[8]=2;
    ok[15]=3;
    ok[16]=4;
    ok[23]=5;
    ok[42]=6;
    for (int i=1;i<=n;i++)
    {
        int u;
        cin>>u;
        a[i]=ok[u];
        b[ok[u]].push_back(i);
    }
    int kat=b[1].size();
    //cout<<kat<<endl;
    for (int i=2;i<=6;i++)
    {
        int j=0;
        int t=0;
        int tam=0;
        while (t<b[i-1].size() && j<b[i].size())
        {
            int v=b[i][j];
            int o=b[i-1][t];
            if (v<o)
            {
                j++;
            }
            else
            {
                t++;
                j++;
                tam++;
            }
        }
        kat=min(kat,tam);
    }
    cout<<n-kat*6<<endl;
    return 0;
}
