#include <bits/stdc++.h>
using namespace std;
int n,mmax;
long long MOD=1e9+7;
int dem(0);
void qlvc(int time,int m[4])
{
    cerr<<"";
    for(int i(1);i<=3;++i)
    {
        int a[4];
        for(int j(1);j<=3;++j)a[j]=m[j];
            if(time==n){++dem;break;}
        if(i==1&&m[1]==mmax) continue;
        else if(i==1) {a[1]+=1;qlvc(time+1,a);continue;}
        if(i==2&&m[1]==0||m[2]==mmax) continue;
        else if(i==2) {a[2]+=1;a[1]-=1;qlvc(time+1,a);continue;}
        if(i==3&&m[3]==mmax) break;
        if(i==3&&m[1]>=3) {a[1]-=3;a[3]++;qlvc(time+1,a);}
        if(i==3&&m[1]>=1&&m[2]>=1) {a[1]--;a[2]--;a[3]++;qlvc(time+1,a);}
    }
}
int main()
{
    ifstream cin("ICECREAM.inp");
    ofstream cout("ICECREAM.out");
    cin>>n>>mmax;
    int m[4];
    for(int i(1);i<=3;++i)
        cin>>m[i];
    qlvc(0,m);
    cout<<dem%MOD;
}
