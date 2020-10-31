#include<bits/stdc++.h>
using namespace std;
ifstream fi("MINSUM.INP");
ofstream fo("MINSUM.OUT");
long long x, y, ans1,ans2,ans;
int cnt=0,p[51],a,b;
vector<int>pr;
bool f[50001];
void bt(int k)
{
    if(x+y>=ans)return;
    if(k==cnt+1)
    {
        ans=x+y;
        ans1=x;
        ans2=y;
        return;
    }
    x*=p[k]; bt(k+1); x/=p[k];
    y*=p[k]; bt(k+1); y/=p[k];
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int T;
    fi>>T;
    for(int i=2;i<=sqrt(1000000000);++i)
        if(!f[i])
        {
            pr.push_back(i);
            for(int j=2*i;j<=sqrt(1000000000);j+=i)f[j]=true;
        }
    while(T--)
    {
        fi>>a>>b;
        x=a,y=b;cnt=0;
        for(int i=0;i<(int)pr.size();++i)
        {
            int sl=0;
            while(x%pr[i]==0)sl++,x/=pr[i];
            while(y%pr[i]==0)sl++,y/=pr[i];
            if(sl&1)
            {
                ++cnt;
                p[cnt]=pr[i];
            }
        }
        if(x!=1&&y==x)cnt++,p[cnt]=x;
        else
        {
            if(x!=1)cnt++,p[cnt]=x;
            if(y!=1)cnt++,p[cnt]=y;
        }
        x=1,y=1;
        ans=a+b;
        ans1=a;
        ans2=b;
        bt(1);
        fo<<ans1<<' '<<ans2<<"\n";
    }
}
