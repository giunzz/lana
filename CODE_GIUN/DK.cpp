#include<bits/stdc++.h>
#define ll long long 
#define cll const long long 
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;
vector <string > sub ;
vector<string> name ;
vector<string> ho;
map <string,ll> dd , dn , dh;
string s;
ll  t; 
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t ;
    for (int j = 1 ; j <= t ; j++)
    {
        string a, b, c;
        cin >> a >> b >> c;
        name.push_back(a) , ho.push_back(b);
        if(!dd[c]++) sub.push_back(c);

    }
        sort(sub.begin(),sub.end());
        for (int i =  0 ; i < sub.size(); i++) 
        {
            if (dd[sub[i]] >= 10 ) cout << sub[i] << " " << dd[sub[i]] << " YES" << endl;
            else cout << sub[i] << " " << dd[sub[i]]  << " NO" << endl;
        }
}