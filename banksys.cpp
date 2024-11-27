#include <iostream>
#include <iomanip>

void showBal(double bal);
double withdrawBal(double bal);
double deposit();
void printl(std::string text);
void print(std::string text);

int main(){

    double bal = 0;
    int choice = 0;

    do{
        printl("AVAILABLE TRANSACTION");
        printl("1. show balance");
        printl("2. deposit");
        printl("3. withdraw");
        printl("4. exit");
        print("SELECT YOUR TRANSACTION: ");
        std::cin >> choice;

        std::cin.clear();
        fflush(stdin);

        switch(choice){
            case 1: showBal(bal);
            break;
            case 2: bal += deposit();
            showBal(bal);
            break;
            case 3: bal -= withdrawBal(bal);
            showBal(bal);
            break;
            case 4: printl("THANK YOU");
            break;
            default: printl("INVALID INPUT");
        }

    }while(choice != 4);

    return 0;
}

double withdrawBal(double bal){
    double amt = 0;
    printl(" ");
    print("ENTER AMOUNT YOU WANT TO WITHDRAW: ");
    std::cin >> amt;

    if(amt > bal){
        printl("YOU HAVE INSUFFICIENT BALANCE IN YOUR ACCOUNT");
        return 0;
    }else if (amt <= 0){
        printl("YOU HAVE ENTERED INVALID AMOUNT");
        return 0;
    }else{
        return amt;
    }

}

double deposit(){
    double amt = 0;
    printl(" ");
    print("ENTER AMOUNT TO DEPOSIT: ");
    std::cin >> amt;

    if(amt > 0 ){
        return amt;
    }else{
        printl("YOU HAVE ENTERED INVALID AMOUNT");
        return 0;
    }
}

void showBal(double bal){
    std::cout << "YOUR BALANCE IS " << std::setprecision(2) << std::fixed << bal << " PESOS" << '\n' << '\n';
}

void printl (std::string text){
    std::cout << text << '\n';
}

void print (std::string text){
    std::cout << text;
}