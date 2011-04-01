#include "test.h"
#include "bigint.h"
#include <string>

void ls_test() {
    // Luke Seelenbinder Tests
    BigInt ls1 = string("100");

    assert(ls1.toString() == "100", "Test string constructor");
}

void ev_test() {
    // Elias Villiger Tests
    BigInt ev10("12345");
    assert(ev10.toString() == "12345", "String constructor and ToString() test.");
    
    BigInt ev11("00134");
    assert(ev11.toString() == "134", "String constructor with 0's test.");
    
    BigInt ev20(142);
    assert(ev20.toString() == "142", "Int constructor test.");
    
    BigInt ev21(90);
    assert(ev21.toString() == "90", "ToString test.");
    
    BigInt ev22(100);
    BigInt ev23(50);
    ev23 = ev22;
    assert(ev23.toString() == "100", "Operator= assignment test.");
    
    BigInt ev24(0);
    assert(ev24.toString() == "0", "Zero number test.");
    
    BigInt ev25("000");
    assert(ev25.toString() == "0", "Multiple zero number test.");
    
    BigInt ev30(9);
    BigInt ev31(18);
    BigInt ev32 = ev30 + ev31;
    assert(ev32.toString() == "27", "Addition with small numbers");
    
    BigInt ev33("1000000000000000000000000000000");
    BigInt ev34("2000000000000000000000000000000");
    BigInt ev35 = ev33 + ev34;
    assert(ev35.toString() == "3000000000000000000000000000000", "Addition with big numbers");
    
    BigInt ev36(9999);
    BigInt ev37(1);
    BigInt ev38 = ev36 + ev37;
    assert(ev38.toString() == "10000", "Addition with medium numbers");
    
    BigInt ev39a("00012359827530012312312398498230498");
    BigInt ev39b("93489080923952310124023958792308203");
    BigInt ev39c = ev39a + ev39b;
    assert(ev39c.toString() == "93501440751482322436336357290538701", "Addition with big random numbers");
    
    BigInt ev40(10);
    BigInt ev41(5);
    BigInt ev42 = ev40 * ev41;
    assert(ev42.toString() == "50", "Multiplication with small numbers");
    
    BigInt ev43(999);
    BigInt ev44(872);
    BigInt ev45 = ev43 * ev44;
    assert(ev45.toString() == "871128", "Multiplication with medium small numbers");
        
    BigInt ev46("1000000000000000000000000000000");
    BigInt ev47("9000000000000000000000000000009");
    BigInt ev48 = ev46 * ev47;
    assert(ev48.toString() == "9000000000000000000000000000009000000000000000000000000000000", "Multiplication with big numbers");

    // 500 digits each -- SUCCESSFUL but uncommented because it takes some seconds
    /*BigInt ev49("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    BigInt ev50("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    BigInt ev51 = ev49 * ev50;
    assert(ev51.toString() == "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "Multiplication with huge numbers");
    */
    
    BigInt ev52("1259238582924858");
    BigInt ev53("2849385934024938");
    BigInt ev54 = ev52 * ev53;
    assert(ev54.toString() == "3588056705767585855928352108804", "Multiplication test with medium big numbers.");

    BigInt ev60("100");
    ev60 = 55;
    assert(ev60.toString() == "55", "Int assignment test.");
}

void td_test() {
    // Thomas Dalton Tests
}

int main() {
    user = "Luke";
    ls_test();
    user = "Elias";
    ev_test();
    user = "Thomas";
    td_test();
    return 0;
}