#include <bits/stdc++.h>

using namespace std;
int n, a[100007], b[100007];

int maxDiff(int arr[], int arr_size)
{
     // Maximum difference found so far
     int max_diff = arr[1] - arr[0];

     // Minimum number visited so far
     int minelement = arr[0];
     for(int i = 1; i < arr_size; i++)
     {
       if (arr[i] - minelement > max_diff)
       max_diff = arr[i] - minelement;

       if (arr[i] < minelement)
       minelement = arr[i];
     }

     return max_diff;
}

int main(){
    cin >> n;
    for (int i = 1; i <= 1; i++){
        cin >> a[i];
        b[i] = a[i];
    }
}
