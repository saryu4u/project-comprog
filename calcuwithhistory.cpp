#include <iostream>
#include <list>
#include <string>
using namespace std;

class Calculator {
private:
    float num1, num2, result;
    char ope, option;
    struct History {
        float num1;
        float num2;
        char ope;
        float result;
    };
    list<History> history;

public:
    void getData() {
        cout << "Enter First Number: ";
        cin >> num1;
        cout << "Enter Second Number: ";
        cin >> num2;
        cout << "Enter Operator (+, -, /, *, %): ";
        cin >> ope;
        cout << "= " << getResult(num1, num2, ope) << endl;
        History h;
        h.num1 = num1;
        h.num2 = num2;
        h.ope = ope;
        h.result = getResult(num1, num2, ope);
        history.push_front(h);
        options();
    }

    float getResult(float num1, float num2, char ope) {
        switch (ope) {
            case '+': return num1 + num2;
            case '-': return num1 - num2;
            case '/': return num1 / num2;
            case '*': return num1 * num2;
            case '%': return (int)num1 % (int)num2;
            default: cout << "Invalid Operator\n" << endl; return 0;
        }
    }

    void displayHistory() {
        for (auto& h : history) {
            cout << h.num1 << " " << h.ope << " " << h.num2 << " = " << h.result << endl;
        }
    }

    void options() {
        cout << "Press 1 to display history\n";
        cout << "Press 2 to continue using calculator\n";
        cin >> option;
        switch (option) {
            case '1': displayHistory(); options(); break;
            case '2': getData(); break;
            default: cout << "Invalid Option" << endl; options();
        }
    }
};
int main() {
    Calculator calc;
    calc.getData();
    return 0;
}