#include<iostream>
using namespace std;
short int dle(unsigned short int x,unsigned short int y){
     if(y==0){
        return -1;
     }
     else{
        return x/y;
     }
} 
int main(){
    int a,b;
    cin>>a>>b;
    cout<<dle(a,b)<<endl;
    return 0;
}