#include <iostream>

using namespace std;


void display (const char array[], int size);
void highest (const char array[], int size);

int main() {
    const int SIZE = 3;
    char array [SIZE] = {'R', 'S', 'T'};

    display (array, SIZE);
    cout << endl;
    highest (array, SIZE);

    return 0;
}

void display (const char array[], int size){
    for(int i =0; i < size - 1; ++i){
        cout << array[i]<< ",";
    }
    cout << array[size -1];
}

void highest (const char array[], int size){
    char high = array[0];
    for(int i=0;i<size;++i){
        if(high<array[i]){
            high = array[i];
        }
    }
    cout << "highest: " << high;
}