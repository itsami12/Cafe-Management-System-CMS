// CafeStaff.cpp

#include "CafeStaff.h"
#include <iostream>
#include<fstream>
#include"order.h"
#include"user.h"

CafeStaff::CafeStaff(string id, string name, string pass)
    : user(id, name, pass, "CafeStaff") {}



bool CafeStaff::Authenticate() {

    // Prompt the user for username and password
    cout << "Enter cafetaff username: ";
    cin >> userName;

    cout << "Enter cafstaff password: ";
    cin >> password;
    if ((userName == "staff") && (password == "zxc"))
    {

        // Add logic for authentication (e.g., check entered username and password)
        // For simplicity, let's assume the authentication is successful
        cout << "cafestaff login successful." << endl;
        return true;
    }
    cout << "cafestaff credintals incorrect!imposter detected." << endl;
    return false;

}


void CafeStaff::ViewMenu() {
    cout << " ===============================" << endl;
    cout << " |           Menu              |" << endl;
    cout << " ===============================" << endl;

    // Ask the user to choose a category
    cout << "Choose a category:\n";
    cout << "1. Desi\n";
    cout << "2. FastFood\n";
    cout << "3. Shakes/chai/colddrink\n";
    cout << "4. DEALS\n";
    // Add more categories as needed

    int categoryChoice;
    cin >> categoryChoice;
   



    string categoryFileName;

    switch (categoryChoice) {
    case 1:
        categoryFileName = "desi_menu.txt";
        break;
    case 2:
        categoryFileName = "fastfood_menu.txt";
        break;
        // Add cases for more categories

    case 3:
        categoryFileName = "shakes.txt";
        break;
    case 4:
        categoryFileName = "deals.txt";
        break;


    default:
        cout << "Invalid category choice.\n";
        return;
    }




    // Open the file for reading
    ifstream menuFile(categoryFileName);

    if (!menuFile.is_open()) {
        cerr << "Error: Unable to open " << categoryFileName << " for reading\n";
        return;
    }

    string itemName;
    double itemPrice;

    // Read and display each menu item from the file
    while (menuFile >> itemName >> itemPrice) {
        cout << itemName << " - Rs" << itemPrice << endl;
    }

    // Close the file
    menuFile.close();
}

void CafeStaff::ProcessOrder() {
    cout << "Processing order as CafeStaff." << endl;

    // Assume you have an Order class or structure to represent the order
    Order order;

    // Display the menu to the CafeStaff
    ViewMenu();

    char choice;
    do {
        // Get the order details from the user
        cout << "Enter item ID: ";
        string itemID;
        cin >> itemID;

        // Check if the item exists in the menu
        Menuitem* menuItem = FindMenuItem(itemID);
        if (menuItem == nullptr) {
            cout << "Invalid item ID. Please enter a valid item ID." << endl;
            continue;
        }

        // Get the quantity
        cout << "Enter quantity: ";
        int quantity;
        cin >> quantity;

        // Add the item to the order
        order.AddItem(menuItem, quantity);

        // Ask if there are more items
        cout << "Add another item? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');  // Allow both upper and lower case 'y'

    // Display the final order details
    cout << "Customer's Order:\n";
    order.DisplayOrder();

    // Calculate the total cost and confirm the order
    double totalCost = order.CalculateTotalCost();
    cout << "Total Cost: Rs" << totalCost << endl;

    // Save the order in order_history.txt
    ofstream orderHistoryFile("order_history.txt", ios::app);  // Open the file in append mode
    if (orderHistoryFile.is_open()) {
        orderHistoryFile << "Order Details:\n";
        orderHistoryFile << "Total Cost: Rs" << totalCost << "\n";
        orderHistoryFile << "Items:\n";
        orderHistoryFile << order.OrderDetails() << "\n";
        orderHistoryFile << "---------------------------------\n";
        orderHistoryFile.close();
        cout << "Order details saved in order_history.txt\n";
    }
    else {
        cerr << "Error: Unable to open order_history.txt for writing\n";
    }

    // Confirm the order with the customer (you can add more confirmation logic)
    cout << "Confirm the order? (y/n): ";
    char confirmChoice;
    cin >> confirmChoice;
    if (confirmChoice == 'y' || confirmChoice == 'Y') {  // Allow both upper and lower case 'y'
        cout << "Order confirmed. Proceeding with preparation.\n";
        // Add logic for further order processing, e.g., updating inventory, preparing items, etc.
    }
    else {
        cout << "Order canceled.\n";
    }
}

// Helper function to find a menu item by ID (replace with your actual logic)
Menuitem* CafeStaff::FindMenuItem(const string& itemID) {
    // Implement your logic to find the menu item by ID
    // For simplicity, assume you have a list of menu items
    for (Menuitem* menuItem : menuItems) {
        if (menuItem->GetID() == itemID) {
            return menuItem;
        }
    }
    return nullptr; // Item not found
}




// Function to add a menu item
void CafeStaff::AddMenuItem() {
    // Check if the maximum number of menu items has been reached
    if (numMenuItems >= MaxMenuItems) {
        cout << "Cannot add more menu items. Maximum limit reached." << endl;
        return;
    }

    // Get details for the new menu item
    string itemID, itemName, itemDescription;
    double price;
    int quantityInStock;

    cout << "Enter item ID: ";
    cin >> itemID;
    cout << "Enter item name: ";
    cin >> itemName;
    cout << "Enter item description: ";
    cin >> itemDescription;
    cout << "Enter item price: ";
    cin >> price;
    cout << "Enter quantity in stock: ";
    cin >> quantityInStock;

    // Create a new Menuitem object
    Menuitem* newItem = new Menuitem(itemID, itemName, itemDescription, price, quantityInStock);

    // Add the new item to the array
    menuItems[numMenuItems++] = newItem;

    cout << "Menu item added successfully." << endl;
}





void CafeStaff::Register() {
    // Implementation of the Register method for CafeStaff
    cout << "Enter CafeStaff details for registration:\n";

    // Prompt for and input necessary information (e.g., staff ID, name, password)
    cout << "Enter staff ID: ";
    cin >> userID;

    cout << "Enter staff name: ";
    cin.ignore(); // Ignore any remaining newline characters
    getline(cin, userName);

    cout << "Enter password: ";
    cin >> password;

    // Additional registration logic if needed

    cout << "CafeStaff registration successful." << endl;
}

void CafeStaff::Login() {
    // Implementation of login logic for CafeStaff
    cout << "Enter CafeStaff username: ";
    cin >> userName;

    cout << "Enter CafeStaff password: ";
    cin >> password;

    // Add authentication logic (e.g., check entered username and password)
    // For simplicity, let's assume the authentication is successful
    cout << "CafeStaff login successful." << endl;
}




void CafeStaff::Logout() {
    // Implementation of logout logic for CafeStaff
    cout << "Logging out as CafeStaff..." << endl;
    // Any additional logout logic can be added here

    // Call the base class (user) logout method
    user::Logout();
}