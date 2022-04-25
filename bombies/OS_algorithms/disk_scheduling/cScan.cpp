// C++ program to demonstrate
// C-SCAN Disk Scheduling algorithm
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int disk_size = 200;   // "disk has 200 cyclinders" - can be changed accordingly 

void CSCAN(int arr[], int size, int head);

//****************************************************************************************************

int main() {
    int size,
        head;

    cout << "CSCAN" << endl;
    cout << "How many request: ";
    cin >> size;
    cout << "Read/Write head starts on track: ";
    cin >> head;

    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        cout << "Enter request " << i + 1 << ": ";
        cin >> arr[i];
    }

    CSCAN(arr, size, head);

    delete[] arr;

    return 0;
}

void CSCAN(int arr[], int size, int head) {
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;

    // appending end values
    // which has to be visited
    // before reversing the direction
    left.push_back(0);
    right.push_back(disk_size - 1);

    // tracks on the left of the
    // head will be serviced when
    // once the head comes back
    // to the beginning (left end).
    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }

    // sorting left and right vectors
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    // first service the requests
    // on the right side of the
    // head.
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

    // once reached the right end
    // jump to the beginning.
    head = 0;

    // adding seek count for head returning from 199 to 0
    seek_count += (disk_size - 1);

    // Now service the requests again
    // which are left.
    for (int i = 0; i < left.size(); i++) {
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
it immediately returns to the seek sequence 0 (beginning of the disk) without servicing 
any requests on the return trip and starts servicing again once reaches the beginning. 

CSCAN
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

Total number of seek operations = 385
Average seek: 42.7778

Seek Sequence
147
150
175
177       <<<<<<  //note      from track#: 177  
199       <<<<<<  //note  
0         <<<<<<  //note                        
86        <<<<<<  //note       to track#: 86  // "177 - 199 - 0 - 86" // travel distance: 307 
91
94
102
130

*/