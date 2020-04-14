/*http://codeforces.com/contest/977/problem/A
Little girl Tanya is learning how to decrease a number by one, 
but she does it wrong with a number consisting of two or more  digits. 
Tanya subtracts one from a number by the following 
algorithm:

if the last digit of the number is non-zero, 
she decreases the number by one;
if the last digit of the number is zero, 
she divides the number by 10 (i.e. removes the last digit).
You are given an integer number n. 
Tanya will subtract one from it k times. Your task is to print the result after all k subtractions.

It is guaranteed that the result will be positive integer number.

( 2 ≤ n ≤ 109 , 1 ≤k ≤50)*/

#include<bits/stdc++.h>
using namespace std;
long n ;
int k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    while ( k != 0 )
    {
        if (n % 10 == 0) n /= 10;
        else n--;
        k--;
    }
    cout << n;
    return 0;
}


