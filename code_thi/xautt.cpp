#include<bits/stdc++.h>

using namespace std;

int n = 1;
string st[5009] , tam ="";
string ans = "";

int main()
{
    ios_base::sync_with_stdio(0) , cin.tie(0);
    freopen("xautt.inp","r",stdin);
    freopen("xautt.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >>st[i] ; //, n = max(st[i].length() , n );
    }
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = i+1 ; j <= n ; j++){
            tam.clear();
            for (int z = 0; z < (int)min(st[i].length(), st[j].length()); z++){
                if(st[i][z] != st[j][z]) {
                    if(ans.empty() || tam.length() > ans.length()) ans = tam;
                    else if(tam.length() == ans.length() && tam < ans) ans = tam;
                    break;
                }
                else tam.push_back(st[i][z]);
            }
        } 
    }
    cout << ans;
    return 0;
    
}