#include<iostream>
using namespace std;
int main(){
    int score;
    cin>>score;
    switch(score){
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            cout<<"你认为电影烂片"<<endl;
            break;
        case 5:
        case 6:
            cout<<"你认为电影一般"<<endl;
            break;
        case 7:
        case 8:
            cout<<"你认为电影非常好"<<endl;
            break;
        case 9:
        case 10:
            cout<<"你认为电影经典"<<endl;
            break;
        default:
            cout<<"打分无效，请重新输入（0~10）"<<endl;
            break;
    }
    return 0;
}