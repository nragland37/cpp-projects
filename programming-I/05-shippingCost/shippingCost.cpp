#include <iostream>
#include <iomanip>
using namespace std;

// Class untuk menghitung biaya pengiriman
class ShippingCalculator {
public:
    float calculateShipping(float weight) {
        const float LESS_ONE_LB = 10,
                    LESS_FIVE_LB = 7,
                    LESS_EIGHT_LB = 5,
                    LESS_TEN_LB = 3,
                    LESS_TWENTY_LB = 2,
                    ABOVE_TWENTY = 1;

        if (weight < 1)
            return LESS_ONE_LB * weight;
        else if (weight < 5)
            return LESS_FIVE_LB * weight;
        else if (weight < 8)
            return LESS_EIGHT_LB * weight;
        else if (weight < 10)
            return LESS_TEN_LB * weight;
        else if (weight < 20)
            return LESS_TWENTY_LB * weight;
        else
            return ABOVE_TWENTY * weight;
    }
};

// Class untuk menghitung pajak
class TaxCalculator {
public:
    float calculateTax(float price) {
        const float TAXRATE = 4.225 / 100;
        return price * TAXRATE;
    }
};

// Class untuk menghitung total biaya
class TotalCostCalculator {
public:
    float calculateTotalCost(float price, float tax, float shipping) {
        return price + tax + shipping;
    }
};

// Class untuk menangani input pengguna
class PurchaseInput {
public:
    void getInput(float &price, float &weight) {
        cout << "Enter the item's price: ";
        cin >> price;
        cout << "Enter the item's weight: ";
        cin >> weight;
    }
};

// Class utama untuk mengkoordinasi proses perhitungan
class OnlinePurchaseCalculator {
public:
    void calculate() {
        float price, weight, tax, shipping, totalCost;

        // Mengambil input
        PurchaseInput input;
        input.getInput(price, weight);

        // Menghitung biaya pengiriman
        ShippingCalculator shippingCalc;
        shipping = shippingCalc.calculateShipping(weight);

        // Menghitung pajak
        TaxCalculator taxCalc;
        tax = taxCalc.calculateTax(price);

        // Menghitung total biaya
        TotalCostCalculator totalCalc;
        totalCost = totalCalc.calculateTotalCost(price, tax, shipping);

        // Menampilkan hasil
        cout << "\nTotal price: " << fixed << setprecision(2) << totalCost << endl;
    }
};

// Program utama
int main() {
    OnlinePurchaseCalculator calculator;
    calculator.calculate();

    return 0;
}
