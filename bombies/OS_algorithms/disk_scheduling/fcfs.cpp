// FCFS Disk Scheduling algorithm

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void FCFS(int arr[], int size, int head);

//****************************************************************************************************

int main() {
    int size,
        head;

    cout << "FCFS" << endl;
    cout << "How many request: ";
    cin >> size;
    cout << "Read/Write head starts on track: ";
    cin >> head;

    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        cout << "Enter request " << i + 1 << ": ";
        cin >> arr[i];
    }

    FCFS(arr, size, head);

    delete[] arr;
    return 0;
}

//****************************************************************************************************

void FCFS(int arr[], int size, int head) {
    int seek_count = 0;
    int distance, cur_track;

    for (int i = 0; i < size; i++) {
        cur_track = arr[i];

        // calculate absolute distance
        distance = abs(cur_track - head);

        // increase the total count
        seek_count += distance;

        // accessed track is now new head
        head = cur_track;
    }

    cout << "\nTotal number of seek operations = "
         << seek_count << endl;
    cout << "Average seek: " << (static_cast<double>(seek_count) / size) << endl;
    // Seek sequence would be the same
    // as request array sequence
    cout << "\nSeek Sequence" << endl;

    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}

/*

FCFS
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

Total number of seek operations = 565
Average seek: 62.7778

Seek Sequence
86
147
91
177
94
150
102
175
130

/*