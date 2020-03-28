#include<bits/stdc++.h>
#define giuncute freopen("input.inp", "r", stdin) , freopen("output.txt", "w", stdout)
#define giun ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;

char numToString(int k)
{
    return (char)(k+48);
}

void decToBinary(long n) 
{  
    int binaryNum;  
	string st ="" , ans ="";
    while (n > 0) 
	{ 
 
        if (st.length() != 8)
		{
			binaryNum = n % 2;
			st += numToString(binaryNum); 				 
		}
		else 
		{
			reverse(st.begin(), st.end() );
			ans += st;
			st.clear();
		}    
		n = n / 2;
    } 
	cout <<  ans;
	cerr << ans.length();
} 

string st;
int n ;
int main()
{
	giun;
	giuncute;
	cin >> st;
	cout << st.length();
	cout << endl;
	decToBinary(6382179);
	return 0;
}
