// Administrator.cpp

#include "Administrator.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <iomanip>

using namespace std;  // Add using namespace std to avoid using std:: prefix

//1
Administrator::Administrator(string id, string name, string pass)
    : user(id, name, pass, "Administrator") {
    // Constructor implementation...
}

bool Administrator::Authenticate() {
    // Prompt the user for username and password
    cout << "Enter Administrator username: ";
    cin >> userName;

    cout << "Enter Administrator password: ";
    cin >> password;
    if ((userName == "admin") && (password == "zxc"))
    {
        // Add logic for authentication (e.g., check entered username and password)
        // For simplicity, let's assume the authentication is successful
        cout << "Administrator login successful." << endl;
        return true;
    }
    cout << "Administrator credentials incorrect! Imposter detected." << endl;
    return false;
}

//2
void Administrator::Login() {
    // Implementation of login logic for the administrator
    cout << "Administrator Login:\n";

    // Clear input buffer to handle potential issues
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string enteredUsername, enteredPassword;

    // Prompt for administrator credentials
    cout << "Enter Administrator Username: ";
    getline(cin, enteredUsername);

    cout << "Enter Administrator Password: ";
    getline(cin, enteredPassword);

    // Open the administrator credentials file for reading
    ifstream adminCredentialsFile("admin_credentials.txt");  // Assuming you have a file named "admin_credentials.txt"

    if (adminCredentialsFile.is_open()) {
        string storedUsername, storedPassword;

        // Read the stored administrator credentials from the file
        adminCredentialsFile >> storedUsername >> storedPassword;

        // Close the file
        adminCredentialsFile.close();

        // Check if entered credentials match the stored credentials
        if (enteredUsername == storedUsername && enteredPassword == storedPassword) {
            cout << "Administrator login successful.\n";
        }
        else {
            cout << "Invalid credentials. Login failed.\n";
        }
    }
    else {
        cout << "Unable to open admin credentials file for login.\n";
    }
}

//3

//5
void Administrator::RemoveMenuItem() {
    // Implementation to remove a menu item
    cout << "Removing a menu item..." << endl;

    // Get the category and item name to remove
    int categoryChoice;
    cout << "Choose a category to remove from:\n";
    cout << "1. Desi\n";
    cout << "2. FastFood\n";
    cout << "3. Shakes/Tea\n";
    // Add more categories as needed

    cin >> categoryChoice;

    string categoryName;
    switch (categoryChoice) {
    case 1:
        categoryName = "desi_menu.txt";
        break;
    case 2:
        categoryName = "fastfood_menu.txt";
        break;
    case 3:
        categoryName = "shakes_tea_menu.txt";
        break;
        // Add more cases for additional categories
    default:
        cerr << "Invalid category choice." << endl;
        return;
    }

    string itemName;
    cout << "Enter item name to remove: ";
    cin >> itemName;

    // Read the existing menu file
    ifstream menuFile(categoryName);
    if (!menuFile.is_open()) {
        cerr << "Error: Unable to open menu file." << endl;
        return;
    }

    // Create a temporary file to store updated menu items
    ofstream tempFile("temp_menu.txt");
    if (!tempFile.is_open()) {
        cerr << "Error: Unable to create temporary file." << endl;
        menuFile.close();
        return;
    }

    // Read each line of the menu file
    string line;
    bool itemFound = false;
    while (getline(menuFile, line)) {
        // Check if the line contains the item to be removed
        if (line.find(itemName) == string::npos) {
            // If not, write it to the temporary file
            tempFile << line << endl;
        }
        else {
            itemFound = true;
        }
    }

    // Close the files
    menuFile.close();
    tempFile.close();

    // Remove the original file
    if (remove(categoryName.c_str()) != 0) {
        cerr << "Error: Unable to remove the original menu file." << endl;
        return;
    }

    // Rename the temporary file to the original file name
    if (rename("temp_menu.txt", categoryName.c_str()) != 0) {
        cerr << "Error: Unable to rename the temporary file." << endl;
        return;
    }

    if (itemFound) {
        cout << "Menu item removed successfully." << endl;
    }
    else {
        cout << "Item not found in the menu." << endl;
    }
}
//6
void Administrator::ManageInventory() {
    cout << "Managing inventory as Administrator." << endl;

    // Clear input buffer to handle potential issues
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int choice;
    cout << "1. Add Item to Inventory\n";
    cout << "2. View Inventory\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        // Add Item to Inventory
        ofstream inventoryFile("inventory.txt", ios::app);  // Assuming you have a file named "inventory.txt"

        if (inventoryFile.is_open()) {
            string itemName;
            int quantity;

            cout << "Enter the item name: ";
            cin.ignore();  // Clear input buffer before using getline
            getline(cin, itemName);

            cout << "Enter the quantity to add: ";
            cin >> quantity;

            // Write the inventory information to the file
            inventoryFile << setw(20) << left << itemName << " | Quantity: " << quantity << "\n";

            cout << "Item added to inventory successfully.\n";

            // Close the file
            inventoryFile.close();
        }
        else {
            cout << "Unable to open inventory file for adding.\n";
        }
    }
    else if (choice == 2) {
        // View Inventory
        ifstream inventoryFile("inventory.txt");  // Assuming you have a file named "inventory.txt"

        if (inventoryFile.is_open()) {
            cout << "\nInventory:\n";
            cout << "----------------------------\n";
            cout << "Item Name             | Quantity\n";
            cout << "----------------------------\n";

            string itemName;
            int quantity;

            while (inventoryFile >> setw(20) >> left >> itemName >> quantity) {
                cout << setw(20) << left << itemName << " | " << quantity << "\n";
            }

            cout << "----------------------------\n";

            // Close the file
            inventoryFile.close();
        }
        else {
            cout << "Unable to open inventory file for viewing.\n";
        }
    }
    else {
        cout << "Invalid choice. Please enter 1 or 2.\n";
    }
}
#include<vector>
//7
void Administrator::ManageDiscountPromotion() {
    cout << "Managing discounts and promotions as Administrator." << endl;

    // Clear input buffer to handle potential issues
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int choice;
    cout << "1. Add Discount or Promotion\n";
    cout << "2. View Discounts and Promotions\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        // Add Discount or Promotion
        ofstream discountFile("discounts.txt", ios::app);  // Assuming you have a file named "discounts.txt"

        if (discountFile.is_open()) {
            string itemName;
            double discountPercentage;

            cout << "Enter the item name: ";
            cin.ignore();  // Clear input buffer before using getline
            getline(cin, itemName);

            cout << "Enter the discount percentage: ";
            cin >> discountPercentage;

            // Write the discount information to the file
            discountFile << fixed << setprecision(2) << itemName << " " << discountPercentage << "\n";

            cout << "Discount or Promotion added successfully.\n";

            // Close the file
            discountFile.close();
        }
        else {
            cout << "Unable to open discounts file for adding.\n";
        }
    }
    else if (choice == 2) {
        // View Discounts and Promotions
        ifstream discountFile("discounts.txt");  // Assuming you have a file named "discounts.txt"

        if (discountFile.is_open()) {
            cout << "\nDiscounts and Promotions:\n";
            cout << "--------------------------------\n";
            cout << "Item Name             |  Discount (%)\n";
            cout << "--------------------------------\n";

            string itemName;
            double discountPercentage;

            while (discountFile >> itemName >> discountPercentage) {
                cout << left << setw(20) << itemName << " |  " << setw(10) << discountPercentage << "\n";
            }

            cout << "--------------------------------\n";

            // Close the file
            discountFile.close();
        }
        else {
            cout << "Unable to open discounts file for viewing.\n";
        }
    }
    else {
        cout << "Invalid choice. Please enter 1 or 2.\n";
    }
}
//8
void Administrator::ViewOrderHistory() {
    cout << "Viewing order history as Administrator." << endl;

    // Open the order history file for reading
    ifstream orderHistoryFile("order_history.txt");  // Assuming you have a file named "order_history.txt"

    if (orderHistoryFile.is_open()) {
        cout << "\nOrder History:\n";
        cout << "----------------------------------------------\n";
        cout << "Order ID   |  Customer Name  |  Total Price\n";
        cout << "----------------------------------------------\n";

        // Read and display order history data from the file
        string orderId, customerName;
        double totalPrice;

        while (orderHistoryFile >> orderId >> customerName >> totalPrice) {
            cout << left << setw(12) << orderId << " |  " << setw(16) << customerName
                << " |  RS" << setw(10) << fixed << setprecision(2) << totalPrice << "\n";
        }

        cout << "----------------------------------------------\n";

        // Close the file
        orderHistoryFile.close();
    }
    else {
        cout << "Unable to open order history file for viewing.\n";
    }
}

//9
void Administrator::AddNotification() {
    // Implementation of the AddNotification method
    cout << "Adding notification as Administrator." << endl;

    // Clear input buffer to handle potential issues
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string notificationMessage;
    cout << "Enter notification message: ";
    getline(cin, notificationMessage);

    // Open the notifications file for appending
    ofstream notificationFile("notifications.txt", ios::app);  // Assuming you have a file named "notifications.txt"

    if (notificationFile.is_open()) {
        // Save the new notification to the file
        notificationFile << notificationMessage << "\n";
        notificationFile.close();

        cout << "Notification added successfully." << endl;
    }
    else {
        cout << "Unable to open notifications file for adding a notification.\n";
    }
}

//10
void Administrator::RemoveNotification() {
    // Implementation of the RemoveNotification method
    cout << "Removing notification as Administrator." << endl;

    // Clear input buffer to handle potential issues
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string notificationToRemove;
    cout << "Enter the notification to remove: ";
    getline(cin, notificationToRemove);

    // Read existing notifications from the file into a vector
    vector<string> notifications;
    ifstream notificationFile("notifications.txt");  // Assuming you have a file named "notifications.txt"

    if (notificationFile.is_open()) {
        string line;
        while (getline(notificationFile, line)) {
            notifications.push_back(line);
        }
        notificationFile.close();
    }
    else {
        cout << "Unable to open notifications file for removing a notification.\n";
        return;
    }

    // Open the notifications file for writing
    ofstream updatedNotificationFile("notifications.txt");

    if (updatedNotificationFile.is_open()) {
        // Write back notifications to the file excluding the one to remove
        for (const string& notification : notifications) {
            if (notification != notificationToRemove) {
                updatedNotificationFile << notification << "\n";
            }
        }
        updatedNotificationFile.close();

        cout << "Notification removed successfully." << endl;
    }
    else {
        cout << "Unable to open notifications file for updating notifications.\n";
    }
}

//11
void Administrator::RateMenuItem() {
    // Implementation of the RateMenuItem method
    cout << "Rating menu item as Administrator." << endl;

    // Clear input buffer to handle potential issues
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ratingID;
    string menuItemID;
    string customerID;
    int score;
    string comment;

    cout << "Enter the Rating id : ";
    getline(cin, ratingID);
    cout << "Enter the name of the menu item to rate: ";
    getline(cin, menuItemID);
    cout << "Enter the Customer id: ";
    getline(cin, customerID);
    cout << "Enter score: " << endl;
    cin >> score;
    cout << "Enter the comments: ";
    getline(cin, comment);



    cout << "Enter the rating (1-5): ";
    while (!(cin >> score) || score < 1 || score > 5) {
        // Handle invalid rating input
        cout << "Invalid input. Please enter a rating between 1 and 5: ";
        cin.clear();  // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
    }

    // Create a new Rating object using the input
    Rating* newRating = new Rating(ratingID, menuItemID, customerID, score, comment);

    // Save the new rating to the ratings file
    SaveRatingToFile(newRating);

    cout << "Rating added successfully." << endl;

    // Don't forget to deallocate the memory for the dynamically allocated Rating
    delete newRating;
}

//12
void Administrator::DisplayFromFile() {
    cout << "Displaying data from file as Administrator." << endl;

    // Open the data file for reading
    ifstream dataFile("data.txt");  // Assuming you have a file named "data.txt"

    if (dataFile.is_open()) {
        // Display data from the file
        cout << "\nData from File:\n";
        cout << "----------------------------\n";

        string line;
        while (getline(dataFile, line)) {
            cout << line << "\n";
        }

        cout << "----------------------------\n";

        // Close the file
        dataFile.close();
    }
    else {
        cout << "Unable to open data file for viewing.\n";
    }
}

//13
void Administrator::ViewUsersFromFile() {
    // Implementation of the ViewUsersFromFile method
    cout << "Viewing users from file as Administrator." << endl;

    // Open the user data file for reading
    ifstream userDataFile("user_data.txt");  // Assuming you have a file named "user_data.txt"

    if (userDataFile.is_open()) {
        // Read and display user data from the file
        string userId, userName, userPassword, userType;

        cout << "\nUser Data from File:\n";
        cout << "---------------------------------------------\n";
        cout << "User ID   |  User Name  |  Password  |  User Type\n";
        cout << "---------------------------------------------\n";

        while (userDataFile >> userId >> userName >> userPassword >> userType) {
            cout << userId << "        |  " << userName << "       |  " << userPassword << "    |  " << userType << "\n";
        }

        cout << "---------------------------------------------\n";

        // Close the file
        userDataFile.close();
    }
    else {
        cout << "Unable to open user data file for viewing.\n";
    }
}

//14
void Administrator::ViewMenuItemsFromFile() {
    cout << "Viewing menu items from file as Administrator." << endl;

    // Open the menu items file for reading
    ifstream menuItemsFile("menu_items.txt");  // Assuming you have a file named "menu_items.txt"

    if (menuItemsFile.is_open()) {
        // Read and display menu item data from the file
        string itemId, itemName, itemDescription;
        double itemPrice;
        int quantityInStock;

        cout << "\nMenu Items from File:\n";
        cout << "----------------------------------------------------------------\n";
        cout << "Item ID   |  Item Name  |  Description  |  Price  |  Quantity\n";
        cout << "----------------------------------------------------------------\n";

        while (menuItemsFile >> itemId >> itemName >> itemDescription >> itemPrice >> quantityInStock) {
            cout << itemId << "        |  " << itemName << "       |  " << itemDescription
                << "       |  RS" << itemPrice << "  |  " << quantityInStock << "\n";
        }

        cout << "----------------------------------------------------------------\n";

        // Close the file
        menuItemsFile.close();
    }
    else {
        cout << "Unable to open menu items file for viewing.\n";
    }
}

//15
void Administrator::ViewOrdersFromFile() {
    cout << "Viewing orders from file as Administrator." << endl;

    // Open the orders file for reading
    ifstream ordersFile("orders.txt");  // Assuming you have a file named "orders.txt"

    if (ordersFile.is_open()) {
        // Read and display order data from the file
        string orderId, itemName, customerName;
        double totalPrice;
        int quantity;

        cout << "\nOrders from File:\n";
        cout << "---------------------------------------------\n";
        cout << "Order ID   |  Item Name  |  Customer Name  |  Quantity  |  Total Price\n";
        cout << "---------------------------------------------\n";

        while (ordersFile >> orderId >> itemName >> customerName >> quantity >> totalPrice) {
            cout << orderId << "        |  " << itemName << "       |  " << customerName
                << "        |  " << quantity << "        |  RS" << totalPrice << "\n";
        }

        cout << "---------------------------------------------\n";

        // Close the file
        ordersFile.close();
    }
    else {
        cout << "Unable to open orders file for viewing.\n";
    }
}

//16
void Administrator::ViewRatingsFromFile() {
    cout << "Viewing ratings from file as Administrator." << endl;

    // Open the ratings file for reading
    ifstream ratingsFile("ratings.txt");  // Assuming you have a file named "ratings.txt"

    if (ratingsFile.is_open()) {
        // Read and display ratings data from the file
        string itemName;
        int rating;

        cout << "\nRatings from File:\n";
        cout << "------------------------\n";
        cout << "Item Name  |  Rating\n";
        cout << "------------------------\n";

        while (ratingsFile >> itemName >> rating) {
            cout << itemName << "       |  " << rating << "\n";
        }

        cout << "------------------------\n";

        // Close the file
        ratingsFile.close();
    }
    else {
        cout << "Unable to open ratings file for viewing.\n";
    }
}

//17
void Administrator::ViewPaymentsFromFile() {
    cout << "Viewing payments from file as Administrator." << endl;

    // Open the payments file for reading
    ifstream paymentsFile("payments.txt");  // Assuming you have a file named "payments.txt"

    if (paymentsFile.is_open()) {
        // Read and display payment data from the file
        string paymentId, customerName;
        double amount;
        int transactionStatus;

        cout << "\Payments from File:\n";
        cout << "---------------------------------------------\n";
        cout << "Payment ID   |  Customer Name  |  Amount  |  Status\n";
        cout << "---------------------------------------------\n";

        while (paymentsFile >> paymentId >> customerName >> amount >> transactionStatus) {
            cout << paymentId << "        |  " << customerName << "       |  RS" << amount
                << "  |  " << (transactionStatus == 1 ? "Success" : "Failed") << "\n";
        }

        cout << "---------------------------------------------\n";

        // Close the file
        paymentsFile.close();
    }
    else {
        cout << "Unable to open payments file for viewing.\n";
    }
}

//18
void Administrator::CalculateMonthlyEarnings() {
    cout << "Calculating monthly earnings as Administrator." << endl;

    // Open the earnings file for reading
    ifstream earningsFile("earnings.txt");  // Assuming you have a file named "earnings.txt"

    if (earningsFile.is_open()) {
        // Read and calculate total monthly earnings
        double totalEarnings = 0.0;
        double currentEarning;

        while (earningsFile >> currentEarning) {
            totalEarnings += currentEarning;
        }

        // Close the file
        earningsFile.close();

        cout << "Total Monthly Earnings: RS" << totalEarnings << endl;
    }
    else {
        cout << "Unable to open earnings file for calculation.\n";
    }
}

void Administrator::Logout() {
    cout << "Logging out as Administrator..." << endl;

    // Any additional logout logic can be added here
    // For example, you may want to perform cleanup or additional actions specific to the Administrator role.

    // Call the base class (user) logout method
    user::Logout();
}

void SaveUserToFile1(user* user) {
    // Open the user data file for writing
    ofstream userDataFile("user_data.txt", ios::app);  // Assuming you have a file named "user_data.txt"

    if (userDataFile.is_open()) {
        // Write user data to the file
        userDataFile << "User ID: " << user->getUserID() << "\n";
        userDataFile << "User Name: " << user->getUserName() << "\n";
        userDataFile << "User Type: " << user->getUserType() << "\n";
        // Add more data fields as needed...

        userDataFile << "---------------------------------\n";  // Separator between user entries

        // Close the file
        userDataFile.close();
    }
    else {
        cerr << "Error: Unable to open user data file for writing.\n";
    }
}

void SavePaymentToFile1(Payment* payment) {
    // Open the payment data file for writing
    ofstream paymentDataFile("payment_data.txt", ios::app);  // Assuming you have a file named "payment_data.txt"

    if (paymentDataFile.is_open()) {
        // Write payment data to the file
        paymentDataFile << "Transaction ID: " << payment->getPaymentID() << "\n";
        paymentDataFile << "Amount: RS" << payment->getAmount() << "\n";
        paymentDataFile << "Payment Date: " << payment->getPaymentStatus() << "\n";
        // Add more data fields as needed...

        paymentDataFile << "---------------------------------\n";  // Separator between payment entries

        // Close the file
        paymentDataFile.close();
    }
    else {
        cerr << "Error: Unable to open payment data file for writing.\n";
    }
}

void SaveOrderToFile1(Order* order) {
    // Open the order data file for writing
    ofstream orderDataFile("order_data.txt", ios::app);  // Assuming you have a file named "order_data.txt"

    if (orderDataFile.is_open()) {
        // Write order data to the file
        orderDataFile << "Order ID: " << order->getOrderID() << "\n";
        orderDataFile << "Customer Name: " << order->getCustomerID() << "\n";
        orderDataFile << "Total Price: RS" << order->getTotalPrice() << "\n";
        // Add more data fields as needed...

        orderDataFile << "---------------------------------\n";  // Separator between order entries

        // Close the file
        orderDataFile.close();
    }
    else {
        cerr << "Error: Unable to open order data file for writing.\n";
    }
}

void SaveRatingToFile1(Rating* rating) {
    // Open the rating data file for writing
    ofstream ratingDataFile("rating_data.txt", ios::app);  // Assuming you have a file named "rating_data.txt"

    if (ratingDataFile.is_open()) {
        // Write rating data to the file
        ratingDataFile << "Menu Item ID: " << rating->getMenuItemID() << "\n";
        ratingDataFile << "Customer Name: " << rating->getCustomerID() << "\n";
        ratingDataFile << "Rating: " << rating->getComment() << "\n";
        // Add more data fields as needed...

        ratingDataFile << "---------------------------------\n";  // Separator between rating entries

        // Close the file
        ratingDataFile.close();
    }
    else {
        cerr << "Error: Unable to open rating data file for writing.\n";
    }
}



void Administrator::Register() {
    cout << "Administrator registration implemented." << endl;

    // Gather additional information during registration
    string contactNumber;
    cout << "Enter contact number: ";
    cin >> contactNumber;

    // You can add more fields and gather additional information as needed

    // Save the registration information to a file or database
    SaveAdministratorRegistrationToFile(contactNumber);

    cout << "Registration successful.\n";
}

void SaveAdministratorRegistrationToFile(string& contactNumber) {
    ofstream adminRegistrationFile("admin_registration.txt", ios::app);  // Assuming you have a file named "admin_registration.txt"

    if (adminRegistrationFile.is_open()) {
        adminRegistrationFile << "Contact Number: " << contactNumber << "\n";
        // Add more fields and information as needed...

        adminRegistrationFile << "---------------------------------\n";  // Separator between entries

        adminRegistrationFile.close();
    }
    else {
        cerr << "Error: Unable to open admin registration file for writing.\n";
    }
}

void Administrator::ViewMenu() {
    // Implementation to view the menu
    // You can read the menu items from a file or any other data source
    // and display them to the administrator
    cout << "Viewing menu..." << endl;

    // Example: Display menu items from a file
    ifstream menuFile("menu.txt");  // Assuming you have a file named "menu.txt"
    string itemName;
    double itemPrice;
    while (menuFile >> itemName >> itemPrice) {
        cout << itemName << " - RS" << itemPrice << endl;
    }
    menuFile.close();
}

void Administrator::AddMenuItem() {
    // Implementation to add a new menu item
    // You may get input from the administrator and save it to the menu file
    cout << "Adding a new menu item..." << endl;

    // Clear input buffer to handle potential issues
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string itemName;
    double itemPrice;
    cout << "Enter item name: ";
    getline(cin, itemName);

    cout << "Enter item price: ";
    while (!(cin >> itemPrice)) {
        // Handle non-numeric input
        cout << "Invalid input. Please enter a numeric value for item price: ";
        cin.clear();  // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
    }

    // Create a new Menuitem object using the input
    Menuitem* newItem = new Menuitem("ID_placeholder", itemName, "Description_placeholder", itemPrice, 0);

    // Save the new item to the menu file
    SaveMenuItemToFile(newItem);

    cout << "New menu item added successfully." << endl;

    // Don't forget to deallocate the memory for the dynamically allocated Menuitem
    delete newItem;
}