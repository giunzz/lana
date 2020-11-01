#include<bits/stdc++.h>
using namespace std;
int n,m,k,M1[1005][1005],M2[1005][1005],trace1[1005][1005],trace2[1005][1005],a[1005],b[1005];
vector<int> res;
vector<int> megre(vector<int> now1, vector<int> now2)
{
    vector<int> now;
    now1.push_back(9999999);now2.push_back(9999999);
    now1.push_back(9999999);now2.push_back(9999999);
    int vt1=0, vt2=0;
    while (now.size()<k)
    {
        if (now1[vt1]<now2[vt2]) {now.push_back(now1[vt1]); vt1++;}
        if (now1[vt1]>now2[vt2]) {now.push_back(now2[vt2]); vt2++;}
        if (now1[vt1]==now2[vt2])
        {
            if (now1[vt1+1]>now2[vt2+1]) {now.push_back(now2[vt2]);vt2++;}
            else {now.push_back(now1[vt1]);vt1++;}
        }
    }
    return now;
}
int main()
{
	freopen("SEQUENCE.inp","r",stdin);
	freopen("SEQUENCE.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int j=1;j<=m;j++) cin>>b[j];
	for (int i=1;i<=n;i++) for (int j=i;j<=n;j++)
    {
        M1[i][j]=a[i];
        trace1[i][j]=i;
        for (int g=i;g<=j;g++) if (M1[i][j]>a[g])
        {
            M1[i][j]=a[g];
            trace1[i][j]=g;
        }
    }
    for (int i=1;i<=m;i++) for (int j=i;j<=m;j++)
    {
        M2[i][j]=b[i];
        trace2[i][j]=i;
        for (int g=i;g<=j;g++) if (M2[i][j]>b[g])
        {
            M2[i][j]=b[g];
            trace2[i][j]=g;
        }
    }
    for (int num=0;num<=min(n,k);num++)
    {
        if (k-num>m) continue;
        vector<int> now1;
        int vt1=1;
        for (int i=1;i<=num;i++)
        {
            int vt2=n-(num-i);
            now1.push_back(M1[vt1][vt2]);
            vt1=trace1[vt1][vt2]+1;
        }
        vector<int> now2;
        vt1=1;
        for (int i=1;i<=k-num;i++)
        {
            int vt2=m-(k-num-i);
            now2.push_back(M2[vt1][vt2]);
            vt1=trace2[vt1][vt2]+1;
        }
        vector<int> now=megre(now1,now2);
        if (res.size()==0) res=now; else
        {
            for (int i=0;i<k;i++) if (res[i]>now[i]) {res=now;break;}
        }
    }
    for (int i=0;i<k;i++) cout<<res[i]<<" ";
	return 0;
}


