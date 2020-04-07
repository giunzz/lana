#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool checkPrime(unsigned long int Num)
{
    int maxCheck = round(sqrt(Num));

    for(int dem = 2; dem <= maxCheck; ++dem)
        if (Num % dem == 0)
            return false;

    return true;
}

int countPrime(unsigned long int firstNum, unsigned long int secondNum)
{
    int dem = 0;

    for(; firstNum <= secondNum; ++firstNum)
        if (checkPrime(firstNum) && firstNum > 1)
            ++dem;

    return dem;
}

int main()
{
    int all;
    ifstream nhapfile;
    nhapfile.open("PRIMECOUNT.INP");
    ofstream xuatFile;
    xuatFile.open("PRIMECOUNT.OUT");

    nhapfile >> all;
    unsigned long int L[all], R[all];
    int dem = 0;

    while (nhapfile >> L[dem] >> R[dem])
        ++dem;

    for(int dem = 0; dem < all; ++dem)
        xuatFile << countPrime(L[dem], R[dem]) << endl;

    nhapfile.close();
    xuatFile.close();
    return 0;
}
