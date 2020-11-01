#include <bits/stdc++.h>
using namespace std;
ifstream fi("Bubbletea.inp");
ofstream fo("Bubbletea.out");
typedef pair<long long,long long> ii;
bool check=true;
long long n,k,kq,a[500005],b[500005];
vector <ii> v[500005];
map <int,int> ma;
bool DFS(int x)
{
    b[x]=1;
    long long dem=0,nho;
    for (int i=0; i<v[x].size(); ++i)
    {
        int z=v[x][i].first;
        if (b[z]==0) if (DFS(z)==false) ++dem,nho=v[x][i].second;
    }
    if (dem==0) return false;
    if (dem==1)
    {
        kq=max(kq,nho);
        return true;
    }
    check=false;
    return false;
}
void sub2()
{
    if (k%2==0&&DFS(1)==true&&check==true) fo<<kq;
    else fo<<-1;
}
void sub13()
{

}
int main()
{
    int x,y,z;
    fi>>n>>k;
    for (int i=1; i<=k; ++i)
    {
        fi>>a[i];
    }
    for (int i=1; i<n; ++i)
    {
        fi>>x>>y>>z;
        v[x].push_back(ii(y,z));
        v[y].push_back(ii(x,z));
    }
    sub2();
}
