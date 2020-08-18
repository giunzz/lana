#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> a;
    a.push_back(1);
    a.push_back(3);
    vector<int>::iterator i;
    i = a.begin();
    cout<< *(i + 1);
}