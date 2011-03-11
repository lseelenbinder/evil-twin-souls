#include "test.h"
#include "bigint.h"
#include <string>

void example_test() {
    BigInt b = string("100");

    assert(b.toString() == "100", "Test string constructor");
}

int main() {
    example_test();
    return 0;
}
