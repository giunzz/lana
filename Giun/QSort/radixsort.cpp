#include<iostream> 
#include<stdio.h>
using namespace std; 
int n, a[(int)1e7 + 7], output[(int)1e7 + 7];  
// A utility function to get maximum value in arr[] 
int getMax(int n) 
{ 
    int mx = a[1]; 
    for (int i = 2; i <= n; i++) 
        if (a[i] > mx) 
            mx = a[i]; 
    return mx; 
} 
  
// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(int n, int exp) 
{ 
    // output array 
    int i, count[10] = {0}; 
  
    // Store count of occurrences in count[] 
    for (i = 1; i <= n; i++) 
        count[ (a[i]/exp)%10 ]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n; i > 0; i--) 
    { 
        output[count[ (a[i]/exp)%10 ] - 1] = a[i]; 
        count[ (a[i]/exp)%10 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 1; i <= n; i++) 
        a[i] = output[i]; 
} 
  
// The main function to that sorts arr[] of size n using  
// Radix Sort 
void radixsort(int n) 
{ 
    // Find the maximum number to know number of digits 
    int m = getMax(n); 
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(n, exp); 
} 
  
// A utility function to print an array 
void print(int n) 
{ 
    for (int i = 1; i <= n; i++) 
        cout << a[i] << " "; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    radixsort(n); 
    print(n); 
    return 0; 
} 