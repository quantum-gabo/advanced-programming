

/*
1. Use std::map<std::string, int> to store products in the inventory. The key is the product name, and the value is the quantity available.
Implement functions to:
Add a new product to the inventory.
Update the quantity of an existing product.
Display all available products.
*/
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>

void displayInventory(const std::map<std::string, int>& inventory) {
    std::cout << "Current Inventory:\n";
    for (const auto& item : inventory) {
        std::cout << item.first << ": " << item.second << " in stock\n";
    }
    std::cout << std::endl;
}

void addProduct(std::map<std::string, int>& inventory, const std::string& productName, int quantity) {
    inventory[productName] += quantity;
    std::cout << "Added " << quantity << " of " << productName << " to the inventory.\n";
}

void updateProduct(std::map<std::string, int>& inventory, const std::string& productName, int newQuantity) {
    if (inventory.find(productName) != inventory.end()) {
        inventory[productName] = newQuantity;
        std::cout << "Updated " << productName << " quantity to " << newQuantity << ".\n";
    } else {
        std::cout << productName << " not found in the inventory.\n";
    }
}

/*
2. Use std::set<std::string> to store unique product categories.
Implement functions to:
Add a new category.
Display all categories.
*/

void addCategory(std::set<std::string>& productCategories, const std::string& category) {
    productCategories.insert(category);
    std::cout << "Added category: " << category << "\n";
}

void displayCategories(const std::set<std::string>& productCategories) {
    std::cout << "Product Categories:\n";
    for (const auto& category : productCategories) {
        std::cout << "- " << category << "\n";
    }
}

/*
3. Use std::queue<std::string> to manage customer orders (FIFO processing).
Implement functions to:
Add a new order.
Process an order (remove from the queue).
*/

void addOrder(std::queue<std::string>& orders, std::string order) {
    orders.push(order);
    std::cout << "Added order: " << order << "\n";
}

void processOrder(std::queue<std::string>& orders) {
    while (!orders.empty()) {
        std::cout << "Processing order: " << orders.front() << std::endl;
        orders.pop();
    }
}

/*
4. Use std::stack<std::pair<std::string, int>> to manage restocked items (LIFO processing).
Implement functions to:
Add a restock batch.
Process a restock batch.
*/

void addRestock(std::stack<std::pair<std::string, int>>& restocks, std::string productName, int stock) {
    restocks.push({productName, stock});
    std::cout << "Added restock: " << productName << " with " << stock << " items" << std::endl;
}

void processRestock(std::stack<std::pair<std::string, int>>& restocks) {
    while (!restocks.empty()) {
        auto item = restocks.top();
        std::cout << "Restocking " << item.second << " units of " << item.first << std::endl;
        restocks.pop();
    }
}

/*
5. Use std::vector<std::string> to keep track of items a customer purchases.
Implement functions to:
Add items to a customer’s cart.
Display the items in the cart.
*/

void addToCart(std::vector<std::string>& customerCart, std::string product) {
    customerCart.push_back(product);
    std::cout << "Added " << product << " to the cart.\n";
}

void displayCart(std::vector<std::string>& customerCart) {
    std::cout << "Items in the cart: " << std::endl;
    for (const auto& item : customerCart) {
        std::cout << "- " << item << std::endl;
    }
}



int main() {
    std::cout << "######################### TASK 1 #########################\n";
    std::map<std::string, int> inventory;
    std::set<std::string> productCategories;
    // Adding products
    addProduct(inventory, "Apples", 50);
    addProduct(inventory, "Bananas", 30);
    addProduct(inventory, "Oranges", 20);


    displayInventory(inventory);

    // Updating products
    updateProduct(inventory, "Bananas", 25);
    updateProduct(inventory, "Grapes", 15);
    displayInventory(inventory);

    std::cout << "######################### TASK 2#########################\n";
   

    // Adding categories
    addCategory(productCategories, "Electronics");
    addCategory(productCategories, "Groceries");
    addCategory(productCategories, "Clothing");

    displayCategories(productCategories);

    std::cout << "######################### TASK 3 #########################\n";
    std::queue<std::string> orders;

    // Adding orders
    addOrder(orders, "Order#1: Laptop");
    addOrder(orders, "Order#2: Phone");

    // Processing orders
    processOrder(orders);

    std::cout << "######################### TASK 4 #########################\n";
    std::stack<std::pair<std::string, int>> restocks;

    // Adding restocks
    addRestock(restocks, "Mouse", 10);
    addRestock(restocks, "Keyboard", 5);
    addRestock(restocks, "Monitor", 2);

    // Processing restocks
    processRestock(restocks);

    std::cout << "######################### TASK 5 #########################\n";
    std::vector<std::string> customerCart;

    // Adding items to cart
    addToCart(customerCart, "Laptop");
    addToCart(customerCart, "Mouse");
    addToCart(customerCart, "Keyboard");

    // Displaying cart items
    displayCart(customerCart);

    std::cout << "Challenge Completed!\n";

    return 0;
}


