#include<bits/stdc++.h>
using namespace std;

#define LL long long int
vector<pair<LL,LL> > a;
LL N,M,P;
void play()
{
    sort(a.begin(),a.end());
    LL grundy_value=1, ans = 0;
    LL i;
    for(i=1;i<P;i++)
    {
            if(a[i]==a[i-1])
            grundy_value++;
            else
            {
            LL x,y;
            x=a[i-1].first;
            y=a[i-1].second;
            if( (x+y) % 2 != (1+M) % 2) //(1,M) is the destination
            ans^=grundy_value;
            grundy_value=1;
            }
    }
            LL x,y;
            x=a[P-1].first;
            y=a[P-1].second;
            if( (x+y) % 2 != (1+M) % 2) //(1,M) is the destination
            ans^=grundy_value;

    cout<<(ans ? "Yes" : "No")<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("INSQ15_G.inp", "r", stdin);
    freopen("INSQ15_G.ans", "w", stdout);
    LL i,j;
    cin>>N>>M>>P;
    for(i=0;i<P;i++)
    {
        LL X,Y;
        cin>>X>>Y;
        a.push_back(make_pair(X,Y));
    }
    play();
    return 0;
}