#include<bits/stdc++.h>
using namespace std;

int sang[(int) 1e7 + 7] ={0};
void ss()
{
    sang[0] = 1, sang [1] = 1;
    for (int i = 2 ; i <= (int) 1e7 ; i++)
        if (!sang[i])
            for (int j = i*2 ; j <= (int) 1e7 ; j+=i) sang[j] = 1;
}
bool isSpecialPrime(int n)
{
    if (n == 0 ) return false;
    ss();
    string s = to_string(n), t ;
    int i = 1, g;
    while ( i <= (int) s.length())
    {
        t = s.substr(0,i);
        g = stoi(t);
        cerr << t << " ";
        if (sang[g] == 1) return false;
        i++;
    }
    return true;
}

int n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    cin >> n;
    if ( isSpecialPrime(n) == true ) cout << "true";
    else cout << "false";
    return 0;
}
