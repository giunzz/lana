#include<bits/stdc++.h>
using namespace std;
const string tenfile = "SC1";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

string s , num , x , s1;
long n ,  ok = 0;
vector <int> ans;

int main()
{
    balabalo;
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
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
                ans.push_back(j);
                ok = 1;
                break;
                    
            }
        }
        if ( ok == 0 ) ans.push_back(20);
    }
    sort(ans.begin() , ans.end());
    for (int i = (int) ans.size() -1  ; i >= 0 ; i--)
    {
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
}
