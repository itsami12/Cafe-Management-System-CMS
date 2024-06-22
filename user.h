#pragma once
#include<string>
#include<iostream>
using namespace std;

class user
{
protected:
    string userID;
    string userName;
    string password;
    string userType;

public:
    user(string id, string name, string pass, string type);
    string& getUserID();
    string& getUserName();
    string& getUserType();

    // Setter methods
    void setUserID(string& newUserID);
    void setUserName(string& newUserName);
    void setUserType(string& newUserType);
    virtual void Register() = 0;
    virtual void Login() = 0;
    virtual void Logout() = 0;

    // Friend function to save user data to a file
    friend void SaveUserToFile(user* user);

    virtual ~user();

   
 
   

};

