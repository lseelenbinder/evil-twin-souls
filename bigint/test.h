#include<iostream>
#include<string>

using namespace std;

string user;

bool failed(string s) {
    s += " (by " + user + ')';
    cout << "!!! Test failed !!!: " << s << endl;
    return false;
}
bool passed(string s) {
    s += " (by " + user + ')';
    cout << "Test passed: " << s << endl;
    return true;
}

bool assert(bool b, string s) {
    if (!b) {
        return failed(s);
    }
    else {
        return passed(s);
    }
}

bool assert_false(bool b, string s) {
    if (b) {
        return failed(s);
    }
    else {
        return passed(s);
    };
}

bool assert_equal_int(int i, int x, string s) {
    if (i != x) {
        return failed(s);
    }
    else {
        return passed(s);
    }
}

bool assert_equal_str(string s1, string s2, string s) {
    if (s1 != s2) {
        return failed(s);
    }
    else {
        return passed(s);
    }
}
