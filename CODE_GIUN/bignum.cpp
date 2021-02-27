#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

vector<int> v1 , v2 , v3;
string s1 , s2;

void remove0( vector<int> &v)
{
    while (v[v.size() - 1] == 0 && v.size() > 1)
    {
        v.pop_back();
    }
}
void addnit(string a , vector<int> &v)
{
    for (int i = a.length() -1; i >= 0 ; i--)
    {
        v.push_back(a[i] -'0');
    }
    remove0(v);
}

void print_ans( vector<int> v)
{
    for (int i = v.size() - 1 ; i >= 0 ; i--) cout <<v[i];
}

int main()
{
        giuncute;
        balabalo;
        cin >> s1 >> s2;
        addnit( s1 , v1);
        addnit( s2 , v2);
        print_ans(v1) ; cout << endl;
        print_ans(v2) ; cout << endl;
        return 0;
    
}