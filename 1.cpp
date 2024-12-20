#include<iostream>
using namespace std;

class Complex {
    float real, img;
public:
    Complex() : real(0), img(0) {}  // Default constructor
    Complex(float a, float b) : real(a), img(b) {}  // Parameterized constructor

    void accept() {
        cout << "\nEnter Real Number: ";
        cin >> real;
        cout << "Enter Imaginary Number: ";
        cin >> img;
    }

    void display() {
        cout << "\nReal Number: " << real;
        cout << "\nImaginary Number: " << img << "i\n";
    }

    friend Complex operator + (Complex, Complex);
    friend Complex operator - (Complex, Complex);
    Complex operator * (Complex);
    Complex operator / (Complex);
};

Complex operator + (Complex x, Complex y) {
    return Complex(x.real + y.real, x.img + y.img);
}

Complex operator - (Complex x, Complex y) {
    return Complex(x.real - y.real, x.img - y.img);
}

Complex Complex::operator * (Complex x) {
    return Complex(real * x.real - img * x.img, real * x.img + img * x.real);
}

Complex Complex::operator / (Complex x) {
    float denominator = (x.real * x.real + x.img * x.img);
    return Complex(((real * x.real) + (img * x.img)) / denominator,
                   ((img * x.real) - (real * x.img)) / denominator);
}

int main() {
    int ch;
    Complex c1, c2, c3;
    do {
        cout << "\n********* MENU *********";
        cout << "\n1. Addition";
        cout << "\n2. Subtraction";
        cout << "\n3. Multiplication";
        cout << "\n4. Division";
        cout << "\n5. Exit";
        cout << "\nEnter The choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter First Complex Number";
                c1.accept();
                cout << "Enter Second Complex Number\n";
                c2.accept();
                c3 = c1 + c2;
                cout << "\nAddition Of Numbers:";
                c3.display();
                break;
            case 2:
                cout << "\nEnter First Complex Number";
                c1.accept();
                cout << "Enter Second Complex Number\n";
                c2.accept();
                c3 = c1 - c2;
                cout << "\nSubtraction Of Numbers:";
                c3.display();
                break;
            case 3:
                cout << "\nEnter First Complex Number";
                c1.accept();
                cout << "Enter Second Complex Number\n";
                c2.accept();
                c3 = c1 * c2;
                cout << "\nMultiplication Of Numbers:";
                c3.display();
                break;
            case 4:
                cout << "\nEnter First Complex Number";
                c1.accept();
                cout << "Enter Second Complex Number\n";
                c2.accept();
                c3 = c1 / c2;
                cout << "\nDivision Of Numbers:";
                c3.display();
                break;
            case 5:
                return 0;
        }
    } while (ch != 5);
}
