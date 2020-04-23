#include <iostream>
#include <fstream>

using namespace std;

int quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int left_ = low, right_ = high - 1, pi = a[high];

        while(true) 
        {
            while (left_ < high && a[left_] < pi)
                left_++;
            while (right_ > low && a[right_] > pi)
                right_--;
            if (left_ < right_) //>= thi da chuyen het so
                swap(a[left_],a[right_]);// left_++, right_--;
            else break;
        }

        swap(a[left_],a[high]);

        quicksort(a, low, left_ - 1);
        quicksort(a, left_ + 1, high);
    }
}

int main()
{
    ifstream nhap;
    ofstream xuat;
    nhap.open("DATA.INP");
    xuat.open("DATA.OUT");

    int n, i = 0;
    nhap >> n;
    int a[n];
    while (nhap >> a[i]) i++;

    quicksort(a, 0, n-1);
    for (int i = 0; i < n; i++)
        xuat << a[i] << " ";

    nhap.close();
    xuat.close();
    return 0;
}
