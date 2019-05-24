#include <iostream>
#include "tests.h"

using namespace std;

int main()
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //testing getline

    char* str;
    str = getline(cin);
    cout << str << endl;
    delete[] str;
    str = getline(cin);
    cout << str << endl;
    delete[] str;

    //

    int n;
    cin >> n;
    testResize(n);
    testSwapMin(n);

    return 0;
}
