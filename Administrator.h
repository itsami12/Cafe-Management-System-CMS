#pragma once
#include"user.h"
#include"Menuitem.h"
#include"order.h"
#include"Rating.h"
#include"Payment.h"

// Class representing Administrator
class Administrator : public user {
public:
    //Administrator(string id, string name, string pass);
    Administrator(string id, string name, string pass);

    // Declarations of other member functions...
    void Register() override;
  
    void Login() override;
  

    void ViewMenu();
    void AddMenuItem();
    void RemoveMenuItem();
    void ManageInventory();
    void ManageDiscountPromotion();
    void ViewOrderHistory();
    void AddNotification();
    void RemoveNotification();
    void RateMenuItem();
    void DisplayFromFile();
    void ViewUsersFromFile();
    void ViewMenuItemsFromFile();
    void ViewOrdersFromFile();
    void ViewRatingsFromFile();
    void ViewPaymentsFromFile();
    void CalculateMonthlyEarnings();
    void Logout() override;
    bool Authenticate();
   


};

// Friend functions for file handling
void SaveUserToFile1(user* user);
void SaveMenuItemToFile1(Menuitem* item);
void SaveOrderToFile1(Order* order);
void SaveRatingToFile1(Rating* rating);
void SavePaymentToFile1(Payment* payment);
void SaveAdministratorRegistrationToFile(string& contactNumber);


