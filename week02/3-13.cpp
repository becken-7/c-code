#include<iostream>
using namespace std;
long long fib(int n){
    if(n<=0){
        return 0;           // 防止n<=0时无限递归
    }
    if(n==1 || n==2){
        return 1;
 }
    return fib(n-1)+fib(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}