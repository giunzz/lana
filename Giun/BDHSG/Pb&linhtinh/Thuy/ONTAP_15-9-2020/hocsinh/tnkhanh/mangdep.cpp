#include <iostream>
#include <fstream>
using namespace std;
int n,p[6]={4,8,15,16,23,42},dem[6],nhan[100];
int main()
{
    freopen("mangdep.inp","r",stdin);
    freopen("mangdep.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0;i<6;i++)nhan[p[i]]=i;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        int tmp=nhan[a];
        dem[tmp]++;
        if(tmp)dem[tmp]=min(dem[tmp],dem[tmp-1]);
    }
    cout<<n-dem[5]*6<<endl;
}
