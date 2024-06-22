#pragma once
#include "Menuitem.h"
#include <string>

class Order {
protected:
    string orderID;
    string customerID;
    Menuitem** itemsOrdered;
    int numItems;
    double totalPrice;
    string orderStatus;

public:
    Order(string id = "", string custID = "");
    string GetName() const;
    int GetQuantity() const;

    string getOrderID();
    void setOrderID(string& orderID);

    // Getter and setter methods for customerID
    string getCustomerID();
    void setCustomerID(string& customerID);

    // Getter and setter methods for totalPrice
    double getTotalPrice();
    void setTotalPrice(double totalPrice);

    void AddItem(Menuitem* item, int quantity);
    void AddItem(Menuitem* item);
    void RemoveItem(Menuitem* item);
    void CalculateTotal();
    void ConfirmOrder();


    string OrderDetails() const;

    void CancelOrder();
    void DisplayOrder() const;
     // New function to display menu item details
    void DisplayMenuItem() const;

    double CalculateTotalCost() const;
    // Friend function to save order data to a file
    friend void SaveOrderToFile(Order* order);

    virtual ~Order();
};
