#include <iostream>
using namespace std;

int main() {
    int peach = 1;  
    for (int day = 9; day >= 1; day--) {
        peach = (peach + 1) * 2;
        cout << "第 " << day << " 天早上还剩 " << peach << " 个桃子" << endl;
    }
    cout << "第一天共摘了 " << peach << " 个桃子" << endl;
    return 0;
}