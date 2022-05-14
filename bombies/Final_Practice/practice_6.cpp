#include <iostream>
#include <string>
using namespace std;

class Dealer {
   private:
    string dealerName;
    string carName;
    int carSold;

   public:
    Dealer(const string& n = "");
    ~Dealer();
    string getDealerName() const;
    void setDealerName(const string& n);
    string getCarName() const;
    void setCarName(const string& n);
    int getCarSold() const;
    void setCarSold(const int& s);
    void display() const;
    void populate();
};

Dealer::Dealer(const string& n) {
    setDealerName(n);
    setCarName(n);
    carSold = 0;
}

Dealer::~Dealer() {
}

string Dealer::getDealerName() const {
    return dealerName;
}
void Dealer::setDealerName(const string& n) {
    dealerName = n;
}

string Dealer::getCarName() const {
    return carName;
}
void Dealer::setCarName(const string& n) {
    carName = n;
}
int Dealer::getCarSold() const {
    return carSold;
}
void Dealer::setCarSold(const int& s) {
    carSold = s;
}
void Dealer::display() const {
    cout << getDealerName() << endl;
    cout << getCarName() << endl;
    cout << getCarSold() << endl;
}
void Dealer::populate(){
    cout << "dealer name: ";
    getline(cin, dealerName);
    setDealerName(dealerName);
    cin.ignore();
    cout << "car name: ";
    getline(cin,carName);
    setCarName(carName);
    cout << "# of car sold: ";
    cin >> carSold;
    setCarSold(carSold);
}
int main() {
    Dealer d;               
    d.populate();
    d.display();

    return 0;
}