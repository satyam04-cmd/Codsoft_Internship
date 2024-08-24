#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

string add(double a, double b);
string subtract(double a, double b);
string multiply(double a, double b);
string divide(double a, double b);

int main()
{
    double num1, num2;
    char opr;
    double result;

    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Choose the following option" << endl;
    cout << "Press '+' to perform Addition" << endl;
    cout << "Press '-' to perform Subtraction" << endl;
    cout << "Press '*' to perform Multiplication" << endl;
    cout << "Press '/' to perform Division" << endl;

    cin >> opr;

        if (opr == '+')
        {
            cout << add(num1, num2);
        }
        else if (opr == '-')
        {
            cout << subtract(num1, num2);
        }
        else if (opr == '*')
        {
            cout << multiply(num1, num2);
        }
        else if (opr == '/')
        {    
            cout << divide(num1, num2);
        } else {
            cout<<"Something went wrong";
        }

    return 0;
}

string add(double a, double b)
{
    int i_result = a + b;
    string text = "Result: ";
    string result = text + to_string(i_result);

    return result;
}
string subtract(double a, double b)
{
    int i_result = a - b;
    string text = "Result: ";
    string result = text + to_string(i_result);

    return result;
}
string multiply(double a, double b)
{
    int i_result = a * b;
    string text = "Result: ";
    string result = text + to_string(i_result);

    return result;
}
string divide(double a, double b)
{
    int i_result = a / b;
    string text = "Result: ";
    string result;;
    if (b == 0)
    {
        result = "Cannot divide by zero";
    } else{
        string result = text + to_string(i_result);
    }

    return result;
}