#include<iostream>
#include<fstream>
using namespace std;
const int maxn = 1e4+7;
int n,m,a[maxn][maxn],c[(int) 1e7+7],d[(int) 1e7+7],x,y,dem;
int main()
{
    ifstream f1("CHUYEN03.inp");
    ofstream f2("CHUYEN03.out");
    f1>>n>>m;
    for(int i=1;i<=m;i++)
    {
        f1>>x>>y;
        a[x][y]++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            if(a[i][j]>0) dem++,c[dem]=j;
        d[i]=dem;
    }
    for(int i=0;i<=n;i++) f2<<d[i]<<" ";
    f2<<"\n";
    for(int i=1;i<=dem;i++) f2<<c[i]<< " ";
}
