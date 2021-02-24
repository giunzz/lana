#include<bits/stdc++.h>
using namespace std;
const string tenfile = "bai47ql";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

int n ;
char X[30];
char a[] = {'(' ,')' };

bool KT_Ngoac()
{
    int d=0;
    for(int i=1;i<=n;i++)
    {
        if(X[i]=='(')d+=1;
        else d-=1;
        if(d<0)return false;
    }
    return (d==0);
}


void GhiNghiem()
{
    if(!KT_Ngoac())return;
    for(int i=1;i<=n;i++)cout<<X[i];
    cout<<endl;
}

void Try(int i)
{
    for(char j='(';j<=')';j++)
    {
        X[i]=j;
        if(i==n) GhiNghiem();
        else Try(i+1);
    }
}


int main()
{
    balabalo;
    giuncute;
    cin >> n;
    n*=2 ;
    Try(1);
}
