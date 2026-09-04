#include <iostream>
#include <string>
using namespace std;

int main()
{
    string num1, num2;
    cin >> num1 >> num2;

    int real1 = 0, imag1 = 0;
    int real2 = 0, imag2 = 0;

    // Find '+' in first number
    int pos1 = num1.find('+');

    // Find '+' in second number
    int pos2 = num2.find('+');

    // Extract real and imaginary parts
    real1 = stoi(num1.substr(0, pos1));
    imag1 = stoi(num1.substr(pos1 + 1, num1.length() - pos1 - 2));

    real2 = stoi(num2.substr(0, pos2));
    imag2 = stoi(num2.substr(pos2 + 1, num2.length() - pos2 - 2));

    // Complex multiplication:
    // (a + bi)(c + di)
    // = (ac - bd) + (ad + bc)i

    int real = real1 * real2 - imag1 * imag2;
    int imag = real1 * imag2 + imag1 * real2;

    cout << real << "+" << imag << "i";

    return 0;
}