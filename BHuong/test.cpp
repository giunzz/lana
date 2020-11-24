#include <bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;
int t , n , a[(int) 1e5 + 7];
int main()
{
	//freopen("giun.inp","r",stdin);
    //freopen("giun.out","w",stdout);
	giuncute;
	cin >> t;
	while (t--)  
	{
		cin >> n ;
		int  ans = n;
		for (int i = 0 ;  i < n ; i++) cin >> a[i];
		vector<int> b;		
		b.push_back(a[0]);
		for (int i = 1 ; i < n ; i++) if (a[i] != a[i-1]) b.push_back(a[i]);
		n = b.size();
		//for (int i = 0 ; i < n ; i++) cerr << b[i] << " ";
		//cerr << endl;
		map<int,int> giun;
		for (int i = 0 ; i < n ; i++) giun[b[i]]++;
		giun[b[0]]-- , giun[b[n-1]]--;
		for (auto j : giun) 
		{
			//cerr << j.first << " " << j.second << endl;
			ans = min(ans , j.second);
		}
		cerr << endl;
		cout << ans+1 << endl;
	}
}
/*#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("giun.inp","r",stdin);
//    freopen("giun.out","w",stdout);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> b;
    b.push_back(a[0]);
    for (int j = 1; j < n; j++){
      if (a[j] != a[j - 1]){
        b.push_back(a[j]);
      }
    }
	n = b.size();
    map<int, int> mp;
    for (int j = 0; j < n; j++){
      mp[b[j]]++;
    }
    mp[b[0]]--;
    mp[b[n - 1]]--;
    int ans = n;
    for (auto P : mp){
	//	cerr << P.first << " " << P.second << endl;
      ans = min(ans, P.second);
    }
	//cerr << endl;
    cout << ans + 1 << endl;
  }
}*/