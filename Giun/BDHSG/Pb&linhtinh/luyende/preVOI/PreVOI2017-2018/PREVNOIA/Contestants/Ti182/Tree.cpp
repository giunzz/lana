#include <bits/stdc++.h>
using namespace std;
ifstream fi("Tree.inp");
ofstream fo("Tree.out");
long long n,a[5005],kq=1e18;
map <long long,long long> m[5005],b[5005];
map <long long,long long>::iterator it,ti;
vector <int> v[5005];
void DFS(int x)
{
    if (v[x].size()==0)
    {
        for (long long i=0; i<=1; ++i)
            m[x][i]=abs(a[x]-i);
    }
    else if (v[x].size()==1)
    {
        int z=v[x][0];
        DFS(z);
        for (it=m[z].begin(); it!=m[z].end(); ++it)
            m[x][it->first]=it->second+abs(a[x]-it->first);
        //m[z].clear();
    }
    else
    {
        int z1=v[x][0],z2=v[x][1];
        DFS(z1);
        DFS(z2);
        for (it=m[z1].begin(); it!=m[z1].end(); ++it)
            for (ti=m[z2].begin(); ti!=m[z2].end(); ++ti)
            {
                long long tmp=it->first+ti->first;
                if (b[x][tmp]==0) m[x][tmp]=it->second+ti->second+abs(a[x]-tmp),b[x][tmp]=1;
                else m[x][tmp]=min(m[x][tmp],it->second+ti->second+abs(a[x]-tmp));
            }
        /*m[z1].clear();
        b[z1].clear();
        m[z1].clear();
        b[z1].clear();*/
    }
}
int main()
{
    int x,y;
    fi>>n;
    for (int i=1; i<=n; ++i)
        fi>>a[i];
    for (int i=1; i<n; ++i)
    {
        fi>>x>>y;
        v[x].push_back(y);
    }
    DFS(1);
    for (it=m[1].begin(); it!=m[1].end(); ++it) kq=min(kq,it->second);
    fo<<kq;
}
