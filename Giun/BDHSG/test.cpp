#include <bits/stdc++.h>
<<<<<<< HEAD
#include <sys/stat.h>
#define fname "b"

using namespace std;

int main(){
    struct stat buffer;
    if(!stat(fname".inp", &buffer))
        cout << 1;
    else cout << 3;
=======
<<<<<<< HEAD
#include <sys/stat.h>
#define fname "b"

using namespace std;

int main(){
    struct stat buffer;
    if(!stat(fname".inp", &buffer))
        cout << 1;
    else cout << 0;
=======
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a = (long long)1 << (long long)3;
    cout << a;
>>>>>>> 1b5c812d903df17d42541c82c30e0fc279825697
>>>>>>> 71dae57a442cd26f3ab066fd924a841fdd2985b9
}