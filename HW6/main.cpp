#include <iostream>
#include "String.h"

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //not good at writing tests
    String s1("hi");
    String s2('k', 4);
    char* p = const_cast<char*>("hello");
    String s3(p);

    cout << "s1 = " << s1 << ", s2 = " << s2 << ", s3 = " << s3 << endl;

    s1.append(s1);
    cout << "s1.append(s1) : " << s1 << ", size = " << s1.size() << endl;

    String k = s3.substring(1, 2);
    cout << "s3.substring(1, 2) = " << k << endl;

    s2[1] = 'c';
    cout << "s2[1] 'c' : " << s2 << endl;

    s1 = s2;
    cout << "after assigning s2 to s1, s1 is " << s1 << ", s2 is " << s2 << endl;

    String s4(s3);
    cout << "s4 = copy of s3 = " << s4 << endl;

    String s("123");
    int x = s.toInt();
    cout << "int " << x << endl;

    String so = toStr(-25);
    cout << "String " << so << endl;

    s2.append(so);
    cout << s2 << endl;

    return 0;
}
