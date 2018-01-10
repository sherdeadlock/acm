#include <iostream>
using namespace std;

void test_from_char() {
    char arr[10] = "hello";
    string s = string(arr);
    cout << s << "\n";
    arr[0] = 'H';
    cout << s << "\n";
}

int main(int argc, char *argv[]) {
    test_from_char();
    return 0;
}
