#include<bits/stdc++.h>
using namespace std;
const int Nmax=305;
int n,mmax,a[Nmax],x[Nmax],mn[4],ans=0;

void quaylui(int i,int sl1,int sl2,int sl3)
{
    //cout<<i<<" ";
    for(int j=1;j<=3;j++)
    {

        int tmp=mn[j]-50;
        if(tmp!=0&&a[j]+1<=mmax)
        {
        for(int j1=3;j1>=1;j1--)
        {
            if(mn[j1]<=tmp) {int tmp1=min(tmp/mn[j1],a[j1]); tmp-=tmp1*mn[j1]; a[j1]-=tmp1;}
        }
       // cout<<tmp<<endl;
        if(tmp==0)
        {
            x[i]=j;
            a[j]++;
           // cout<<a[1]<<" "<<a[2]<<" "<<a[3];
            if(i==n) {ans++;}
            else
            {
                quaylui(i+1,a[1],a[2],a[3]);

            }
        }
           a[1]=sl1;
            a[2]=sl2;
            a[3]=sl3;
        }
        else if(tmp==0&&a[1]+1<=mmax)
        {
            x[i]=1;
            a[1]++;
            if(i==n) {ans++;}
            else
            {
                quaylui(i+1,a[1],a[2],a[3]);
            }
            a[1]--;
        }
       // cout<<j<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<tmp<<endl;
       // cout<<tmp<<endl;
    }
}

int main()
{
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>mmax;
    int i,j;
    for(i=1;i<=n;i++) cin>>a[i];
    mn[1]=50;mn[2]=100;mn[3]=200;
    quaylui(1,a[1],a[2],a[3]);
    cout<<ans;
}
