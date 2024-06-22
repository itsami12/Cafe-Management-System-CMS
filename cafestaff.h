#pragma once
#include"user.h"
#include"Menuitem.h"
//// Class representing CafeStaff

class CafeStaff : public user {
public:
    CafeStaff(string id, string name, string pass);

    void ViewMenu();
    void ProcessOrder();
    void Register()override;
    void Login() override;
    void Logout()override;
    bool Authenticate();
    void AddMenuItem();
    // New function prototype to find a menu item by ID
    Menuitem* FindMenuItem(const std::string& itemID);

    // Maximum number of menu items, adjust as needed
    static const int MaxMenuItems = 100;
    // Array to store menu items
    Menuitem* menuItems[MaxMenuItems];
    // Variable to keep track of the number of menu items
    int numMenuItems;



};
