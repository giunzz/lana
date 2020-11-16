//
//  main.cpp
//  seed
//
//  Created by Trần Nam Khánh on 11/15/20.
//

#include <iostream>
#include <vector>
using namespace std;
long long n,l,m;
string s;
struct trie
{
    long long p,au,g[2];
    long long child[2],pa,leaf;
    trie(long long tmppa,long long tmpp)
    {
        pa=tmppa;
        p=tmpp;
        au=-1;
        g[0]=-1;
        g[1]=-1;
        child[0]=-1;
        child[1]=-1;
        leaf=0;
    }
};
vector<trie> tries;
vector<vector<long long> >dp;
long long cal(long long id,long long ch)
{
    if(tries[id].au!=-1)return tries[id].au;
    long long ans=0;
    if(tries[id].pa!=0)
    {
        long long cur=cal(tries[id].pa,tries[tries[id].pa].p);
        while(cur!=0&&tries[cur].child[ch]==-1)
        {
            cur=cal(cur,tries[cur].p);
        }
        if(cur!=0)
        {
            ans=tries[cur].child[ch];
        }else
        {
            if(tries[cur].child[ch]!=-1)
            {
                ans=tries[cur].child[ch];
            }else ans=cur;
        }
    }else
    {
        ans=0;
    }
    return tries[id].au=ans;
}
void add(long long id,long long ch)
{
    if(tries[id].child[ch]!=-1)return;
    tries.push_back(trie(id,ch));
    tries[id].child[ch]=(long long)tries.size()-1;
}
void precal()
{
    tries.push_back(trie(0,0));
    for(long long i=0;i<s.length();i++)
    {
        if(s[i]=='*')m++;
    }
    for(long long i=0;i<(1ll<<m);i++)
    {
        long long l=0,cur=0;
        for(long long j=0;j<s.length();j++)
        {
            if(s[j]=='1')
            {
                add(cur,1);
                cur=tries[cur].child[1];
            }else
            {
                long long tmp=((1ll<<l)&i)!=0;
                add(cur,tmp);
                l++;
                cur=tries[cur].child[tmp];
            }
        }
        tries[cur].leaf=1;
    }
}
long long go(long long i,long long ch)
{
    if(tries[i].child[ch]!=-1)return tries[i].child[ch];
    if(i==0)return 0;
    if(tries[i].g[ch]!=-1)return tries[i].g[ch];
    long long cur=cal(i,tries[i].p);
    long long ans=0;
    while(cur!=0&&tries[cur].child[ch]==-1)
    {
        cur=cal(cur,tries[cur].p);
    }
    if(tries[cur].child[ch]==-1)ans=0;else ans=tries[cur].child[ch];
    return tries[i].g[ch]=ans;
}
long long tinh(long long i,long long id)
{
    if(i>n)return 1;
    if(dp[i][id]!=-1)return dp[i][id];
    long long ans=0;
    for(long long d=0;d<=1;d++)
    {
        long long tmp=go(id,d);
        if(tries[tmp].leaf==0)ans+=tinh(i+1,tmp);
    }
    //cout<<i<<" "<<id<<" "<<ans<<endl;u
    return dp[i][id]=ans;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    cin>>s;
    l=(long long)s.length();
    precal();
    dp.resize(n+1,vector<long long>(tries.size()));
    for(long long i=0;i<=n;i++)
    {
        for(long long j=0;j<tries.size();j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<(long long)(1ll<<n)-tinh(1,0)<<endl;
    return 0;
}
/*
 1010
 1011
 1111
 1110
 1101
 0101
 */
//20 1*1*1*1***11
//8 1*1*11





