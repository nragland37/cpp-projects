#include <iostream>

using namespace std;

const int LIST_LEN = 10;

void print_array_backwards(int list[LIST_LEN]) // reverses the order but not array itself 
{
    for (int i = LIST_LEN-1; i >= 0; --i){
        cout << list[i] << " ";
    }
}

void print_array(int list[LIST_LEN]) 
{
    for (int i = 0; i < LIST_LEN; ++i){
        cout << list[i] << " ";
    }
}

// TODO: swap the array with temporary element 
void swap_array(int list[LIST_LEN], int x, int y) 
{
    int temp = list[x];
    list[x] = list[y];
    list[y] = temp;
}

int main()
{
    int list[LIST_LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Initial array: ";
    print_array(list);

    cout << endl << "Reverse values of array: "; 
    print_array_backwards(list);

    cout << endl << "Reversed_array: ";
    swap_array(list, 9, 0);
    print_array(list);

    cout << endl;
}