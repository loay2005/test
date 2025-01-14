#pragma once

#include <iostream>
using namespace std;

// Struct for the market items
struct market {
    float price;
    string item;
    char size;
};

// Client class
class client {
private:
    int id;
    string fullname;
    int age;
    int phoneNumber;
    market cart[10]; // Fixed-size array for storing purchased items
    int cartSize; // Counter for items in the cart

public:
    // Constructor
    client(int id, string fullname, int age, int phoneNumber) {
        this->id = id;
        this->fullname = fullname;
        this->age = age;
        this->phoneNumber = phoneNumber;
        cartSize = 0; // Initialize cart size to 0
    }

    // Marketplace method to display menu
    void marketplace() {
        cout << "Welcome to the Market!\n";

        // 2D Array: Rows = Meals, Columns = Different Sizes
        market menu[3][3] = {
            { {"Chicken", 'S', 4.99}, {"Chicken", 'M', 6.99}, {"Chicken", 'L', 8.99} },
            { {"Fish", 'S', 3.99}, {"Fish", 'M', 5.99}, {"Fish", 'L', 7.99} },
            { {"Milkshake", 'S', 2.49}, {"Milkshake", 'M', 3.49}, {"Milkshake", 'L', 4.49} }
        };

        // Displaying the menu
        cout << "\nMenu:\n";
        for (int i = 0; i < 3; i++) {
            cout << menu[i][0].item << " Options:\n"; // Print the meal name once
            for (int j = 0; j < 3; j++) {
                cout << "  Size: " << menu[i][j].size
                    << " - Price: $" << menu[i][j].price << endl;
            }
            cout << endl;
        }
    }

    // Buy method to allow users to purchase multiple items
    void buy() {
        string name;
        char size;
        float price = 0;
        char choice;

        do {
            if (cartSize >= 10) {
                cout << "Cart is full! You can't add more items.\n";
                break;
            }

            cout << "Enter the name of the meal you want to buy: ";
            cin >> name;
            cout << "Enter the size (S/M/L): ";
            cin >> size;

            // Convert input to lowercase for case insensitivity
            for (char& c : name) c = tolower(c);
            size = toupper(size);

            // Find the price
            if (name == "chicken") {
                if (size == 'L') price = 8.99;
                else if (size == 'M') price = 6.99;
                else price = 4.99;
            }
            else if (name == "fish") {
                if (size == 'L') price = 7.99;
                else if (size == 'M') price = 5.99;
                else price = 3.99;
            }
            else if (name == "milkshake") {
                if (size == 'L') price = 4.49;
                else if (size == 'M') price = 3.49;
                else price = 2.49;
            }
            else {
                cout << "Invalid item name! Please try again.\n";
                continue;
            }

            // Add item to cart
            cart[cartSize] = { price, name, size };
            cartSize++; // Increase cart size

            cout << "Added " << name << " (Size: " << size << ") to your cart for $" << price << endl;
            cout << "Would you like to buy another item? (y/n): ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');

        printBill(); // Call billing function after shopping
    }

    // Function to print the final bill
    void printBill() {
        if (cartSize == 0) {
            cout << "Your cart is empty. No items to bill.\n";
            return;
        }

        float total = 0;
        cout << "\n********** BILL **********\n";
        cout << "Item\t\tSize\tPrice\n";
        cout << "-----------------------------\n";

        for (int i = 0; i < cartSize; i++) {
            cout << cart[i].item << "\t\t" << cart[i].size << "\t$" << cart[i].price << endl;
            total += cart[i].price;
        }

        cout << "-----------------------------\n";
        cout << "Total Amount: $" << total << endl;
        cout << "*****************************\n";
    }

    // Placeholder for other functions
    void authenticate() { cout << "Authentication feature coming soon!\n"; }
    void accessDietSupplement() { cout << "Diet Supplement feature coming soon!\n"; }
    void accessSchedules() { cout << "Schedules feature coming soon!\n"; }
    void communicate() { cout << "Communication feature coming soon!\n"; }
};
