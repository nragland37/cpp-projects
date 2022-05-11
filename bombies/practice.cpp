#include <iostream>

using namespace std;

void displayBubble(int list[], int size);
void displayBubbleSwap(int list_sort[], int size);
void displaySelection(int list_select[], int size);
void bubbleSort(int list[], int size);
void swapValues(int &a, int &b);
void bubbleSortSwap(int list[], int size);
void selectionSort(int list_select[], int size);

int main() {
    const int SIZE = 10;

    int list[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        list_swap[SIZE] = {69, 1, 7, 40, 3, 2, 8, 42, 47, 85},
        list_select[SIZE] = {934, 854, 54, 7, 543, 85, 390, 5432, 37, 1};

    displayBubble(list, SIZE);
    bubbleSort(list, SIZE);
    cout << "bubble-sorted ";  // why cant void functions be called before << ?
    displayBubble(list, SIZE);

    cout << endl;

    displayBubbleSwap(list_swap, SIZE);
    bubbleSortSwap(list_swap, SIZE);
    cout << "bubble-sorted (calling swap function) ";
    displayBubbleSwap(list_swap, SIZE);

    cout << endl;

    displaySelection(list_select, SIZE);
    selectionSort(list_select, SIZE);
    cout << "selection-sorted ";
    displaySelection(list_select, SIZE);

    return 0;
}

//****************************************************************************************************

void displayBubble(int list[], int size) {
    cout << "array: ";

    for (int arraySize = 0; arraySize < size; ++arraySize) {
        cout << list[arraySize] << " ";
    }
    cout << endl;
}

//****************************************************************************************************

void displayBubbleSwap(int list_sort[], int size) {
    cout << "array: ";

    for (int arraySize = 0; arraySize < size; ++arraySize) {
        cout << list_sort[arraySize] << " ";
    }
    cout << endl;
}

//****************************************************************************************************

void displaySelection(int list_select[], int size) {
    cout << "array: ";

    for (int arraySize = 0; arraySize < size; ++arraySize) {
        cout << list_select[arraySize] << " ";
    }
    cout << endl;
}

//****************************************************************************************************

void bubbleSort(int list[], int size) {
    bool swap;
    int temp;
    do {
        swap = false;
        for (int count = 0; count < (size - 1); ++count) {
            if (list[count] > list[count + 1]) {
                temp = list[count];
                list[count] = list[count + 1];
                list[count + 1] = temp;
                swap = true;
            }
        }
    } while (swap);
}

//****************************************************************************************************

void swapValues(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//****************************************************************************************************

void bubbleSortSwap(int list_swap[], int size)  // bubble sorting & calling swapValues function
{
    bool swap;
    int total = size;
    do {
        swap = false;
        for (int count = 0; count < (total - 1); ++count) {
            if (list_swap[count] > list_swap[count + 1]) {
                swapValues(list_swap[count], list_swap[count + 1]);
                swap = true;
            }
        }
        total--;
    } while (swap);
}

//****************************************************************************************************

void selectionSort(int list_select[], int size) {
    int minIndex;
    int minValue;
    for (int startScan = 0; startScan < (size - 1); ++startScan) {
        minIndex = startScan;
        minValue = list_select[minIndex];
        for (int index = startScan + 1; index < size; ++index) {
            if (list_select[index] < minValue) {
                minValue = list_select[index];
                minIndex = index;
            }
        }
        list_select[minIndex] = list_select[startScan];
        list_select[startScan] = minValue;
    }
}

/*

array: 10 9 8 7 6 5 4 3 2 1 
bubble-sorted array: 1 2 3 4 5 6 7 8 9 10 

array: 69 1 7 40 3 2 8 42 47 85 
bubble-sorted (calling swap function) array: 1 2 3 7 8 40 42 47 69 85 

array: 934 854 54 7 543 85 390 5432 37 1 
selection-sorted array: 1 7 37 54 85 390 543 854 934 5432 

*/