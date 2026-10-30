#include<iostream>
using namespace std;
bool jud(int x){
    if(x<2){
        return false;       
    }
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            return false;   
        }
    }
    return true;
}
int main(){
    int a;
    cin>>a;
    if(jud(a)){
        cout<<"shizhishu"<<endl;
    }
    else{
        cout<<"bushizhishu"<<endl;
    }
    return 0;
}