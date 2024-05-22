#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>

using namespace std;

class shopping {
private:
    int pcode; // product code
    float price;
    float dis; // discount
    string pname; // name of the product

public:
    // public functions
    void menu();
    void administrator(); // for administrators
    void buyer(); // for buyers
    void add(); // to add a product
    void edit(); // to edit the price, name, etc.
    void rem(); // to remove a product
    void list(); // to list all the items
    void receipt(); // to get the receipt
};

// defining the menu function outside the class using the scope resolution operator
void shopping::menu() {
    m: // label for goto
    int choice;
    string email;
    string password;

    cout << "\n\t\t\t\t\t________________________________________\n";
    cout << "\t\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t\t|         Supermarket Main Menu        |\n";
    cout << "\t\t\t\t\t|______________________________________|\n";
    cout << "\t\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t\t| 1) Administrator                     |\n";
    cout << "\t\t\t\t\t| 2) Buyer                             |\n";
    cout << "\t\t\t\t\t| 3) Exit                              |\n";
    cout << "\t\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t\t|______________________________________|\n\n";
    cout << "\t\t\t\t\t  Please select an option: ";
    cin >> choice;

    // using switch statement to execute different functionalities for different users
    switch (choice) {
    case 1: {
        cout << "\n\t\t\t\t\t  Please Login\n";
        cout << "\t\t\t\t\t  Enter Your Email: ";
        cin >> email;
        cout << "\t\t\t\t\t  Enter Password: ";
        cin >> password;

        // checking for authentication. It is already set and only admin knows it!
        if (email == "admin@gmail.com" && password == "admin@101") {
            administrator(); // call the administrator function if the email and password are correct
        } else {
            cout << "\n\t\t\t\t\t  Invalid Email Or Password\n";
        }
        break; // stop the case here
    }
    case 2: {
        buyer();
        break;
    }
    case 3: {
        exit(0); // successful termination of the program
        break;
    }
    default: {
        cout << "\n\t\t\t\t\t  Please select from the given Options\n";
    }
    }
    goto m; // jump to the main menu
}

void shopping::administrator() {
    m: // label for goto option
    int choice;
    cout << "\n\t\t\t\t\t  Administrator Menu\n";
    cout << "\n\t\t\t\t\t| 1) Add new product        |";
    cout << "\n\t\t\t\t\t| 2) Modify the product     |";
    cout << "\n\t\t\t\t\t| 3) Remove product         |";
    cout << "\n\t\t\t\t\t| 4) Back to Main menu      |";
    cout << "\n\n\t\t\t\t\t  Please Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        add(); // to add a new product
        break;
    }
    case 2: {
        edit(); // to modify or edit the existing product
        break;
    }
    case 3: {
        rem(); // to remove the product
        break;
    }
    case 4: {
        menu(); // to display the menu
        break;
    }
    default:
        cout << "\n\t\t\t\t\t  Invalid Choice!!";
    }

    goto m; // jump statement
}

void shopping::buyer() {
    m: // label for goto statement
    int choice;
    cout << "\n\t\t\t\t\t  Buyer Menu\n";
    cout << "\n\t\t\t\t\t| 1) Buy Product       |";
    cout << "\n\t\t\t\t\t| 2) Go back           |";
    cout << "\n\n\t\t\t\t\t  Enter your Choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        receipt();
        break;
    }
    case 2: {
        menu();
        break;
    }
    default:
        cout << "\n\t\t\t\t\t  Invalid Choice!!" << endl;
    }

    goto m;
}

// this function helps to add the product in the cart - can be done by admin only not buyers
void shopping::add() {
    m:
    fstream data; // file handling operations
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t\t\t  Add new product\n";
    cout << "\n\t\t\t\t\t  Enter Product code: ";
    cin >> pcode;
    cout << "\n\t\t\t\t\t  Name of the Product: ";
    cin >> pname;
    cout << "\n\t\t\t\t\t  Price of the Product: ";
    cin >> price;
    cout << "\n\t\t\t\t\t  Discount on Product: ";
    cin >> dis;

    data.open("database.txt", ios::in); // ios::in -- is used to read from the file

    if (!data) { // if the file doesn't exist
        data.open("database.txt", ios::app | ios::out); // ios::app is used to append to the file and ios::out is used to write in the file
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close(); // closing the file
    } else {
        data >> c >> n >> p >> d; // if the file exists then we will iterate over the file values

        while (!data.eof()) { // iterate till the end of the file
            if (c == pcode) { // if a product with the same code exists then we will not add it again
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close(); // closing the file

        if (token == 1) { // if the token value is incremented to 1 it means that the product is already present
            cout << "\n\t\t\t\t\t  Product code already exists. Please try again.\n";
            goto m;
        } else {
            data.open("database.txt", ios::app | ios::out); // ios::app is used to append to the file and ios::out is used to write in the file
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close(); // closing the file
        }
    }

    cout << "\n\t\t\t\t\t  Record Inserted Successfully!!" << endl;
}

void shopping::edit() {
    fstream data, data1; // creating two objects of the fstream class 
    int pkey; // to get the product code from the administrator
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t\t\t  Modify the Product\n";
    cout << "\n\t\t\t\t\t  Enter Product Code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);

    if (!data) { // if the file doesn't exist
        cout << "\n\t\t\t\t\t  File doesn't Exist!";
    } else {
        // we will write the updated value in the database1 file and then we will update its name to database after we make the changes 
        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;

        while (!data.eof()) {
            if (pkey == pcode) { // if the product exists
                cout << "\n\t\t\t\t\t  Product new Code: ";
                cin >> c;
                cout << "\n\t\t\t\t\t  Name of the Product: ";
                cin >> n;
                cout << "\n\t\t\t\t\t  Price: ";
                cin >> p;
                cout << "\n\t\t\t\t\t  Discount: ";
                cin >> d;

                // enter the new record
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\t\t\t\t\t  Record Edited Successfully!!" << endl;
                token++; // to check if the product code exists or not
            } else {
                // otherwise simply write the old record
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }

        data.close();
        data1.close();

        // deleting the existing file and renaming the new file to the old file name
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0) { // if no record found
            cout << "\n\t\t\t\t\t  Record Not Found Sorry!!";
        }
    }
}

void shopping::rem() {
    fstream data, data1; // creating two objects of the fstream class 
    int pkey;
    int token = 0;

    cout << "\n\t\t\t\t\t  Delete Product\n";
    cout << "\n\t\t\t\t\t  Enter Product Code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);

    if (!data) {
        cout << "\n\t\t\t\t\t  File doesn't exist";
    } else {
        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) {
            if (pcode == pkey) {
                cout << "\n\t\t\t\t\t  Product Deleted Successfully";
                token++;
            } else {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }

        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0) {
            cout << "\n\t\t\t\t\t  Record not found";
        }
    }
}

void shopping::list() {
    fstream data;
    data.open("database.txt", ios::in);

    cout << "\n\n\t\t\t\t\t________________________________________\n";
    cout << "\t\t\t\t\tProNo\t\tName\t\tPrice\n";
    cout << "\n\n\t\t\t\t\t________________________________________\n";
    data >> pcode >> pname >> price >> dis;

    while (!data.eof()) {
        cout << "\t\t\t\t\t" << setw(8) << pcode << setw(16) << pname << setw(16) << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping::receipt() {
    fstream data;

    int arrc[100]; // array of product codes
    int arrq[100]; // array of product quantity
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t\t  RECEIPT\n";
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\t\t\t\t\t  Empty Database";
    } else {
        data.close();

        list();
        cout << "\n\n\t\t\t\t\t_________________________\n";
        cout << "\t\t\t\t\t|                       |\n";
        cout << "\t\t\t\t\t|   Please place the order   |\n";
        cout << "\t\t\t\t\t|                       |\n";
        cout << "\t\t\t\t\t_________________________\n";

        do {
            m:
            cout << "\n\n\t\t\t\t\t  Enter Product Code: ";
            cin >> arrc[c];
            cout << "\n\n\t\t\t\t\t  Enter the product quantity: ";
            cin >> arrq[c];

            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\n\n\t\t\t\t\t  Duplicate Product Code. Please try again!";
                    goto m;
                }
            }
            c++;
            cout << "\n\n\t\t\t\t\t  Do you want to buy another product? If yes then press y else press n: ";
            cin >> choice;
        } while (choice == 'y');

        cout << "\n\n\t\t\t\t\t_________________________RECEIPT_________________________\n";
        cout << "\nProNo\tName\tQuantity\tPrice\tAmount\tAmount with discount\n";

        for (int i = 0; i < c; i++) {
            fstream data;
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total += dis;
                    cout << "\n" << setw(8) << pcode << setw(16) << pname << setw(16) << arrq[i] << setw(16) << price << setw(16) << amount << setw(16) << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\n\n\t\t\t\t\t____________________________________________________";
    cout << "\n Total Amount : " << total;
}

int main() {
    shopping s;
    s.menu();
}
