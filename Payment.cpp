// Payment.cpp

#include "Payment.h"
using namespace std;
#include <iostream>
#include <fstream>
string& Payment::getPaymentID() {
    return paymentID;
}
double Payment::getAmount() {
    return amount;
}

string& Payment::getPaymentStatus() {
    return paymentStatus;
}
void Payment::setPaymentID(string& newPaymentID) {
    paymentID = newPaymentID;
}

// Setter for Amount
void Payment::setAmount(double newAmount) {
    amount = newAmount;
}

// Setter for Payment Status
void Payment::setPaymentStatus(string& newStatus) {
    paymentStatus = newStatus;
}
Payment::Payment(string id, string oID, double amt)
    : paymentID(id), orderID(oID), amount(amt), paymentStatus("Pending") {}

void Payment::ProcessPayment1() {
    // Implementation of the ProcessPayment method
    // You can implement the logic to process the payment
    paymentStatus = "Completed";
    cout << "Payment processed successfully." << endl;
}

void SavePaymentToFile(Payment* payment) {
    // Implementation to save payment data to a file
    // This function assumes a file named "payments.txt" for simplicity

    ofstream paymentsFile("payments.txt", ios::app);
    if (paymentsFile.is_open()) {
        paymentsFile << payment->paymentID << " " << payment->orderID << " "
            << payment->amount << " " << payment->paymentStatus << endl;
        paymentsFile.close();
        cout << "Payment data saved to file." << endl;
    }
    else {
        cout << "Error opening file for saving payment data." << endl;
    }
}

Payment::~Payment() {
    // Implementation of the destructor if needed
    // This could include any cleanup or additional actions when the object is destroyed
    cout << "Payment object with ID " << paymentID << " is being destroyed." << endl;
}
