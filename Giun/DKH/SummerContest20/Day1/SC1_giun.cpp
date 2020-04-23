#include<bits/stdc++.h>
using namespace std;
const string tenfile = "f";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

string s , num , x;
int n ,  ok = 0;
vector <int> ans;

int main()
{
    balabalo;
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    

    for (int i = 1 ; i <= n ; i++)
    {
        cin >> s ;
        for (int j = 0 ; j <= 8 ; j++)
        {
            ok = 0;
            cin >> num;
            for (int z = 0 ; z <= (int) num.length() ; z++)
                if ( num[z] >= 48 && num[z] <= 57) x += num[z];
            cerr << x << " ";
            for (int i = x.size() ; i >= 0 ; i++)
            {
                if (x == s) 
                {
                    ans.push_back(j);
                    ok = 1;
                    break;
                }
            }
        }
        if ( ok == 0 ) ans.push_back(20);
        cerr << endl;
    }
    sort(ans.begin() , ans.end());
    for (int i = ans.size() ; i >= 0 ; i--)
    {
        switch (ans[i])
        {
            case 0:
                cout << "Giai_dac_biet";
                break;
            case 1:
                cout << "Giai_nhat";
                break;
            case 2:
                cout << "Giai_nhi";
                break;
            case 3:
                cout << "Giai_ba";
                break;
            case 4:
                cout << "Giai_tu";
                break;
            case 5:
                cout << "Giai_nam";
                break;
            case 6:
                cout << "Giai_sau";
                break;
            case 7:
                cout << "Giai_bay";
                break;
            case 8:
                cout << "Giai_tam";
            default:
                cout << "NONE";
                break;
            } 
    }
    return 0;
}
