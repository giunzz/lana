#include<bits/stdc++.h>
using namespace std;
const string file = "giun";
#define balabolo(a) freopen((a + ".inp").c_str(), "r", stdin) ,freopen((a + ".out").c_str(), "w", stdout)
#define giun ios_base::sync_with_stdio(0) , cin.tie(0);

vector <int> arr = { 1 , 2 , 3 , 8};
bool ans = false;
bool checkQuadrilateral(vector<int> arr)
{
    int a , b , c, d;
    
    a =  arr[0] , b = arr[1] , c = arr[2] , d = arr[3];
    if (a+b > abs (c-d) && c+b > abs (a-d) ) ans = true;
    if (a+c > abs (b-d) && c+b > abs (a-d) ) ans = true;
    if (a+d > abs (b-c) && c+b > abs (a-d) ) ans = true;
    if (c+b > abs (a-d) && a+d > abs (c-b) ) ans = true;
    if (d+b > abs (a-c) && a+c > abs (d-b) ) ans = true;
    if (c+d > abs (a-b) && a+b > abs (c+d) ) ans = true;
    return ans;
}

int main()
{
    balabolo(file);
    giun;
    //arr[0] = 1 , arr[1] = 2 , arr[2] = 3 , arr[3] = 8;
    checkQuadrilateral(arr);
    cout << ans;


}