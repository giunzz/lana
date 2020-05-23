#include <bits/stdc++.h>
#define changenum 48

using namespace std;

string num;

void sortnum(int chot, int dayso[]){
    for (int i = 0; i != 10; i++){
        if (dayso[i] != 0){
            for (int j = chot; j <= chot + dayso[i]; i++)
                num[j] = changenum + i;
            chot += dayso[i];
        }
    }
}

void hvlonnhonhat (){
    int chot, dayso[10];
    memset(dayso, 0, sizeof(dayso));
    for (int i = num.length() - 1; i != 0; i--){
        ++dayso[num[i] - changenum];
        if (num[i] < num[i - 1]){
            chot = i;
            swap(num[i], num[i - 1]);
            break;
        }
    }
    sortnum(chot, dayso);
}

int main(){
    //freopen("hv.INP", "r", stdin);
    //freopen("hv.OUT", "w", stdout);
    cin >> num;
    hvlonnhonhat();
    cout << num;
    return 0;
}
