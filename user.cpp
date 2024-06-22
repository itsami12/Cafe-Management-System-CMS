// user.cpp

#include "user.h"
#include <iostream>
#include <fstream>
string& user::getUserID() {
    return userID;
}

string& user::getUserName() {
    return userName;
}

string& user::getUserType() {
    return userType;
}

// Setter methods
void user::setUserID(string& newUserID) {
    userID = newUserID;
}

void user::setUserName(string& newUserName) {
    userName = newUserName;
}

void user::setUserType(string& newUserType) {
    userType = newUserType;
}

user::user(string id, string name, string pass, string type)
    : userID(id), userName(name), password(pass), userType(type) {}

void user::Register() {
    // Implementation of the Register method
    // You may want to collect user information and store it
    // For simplicity, let's assume a basic registration process

    cout << "User ID: ";
    cin >> userID;

    cout << "User Name: ";
    cin >> userName;

    cout << "Password: ";
    cin >> password;

    cout << "User Type: ";
    cin >> userType;

    // Save user data to a file
    SaveUserToFile(this);

    std::cout << "User registration completed." << std::endl;
}

void user::Login() {
    // Implementation of the Login method
    // You may want to authenticate the user
    // For simplicity, let's assume a basic login process
    cout << "User login implemented." << endl;
}

void user::Logout() {
    // Implementation of the Logout method
    // You may want to perform any necessary cleanup or actions when logging out
    // For simplicity, let's assume a basic logout process
    cout << "User logout implemented." << endl;
}

void SaveUserToFile(user* user) {
    // Implementation to save user data to a file
    // This function assumes a file named "users.txt" for simplicity

    ofstream usersFile("users.txt", ios::app);
    if (usersFile.is_open()) {
        usersFile << user->userID << " " << user->userName << " " << user->password
            << " " << user->userType << endl;
        usersFile.close();
        cout << "User data saved to file." << endl;
    }
    else {
        cout << "Error opening file for saving user data." << endl;
    }
}

user::~user() {
    // Implementation of the destructor
    // Include any cleanup or additional actions when the object is destroyed
    cout << "User object with ID " << userID << " is being destroyed." << endl;
    // Additional cleanup or actions can be added here
}