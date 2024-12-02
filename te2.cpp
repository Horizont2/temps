#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Product {
public:
    string name;
    string category;
    double price;

    Product(const string& name, const string& category, double price)
        : name(name), category(category), price(price) {}
};

void addProduct(vector<Product>& products, const string& name, const string& category, double price) {
    products.emplace_back(name, category, price);
}

void displayProducts(const vector<Product>& products) {
    for (const auto& product : products) {
        cout << "Name: " << product.name
             << ", Category: " << product.category
             << ", Price: " << product.price << endl;
    }
}

void filterByCategory(const vector<Product>& products, const string& category) {
    for (const auto& product : products) {
        if (product.category == category) {
            cout << "Name: " << product.name
                 << ", Price: " << product.price << endl;
        }
    }
}

void sortByPrice(vector<Product>& products) {
    sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
        return a.price < b.price;
    });
}

int main() {
    vector<Product> products;

    addProduct(products, "Apple", "Fruit", 1.2);
    addProduct(products, "Banana", "Fruit", 0.8);
    addProduct(products, "Milk", "Dairy", 1.5);

    cout << "All Products:" << endl;
    displayProducts(products);

    cout << "\nFiltered by category 'Fruit':" << endl;
    filterByCategory(products, "Fruit");

    cout << "\nProducts sorted by price:" << endl;
    sortByPrice(products);
    displayProducts(products);

    return 0;
}
