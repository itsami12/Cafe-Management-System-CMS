#pragma once
// Class representing Rating
#include"Menuitem.h"
#include<string>
class Rating {
protected:
    string ratingID;
    string menuItemID;
    string customerID;
    int score;
    string comment;

public:
    Rating(string id, string itemID, string custID, int s, string c);
    string& getMenuItemID();
    string& getCustomerID();
    string& getComment();

    // Setter methods
    void setMenuItemID(string& newMenuItemID);
    void setCustomerID(string& newCustomerID);
    void setComment(string& newComment);
    void Rate();
    void DeleteRating(const string& ratingIDToDelete);

    // Friend function to save rating data to a file
    friend void SaveRatingToFile(Rating* rating);

    virtual ~Rating();
};
