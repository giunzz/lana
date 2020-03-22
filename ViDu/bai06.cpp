#include<bits/stdc++.h>

using namespace std;

int n , s  , k , d = 0 , len , ans1 ;
int dd[1007]={0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.inp","r",stdin);
    freopen("output.txt","w",stdout);
    
    //freopen("Bai06.inp","r",stdin);
    //freopen("Bai06.out","w",stdout);
    cin >> n >> s >> k;
    
    vector <int> tam; 

    while ( len != n-1 )
    {
        for(int i = 1 ; i <= n ; i++)
        {
            if ( dd[i] == 0 ) d++;
            if (d == s ) 
            {
                dd[i] = 1;
                d = 0;
                len++;
                if ( k == i )
                {
                    tam.push_back(i);
                    for ( int j = i + 1 ; j <= n ; j++ )
                    {
                        if ( dd[j] == 0 ) tam.push_back(j);
                    }
                    for ( int j = 1 ; j < i ; j++ ) 
                    {
                        if ( dd[j] == 0 ) tam.push_back(j);
                    }
                } 
            }
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        if (dd[i] == 0) ans1 = i;
        //cerr << i << " "  << dd[i] << endl;
    }
    //cerr << endl;
    for (int i = 0 ; i < (int) tam.size() ; i ++)  cerr << tam[i] << " ";
    cout << ans1 << endl << tam[s-1];
    return 0;
}