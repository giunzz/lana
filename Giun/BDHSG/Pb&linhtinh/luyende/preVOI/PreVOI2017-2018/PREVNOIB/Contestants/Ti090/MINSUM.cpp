#include <bits/stdc++.h>

using namespace std;

int t, a, b, lim, c[111], resa, resb, minn;
vector<int> vt;

void check()
{
    int tmpa=1, tmpb=1;
    for (int i=0; i<vt.size(); i++)
        if (c[i]==0) tmpa*=vt[i];
        else tmpb*=vt[i];
    if (tmpa+tmpb<minn)
    {
        minn=tmpa+tmpb;
        resa=tmpa;
        resb=tmpb;
    }
}

void Try(int i)
{
    for (int j=0; j<=1; j++)
    {
        c[i]=j;
        if (i==vt.size()-1) check();
        else Try(i+1);
    }
}

int main()
{
    freopen("MINSUM.INP", "r", stdin);
    freopen("MINSUM.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    for (int in=1; in<=t; in++)
    {
        cin>>a>>b;
        vt.clear();
        lim=max(int(sqrt(a)), int(sqrt(b)));
        for (int i=2; i<=lim; i++)
        {
            int cnt=0;
            while (a%i==0) { cnt++; a/=i; }
	    while (b%i==0) { cnt++; b/=i; }
            if (cnt%2==1) vt.push_back(i);
        }
        if (a>1) vt.push_back(a);
        if (b>1) vt.push_back(b);
        if (vt.size()==0) cout<<1<<" "<<1<<"\n";
        else
        {
            minn=2*1e9+11;
            Try(0);
            cout<<resa<<" "<<resb<<"\n";
        }
    }
    return 0;
}
