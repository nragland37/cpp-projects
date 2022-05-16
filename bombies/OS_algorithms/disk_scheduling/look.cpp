// C++ program to demonstrate
// LOOK Disk Scheduling algorithm
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int disk_size = 200;  //"disk has 200 cyclinders" - can be changed accordingly

void LOOK(int arr[], int size, int head, string direction);

int main() {
    int size,
        head;

    cout << "LOOK" << endl;
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

    LOOK(arr, size, head, direction);
    delete[] arr;
    return 0;
}

//****************************************************************************************************

void LOOK(int arr[], int size, int head, string direction) {
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;

    // appending values which are
    // currently at left and right
    // direction from the head.
    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }

    // sorting left and right vectors
    // for servicing tracks in the
    // correct sequence.
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    // run the while loop two times.
    // one by one scanning right
    // and left side of the head
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
            // reversing the direction
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
            // reversing the direction
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

LOOK
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

Total number of seek operations = 125
Average seek: 13.8889

Seek Sequence
147
150
175
177
130
102
94
91
86

*/