#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

int n, a[22] , dd[1009]={0}, mi = INT_MAX , sum1 = 0 ;

void C2H5OH (int vt)
{
    dd[a[vt]] = 1;
    sum1 = a[vt];
    for (int i = 1 ; i <= n ; i++)
    {
        dd[sum-a[i]]
        sum += a[i]
    }
   
        
        
int main()
{
    balabalo;
    giuncute;
    cin >> n ;
    int sum = 0;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , sum += a[i], dd[sum] = 1;
    C2H5OH(1);    
}
