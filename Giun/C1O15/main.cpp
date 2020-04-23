#include <iostream>
#include <fstream>

using namespace std;
long int sodan[1000000], toado[1000000], soluong = 0, bankinh = 0, dem, tongdan = 0, maxdan = 0;

void tongdankhuvuc()
{
    for (int i = toado[dem] - 1; i <= (toado[dem] + 2 * bankinh - 1); i++)
    {
        for (int j = 0; j <= soluong - 1; j++)
        {
            if (toado[j] == i)
                tongdan += sodan[j];
        }
    }
}

int sodanlonnhat()
{
    for (dem = 0; dem <= soluong - 1; ++dem)
    {
    tongdankhuvuc();
    if (tongdan >= maxdan)
        maxdan = tongdan;
    tongdan = 0;
    }
    return maxdan;
}

int main()
{
    ifstream readfl;
    ofstream writefl;
    readfl.open("MOBI.INP");
    writefl.open("MOBI.OUT");

    readfl >> soluong >> bankinh;
    while (readfl >> toado[dem] >> sodan[dem])
        ++dem;

    writefl << sodanlonnhat();

    readfl.close();
    writefl.close();
    return 0;
}
