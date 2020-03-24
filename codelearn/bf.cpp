#include <bits/stdc++.h>
using namespace std;
const int maxd = 1e6 + 7;

int kthBiggestFrequency(vector<int> a, int k)
{
    int d[maxd] = {0};
    vector<int> re, red;
    for (vector<int>::iterator ii = a.begin(); ii < a.end(); ii++){
        if(!d[*ii]++) re.push_back(*ii);
    }
    for (int i = 0; i < re.size(); i++){
        red.push_back(d[re[i]]);
    }
    vector<int> reds = red;
    sort(reds.begin(), reds.end());
    int i = reds.size() - 1;
    reds.push_back(INT_MAX);
    while (k > 1 && i >= 0){
        if(reds[i] != reds[i-- + 1]) --k;
    }
    if (k != 1 || i < 0) return -1;
    else {
        for (int j = 0; j < red.size(); j++){
            if (red[j] == reds[i]) return re[j]; 
        }
    }
    return -1;
}

int main(){
    }