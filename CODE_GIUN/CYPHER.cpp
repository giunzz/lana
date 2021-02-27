#include <cstdio>
#include <algorithm>
#include<iostream>
#include <fstream>     
#include <math.h>
//#define giuncute freopen("CYPHER.INP", "r", stdin) , freopen("CYPHER.OUT", "w", stdout)
#define giuncute freopen("input.inp", "r", stdin) , freopen("output.txt", "w", stdout)
#define giun ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;

long n ;

char numToString(int k){
    return (char)(k+48);
}

string Dec2Bin1 (long n) 
{
    string s, ans; int si = 0;
    while (n != 0)
        while (s.length() != 8)
        {
           s.push_back(n % 2);
           n /= 2;
        }
    for (int i = 7 ; i >  0 ; i-- )  si += s[i] * pow(2, i); //e có thể tối ưu pow(2, i)
    ans.push_back(char(si));
    s.clear(), si = 0;
    reverse (ans.begin(), ans.end());
    return ans;
}

string Dec2Bin (long u) 
{ 
    int Num ;
    string bala ="" , ans ="";
    while (u > 0) 
    { 
        Num = u % 2; 
        if  (bala.length() != 8) bala += numToString(Num) , u = u / 2;
        else  reverse(bala.begin(), bala.end() ) , ans += bala , bala ="";
        cerr << bala << endl;     
    }   
    cerr << ans.length(); 
    return ans;     
} 

int BinToDec(long long binaryNumber)
{
    int p = 0;
    int decNumber = 0;
    while (binaryNumber > 0)
    {
        decNumber += (binaryNumber % 10) * pow(2, p);
        ++p;
        binaryNumber /= 10;
    }
    return decNumber;
}

int main()
{
    giun;
    giuncute;
    cin >> n ;
    cout << Dec2Bin(n) << endl << Dec2Bin1 (n);
    return 0;
}
