#include <iostream>
#include <fstream>

using namespace std;

int demsocap(int arr[], int k, int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == k) dem++;
    return dem;
}

int main()
{
    ifstream nhap;
    ofstream xuat;
    nhap.open("FE1.INP");
    xuat.open("FE1.OUT");

    int T, n, k;
    nhap >> T;
    for (int dem = 1; dem <= T; dem++)
    {
    nhap >> n >> k;
    int arr[n];
    for (int _dem = 0; _dem < n; _dem++)
        nhap >> arr[_dem];
    xuat << demsocap(arr, k, n) << endl;
    }

    nhap.close();
    xuat.close();
    return 0;
}
