// 6-22  编写函数 void reverse(string &s)，用递归函数使字符串 s 倒序
//
// 知识点：递归三要素——递归出口、规模缩小、递推关系；
//         引用传参可以原地修改实参；string 下标访问。
#include <iostream>
#include <string>
using namespace std;

// 递归辅助函数：把 s[left..right] 这一段倒序
void reverseRange(string &s, int left, int right) {
    if (left >= right) return;                  // 递归出口：区间长度 <= 1
    char t = s[left];                           // 交换首尾
    s[left] = s[right];
    s[right] = t;
    reverseRange(s, left + 1, right - 1);       // 规模缩小：向中间收缩
}

void reverse(string &s) {
    if (s.empty()) return;                      // 空串直接返回
    reverseRange(s, 0, static_cast<int>(s.size()) - 1);
}

// 备选写法（不借助下标、只用一个函数的纯递归，效率略低但更好理解）：
// void reverse(string &s) {
//     if (s.length() <= 1) return;             // 递归出口
//     char first = s[0];
//     s.erase(0, 1);                           // 去掉首字符
//     reverse(s);                              // 递归倒序剩下的部分
//     s += first;                              // 把原首字符接到末尾
// }

int main() {
    string s;
    cout << "请输入一个字符串: ";
    getline(cin, s);
    cout << "原字符串: " << s << endl;
    reverse(s);
    cout << "倒序之后: " << s << endl;
    return 0;
}
