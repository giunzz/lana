#include <bits/stdc++.h>
using namespace std;
int n,k;
long long sl[1000001],sr[1000001],in,res=10000000000000;
long long msl[1000001],msr[1000001];
vector <long long> gft;
int main(){
    freopen("GIFTS.inp","r",stdin);
    freopen("GIFTS.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    gft.push_back(0);
    for(int i=0;i<n;i++){
        cin>>in;
        gft.push_back(in);
    }
    gft.push_back(0);
    for(int i=1;i<=k;i++){
        sl[i]=sl[i-1]+gft[i];
        sr[n-i+1]=sr[n-i+2]+gft[n-i+1];
    }
    for(int i=k+1;i<=n;i++){
        sl[i]=sl[i-1]+gft[i]-gft[i-k];
        sr[n-i+1]=sr[n-i+2]+gft[n-i+1]-gft[n-i+1+k];
    }
    for(int i=1;i<=n;i++){
        msl[i]=max(msl[i-1],sl[i]);
        msr[n-i+1]=max(msr[n-i+2],sr[n-i+1]);
    }
    for(int i=1;i<=n-k+1;i++)
        if(i>k&&i<=n-2*k+1)
            res=min(res,max(msl[i-1],msr[i+k]));
    cout << res;
}
