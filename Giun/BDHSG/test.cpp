// #include <bits/stdc++.h>

// using namespace std;

// int main(){
//     int a, b;
//     vector<int> cs;
//     cin >> a >> b;
//     while(a){
//         cs.push_back(a%b);
//         a /= b;
//     }
//     reverse(cs.begin(), cs.end());
//     for(int i : cs) cout << i;
// }
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,d=0;
vector<ll> ans;
int main()
{

  cin >> a >> b;
  while (a != 0)
  {
    ans.push_back(a%b);
    a/=b;
    //for (ll i = 0 ; i < ans.size() ; i++) cout << ans[i];
    //cout << endl;
  }
  
  //reverse(ans);
 // reverse(ans.begin(),ans.end());
  
    reverse(ans.begin(), ans.end()); 
 d = 0;
  for (ll i = 0 ; i < ans.size() ; i++) 
  {
    if ( ans[i]!= 0) d = 1;
    if (d) cout << ans[i];
  }

}