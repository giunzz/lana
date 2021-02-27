#include <bits/stdc++.h>
using namespace std;
int  n , d = 0; ;
string ans;
void chon (int vt)
{
    for (int i = 'A' ; i <= 'C' ; i++)
    {
        if ( vt > 0 && ans[vt - 1] == 'B' && i == 'C' || vt > 0 && ans[vt - 1] == 'C' && i == 'B' ) continue;
        ans.push_back(i);
        if ( (int) ans.length() == n ) d++;
        else chon (vt + 1);
        ans.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    freopen("GXAU.inp","r",stdin);freopen("GXAU.out","w",stdout);
    cin >> n;
    chon(0);
    cout << d++;
}
