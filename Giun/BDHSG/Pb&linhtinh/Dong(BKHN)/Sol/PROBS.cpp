//
//  main.cpp
//  probs
//
//  Created by Trần Nam Khánh on 11/14/20.
//

#include <iostream>
#include <cmath>
using namespace std;
const long long M=1e9+7;
long long n,dp[50][11][(1<<5)][2],k,l;
long long cal(long long i,long long nho,long long ok,long long tt)
{
    if(i<0&&nho==0&&ok==((1<<(k-1))-1)&&tt)return 1;
    if(i<0)return 0;
    if(dp[i][nho][ok][tt]!=-1)return dp[i][nho][ok][tt];
    long long ans=0;
    for(long long ad=0;ad<(1<<k);ad++)
    {
        long long newok=ok,s=0;
        for(long long j=0;j<k-1;j++)
        {
            long long I=((ad&(1<<j))!=0),I1=((ad&(1<<(j+1)))!=0);
            s+=I;
            if((ok&(1<<j))==0&&(I>I1))
            {
                newok=-1;
                break;
            }
            if(I<I1)
            {
                newok|=(1<<j);
            }
        }
        s+=((ad&(1<<(k-1)))!=0);
        if(newok==-1)continue;
        for(long long nhotmp=0;nhotmp<=10;nhotmp++)
        {
            long long tmp=(((s+nhotmp)&1)<<i),tmp2=(n&(long long)(1ll<<i));
            if((tmp==tmp2)&&((s+nhotmp)>>1)==nho)
            {
                ans+=cal(i-1,nhotmp,newok,tt||(ad&1));
                ans%=M;
            }
        }
    }
    return dp[i][nho][ok][tt]=ans;
}
int main() {
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    l=log2(n);
    for(long long i=0;i<=l;i++)
    {
        for(long long j=0;j<=10;j++)
        {
            for(long long z=0;z<(1<<k);z++)
            {
                dp[i][j][z][1]=-1;
                dp[i][j][z][0]=-1;
            }
        }
    }
    cout<<cal(l,0,0,0)<<endl;
    return 0;
}
//nho=(tong+nhotmp)/10
//1010

