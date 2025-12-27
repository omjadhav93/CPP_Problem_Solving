#include<iostream>
using namespace std;

class Complex {
public:
    double real;
    double imag;
    Complex(double r = 0, double i = 0){
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }
};

int main() {
    Complex c1(2.5, 3.5);
    Complex c2(1.5, 2.5);

    Complex c3 = c1 + c2;

    cout << "Result: " << c3.real << " + " << c3.imag << "i" << endl;

    return 0;
}