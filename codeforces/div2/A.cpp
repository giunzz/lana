//https://codeforces.com/contest/1469/problem/A
#include<bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
using namespace std;
#define ll long long
string s ;
int n ;
int main()
{
    giuncute;
//    freopen("giun.inp","r",stdin);
//    freopen("giun.out","w",stdout);
    cin >> n;
    /*while (n--)
    {
        int d = 0;
        cin >> s;
        if (s[0] == ')' || s[s.length()-1] == '(') cout << "NO" << endl;
        else 
            {
                for (int i = 0 ; i < s.length() ; i++)
                {
                if (s[i] == '(' ) d++;
                else if (s[i] == ')') d--;
                else if (s[i] == '?')
                    {
                        if (d > 0) d--;
                        else  d++; 
                    }
                }
                if (d == 0) cout << "YES" << endl;
                else cout << "NO" << endl;
            }        
    }*/
    while (n--)
    {
        cin >> s;
        vector<char> giun ;
        if (s[0] == ')' || s[s.length()-1] == '(') cout << "NO" << endl;
        else 
            {
                int d = 0 ;
                for (int i = 0 ; i < s.length() ; i++)
                {
                    if (s[i] == '(' ) giun.push_back(s[i]);
                    else if (s[i] == '?')  d++;
                    else 
                    {
                        if (d != 0 ) 
                        {
                            char c = '(';
                            for (int j = 1 ; j <= d ; j++)
                            {
                                giun.push_back(c) ;
                                if (c == '(') c = ')';
                                else c = '(';
                            } 
                            d = 0;
                        }
                            giun.push_back(s[i]);
                            d = 0;
                    }
                }
                int v = 0 ;
                if ( giun.empty() == true && d%2 == 0 && d != 0) v = 0;
                else for (int i = 0 ; i < giun.size() ; i++)
                    {
                        if (giun[i] == '(') v++;
                        else   v--;
                    }
                if (v == 0) cout << "YES" << endl;
                else cout<< "NO" << endl;
            }
    }
}