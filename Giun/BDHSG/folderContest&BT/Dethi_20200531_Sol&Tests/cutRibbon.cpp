#include <iostream>
using namespace std;
int main()
{
    int n,a,b,c,i,j,k,ans=0;
    cin>>n>>a>>b>>c;
    if(a==1 or b==1 or c == 1)
    {
        cout<<n;
        return 0;
    }
    for(int i=0;i<=n/a;i++)
        for(int j=0;j<=(n-i*a)/b;j++)
        for(int k=0;k<=(n-i*a-j*b)/c;k++)
            if(i*a+j*b+k*c==n) ans=max(ans,i+j+k);
    cout<<ans;
}
