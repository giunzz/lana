#include <iostream>
#include <string>
using namespace std;
 
bool doixung(string s)
{
    for (int i=0; i<=s.length()/2; i++)
        if (s[i]!=s[s.length()-i-1])
            return 0;
    return 1;
}
 
int main()
{
    string s;
    getline(cin,s); 
    if (doixung(s))
        cout << "La xau doi xung";
    else
        cout << "ko la xau doi xung";
    return 0;
}