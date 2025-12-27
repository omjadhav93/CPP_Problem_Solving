#include<iostream>
using namespace std;

class A {
public:
    void display() {
        cout << "Displaying from class A" << endl;
    }
};

class B : public A {
public:
    void display() {
        cout << "Displaying from class B" << endl;
    }
};

int main() {
    A objA;
    B objB;

    objA.display();
    objB.display();

    return 0;
}