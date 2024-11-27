#include <iostream>
#include <list>
using namespace std;

class inventory {
private:
    string itemName, description;
    int quantity, itenId;
    char option;
    list<string> itemNames;
    list<string> itemDescriptions;
    list<int> itemIds;
    list<int> itemQuantities;
public:
    void displayMenu() {
        cout << "CTI Inventory System\n\n"
        << "Choose your transaction:\n"
        << "1. Add item\n"
        << "2. Remove item\n"
        << "3. List items\n"
        << "4. Quit\n";
        getOption();
    }
    void getOption() {
        cout << "Choose your option: ";
        cin >> option;
        showResultOption(option);
    }
    void showResultOption(char option) {
        switch (option) {
            case '1': cout << "Add item" << endl; break;
            case '2': cout << "Remove item" << endl; break;
            case '3': cout << "List items" << endl; break;
            case '4': cout << "Quit" << endl; exit(0);
            default: cout << "You have entered invalid input"; getOption(); break;
        }
    }
};

int main() {
    inventory start;
    start.displayMenu();
}