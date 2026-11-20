// 6-21  编写一个函数，统计一条英文句子中字母的个数，在主程序中实现输入输出
//
// 知识点：getline 读整行（含空格）；isalpha 判断字母；
//         用 unsigned char 参与字符分类，避免负 char 值的未定义行为；
//         函数参数用 const string& 避免拷贝。
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int countLetters(const string &s) {
    int count = 0;
    for (unsigned char ch : s) {
        if (isalpha(ch)) {          // 只统计 A~Z、a~z，不含空格、数字、标点
            ++count;
        }
    }
    return count;
}

int main() {
    string sentence;
    cout << "请输入一条英文句子: ";
    getline(cin, sentence);         // 必须用 getline，cin >> 只能读到一个单词
    cout << "字母个数: " << countLetters(sentence) << endl;
    return 0;
}
