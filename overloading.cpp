#include<iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }

    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculator calc;

    int sum1 = calc.add(5, 10);
    cout << sum1 << endl;

    int sum2 = calc.add(5, 10, 15);
    cout << sum2 << endl;

    double sum3 = calc.add(5.5, 10.5);
    cout << sum3 << endl;

    return 0;
}