// Customer.cpp

#include <iostream>
#include<iomanip>
#include "customer.h"
#include <fstream>  // Include this for file handling
using namespace std;

Customer::Customer(string id, string name, string pass)
    : user(id, name, pass, "Customer") {}


//viewing order 
void Customer::ViewMenu() {
    cout << "Viewing menu as Customer." << endl;

    // Read and display menu from the file menu.txt
    ifstream menuFile("menu.txt");
    if (!menuFile) {
        cout << "Error: Unable to open menu file." << endl;
        return;
    }

    cout << left << setw(20) << "ID" << setw(30) << "Description" << setw(10) << "Price" << setw(5) << "Stock" << endl;
    cout << string(65, '-') << endl;

    string id, description;
    double price;
    int stock;

    while (menuFile >> id >> description >> price >> stock) {
        cout << setw(20) << id << setw(30) << description << setw(10) << price << setw(5) << stock << endl;
    }

    menuFile.close();
}



// PlaceOrder function
void Customer::PlaceOrder() {
    cout << "Placing an order as Customer." << endl;

    // Read the menu from the file to display available items
    ifstream menuFile("menu.txt");
    if (!menuFile) {
        cout << "Error: Unable to open menu file." << endl;
        return;
    }

    cout << "Available Menu Items:" << endl;
    cout << left << setw(20) << "ID" << setw(30) << "Description" << setw(10) << "Price" << endl;
    cout << string(65, '-') << endl;

    string id, description;
    double price;
    int stock;

    while (menuFile >> id >> description >> price >> stock) {
        cout << setw(20) << id << setw(30) << description << setw(10) << price << endl;
    }

    menuFile.close();

    // Get user input for placing an order
    string itemId;
    int quantity;

    cout << "Enter the ID of the item you want to order: ";
    cin >> itemId;

    cout << "Enter the quantity: ";
    cin >> quantity;

    // Add logic to place the order (update order history, deduct stock, etc.)
    // For simplicity, this example just displays the selected item and quantity
    cout << "Placed Order:" << endl;
    cout << "Item ID: " << itemId << endl;
    cout << "Quantity: " << quantity << endl;

    // You can add more complex logic based on your system's requirements
    // For example, updating order history, deducting stock from inventory, etc.
}

// ViewOrderHistory function
void Customer::ViewOrderHistory() {
    cout << "Viewing order history as Customer." << endl;

    // Read the order history from the file to display
    ifstream orderHistoryFile("order_history.txt");
    if (!orderHistoryFile) {
        cout << "Error: Unable to open order history file." << endl;
        return;
    }

    cout << "Order History:" << endl;
    cout << left << setw(20) << "Order ID" << setw(20) << "Item ID" << setw(10) << "Quantity" << setw(15) << "Total Price" << endl;
    cout << string(65, '-') << endl;

    string orderId, itemId;
    int quantity;
    double totalPrice;

    while (orderHistoryFile >> orderId >> itemId >> quantity >> totalPrice) {
        cout << setw(20) << orderId << setw(20) << itemId << setw(10) << quantity << setw(15) << totalPrice << endl;
    }

    orderHistoryFile.close();

    // You can add more details to display based on your system's order history format
}

void Customer::Register() {
    // Implementation of the Register method for Customer
    cout << "Customer registration implemented." << endl;
    
}

void Customer::Login() {
    // Implementation of login logic for Customer
    cout << "Customer login successful." << endl;
  
}

void Customer::Logout() {
    // Implementation of logout logic for Customer
    cout << "Logging out as Customer..." << endl;
  
    user::Logout();
  
}