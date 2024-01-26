#include <iostream>
#include <cmath>
using namespace std;


int main(){

    char op;  // op stand for operators
    double number_1;
    double number_2;
    double result;

    cout << "*************CALCULATOR*********************\n";

    cout << "Choose among this operators (- + / *): ";
    cin >> op;

    cout << "Enter the first number: ";
    cin >> number_1;

    cout << "Enter the second number: ";
    cin >> number_2;

    switch(op){
        case '+':
            result = number_1 + number_2;
            cout << "The result is: " << result << '\n';
            break;

        case '/':
            result = number_1 / number_2;
            cout << "The result is: " << result << '\n';
            break;

        case '-':
            result = number_1 - number_2;
            cout << "The result is: " << result << '\n';
            break;

        case '*':
            result = number_1 * number_2;
            cout << "The result is: " << result << '\n';
            break;

        default:
            cout << "You have entered the wrong operators\n";
            break;

        }

    cout << "**********************************************";

    return 0;
}
