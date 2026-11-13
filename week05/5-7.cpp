
#include <iostream>
using namespace std;

class Cat
{
private:
    static int numOfCats;              
public:
    Cat()  { numOfCats++; }            
    ~Cat() { numOfCats--; }            
    static int getNumOfCats()          
    {
        return numOfCats;
    }
};

int Cat::numOfCats = 0;               

int main()
{
    cout << "还没有猫: " << Cat::getNumOfCats() << endl;   

    Cat c1, c2, c3;
    cout << "创建3只猫后: " << Cat::getNumOfCats() << endl;

    {                                  
        Cat c4, c5;
        cout << "再创建2只猫后: " << Cat::getNumOfCats() << endl;
    }                                  

    cout << "局部对象析构后: " << Cat::getNumOfCats() << endl;
    return 0;
}
