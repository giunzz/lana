#include<bits/stdc++.h>
using namespace std;

string add(string a , string b)
{
    int  nho = 0 , x,y, sum = 0,t;
    string ans ="";
    while (a.length() < b.length()) a ='0'+a;
    while (b.length() < a.length()) b ='0'+b;
    for (int i = a.length()-1 ; i >= 0 ; i--)
    {
        x = a[i]-'0',y = b[i]-'0';
        sum = x+y+nho,nho = sum /10,t = sum%10;
        ans = (char)(t+48) + ans;
    }
    if (nho > 0 ) ans = '1'+ ans;
    while (ans.length() > 0 &&  ans[0] == '0' ) ans.erase(0,1);
    return ans;
}
string sub (string a , string b)
{
    string ans ="";
    int bor = 0 , s, x,y; 
    while (a.length() < b.length()) a ='0'+a;
    while (b.length() < a.length()) b ='0'+b;
    for (int i = a.length()-1 ; i >= 0 ; i--)
    {
        x = a[i]-'0',y = b[i]-'0';
        s = x-y- bor;
        if (s < 0)
        {
            s += 10;
            bor = 1;
        }
        else bor = 0 ;
        ans = (char) (s+48) + ans;
    }
    while (ans.length() > 0 &&  ans[0] == '0' ) ans.erase(0,1);
    return ans;
}

/*bool ss (string a , string b)
{
    if (a.length() > b.length()) return true;
    else if (a.length() ==  b.length())
    {
        if (a[0]-'0' > b[0]-'0') return true;
    }
}*/

string s1 , s2;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> s1 >> s2;
    cout << add(s1,s2) << endl << sub(s1,s2);
    /*if (s1[0] == '-' && s2[0] == '-')
    {
        s1.erase(0,1), s2.erase(0,1);
        cout << "-" << add(s1,s2) ;
    }
    else if (s1[0] == '-')
    {
        s1.erase(0,1)
        cout << sub(s1,s2);
    }
    cout << sub(s1,s2);*/
}