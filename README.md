# Super-Market-Billing-System
# Supermarket Management System

## Description
The Supermarket Management System is a console-based application developed in C++. This application provides an interface for administrators to manage products and for buyers to purchase products. The system allows administrators to add, edit, and remove products, and buyers to view and purchase products with a receipt generated for their purchases.

## Features
- **Administrator Menu**
  - Add new products
  - Modify existing products
  - Remove products
  - Return to the main menu

- **Buyer Menu**
  - View the list of available products
  - Purchase products
  - Generate and view receipts for purchases

## Requirements
- C++ compiler (e.g., GCC)
- Standard C++ libraries

## Installation
1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/supermarket-management-system.git
   ```
2. **Navigate to the project directory:**
   ```bash
   cd supermarket-management-system
   ```

## Usage
1. **Compile the program:**
   ```bash
   g++ main.cpp -o supermarket
   ```
2. **Run the program:**
   ```bash
   ./supermarket
   ```

## Menu Navigation
### Main Menu
- Select an option by entering the corresponding number:
  - `1`: Administrator
  - `2`: Buyer
  - `3`: Exit

### Administrator Menu
- Options:
  - `1`: Add new product
  - `2`: Modify existing product
  - `3`: Remove product
  - `4`: Back to main menu

### Buyer Menu
- Options:
  - `1`: Buy product
  - `2`: Go back to main menu

## Code Overview
The program is implemented in a single class `shopping` which contains the following methods:
- `menu()`: Displays the main menu and handles user input.
- `administrator()`: Displays the administrator menu and handles administrator actions.
- `buyer()`: Displays the buyer menu and handles buyer actions.
- `add()`: Adds a new product to the system.
- `edit()`: Modifies an existing product.
- `rem()`: Removes a product from the system.
- `list()`: Lists all available products.
- `receipt()`: Generates and displays a receipt for the buyer's purchases.

## Example Output
### Main Menu
```
________________________________________
|                                      |
|         Supermarket Main Menu        |
|______________________________________|
|                                      |
| 1) Administrator                     |
| 2) Buyer                             |
| 3) Exit                              |
|                                      |
|______________________________________|

  Please select an option:
```

### Receipt
```
_________________________RECEIPT_________________________

ProNo        Name        Quantity    Price       Amount    Amount with discount
1001         Milk        2           2.50        5.00      4.50
```

## Contributing
Feel free to fork this repository and submit pull requests. For major changes, please open an issue first to discuss what you would like to change.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
