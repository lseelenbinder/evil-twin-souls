#include <vector>
#include <iostream>
#include <string>

using namespace std;

class BigInt {
    private:
        vector <char> num;
        BigInt(vector <char>);
        void reduce();

    public:
        BigInt(const int i);
        BigInt(string i);
        string toString();
    
        BigInt& operator=(const BigInt& i);
        
        const BigInt operator+(const BigInt& i);
        const BigInt operator*(const BigInt& i);
};
