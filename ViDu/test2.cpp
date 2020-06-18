#include<bits/stdc++.h>

using namespace std;

char* delAm( char* a)
{
    // cout << a;
    char* p = new char(strlen(a)+ 1);
    strcpy(p, ((const char*)a));
    int last;
    for (int i = 1 ; p[i] != '\0' ; i++ ) 
    {
        p[i-1] = p[i], last = i;    
    }
    p[last] = '\0';
    return p;
}

char* del0( char* a)
{
    // cerr << a << endl;
    char* p2 = new char(strlen(a) + 1);
    strcpy(p2, ((const char*)a));
    // cout << p2 << endl;
    int last;
    if(0 == strlen(p2) - 1)  p2[0] = '\0';
    else {
        while(strlen(p2) > 1 && p2[0] == '0'){
            for (int i = 1 ; p2[i] != '\0' ; i++ ) 
            {
                p2[i-1] = p2[i], last = i;    
            }
            p2[last] = '\0';
        }
    } 
    return p2;
}

int main(){
    char* test = "-0005678";
    // char* p = new char(strlen(test)+ 1);
    // strcpy(p, ((const char*)test));
    // del(p,0);
    // while ( strlen(p) > 1 && p[0] == '0'   ){
    //     // cout << strlen(test) << endl;
    //     del(p, 0);
    //     // cerr << test << endl;
    // }
    // test = p;
    // delete[] p;
    // cout << test;
    test = delAm(test);
    test = del0(test);
    cout << test;
}