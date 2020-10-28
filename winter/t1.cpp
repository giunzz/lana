#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int length;
    cin >> length; cin.ignore();
    int n;
    vector<int> a;
    cin >> n; cin.ignore();
    for (int i = 1; i <= n; i++) 
    {
        if (length % 2)
        {
            for (int j = 0; j < length; j++) {
                int si;
                
                cin >> si; cin.ignore();
                a.push_back(si);
            }
            int diff = a[1] - a[0];
            bool ok = 1;
            if(diff <= 0) ok = 0;
            for (int j = 2 ; j <= a.size()/2; j++)
            {
                if (a[j] - a[j-1] != diff) ok = 0;
            }
            for (int j = a.size()/2 + 1  ; j < a.size() ; j++)
            {
                if (a[j] - a[j-1] != -diff) ok = 0;
            }
            if (ok) cout << diff << " " << a[a.size()/2 ] << endl;
            else cout << "No Mountain Sequence" << endl;
        }
        else cout << "No Mountain Sequence" << endl;
    }
}
