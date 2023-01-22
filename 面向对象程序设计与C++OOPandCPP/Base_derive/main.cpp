#include "base_derive.h"

using namespace std;
int main() {
    system ("chcp 65001");
    {
        Derived derived(1);
    }
    Base *p_base = new Derived(1);
    delete p_base;

    return 0;
}
