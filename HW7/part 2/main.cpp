#include <iostream>

using namespace std;

struct Foo {
    void say() const {
        cout << "Foo says: " << msg << "\n";
    }

protected:
    explicit Foo(const char *msg) : msg(msg) {}

private:
    const char *msg;
};

void foo_says(const Foo &foo) {
    foo.say();
}

struct Bar : public Foo {
    explicit Bar(const char *msg) : Foo(msg) {}
};

const Foo get_foo(const char *msg) {
    return Bar(msg);
}


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    foo_says(get_foo("hhhh"));

    return 0;
}