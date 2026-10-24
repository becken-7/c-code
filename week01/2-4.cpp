#include <iostream>
using namespace std;

int main() {
    cout << "所有三位水仙花数：" << endl;
    for (int n = 100; n <= 999; n++) {
        int a = n / 100;       
        int b = n / 10 % 10;   
        int c = n % 10;        
        if (a * a * a + b * b * b + c * c * c == n)
            cout << n << " ";
    }
    cout << endl;
    return 0;
}