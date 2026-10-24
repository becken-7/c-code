#include <iostream>
using namespace std;

int main() {
    int n, a;
    cout << "请输入项数 n 和数字 a：";
    cin >> n >> a;

    long long term = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        term = term * 10 + a;  
        sum += term;
    }

    cout << "数列前 " << n << " 项的和为：" << sum << endl;
    return 0;
}