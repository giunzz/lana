#include<bits/stdc++.h>
using namespace std; 
#define ll long long
string s1 , s2 , ans ="";
ll l[1007][1007] ={{0}};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> s1 >> s2;
    for (int i = 1 ; i < s1.size() ; i++)
    {
        for (int j = 1 ; j < s2.size() ; j++)
        {
            if (s1[i] == s2[j]) l[i][j] = l[i-1][j-1]+1;
            else l[i][j] = max(l[i-1][j], l[i][j-1]);
        }
    }
    for (int i = 0 ; i < s1.size() ; i++)
    {
        for (int j = 0 ; j < s2.size() ; j++)
        {
            cerr << l[i][j] << " ";
        }
        cerr << endl;
    }
    ans ="";
    cout << l[(ll) s1.size() - 1][(ll)s2.size() - 1 ] << endl;
    ll n = s1.size()-1 , m = s2.size()-1, i = n , j = m ;
    while (i >= 0 && j >= 0 )
    {
        if (s1[i] == s2[j]) ans+=s1[i] , i--,j--;
        else if (l[i-1][j] == l[i][j])i--;
        else j--;
        cerr << ans << " ";
    }
    reverse(ans.begin(), ans.end());
    cout << ans << " ";

}
