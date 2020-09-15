#include<iostream>
#include<vector>
#include<stdio.h>
#include<string.h>
using namespace std;
vector <int> v;
int n;
bool b[1000],a[1000];
int main()
{
    freopen("MANGDEP.inp","r",stdin);
    freopen("MANGDEP.out","w",stdout);
    cin>>n;
    v.push_back(0);
    int x;
    memset(b,sizeof(b),false);
    b[4]=true;b[8]=true;b[15]=true;
    b[16]=true;b[23]=true;b[42]=true;;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(b[x]==false)ans++;
        else
        {
            v.push_back(x);
            a[x]++;
        }
    }
    //for(int i=1;i<=n;i++)cout<<v[i]<<" ";
    //cout<<endl;
    for(int i=1;i<=6;i++)
    {
        if(i==1)
        {
            x=4;
            if(a[x]==0)
            {
                cout<<n;return 0;
            }
        }
        else if(i==2)
        {
            x=8;
            if(a[x]==0)
            {
                cout<<n;return 0;
            }
        }
        else if(i==3)
        {
            x=15;
            if(a[x]==0)
            {
                cout<<n;return 0;
            }
        }
        else if(i==4)
        {
            x=16;
            if(a[x]==0)
            {
                cout<<n;return 0;
            }
        }
        else if(i==5)
        {
            x=23;
            if(a[x]==0)
            {
                cout<<n;return 0;
            }
        }
        else if(i==6)
        {
            x=42;
            if(a[x]==0)
            {
                cout<<n;return 0;
            }
        }
    }




    cout<<ans;
}
