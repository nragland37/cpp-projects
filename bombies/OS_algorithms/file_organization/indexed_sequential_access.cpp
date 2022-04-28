#include <iostream>
using namespace std;

int accessCalc(int rl, int cba, int key, int blockNum);

//****************************************************************************************************

int main() {
    int rl,
        cba,
        key,
        totalRecords,
        totalBlocks,
        blockNum,
        address;

    cout << "Indexed Sequential Access" << endl;
    cout << "\nTotal records in file: ";
    cin >> totalRecords;
    cout << "Total blocks: ";
    cin >> totalBlocks;

    blockNum = totalRecords / totalBlocks;

    cout << "\n"
         << blockNum << " records per block" << endl;

    cout << "\nRecord Length(RL): ";
    cin >> rl;
    cout << "Current byte address(CBA): ";
    cin >> cba;
    cout << "Key: ";
    cin >> key;

    address = accessCalc(rl, cba, key, blockNum);
    cout << "\nByte address: " << address << endl;  

        return 0;
}

int accessCalc(int rl, int cba, int key, int blockNum) {
    return cba + (key % blockNum) * rl;
}