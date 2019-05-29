#include "Decimal.h"

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Decimal a(1, 2);
    a++;
    a--;
    Decimal b(1, 2);
    b++;
    cout << "a: " << a << ", b: " << b << endl;
    cout << "a == b? " << ((a == b) ? "yes" : "no") << endl;
    cout << "a < b? " << ((a < b) ? "yes" : "no") << endl;

    a += b;
    cout << "a += b: " << a << endl;

    a.reduce();
    cout << "reduced a: " << a << endl;

    Decimal d;
    cin >> d;
    cout << "input d: " << d << endl;

    d++;
    cout << "d++: " << d << endl;
    cout << "double d: " << d.toDouble() << endl;
    cout << "a: " << a << ", b: " << b << ", d: " << d << endl;

    a += b;
    cout << "a += b: " << a << endl;

    auto c = a + d;
    cout << "c: " << c << endl;
    cout << "c == d? " << ((c == d) ? "yes" : "no") << endl;

    c = d;
    cout << "c: " << c << ", d: " << d << endl;

    Decimal dec(d);
    cout << "dec: " << dec << endl;

    Decimal deci(5, 6);
    cout << deci << endl;

    deci = (deci, dec);
    cout << deci << endl;

    deci = *dec;
    cout << deci << endl;
    return 0;
}
