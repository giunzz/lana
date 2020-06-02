#include <iostream>
#include <cmath>
using namespace std;
int n,m;
int checkprime(int n)
{
    if(n<2) return 0;
    if(n<=3) return 1;
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0) return 0;
    return 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        for(int i=m; i<=n;i++)
            if(checkprime(i)) cout<<i<<endl;
        cout<<endl;
    }
}
