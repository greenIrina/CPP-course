#include <iostream>
#include "Driver.h"

using namespace std;


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Driver dr;
    dr.main();
    return 0;
}
