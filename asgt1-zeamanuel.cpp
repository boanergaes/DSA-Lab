// writer - Zeamanuel Mebit 
// id - UGR/9677/16
//sec - 2

#include <iostream>
#include <string>
#define TAX 0.15
using namespace std;

int main(){

    // list initialization
    string message1 {"=> this program is aimed to be a product sales and inventory analyzer for a store. it will accept a number of inputs from you like product name, price, catagory, number of sold items  and some more and then it calculates total sales, remaining inventory, and so on. it also analyzes your inventory status and it prints receipts for you. you will also get a summary of your activities in our system. the program will guide you through, so don't worry. we will make your business thrive and lift off some weights from your back!"},
    message2 {"=> REMINDER: our program is built in c++ and c++ is a compiled language. a code written in a compiled language has to be changed to something the computer can understand by something called a compiler. but we won't bore you with all the technical details. just don't forget that you have to compile the before you run it."};
    cout << message1 << endl;
    cout << message2 << endl << endl;

    // vars for product detail
    string prdctName;
    int prdctCatag;
    int initInvent;
    float price;
    int soldItems;

    //vars for computed values
    int newInvent;
    float totSales;
    string inventStatus;

    const double tax = 0.15;
    
    cout << "enter product name: ";
    cin >> prdctName;
    
    cout << "1-electronics...2-groceries...3-clothing...4-stationary...5-miscellaneous" << endl;
    cout << "enter product catagory: ";
    cin >> prdctCatag;
    
    //to ensure a valid product catagory is given.
    decltype(initInvent) maxVal; //assignment after initialization
    maxVal = 5;
    decltype(initInvent) minVal = 0; //direct assignment
    string holder;
    while (true){
        if (prdctCatag < minVal || prdctCatag > maxVal){
            cout << endl << "that is not a valid product catagory number. it should be 1 - 5." << endl;
            cout << "enter product catagory again: ";
            cin >> prdctCatag;
        }else{
            switch (prdctCatag){
                case 1:
                    cout << "catagory 1: electronics" << endl;
                    holder = "electronics";
                    break;
                case 2:
                    cout << "catagory 2: groceries" << endl;
                    holder = "groceries";
                    break;
                case 3:
                    cout << "catagory 3: clothing" << endl;
                    holder = "clothing";
                    break;
                case 4:
                    cout << "catagory 4: stationary" << endl;
                    holder = "stationary";
                    break;
                case 5:
                    cout << "catagory 5: miscellaneous" << endl;
                    holder = "miscellaneous";
                    break;
            }
            break;
        }
    }
    
    cout << "enter initial inventory quantity: ";
    cin >> initInvent;

    cout << "enter the product price: $";
    cin >> price;

    cout << "enter the number of items sold: ";
    cin >> soldItems;

    //to make sure the user enters a number of sold items that's less than initial inventory and that is positive. 
    while (true){
        if (soldItems > initInvent){
            cout << endl << "SORRY! the amount you are trying to sale is greater than what there is in the inventory. your current inventory is " << initInvent << ". (or you might as well be entering an invalid number.)" << endl;
            cout << "enter again: ";
            cin >> soldItems;
        }else if (soldItems < 0) {  
            cout << "SORRY! that's not a valid number.\n";
            cout << "enter again: ";
            cin >> soldItems;
        }else {
            break;
        }
    }

    newInvent = initInvent;
    newInvent -= soldItems; 
    cout << "initial inventory: " << initInvent << endl;
    cout << "new inventory: " << newInvent << endl;

    totSales = soldItems*price;
    cout << "total sales: " << totSales << endl;
    auto totSaleCopy = totSales;

    inventStatus = newInvent < 10 ? "low inventory" : "sufficient inventory";
    cout << "inventory status: " << inventStatus << endl;

    cout << endl << "RECEIPT" << endl;
    for (int i = 1; i <= soldItems; i++){
        cout << "item #" << i << endl << "product name: " << prdctName << endl << "price: " << price << endl << "-------------" << endl;
    }
    cout << "tax(const variable): " << tax << endl;
    cout << "TAX(preprocessor costant): " << TAX << endl;
    cout << "without TAX: $" << totSales << endl << "total(with TAX): $" << totSales - TAX*totSales << endl;

    cout << endl << endl;
    cout << "SUMMARY:" << endl;
    cout << "product name: " << prdctName << endl;
    cout << "category: " << prdctCatag << "(" << holder << ")" << endl;
    cout << "price: $" << price << endl;
    cout << "items sold: " << soldItems << endl;
    cout << "total sales: $" << totSales << endl;
    cout << "initial inventory: " << initInvent << endl;
    cout << "new inventory: " << newInvent << endl;
    cout << "inventory status: " << inventStatus << endl;

    cout << endl << "helper variables: " << endl;
    cout << "totSaleCopy(declared with auto): " << totSaleCopy << endl;
    cout << "maxVal(declared with decltype): " << maxVal << endl;
    cout << "minVal(declared with decltype): " << minVal << endl;
    cout << "holder: " << holder << endl;
    
    return 0;
}