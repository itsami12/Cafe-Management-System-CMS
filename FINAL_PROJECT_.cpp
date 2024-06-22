#include <iostream>
#include "Administrator.h"
#include "CafeStaff.h"
#include "Customer.h"
#include"Menuitem.h"
#include"order.h"
#include"Payment.h"
#include"Rating.h"
#include"user.h"
using namespace std;


int main() {


    cout << " ===============================" << endl;
    cout << " |                             |" << endl;
    cout << " |         Welcome to          |" << endl;
    cout << " |       Cafe Management       |" << endl;
    cout << " |                             |" << endl;
    cout << " ===============================" << endl;

    char userType;
    cout << "Login as:\n";
    cout << "1. Administrator\n";
    cout << "2. Cafe Staff\n";
    cout << "3. Customer\n";
    cout << "Select option (1-3): ";
    cin >> userType;
    //Administrator admin("admin_username", "admin_password", "admin_email");

    Administrator admin("admin001", "Admin User", "adminPass");

    if (admin.Authenticate())
    {
        switch (userType) {
        case '1': {

            admin.Login();

            // Check if authentication is successful



            cout << "Authentication successful. Welcome, Administrator!\n";

            int adminOption;
            do 
            {
                cout << " ===============================" << endl;
                cout << " |  Administrator Options     |" << endl;
                cout << " ===============================" << endl;


                cout << "1. View Menu\n";
                cout << "2. Add Menu Item\n";
                cout << "3. Remove Menu Item\n";
                cout << "4. Manage Inventory\n";
                cout << "5. Manage Discounts/Promotions\n";
                cout << "6. View Order History\n";
                cout << "7. Add Notification\n";
                cout << "8. Remove Notification\n";
                cout << "9. Rate Menu Item\n";
                cout << "10. Display Data from File\n";
                cout << "11. View Users from File\n";
                cout << "12. View Menu Items from File\n";
                cout << "13. View Orders from File\n";
                cout << "14. View Ratings from File\n";
                cout << "15. View Payments from File\n";
                cout << "16. Calculate Monthly Earnings\n";
                cout << "17. Logout\n";
                cout << "Select option (1-17): ";
                cin >> adminOption;

                switch (adminOption) {
                case 1:
                    admin.ViewMenu();
                    break;
                case 2:
                    admin.AddMenuItem();
                    break;
                    // ... add cases for other options
                case 17:
                    admin.Logout();
                    break;
                default:
                    cout << "Invalid option. Try again.\n";
                    break;
                }
            } while (adminOption != 17);
        
    
        break;
        }
        // ... add cases for Cafe Staff and Customer
        default:
            cout << "Invalid option. Exiting...\n";
            break;
        }
    }
else
{
    cout << "Authentication failed. Exiting...\n";
 }

    CafeStaff cafeStaff("staff001", "Staff User", "staffPass");
    switch (userType) {
  
    case '2': {
      
        // Add switch cases for CafeStaff options
        int cafeStaffOption;
        if (cafeStaff.Authenticate()) {
            cout << "Authentication successful. Welcome, Cafe Staff!\n";

            do {
                cout << " ===============================" << endl;
                cout << " |  Cafe Staff Options         |" << endl;
                cout << " ===============================" << endl;
                cout << "1. View Menu\n";
                cout << "2. Process Order\n";

                cout << "3. Add Menu Item\n";
                cout << "4. Remove Menu Item\n";

                cout << "5. Logout\n";
                cout << "Select option (1-5): ";
                cin >> cafeStaffOption;

                switch (cafeStaffOption) {
                case 1:
                    cafeStaff.ViewMenu();
                    break;
                case 2:
                    cafeStaff.ProcessOrder();
                    break;
                case 3:
                    //cafeStaff.AddMenuItem();
                    break;
                case 4:
                    //cafeStaff.RemoveMenuItem();
                    break;
                case 5:
                    cafeStaff.Logout();
                    break;
                default:
                    cout << "Invalid option. Try again.\n";
                    break;
                }
            } while (cafeStaffOption != 5);
        
        }
        else{
        cout << "Authentication failed. Exiting...\n";
        }
        break;
    }
    case '3': {
        Customer customer("cust001", "Customer User", "custPass");
        // Add switch cases for Customer options
        int customerOption;
        do {
            cout << " ===============================" << endl;
            cout << " |  Customer Options           |" << endl;
            cout << " ===============================" << endl;
            cout << "1. View Menu\n";
            cout << "2. Place Order\n";
            cout << "3. View Order History\n";
            cout << "4. Logout\n";
            cout << "Select option (1-4): ";
            cin >> customerOption;

            switch (customerOption) {
            case 1:
                customer.ViewMenu();
                break;
            case 2:
                customer.PlaceOrder();
                break;
            case 3:
                customer.ViewOrderHistory();
                break;
            case 4:
                customer.Logout();
                break;
            default:
                cout << "Invalid option. Try again.\n";
                break;
            }
        } while (customerOption != 4);
        break;
    }
    default:
        cout << "Invalid option. Exiting...\n";
        break;
    }




    return 0;



}

