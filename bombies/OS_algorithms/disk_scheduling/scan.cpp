// SCAN Disk Scheduling algorithm
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int disk_size = 200;  // "disk has 200 cyclinders" - can be changed accordingly

void SCAN(int arr[], int size, int head, string direction);

//****************************************************************************************************

int main() {
    int size,
        head;

    cout << "SCAN" << endl;
    cout << "How many request: ";
    cin >> size;
    cout << "Read/Write head starts on track: ";
    cin >> head;

    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        cout << "Enter request " << i + 1 << ": ";
        cin >> arr[i];
    }
    string direction = "right";  // "right" = large numbers / "left" = small numbers - can be changed accordinly

    SCAN(arr, size, head, direction);
    delete[] arr;
    return 0;
}

//****************************************************************************************************

void SCAN(int arr[], int size, int head, string direction) {
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;

    // appending end values
    // which has to be visited
    // before reversing the direction
    if (direction == "left")
        left.push_back(0);
    else if (direction == "right")
        right.push_back(disk_size - 1);

    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }

    // sorting left and right vectors
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    // run the while loop two times.
    // one by one scanning right
    // and left of the head
    int run = 2;
    while (run--) {
        if (direction == "left") {
            for (int i = left.size() - 1; i >= 0; i--) {
                cur_track = left[i];

                // appending current track to seek sequence
                seek_sequence.push_back(cur_track);

                // calculate absolute distance
                distance = abs(cur_track - head);

                // increase the total count
                seek_count += distance;

                // accessed track is now the new head
                head = cur_track;
            }
            direction = "right";
        } else if (direction == "right") {
            for (int i = 0; i < right.size(); i++) {
                cur_track = right[i];
                // appending current track to seek sequence
                seek_sequence.push_back(cur_track);

                // calculate absolute distance
                distance = abs(cur_track - head);

                // increase the total count
                seek_count += distance;

                // accessed track is now new head
                head = cur_track;
            }
            direction = "left";
        }
    }

    cout << "\nTotal number of seek operations = "
         << seek_count << endl;
    cout << "Average seek: " << (static_cast<double>(seek_count) / size) << endl;
    cout << "\nSeek Sequence" << endl;

    for (int i = 0; i < seek_sequence.size(); i++) {
        cout << seek_sequence[i] << endl;
    }
}

/*

//note:: if seek sequence hits 199 (end of the disk),
it is reversed and the process continues.

SCAN
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

Total number of seek operations = 169
Average seek: 18.7778

Seek Sequence
147
150
175
177    <<<<< //note  from track#: 177
199    <<<<< //note
130    <<<<< //note    to track#: 130     // "177 - 199 - 130" // travel distance: 91
102
94
91
86

*/