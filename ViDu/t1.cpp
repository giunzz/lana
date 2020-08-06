#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    int N,ans;
    string s;
    cin >> N; 
    getline(cin,s);
    for (int i = 0; i < N; i++) 
    {
        getline(cin, s);
        ans = 0;
        for (int j = 0 ; j < (int) s.length() ; j++)
        {
            if (s[j] >='0' && s[j] <='9') ans++;
        }
        cout << ans << endl;       
    }
}