#include <iostream>
#include <cstring>
using namespace std;
int n;
int b[1001];
int ans=0;
int main()
{
    freopen("beautP.inp","r",stdin);
    freopen("beautP.out","w",stdout);
    cin>>n;
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        b[x]++;
    }
    while(1)
    {
        int tmp=0;
        for(int i=1;i<=1000;i++)
            if(b[i]>0)
                {
                    tmp++;
                    b[i]--;
                }
                if(tmp==0) break;
                ans+=tmp-1;
    }
    cout<<ans;
}
