#include <iostream>
#include <list>
#include <string>
#include <limits>
#include <cstdlib>
using namespace std;

struct Item {
    int id;
    string name;
    int quantity;
    string description;
};

class Inventory {
private:
    list<Item> items;

public:
    void displayMenu() {
        clearScreen();
        cout << "--[ SHOPPING LIST ]--\n\n"
             << "\tMENU\n\n"
             << "1. Add item\n"
             << "2. Remove item\n"
             << "3. List items\n"
             << "4. Quit\n";
        getOption();
    }

    void getOption() {
        int option;
        while (true) {
            cout << "\nChoose your option: ";
            cin >> option;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid input, please try again.\n";
            } else {
                showResultOption(option);
                break;
            }
        }
    }

    void showResultOption(int option) {
        switch (option) {
            case 1: cout << "\n\n----Add item----\n\n"; addItemToList(); break;
            case 2: cout << "\n\n---Remove item---\n\n"; removeItemFromList(); break;
            case 3: cout << "\n\n---List items---\n\n"; showItems(); break;
            case 4: cout << "\n\n-----Quit-----\n\n" << endl; exit(0);
            default: cout << "Invalid input, please try again.\n"; getOption();
        }
    }

    void showItems() {
        if (items.empty()) {
            cout << "\n\nNo items in inventory.\n\n"
                 << "------------------\n\n";
        } else {
            cout << "ID\t|\tName\t\t\t|\tQuantity\t|\tDescription" << endl;
            cout << "-------------------------------------------------------------------------------------" << endl;

            for (const auto& item : items) {
                cout << item.id << "\t\t"
                     << item.name << "\t\t\t\t"
                     << item.quantity << "\t\t\t"
                     << item.description << "\n"
                     << "-------------------------------------------------------------------------------------\n\n";
            }
        }
        askToContinue();
    }

    bool validateId(int id) {
        for (const auto& item : items) {
            if (item.id == id) {
                return false;
            }
        }
        return true;
    }

    void addItemToList() {
        Item newItem;
        cout << "Enter item name: ";
        cin.ignore();
        getline(cin, newItem.name);

        while (true) {
            cout << "Enter item quantity: ";
            cin >> newItem.quantity;

            if (cin.fail() || newItem.quantity <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid quantity input. Please enter a valid number greater than 0.\n\n";
            } else {
                break;
            }
        }

        while (true) {
            cout << "Enter item id: ";
            cin >> newItem.id;

            if (cin.fail() || !validateId(newItem.id)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "THE ID YOU HAVE ENTERED ALREADY EXISTS OR IS INVALID. PLEASE TRY AGAIN\n\n";
            } else {
                break;
            }
        }

        cout << "Enter item description: ";
        cin.ignore();
        getline(cin, newItem.description);

        items.push_back(newItem);
        cout << "\nAdded Successfully!\n\n"
             << "------------------\n\n";
        askToContinue();
    }

    void removeItemFromList() {
        cout << "Enter item ID to remove: ";
        int idToRemove;
        cin >> idToRemove;

        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->id == idToRemove) {
                items.erase(it);
                cout << "Item with ID " << idToRemove << " removed successfully.\n\n"
                     << "------------------\n\n";
                askToContinue();
                return;
            }
        }

        cout << "Item with ID " << idToRemove << " not found.\n\n"
             << "------------------\n\n";
        askToContinue();
    }

    void clearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    void askToContinue() {
        char choice;

        while (true) {
            cout << "Do you want to continue? (y/n): ";
            cin >> choice;

            if (choice == 'y' || choice == 'Y') {
                displayMenu();
                break;
            } else if (choice == 'n' || choice == 'N') {
                cout << "\nThank you for your cooperation!\n\n"
                    << "\n-----Quit-----\n\n";
                exit(0);
            } else {
                cout << "\nInvalid input! Please enter either y for yes or n for no.\n\n";
            }
        }
    }
};

int main() {
    Inventory inventory;
    inventory.displayMenu();
    return 0;
}
