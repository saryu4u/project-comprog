#include <iostream>
#include <list>
#include <vector>
using namespace std;

class inventory {
private:
    string itemName, description;
    int quantity, itemId;
    size_t index;

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
        int option;
        while (true) {
            cout << "Choose your option: ";
            cin >> option;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input, please try again.\n";
            } else {
                break;
            }
        }
        showResultOption(option);
    }

    void showResultOption(int option) {
        switch (option) {
            case 1: cout << "Add item\n\n"; addItemToList(); break;
            case 2: cout << "Remove item\n\n"; removeItemFromList(); break;
            case 3: cout << "List items\n\n"; showItems(); break;
            case 4: cout << "Quit" << endl; exit(0);
            default: cout << "Invalid input, please try again.\n"; getOption();
        }

    }

    void showItems() {

        if (itemIds.size() != itemNames.size() || itemIds.size() != itemQuantities.size() || itemIds.size() != itemDescriptions.size()) {
            cout << "Error: Item data is inconsistent." << endl;
            return;
        }

        cout << "ID\t\tName\t\tQuantity\t\tDescription" << endl;
        cout << "---------------------------------------------" << endl;

        for (size_t i = 0; i < itemIds.size(); ++i) {
            cout << itemIds[i] << "\t\t"
                 << itemNames[i] << "\t\t\t"
                 << itemQuantities[i] << "\t\t\t\t"
                 << itemDescriptions[i] << "\n\n";
        }
        displayMenu();
    }
    bool validateId(int id) {
        for (int i = 0; i < itemIds.size(); ++i) {
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
    void removeItemFromList() {
        cout << "Enter item ID to remove: ";
        int idToRemove;
        cin >> idToRemove;

        auto it = find(itemIds.begin(), itemIds.end(), idToRemove);
        if (it != itemIds.end()) {
            index = distance(itemIds.begin(), it);
            itemIds.erase(it);
            itemNames.erase(itemNames.begin() + index);
            itemQuantities.erase(itemQuantities.begin() + index);
            itemDescriptions.erase(itemDescriptions.begin() + index);

            cout << "Item with ID " << idToRemove << " removed successfully.\n\n";
        } else {
            cout << "Item with ID " << idToRemove << " not found.\n\n";
        }
        displayMenu();
    }
};

int main() {
    inventory start;
    start.displayMenu();
}