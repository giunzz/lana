#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

/*int   dem = 0 , ma = INT_MIN;
string a;
vector <int> st;

int giunnn(char c)
{
    return c - '0';
}
int main()
{
    balabalo;
    giuncute;
    cin >> a; 
    for (int i = 0 ; i < (int) a.length() ; i++)  st.push_back(giunnn(a[i]));
    for (int i = 0 ; i < (int) st.size() ; i++)
    {
        if (ma < st[i])
        {
            dem = i ;
            ma = st[i];
        }
    }
    for (int i = 0 ; i < dem ; i++) st.push_back(st[i]);
    cout << dem  << endl;
    for (int i = dem ; i < (int) st.size() ; i++) cout << st[i];
}*/
string s,st;
int t = 0;
int main(){
	balabalo;
    giuncute;
    cin >> s;
	st = s;
	for (int  i = 1 ;  i < (int) s.length() ; i++)
    {
        cerr <<  s.substr(1,s.length()-1) << " " << s.substr(0,1) << endl;
		s = s.substr(1,s.length()-1) + s.substr(0,1);
		if (s > st) st = s , t=i;
        
	}
	cout << t << endl << st;
	return 0;
}


