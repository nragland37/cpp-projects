#include <iostream>

using namespace std;

const size_t LIST_LEN = 10;

// TODO: modify the given array so that elements are reversed
void rev_array(int list[LIST_LEN])
{
}

// TODO: print the elements of the array in order
void print_array(int list[LIST_LEN])
{
}

int main()
{
    int list[LIST_LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Initial array: ";
    print_array(list);

    rev_array(list);

    cout << "Reversed_array: ";
    print_array(list);
}