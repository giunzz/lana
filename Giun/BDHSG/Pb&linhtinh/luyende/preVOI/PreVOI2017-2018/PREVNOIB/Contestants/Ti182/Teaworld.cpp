#include <bits/stdc++.h>
using namespace std;
ifstream fi("Teaworld.inp");
ofstream fo("Teaworld.out");
struct data
{
    int x,y,z,gt;
};
typedef pair <int,int> ii;
data a[2005],c[20],bish;
bool check1,check2;
long long m,n,k,b[20],b1[2005],kq;
vector <ii> v[1005];
void check(data &tmp)
{
    if (tmp.z!=0||tmp.y!=0) check1=false;
    if (tmp.z!=0) check2=false;
    tmp.x+=500;
    tmp.y+=500;
    tmp.z+=500;
}
void Try(int x,long long y)
{
    kq=max(kq,y);
    if (x==n+1) return;
    for (int i=0;i<=1;++i)
    {
        b[x]=i;
        if (b[x]==1)
        {
            int tmp=max(c[x].x,bish.x),tmp1=min(c[x].x,bish.x);
            for (int j=tmp1+1;j<tmp;++j)
            {
                if (v[j].size()>0)
                {
                    for (int h=0;h<v[j].size();++h)
                        b1[v[j][h].first]++;
                }
            }
            for (int h=0;h<v[tmp1].size();++h)
                if (v[tmp1][h].second==1) b1[v[tmp1][h].first]++;
            for (int h=0;h<v[tmp].size();++h)
                if (v[tmp][h].second==0) b1[v[tmp][h].first]++;
            int dem=0;
            for (int j=1;j<=m;++j) if (b1[j]>0) dem++;
            if (dem<=k) Try(x+1,y+c[x].gt);
            for (int j=tmp1+1;j<tmp;++j)
            {
                if (v[j].size()>0)
                {
                    for (int h=0;h<v[j].size();++h)
                        b1[v[j][h].first]--;
                }
            }
            for (int h=0;h<v[tmp1].size();++h)
                if (v[tmp1][h].second==1) b1[v[tmp1][h].first]--;
            for (int h=0;h<v[tmp].size();++h)
                if (v[tmp][h].second==0) b1[v[tmp][h].first]--;
        }
    }
}
void sub1()
{
    for (int i=1; i<=m; ++i)
    {
        //cout<<a[i].x<<" "<<a[i].gt<<endl;
        v[a[i].x+a[i].gt].push_back(ii(i,1));
        v[a[i].x-a[i].gt].push_back(ii(i,0));
    }
    Try(1,0);
    fo<<kq;
}
int main()
{
    bool check1=true,check2=true;
    fi>>m>>n>>k;
    for (int i=1; i<=m; ++i)
    {
        fi>>a[i].x>>a[i].y>>a[i].z>>a[i].gt;
        check(a[i]);
    }
    for (int i=1; i<=n; ++i)
    {
        fi>>c[i].x>>c[i].y>>c[i].z>>c[i].gt;
        check(c[i]);
    }
    fi>>bish.x>>bish.y>>bish.z;
    check(bish);
    if (check1==true) sub1();
    //else if (check2==true) sub2();
    //else sub3();

}
