#pragma once
// Class representing Payment
#include"Menuitem.h"

class Payment {
protected:
    string paymentID;
    string orderID;
    double amount;
    string paymentStatus;

public:
    Payment(string id, string oID, double amt);
    string& getPaymentID();
    double getAmount();
    void ProcessPayment();
    string& getPaymentStatus();

    void setPaymentID(string& newPaymentID);
    void setAmount(double newAmount);
    void setPaymentStatus(string& newStatus);
    void ProcessPayment1();

    // Friend function to save payment data to a file
    friend void SavePaymentToFile(Payment* payment);

    virtual ~Payment();
};
    
