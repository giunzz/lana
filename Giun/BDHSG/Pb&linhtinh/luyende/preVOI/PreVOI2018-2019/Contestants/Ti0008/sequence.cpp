#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int inf=1e9;
int n,m,k,a[3005],b[3005],f[3005][6005],mi[12005],mi1[12005];
void up(int id,int l,int r)
{
    if(l>r) return ;
    if(l==r)
    {
        mi[id]=l;
        return ;
    }
    int mid=(l+r)/2;
    up(id*2,l,mid);
    up(id*2+1,mid+1,r);
    if(a[mi[id*2]]<a[mi[id*2+1]])
        mi[id]=mi[id*2];
    else
    if(a[mi[id*2]]>a[mi[id*2+1]])
        mi[id]=mi[id*2+1];
    else
        mi[id]=min(mi[id*2],mi[id*2+1]);
}
int get(int id,int l,int r,int u,int v)
{
    if(u>r || l>v) return 0;
    if(l>=u && r<=v) return mi[id];
    int mid=(l+r)/2;
    int vt1=get(id*2,l,mid,u,v),vt2=get(id*2+1,mid+1,r,u,v);
    if(a[vt1]<a[vt2]) return vt1;
    if(a[vt1]>a[vt2]) return vt2;
    return min(vt1,vt2);
}
void up1(int id,int l,int r)
{
    if(l>r) return ;
    if(l==r)
    {
        mi1[id]=l;
        return ;
    }
    int mid=(l+r)/2;
    up1(id*2,l,mid);
    up1(id*2+1,mid+1,r);
    if(b[mi1[id*2]]<b[mi1[id*2+1]])
        mi1[id]=mi1[id*2];
    else
    if(b[mi1[id*2]]>b[mi1[id*2+1]])
        mi1[id]=mi1[id*2+1];
    else
        mi1[id]=min(mi1[id*2],mi1[id*2+1]);
}
int get1(int id,int l,int r,int u,int v)
{
    if(u>r || l>v) return 0;
    if(l>=u && r<=v) return mi1[id];
    int mid=(l+r)/2;
    int vt1=get1(id*2,l,mid,u,v),vt2=get1(id*2+1,mid+1,r,u,v);
    if(b[vt1]<b[vt2]) return vt1;
    if(b[vt1]>b[vt2]) return vt2;
    return min(vt1,vt2);
}
vector<int> s1,s2,s3[3000];
string x[3000];
int main()
{
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
   ios_base::sync_with_stdio(false);
   cin>>m>>n>>k;
   for(int i=1;i<=m;i++) cin>>a[i];
   for(int i=1;i<=n;i++) cin>>b[i];
   a[0]=b[0]=inf;
   up(1,1,m);
   up1(1,1,n);
   string z="";
   for(int i=0;i<=3000;i++)
   {
       z=z+" ";
       z[z.size()-1]='9';
   }
   for(int i=max(k-n,0);i<=min(k,m);i++)
   {
        s1.clear();s2.clear();
       int l=1,r=m-i+1;
       int s=0;
       while(s<i && r<=m )
       {
           int c=get(1,1,m,l,r);
           s1.push_back(a[c]);
           s++;
           l=c+1;r++;
       }
       int j=(k-i);
        l=1;r=n-j+1;
        s=0;
       while(s<j && r<=n)
       {
           int c=get1(1,1,n,l,r);
           s2.push_back(b[c]);
           s++;
           l=c+1;r++;
       }
       //if(i==6)
        //for(int j=0;j<s2.size();j++) cout<<s2[j]<<" ";
         l=0;r=0;
        s1.push_back(1e9);s2.push_back(1e9+1);
        while(s3[i].size()<k )
        {
            int l1=l,r1=r;
            while(s1[l1]==s2[r1] && l1<s1.size() && r1<s2.size())
                {
                    l1++,r1++;
                    if(l1>=s1.size() || r1>=s2.size()) break;
                }
            if(s1[l1]<s2[r1]) s3[i].push_back(s1[l]),l++;
            else s3[i].push_back(s2[r]),r++;
        }
        //if(i==5)
            for(int j=0;j<s3[i].size();j++)
            {
                int c=s3[i][j];
                while(c>0)
                {
                    x[i]=x[i]+" ";
                    x[i][x[i].size()-1]=c%10+48;
                    c=c/10;
                }
            }
            if(z>x[i]) z=x[i];
   }
for(int i=0;i<z.size();i++)
    cout<<z[i]<<" ";
    return 0;
}
