#include <iostream>

using namespace std;

unsigned long int daoso(long int n, long int dao)
{
    dao = dao * 10 + n % 10;
    n /= 10;
    if (n != 0)

using namespace std;

unsigned long int daoso(long int n, long int dao)
{
    dao = dao * 10 + n % 10;
    n /= 10;
    if (n != 0)
        return daoso(n, dao);
    return dao;
}

int main()
{
    unsigned long int n, dao = 0;
    cout << "N = ";
    cin >> n;
    cout << daoso(n, dao);

    return 0;
}
        return daoso(n, dao);
    return dao;
}

int main()
{
    unsigned long int n, dao = 0;
    cout << "N = ";
    cin >> n;
    cout << daoso(n, dao);

    return 0;
}
