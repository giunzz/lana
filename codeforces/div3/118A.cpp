#include <iostream>
#include <string>
using namespace std;
string s, s1 ="";
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    getline(cin, s);
    for (int i = 0 ; i < (int)s.length() ; i++)
    {
        if (s[i] >='A' && s[i] <= 'Z') s[i] += 32;
        if (s[i] !='a' && s[i] !='o' && s[i] !='y' && s[i] !='e' && s[i] !='u' && s[i] !='i') s1 += s[i];
    }
    for (int i = 0 ; i <(int) s1.length() ; i++) cout <<'.'<< s1[i];
}