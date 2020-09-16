#include <bits/stdc++.h>
#include <sys/stat.h>
#define fname "b"

using namespace std;

int main(){
    struct stat buffer;
    if(!stat(fname".inp", &buffer))
        cout << 1;
    else cout << 0;
}