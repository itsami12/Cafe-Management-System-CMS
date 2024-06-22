#pragma once
#include <string>
#include <iostream>

using namespace std;

class Menuitem {
protected:
    string itemID;
    string itemName;
    string itemDescription;
    double price;
    int quantityInStock;

public:
    Menuitem(string id, string name, string desc, double p, int quantity);
    double GetPrice() const;
    string GetID() const;
    string GetDescription() const;
    string GetName() const;
    int GetQuantity() const;



    void UpdateStock(int newQuantity);

    // New function to display menu item details
    void DisplayMenuItem() const;

    // Friend function to save menu item data to a file
    friend void SaveMenuItemToFile(Menuitem* item);

    // No destructor declaration in the header file

    // No virtual destructor here unless you have specific reasons for it
};
