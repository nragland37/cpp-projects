// C++ program to demonstrate
// FCFS Disk Scheduling algorithm

#include <bits/stdc++.h>
using namespace std;

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

    cout << "Total number of seek operations = "
         << seek_count << endl;
    cout << "Average seek: " << (static_cast<double>(seek_count) / size) << endl;
    // Seek sequence would be the same
    // as request array sequence
    cout << "Seek Sequence is" << endl;

    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}

// Driver code
int main() {
    int size = 8;
    // request array
    int arr[size] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;

    FCFS(arr, size, head);

    return 0;
}