#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;
int t ;
string s;
struct giun 
{
    string nt ;
    int vl;
}a[100];
int main()
{
    giuncute;
    freopen("SPC4.inp","r",stdin);
    freopen("SPC4.out","w",stdout);
    cin >> t;
    while (t--)
    {
        string k ="", t="";
        vector<int>so;
        cin >> s;
        int d = 0;
        for (int i = 0 ; i < (int) s.size() ; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z') d++ , t += s[i];
            else if (s[i] >= 'a' && s[i] <= 'z')  k += s[i]; 
            else if (s[i] >= '2' && s[i] <= '9') so.push_back(s[i]-'0');
            else if ((s[i-1] >= 'A' && s[i-1] <= 'Z') || (s[i-1] >= 'a' && s[i-1] <= 'z'))
            so.push_back(1);
        }
 //       cerr << d << " "  << t << " " << k  << endl;
   //     for (int i = 0 ; i < (int) so.size() ; i++) cerr << so[i] << " ";
     //   cerr << endl;
        for (int i = 1 ; i <= d ; i++ ) 
        {
            //cout << 1;
            cin >> a[i].nt >> a[i].vl ;
            //a[i].nt.pop_back();
            //cerr << a[i].nt << " " << a[i].vl << endl;
        }
        cout << "em chiuuuuuu";        
    }
}
