#include<bits/stdc++.h>
using namespace std;
const int mn=3003;
int n,m,k;
int a[mn],b[mn];
deque<int>q;
vector<int> bo(int a[mn],int m2,int n2)
{
  int i=1;
  while(m2>0)
  {
      while(!q.empty()&&a[q.back()]>a[i]&&m>0)
        {
            m2--;
            q.pop_back();
       }
      q.push_back(i);
      i++;
      if(i==n2+1)
      {
          while(!q.empty()&&m2>0)
            {
                q.pop_back();
                m2--;
            }
      }
  }
  vector<int>res;
  while(!q.empty()){res.push_back(q.front());q.pop_front();}
  for(int j=i;j<=n;j++)res.push_back(j);
  return res;
}
vector<int>kq;
vector<int> minn(vector<int> a,vector<int>b)
{
    for(int i=0;i<k;i++)
        {
            if(a[i]<b[i])return a;
            if(a[i]>b[i])return b;
        }
        return a;
}
int main()
{
    srand(time(0));
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    for(int i=1;i<=k;i++)kq.push_back(100000009);
    for(int i=0;i<=n;i++)
    {
        int h=k-i;
        if(h<0||h>m)continue;
        vector<int> v=bo(a,n-i,n);
        vector<int> v1=bo(b,m-h,m);
        int l=0;
        int r=0;
        vector<int> res;
        while(l<i||r<h)
        {
            if(l==i) {res.push_back(b[v1[r]]);r++;continue;}
            if(r==h) {res.push_back(a[v[l]]);l++;continue;}
            if(a[v[l]]<b[v1[r]]) {res.push_back(a[v[l]]);l++;}
            else {res.push_back(b[v1[r]]);r++;}
        }
        kq=minn(kq,res);
    }
        for(auto z:kq)cout<<z<<" ";
    return 0;
}
