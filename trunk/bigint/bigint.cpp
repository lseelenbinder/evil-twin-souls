// Implementation for the BigInt class
// Does NOT support negative numbers.

#include "bigint.h"
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

void BigInt::reduce() {
    // private function that cuts off 0's at the beginning of the number
    if (num[num.size()-1] == '0' && num.size() > 1) {
        vector <char> newNum;
        for (int x = 0; x < num.size()-1; ++x) {
            newNum.push_back(num[x]);
        }
        num = newNum;
        reduce();
    }
}

BigInt::BigInt(const int i) {
    // int constructor
    stringstream ss;
    ss << i;
    string str = ss.str();
    for (int x = str.length()-1; x >= 0; --x) {
       num.push_back(str[x]);
    }
    reduce();
}

BigInt::BigInt(string str) {
    // string constructor
    for (int x = str.length()-1; x >= 0; --x) {
       num.push_back(str[x]);
    }
    reduce();
}

BigInt::BigInt(vector <char> n) {
    // vector<char> constructor
    // does not call reduce()
    num = n;
}

string BigInt::toString() {
    // returns the BigInt as a string
    string str;
    for (int x = num.size()-1; x >= 0; --x) {
        str += num[x];
    }
    return str;
}

BigInt& BigInt::operator=(const BigInt& i) {
    // assigns a BigInt to another BigInt
    num = i.num;
    return *this;
}

const BigInt BigInt::operator+(const BigInt& i) {
    // adds two BigInts
    vector <char> big = (i.num.size() > num.size()?i.num:num);
    vector <char> small = (big == i.num?num:i.num);
    vector <char> result;
    int pushDigit = 0;
    for (int c = 0; c < big.size() || pushDigit > 0; ++c) {
        int numBig = (c < big.size()?big[c] - '0':0);
        int numSmall = (c < small.size()?small[c] - '0':0);
        int newDigit = (numBig+numSmall+pushDigit)%10;
        result.push_back('0' + newDigit);
        pushDigit = ((numBig+numSmall+pushDigit)-newDigit)/10;
    }
    BigInt temp(result);
    return temp;
}

const BigInt BigInt::operator*(const BigInt& i) {
    // Multiplies two BigInts
    BigInt result(0);
    for (int x = 0; x < num.size(); ++x) {
        for (int y = 0; y < i.num.size(); ++y) {
            int digit1 = num[x] - '0';
            int digit2 = i.num[y] - '0';
            stringstream digitResult;
            digitResult << digit1*digit2;
            for (int power = 0; power < x + y; ++power) {
                digitResult << '0';
            }
            BigInt singleResult(digitResult.str());
            result = result + singleResult;
        }
    }
    return result;
}
