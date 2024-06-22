#pragma once
#include"user.h"
#include"Menuitem.h"

class Customer : public user {
public:
    Customer(string id, string name, string pass);

    void ViewMenu();
    void PlaceOrder();
    void ViewOrderHistory();
    void Register() override;
    void Login() override;

    void Logout() override;




};

