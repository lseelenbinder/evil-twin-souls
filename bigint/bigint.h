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
        BigInt(const long long int i);
        BigInt(string i);
        string toString();
    
        BigInt& operator=(const BigInt& i);
        BigInt& operator=(const long long int i);
        
        const BigInt operator+(const BigInt& i);
        const BigInt operator*(const BigInt& i);
};
