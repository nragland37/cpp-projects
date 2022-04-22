// C++ program for implementation of
// SSTF disk scheduling
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void calculatedifference(int request[], int head, int diff[][2], int size);
int findMIN(int diff[][2], int size);
void shortestSeekTimeFirst(int request[], int head, int size);

//****************************************************************************************************

int main() {
    int size,
        head;
    // request array

    cout << "SSTF" << endl;
    cout << "How many request: ";
    cin >> size;
    cout << "Read/Write head starts on track: ";
    cin >> head;

    int* proc = new int[size];
    for (int i = 0; i < size; ++i) {
        cout << "Enter request " << i + 1 << ": ";
        cin >> proc[i];
    }

    shortestSeekTimeFirst(proc, head, size);
    delete[] proc;
    return 0;
}

//****************************************************************************************************

// Calculates difference of each
// track number with the head position
void calculatedifference(int request[], int head, int diff[][2], int size) {
    for (int i = 0; i < size; i++) {
        diff[i][0] = abs(head - request[i]);
    }
}

//****************************************************************************************************

// Find unaccessed track which is
// at minimum distance from head
int findMIN(int diff[][2], int size) {
    int index = -1;
    int minimum = 1e9;

    for (int i = 0; i < size; i++) {
        if (!diff[i][1] && minimum > diff[i][0]) {
            minimum = diff[i][0];
            index = i;
        }
    }
    return index;
}

//****************************************************************************************************

void shortestSeekTimeFirst(int request[], int head, int size) {
    if (size == 0) {
        return;
    }

    // Create array of objects of class node
    int diff[size][2] = {{0, 0}};

    // Count total number of seek operation
    int seekcount = 0;

    // Stores sequence in which disk access is done
    int seeksequence[size + 1] = {0};

    for (int i = 0; i < size; i++) {
        seeksequence[i] = head;
        calculatedifference(request, head, diff, size);
        int index = findMIN(diff, size);
        diff[index][1] = 1;

        // Increase the total count
        seekcount += diff[index][0];

        // Accessed track is now new head
        head = request[index];
    }
    seeksequence[size] = head;

    cout << "\nTotal number of seek operations = " << seekcount << endl;
    cout << "Average seek: " << (static_cast<double>(seekcount) / size) << endl;
    cout << "\nSeek sequence" << endl;

    // Print the sequence
    for (int i = 0; i <= size; i++) {
        cout << seeksequence[i] << "\n";
    }
}

/*

SSTF
How many request: 9
Read/Write head starts on track: 143
Enter request 1: 86
Enter request 2: 147
Enter request 3: 91
Enter request 4: 177
Enter request 5: 94
Enter request 6: 150
Enter request 7: 102
Enter request 8: 175
Enter request 9: 130

Total number of seek operations = 162
Average seek: 18

Seek sequence
143            // Read/Write head starts on track
147
150
130
102
94
91
86
175
177

*/