/*#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

string s , num , x , s1;
long n ,  ok = 0;
vector <int> ans , tam;

int main()
{
    balabalo;
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        tam.clear();
        cin >> s ;
        cin.ignore();
        for (int j = 0 ; j <= 8 ; j++)
        {
            x="";
            s1 ="";
           getline (cin , num) ;
            int z = num.length()-1 ;
                while (num[z] != ' ')
                {
                       x += num[z]; 
                       z--;             
                }
            reverse(x.begin() , x.end());
            for (int k = s.length() - x.length() ; k <(int) s.length()  ; k++ )
                s1 += s[k];
            if ( s1 == x)
            {
                tam.push_back(j);
                ok = 1;
            }
        }
        if ( ok == 0 ) ans.push_back(20);
        else 
        {
            int t1 = tam[0];
            for (int yy = 1 ; yy < (int)tam.size() ; yy++)
                t1 = max ( t1 , tam[yy]);
            ans.push_back(t1);
        }
    }
    sort(ans.begin() , ans.end());
    for (int i = (int) ans.size() -1  ; i >= 0 ; i--)
    {
        cerr << ans[i] << " ";
        switch (ans[i])
        {
            case 0:
                cout << "Giai_dac_biet" << endl;
                break;
            case 1:
                cout << "Giai_nhat" << endl;
                break;
            case 2:
                cout << "Giai_nhi" << endl;
                break;
            case 3:
                cout << "Giai_ba"<<endl;
                break;
            case 4:
                cout << "Giai_tu"<<endl;
                break;
            case 5:
                cout << "Giai_nam"<<endl;
                break;
            case 6:
                cout << "Giai_sau"<<endl;
                break;
            case 7:
                cout << "Giai_bay"<<endl;
                break;
            case 8:
                cout << "Giai_tam"<<endl;
            default:
                cout << "NONE"<<endl;
                break;
            } 
    }
    return 0;
}*/

#include <bits/stdc++.h> 

using namespace std;

int test; 
string s; 

bool check(string st) {
  for (int i = (int) st.size() - 1, j = (int) s.size() - 1; i >= 0; i--, j--) {
    if (st[i] != s[j]) {
      return false;
    }
  }
  return true; 
}

int main () {
  freopen("giun.INP", "r", stdin);
  freopen("giun.OUT", "w", stdout);
  cin >> test;
  for (int tt = 1; tt <= test; tt++) {
    bool found = false; 
    string res = "NONE"; 
    cin >> s; 
    for (int i = 1; i <= 9; i++) {
      string name, st;
      cin >> name >> st; 
      if (found == false && check(st) == true) {
        found = true;
        res = name;   
      }
    }
    if (res[(int) res.size() - 1] == ':') {
      res = res.substr(0, (int) res.size() - 1); 
    }                                    
    cout << res << endl; 
  }
  return 0; 
}
