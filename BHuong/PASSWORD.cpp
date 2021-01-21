#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
string s1 , s;
int sang[1007]={0} , ans = 0;
void xaysang()
{
    sang[0] = 1; sang[1] = 1;
    for (int i = 2; i * i <= 1000; i++)
        if (!sang[i]) 
           for (int j = i * 2; j <= 1000; j += i) sang[j] = 1;
}
int stringToNum(char c){return c - '0';}
int main()
{
    giuncute;
    freopen("PASSWORD.inp","r",stdin);
    freopen("PASSWORD.out","w",stdout);
    cin >> s1 ;
    xaysang();
    for (int  i = 0 ; i < (int) s1.size() ; i++)
    {
        if (s1[i] >= '0' && s1[i] <='9') s += s1[i];
    }
    //cerr << s << endl;
    for (int i = 0 ; i < (int) s.size() ; i++)
    {
        int  j = i , t =0;
        for (int k = 1 ; k <= 3 ; k++)
        {
            t = t*10+stringToNum(s[j]);
            //cerr << t << " ";
            if (t > 105) break;
            else if (!sang[t])  ans = max(ans,t);
            j++;
            if (j == (int) s.size()) break;
        }
    }
    cout << ans;
}