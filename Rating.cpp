// Rating.cpp

#include "Rating.h"
#include <fstream>
#include <iostream>
string& Rating::getMenuItemID() {
    return menuItemID;
}

string& Rating::getCustomerID() {
    return customerID;
}

string& Rating::getComment() {
    return comment;
}

// Setter methods
void  Rating::setMenuItemID(string& newMenuItemID) {
    menuItemID = newMenuItemID;
}

void  Rating::setCustomerID(string& newCustomerID) {
    customerID = newCustomerID;
}

void  Rating::setComment(string& newComment) {
    comment = newComment;
}
Rating::Rating(string id, string itemID, string custID, int s, string c)
    : ratingID(id), menuItemID(itemID), customerID(custID), score(s), comment(c) {}

void Rating::Rate() {
    // Implementation of the Rate method
    // You can customize this method based on how you want the rating to be provided
    // For simplicity, let's assume a basic input for score and comment
    cout << "Enter your rating (1-5): ";
    cin >> score;
    cout << "Enter your comment: ";
    cin.ignore(); // Ignore the newline character left in the stream by previous input
    getline(cin, comment);
}

void SaveRatingToFile(Rating* rating) {
    // Implementation to save rating data to a file
    // This function assumes a file named "ratings.txt" for simplicity

    ofstream ratingsFile("ratings.txt", ios::app);
    if (ratingsFile.is_open()) {
        ratingsFile << rating->ratingID << " " << rating->menuItemID << " " << rating->customerID
            << " " << rating->score << " " << rating->comment << endl;
        ratingsFile.close();
        cout << "Rating data saved to file." << endl;
    }
    else {
        cout << "Error opening file for saving rating data." << endl;
    }
}
void Rating::DeleteRating(const string& ratingIDToDelete) {
    // Implementation to delete a rating from the file based on rating ID
    // This assumes a file named "ratings.txt" for simplicity

    ifstream inFile("ratings.txt");
    ofstream outFile("temp.txt");

    string tempRatingID;
    bool ratingFound = false;

    while (inFile >> tempRatingID >> menuItemID >> customerID >> score >> comment) {
        if (tempRatingID == ratingIDToDelete) {
            ratingFound = true;
            cout << "Rating with ID " << ratingIDToDelete << " deleted." << endl;
        }
        else {
            outFile << tempRatingID << " " << menuItemID << " " << customerID
                << " " << score << " " << comment << endl;
        }
    }

    inFile.close();
    outFile.close();

    if (remove("ratings.txt") != 0) {
        cerr << "Error deleting file: ratings.txt" << endl;
        // Handle the error or exit the function as needed
        return;
    }

    if (rename("temp.txt", "ratings.txt") != 0) {
        cerr << "Error renaming file: temp.txt to ratings.txt" << endl;
        // Handle the error or exit the function as needed
    }

    if (!ratingFound) {
        cout << "Rating with ID " << ratingIDToDelete << " not found." << endl;
    }
}


Rating::~Rating() {
    // Implementation of the destructor if needed
    // This could include any cleanup or additional actions when the object is destroyed
    cout << "Rating object with ID " << ratingID << " is being destroyed." << endl;
}
