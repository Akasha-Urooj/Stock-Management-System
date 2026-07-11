#include <iostream>
#include <string>
using namespace std;
 
const int MAX = 100;
 
 
int id[MAX];
string name[MAX];
string category[MAX];
double price[MAX];
int qty[MAX];
int minStock[MAX];
 
int productCount = 0;
int nextId = 101;
 
int main() {
    int choice;
 
    while (true) {
 
        cout << "\n===== STOCK MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Product\n";
        cout << "2. View Products\n";
        cout << "3. Search Product (by ID)\n";
        cout << "4. Sell Product\n";
        cout << "5. Low Stock Alert\n";
        cout << "6. Edit Product\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
 
        switch (choice) {
 
           
        case 1: {
            if (productCount < MAX) {
 
                id[productCount] = nextId++;
 
                cout << "Enter product name: ";
                cin >> name[productCount];
 
                cout << "Enter category: ";
                cin >> category[productCount];
 
                
                cout << "Enter price: ";
                cin >> price[productCount];
 
                while (price[productCount] < 0) {
                    cout << "Invalid input! Price cannot be negative.\n";
                    cout << "Enter price again: ";
                    cin >> price[productCount];
                }
 
                
                cout << "Enter quantity: ";
                cin >> qty[productCount];
 
                while (qty[productCount] < 0) {
                    cout << "Invalid input! Quantity cannot be negative.\n";
                    cout << "Enter quantity again: ";
                    cin >> qty[productCount];
                }
 
                
                cout << "Enter minimum stock: ";
                cin >> minStock[productCount];
 
                while (minStock[productCount] < 0) {
                    cout << "Invalid input! Minimum stock cannot be negative.\n";
                    cout << "Enter minimum stock again: ";
                    cin >> minStock[productCount];
                }
 
                productCount++;
 
                cout << "Product added successfully!\n";
            }
            else {
                cout << "Inventory full!\n";
            }
 
            break;
        }
              
        case 2: {
            cout << "\nID\tName\tCat\tPrice\tQty\tMin\n";
 
            for (int i = 0; i < productCount; i++) {
                cout << id[i] << "\t"
                    << name[i] << "\t"
                    << category[i] << "\t"
                    << price[i] << "\t"
                    << qty[i] << "\t"
                    << minStock[i] << "\n";
            }
 
            if (productCount == 0) {
                cout << "No products available.\n";
            }
 
            break;
        }
 
              
        case 3: {
            int searchId;
            cout << "Enter ID to search: ";
            cin >> searchId;
 
            int found = 0;
 
            for (int i = 0; i < productCount; i++) {
                if (id[i] == searchId) {
                    cout << "Product Found!\n";
                    cout << "Name: " << name[i] << "\n";
                    cout << "Category: " << category[i] << "\n";
                    cout << "Price: " << price[i] << "\n";
                    cout << "Quantity: " << qty[i] << "\n";
                    found = 1;
                    break;
                }
            }
 
            if (found == 0) {
                cout << "Product not found!\n";
            }
 
            break;
        }
 
             
        case 4: {
            int searchId, sellQty;
            cout << "Enter product ID: ";
            cin >> searchId;
 
            int found = 0;
 
            for (int i = 0; i < productCount; i++) {
                if (id[i] == searchId) {
 
                    cout << "Enter quantity to sell: ";
                    cin >> sellQty;
 
                    if (sellQty <= qty[i]) {
                        qty[i] = qty[i] - sellQty;
                        cout << "Sale completed!\n";
                    }
                    else {
                        cout << "Not enough stock!\n";
                    }
 
                    found = 1;
                    break;
                }
            }
 
            if (found == 0) {
                cout << "Product not found!\n";
            }
 
            break;
        }
 
             
        case 5: {
            cout << "\nLow Stock Items:\n";
            int alert = 0;
 
            for (int i = 0; i < productCount; i++) {
                if (qty[i] <= minStock[i]) {
                    cout << id[i] << " - " << name[i]
                        << " (Qty: " << qty[i] << ")\n";
                    alert = 1;
                }
            }
 
            if (alert == 0) {
                cout << "All stock levels are fine.\n";
            }
 
            break;
        }
 
        case 6: {
            int searchId;
            cout << "Enter product ID to edit: ";
            cin >> searchId;
 
            int found = 0;
 
            for (int i = 0; i < productCount; i++) {
                if (id[i] == searchId) {
 
                    found = 1;
                    int option;
 
                    cout << "\nProduct Found: " << name[i] << "\n";
                    cout << "What do you want to edit?\n";
                    cout << "1. Name\n";
                    cout << "2. Category\n";
                    cout << "3. Price\n";
                    cout << "4. Increase Quantity\n";
                    cout << "5. Decrease Quantity\n";
                    cout << "Enter choice: ";
                    cin >> option;
 
                    if (option == 1) {
                        cout << "Enter new name: ";
                        cin >> name[i];
                    }
 
                    else if (option == 2) {
                        cout << "Enter new category: ";
                        cin >> category[i];
                    }
 
                    else if (option == 3) {
                        cout << "Enter new price: ";
                        cin >> price[i];
 
                        while (price[i] < 0) {
                            cout << "Invalid! Enter positive price: ";
                            cin >> price[i];
                        }
                    }
 
                    else if (option == 4) {
                        int addQty;
                        cout << "Enter quantity to add: ";
                        cin >> addQty;
 
                        while (addQty < 0) {
                            cout << "Invalid! Enter positive value: ";
                            cin >> addQty;
                        }
 
                        qty[i] = qty[i] + addQty;
                    }
 
                    else if (option == 5) {
                        int subQty;
                        cout << "Enter quantity to decrease: ";
                        cin >> subQty;
 
                        while (subQty < 0) {
                            cout << "Invalid! Enter positive value: ";
                            cin >> subQty;
                        }
 
                        if (subQty <= qty[i]) {
                            qty[i] = qty[i] - subQty;
                        }
                        else {
                            cout << "Error: Not enough stock!\n";
                        }
                    }
 
                    else {
                        cout << "Invalid option!\n";
                    }
 
                    break;
                }
            }
 
            if (found == 0) {
                cout << "Product not found!\n";
            }
 
            break;
        }
        case 7: {
            cout << "Exiting system...\n";
            return 0;
        }
 
        default: {
            cout << "Invalid choice!\n";
        }
        }
    }
}
