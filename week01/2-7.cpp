#include <iostream>
using namespace std;

int main() {
    long long prev = 1;  
    long long curr = 1;  
    for (int month = 1; month <= 20; month++) {
        if (month == 1 || month == 2)
            curr = 1;                          
        else {
            long long next = prev + curr;      
            prev = curr;
            curr = next;
        }
        cout << "第 " << month << " 个月：兔子总数 " << curr << " 对" << endl;
    }
    return 0;
}
