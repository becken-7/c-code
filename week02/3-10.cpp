#include<iostream>
using namespace std;
int gcd(int a,int b){
    while( b!=0){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int lcm(int a,int b){
    int m=a/gcd(a,b)*b;
    return m;
}
int main(){
    int x,y;
    cin>>x>>y;
    cout<<gcd(x,y)<<" "<<lcm(x,y)<<endl;
    return 0;

}