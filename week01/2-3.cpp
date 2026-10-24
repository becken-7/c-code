#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "请输入一个整数：";
    cin >> n;

    int t = n; 
    long long rev = 0;
    while (t != 0) {
        rev = rev * 10 + t % 10;
        t /= 10;
    }

    if (rev == n)
        cout << n << " 是回文数" << endl;
    else
        cout << n << " 不是回文数" << endl;
    return 0;
}