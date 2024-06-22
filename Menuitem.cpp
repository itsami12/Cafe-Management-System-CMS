#include "Menuitem.h"
#include<fstream>

Menuitem::Menuitem(string id, string name, string desc, double p, int quantity)
    : itemID(id), itemName(name), itemDescription(desc), price(p), quantityInStock(quantity) {}

double Menuitem::GetPrice() const {
    return price;

}

string Menuitem::GetID() const {
    return itemID;
}

string Menuitem::GetDescription() const {
    return itemDescription;
}


// Implementation of GetName function
string Menuitem::GetName() const {
    return itemName;  // Assuming itemName is a member variable storing the item name
}

// Implementation of GetQuantity function
int Menuitem::GetQuantity() const {
    return quantityInStock;  // Assuming quantity is a member variable storing the item quantity
}



void Menuitem::UpdateStock(int newQuantity) {
    // Implement the logic to update stock here
    quantityInStock = newQuantity;
}
void SaveMenuItemToFile(Menuitem* item) {
    // Implementation to save menu item data to a file
    // This function assumes a file named "menu.txt" for simplicity

    ofstream menuFile("menu.txt", ios::app);
    if (menuFile.is_open()) {
        menuFile << item->itemID << " " << item->itemName << " " << item->itemDescription
            << " " << item->price << " " << item->quantityInStock << endl;
        menuFile.close();
        cout << "Menu item data saved to file." << endl;
    }
    else {
        cout << "Error opening file for saving menu item data." << endl;
    }
}
// Implement other member functions if needed


void Menuitem::DisplayMenuItem() const {
    // Implementation to display menu item details
    cout << "ID: " << itemID << endl;
    cout << "Name: " << itemName << endl;
    cout << "Description: " << itemDescription << endl;
    cout << "Price: $" << price << endl;
    cout << "Quantity in Stock: " << quantityInStock << endl;
    cout << string(40, '-') << endl;
}