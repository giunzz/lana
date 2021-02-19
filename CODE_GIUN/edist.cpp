#include<bits/stdc++.h>
using namespace std; 
#define ll long long
string s1 , s2 ;
ll t , f[3007][3007]; //so buoc it nhat de bien i ki tu dau tien cua xau s thanh j ki tu dau tien cua xau t ;
//fi-1,j xoa , fi,j-1 them, neu si = tj fi-1,j-1 + 0 ,  
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t;
    while(t--)
    {
        for (int i = 1 ; i <= 2000 ; i++) f[i][0] = i;
        for (int j = 1 ; j <= 2000 ; j++) f[0][j] = j;
        cin >> s1 >> s2;
        s1 = '0' + s1;
        s2 = '0' + s2;
        int check = 0;
        for (int i = 1 ; i < s1.length() ; i++)
        {
            for (int j = 1 ; j < s2.length() ; j++)
            {
                f[i][j] = min ({f[i-1][j]+1 , f[i][j-1]+1 , f[i-1][j-1] + (s1[i] != s2[j])});
            }
        }
        cout << f[s1.length()-1][s2.length()-1] << endl;
    }
}
