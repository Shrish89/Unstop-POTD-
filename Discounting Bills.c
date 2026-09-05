#include <bits/stdc++.h>
using namespace std;

class Cashier {
public:
    int n;
    int discount;
    int customerCount;

    vector<int> products;
    vector<int> prices;

    Cashier(int n, int discount, vector<int> products, vector<int> prices) {
        this->n = n;
        this->discount = discount;
        this->products = products;
        this->prices = prices;

        customerCount = 0;
    }

    double getBill(vector<int> product, vector<int> amount) {
        customerCount++;

        double bill = 0;

        // Calculate subtotal
        for (int i = 0; i < product.size(); i++) {

            for (int j = 0; j < products.size(); j++) {

                if (product[i] == products[j]) {
                    bill += product[i] == products[j]
                            ? amount[i] * prices[j]
                            : 0;
                    break;
                }
            }
        }

        // Apply discount to every nth customer
        if (customerCount % n == 0) {
            bill = bill * (100 - discount) / 100.0;
        }

        return bill;
    }
};

int main() {
    int n, discount;
    cin >> n >> discount;

    int z;
    cin >> z;

    vector<int> products(z);
    vector<int> prices(z);

    for (int i = 0; i < z; i++) {
        cin >> products[i];
    }

    for (int i = 0; i < z; i++) {
        cin >> prices[i];
    }

    Cashier cashier(n, discount, products, prices);

    int q;
    cin >> q;

    while (q--) {

        int y;
        cin >> y;

        vector<int> product(y);
        vector<int> amount(y);

        for (int i = 0; i < y; i++) {
            cin >> product[i] >> amount[i];
        }

        double result = cashier.getBill(product, amount);

        cout << result << endl;
    }

    return 0;
}