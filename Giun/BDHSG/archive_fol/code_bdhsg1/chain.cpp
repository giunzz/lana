#include<bits/stdc++.h>
using namespace std;
int n , l[(int) 5e5+7],ans=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("f.inp","r",stdin);
    freopen("f.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> l[i];
    sort(l+1,l+1+n);
    int  j = 1 ;
    for (int i = n ; i >= 1 ; i--)
    {
        if (j < i)
        {
            ans++; 
            l[j]--;
        }
        else {break;}
        if(l[j] == 0) j++;
 //       cerr << j << " " << i << endl;
    }
    cout << ans;
}