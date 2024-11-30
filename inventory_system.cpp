#include <iostream>
#include <list>
#include <vector>
using namespace std;

class inventory {
private:
    string itemName, description;
    int quantity, itemId;
    char option;
    // list<string> itemNames;
    // list<string> itemDescriptions;
    // list<int> itemIds;
    // list<int> itemQuantities;
    vector<int> itemIds;
    vector<string> itemNames;
    vector<int> itemQuantities;
    vector<string> itemDescriptions;
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
            case '1': cout << "Add item\n\n"; addItemToList(); break;
            case '2': cout << "Remove item" << endl; break;
            case '3': cout << "List items\n\n"; showItems(); break;
            case '4': cout << "Quit" << endl; exit(0);
            default: cout << "You have entered invalid input\n"; getOption(); break;
        }
    }

    void showItems() {

        if (itemIds.size() != itemNames.size() || itemIds.size() != itemQuantities.size() || itemIds.size() != itemDescriptions.size()) {
            cout << "Error: Item data is inconsistent." << endl;
            return;
        }

        cout << "ID\tName\tQuantity\tDescription" << endl;
        cout << "---------------------------------------------" << endl;

        for (size_t i = 0; i < itemIds.size(); ++i) {
            cout << itemIds[i] << "\t"
                 << itemNames[i] << "\t"
                 << itemQuantities[i] << "\t\t"
                 << itemDescriptions[i] << "\n\n";
        }
        displayMenu();
    }
    bool validateId(int id) {
        for (size_t i = 0; i < itemIds.size(); ++i) {
            if(itemIds.at(i) == id) {
                return false;
            }
         }
        return true;
    }
    void addItemToList() {
        cout << "Enter item name: ";
        cin >> itemName;
        cout << "Enter item quantity: ";
        cin >> quantity;
        cout << "Enter item id: ";
        cin >> itemId;
        cout << "Enter item description: ";
        cin >> description;

        if(validateId(itemId)) {
            itemNames.push_back(itemName);
            itemQuantities.push_back(quantity);
            itemIds.push_back(itemId);
            itemDescriptions.push_back(description);

            cout << "Added Successfully\n\n";
            displayMenu();
        }else {
            cout << "THE ID YOU HAVE ENTERED IS ALREADY EXISTED. PLS TRY AGAIN\n\n";
            addItemToList();
        }
    }
};

int main() {
    inventory start;
    start.displayMenu();
}