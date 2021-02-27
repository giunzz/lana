#include<bits/stdc++.h>
using namespace std;
const string tenfile = "bai49ql";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long
string S,X;
map<string,bool> d;
bool C[30]={false};
ll n;
void Try (int i)
{
    for(int j=0;j<n;j++)
    {
        if(!C[j])
        {
            X[i]=S[j];
            C[j]=true;
            if(i==n-1)
            {
                if (d[X] != 1) cout << X << endl;
                d[X] = 1;
            } 
            else Try(i+1);
            C[j]=false;
        }
    }
}
int main()
{   
    balabalo;
    giuncute;
    cin>> S;
    n=S.length();
    X=S;
    Try(0);
    return 0;
}
