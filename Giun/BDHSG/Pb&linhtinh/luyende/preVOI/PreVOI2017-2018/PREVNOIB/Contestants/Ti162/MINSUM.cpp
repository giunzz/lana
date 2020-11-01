#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int sa[maxn],sb[maxn];
int t;
int a,b;
int nt[maxn];
int s[maxn];
int d;
void sang(int maxn)
{
    nt[1]=0;
    nt[2]=1;
    nt[3]=1;
    for(int i=2;i<=maxn;++i)
        if(i%6==1||i%6==5) nt[i]=1;
    for(int i=1;i<=maxn;++i)
    if(nt[i])
    {
        s[++d]=i;
        int j=i*i;
        while(j<=maxn)
        {
            nt[j]=0;
            j+=i;
        }
    }
}
void nhap()
{
    cin>>t;
    sang(maxn);
    while(t--)
    {
        cin>>a>>b;
       int  aa=a;
        int  bb=b;
        for(int i=1;i<=d;++i)
        {
            while(aa%s[i]==0)
            {
                sa[i]++;
                aa=aa/s[i];
            }
            while(bb%s[i]==0)
            {
                sb[i]++;
                bb=bb/s[i];
            }
            if(sa[i]>=sb[i])
            {
                a=a/pow(s[i],sb[i]);
                b=b/pow(s[i],sb[i]);
                sa[i]=sa[i]-sb[i];
                sb[i]=0;
            }
            else
            {
                a=a/pow(s[i],sa[i]);
                b=b/pow(s[i],sa[i]);
                sa[i]=0;
                sb[i]=sb[i]-sa[i];

            }
            if(sa[i]==0&&sb[i]>=2)
                b=b/pow(s[i],2*(sb[i]/2)),sb[i]=sb[i]%2;
            if(sb[i]==0&&sa[i]>=2)
                a=a/pow(s[i],2*(sa[i]/2)),sa[i]=sa[i]%2;
                for(int i=1;i<=d;++i)
                    if(sa[i])
                    {
                        if(a/s[i]+b*s[i]<a+b) a=a/s[i],b=b*s[i];
                        sa[i]=0;
                        sb[i]=0;
                    }
                    else if(sb[i])
                    {
                          if(a*s[i]+b/s[i]<a+b) a=a*s[i],b=b/s[i];
                        sa[i]=0;
                        sb[i]=0;
                    }

        }
        cout<<a<<" "<<b<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("MINSUM.INP","r",stdin);
    freopen("MINSUM.OUT","w",stdout);
    nhap();
}
