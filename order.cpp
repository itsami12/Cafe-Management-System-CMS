#include "Order.h"
#include "Menuitem.h"
#include <iostream>
#include <fstream>

using namespace std;
string Order::getOrderID() {
    return orderID;
}

void Order::setOrderID(string& orderID) {
    this->orderID = orderID;
}

// Getter and setter methods for customerID
string Order::getCustomerID() {
    return customerID;
}

void Order::setCustomerID(string& customerID) {
    this->customerID = customerID;
}

// Getter and setter methods for totalPrice
double Order::getTotalPrice() {
    return totalPrice;
}

void Order::setTotalPrice(double totalPrice) {
    this->totalPrice = totalPrice;
}
Order::Order(string id, string custID)
    : orderID(id), customerID(custID), itemsOrdered(nullptr), numItems(0), totalPrice(0.0), orderStatus("Pending") {}

void Order::AddItem(Menuitem* item) {
    if (itemsOrdered == nullptr) {
        itemsOrdered = new Menuitem * [1];
    }
    else {
        Menuitem** tempArray = new Menuitem * [numItems + 1];
        for (int i = 0; i < numItems; ++i) {
            tempArray[i] = itemsOrdered[i];
        }
        delete[] itemsOrdered;
        itemsOrdered = tempArray;
    }

    itemsOrdered[numItems++] = item;

    cout << "Item added to the order." << endl;
}

void Order::RemoveItem(Menuitem* item) {
    for (int i = 0; i < numItems; ++i) {
        if (itemsOrdered[i] == item) {
            for (int j = i; j < numItems - 1; ++j) {
                itemsOrdered[j] = itemsOrdered[j + 1];
            }
            --numItems;

            cout << "Item removed from the order." << endl;
            return;
        }
    }

    cout << "Item not found in the order." << endl;
}

void Order::CalculateTotal() {
    totalPrice = 0.0;
    for (int i = 0; i < numItems; ++i) {
        totalPrice += itemsOrdered[i]->GetPrice(); // Assuming MenuItem has a GetPrice method
    }
}

void Order::ConfirmOrder() {
    orderStatus = "Confirmed";
    cout << "Order confirmed." << endl;
}

void Order::CancelOrder() {
    orderStatus = "Cancelled";
    cout << "Order cancelled." << endl;
}

void Order::DisplayOrder() const {
    cout << "Order ID: " << orderID << endl;
    cout << "Customer ID: " << customerID << endl;
    cout << "Number of Items: " << numItems << endl;

    for (int i = 0; i < numItems; ++i) {
        cout << "Item " << i + 1 << ":" << endl;
        itemsOrdered[i]->DisplayMenuItem(); // Assuming MenuItem has a DisplayMenuItem method
    }

    cout << "Total Price: " << totalPrice << endl;
    cout << "Order Status: " << orderStatus << endl;
}

double Order::CalculateTotalCost() const {
    return totalPrice;
}


string Order::OrderDetails() const {
    string details;
    for (int i = 0; i < numItems; ++i) {
        details += itemsOrdered[i]->GetName() + " - Quantity: " + to_string(itemsOrdered[i]->GetQuantity()) + "\n";
    }
    return details;
}

void Order::AddItem(Menuitem* item, int quantity) {
    // Implement the logic to add an item to the order with a specific quantity
    // You need to dynamically allocate memory for itemsOrdered and store the item with quantity
}

void SaveOrderToFile(Order* order) {
    ofstream ordersFile("orders.txt", ios::app);
    if (ordersFile.is_open()) {
        ordersFile << order->orderID << " " << order->customerID << " " << order->numItems
            << " " << order->totalPrice << " " << order->orderStatus << endl;

        for (int i = 0; i < order->numItems; ++i) {
            ordersFile << order->itemsOrdered[i]->GetID() << " "; // Assuming MenuItem has a GetID method
            ordersFile << order->itemsOrdered[i]->GetDescription() << " "; // Assuming MenuItem has a GetDescription method
            ordersFile << order->itemsOrdered[i]->GetPrice() << " "; // Assuming MenuItem has a GetPrice method
            // Add more details based on your MenuItem class
        }

        ordersFile << endl;
        ordersFile.close();
        cout << "Order data saved to file." << endl;
    }
    else {
        cout << "Error opening file for saving order data." << endl;
    }
}

Order::~Order() {
    delete[] itemsOrdered;
}
