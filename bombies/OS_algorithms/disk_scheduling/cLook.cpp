// C++ implementation of the approach
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int disk_size = 200;  //"disk has 200 cyclinders" - can be changed accordingly

void CLOOK(int arr[], int size, int head);

//****************************************************************************************************

int main() {
    int size,
        head;

    cout << "C-LOOK" << endl;
    cout << "How many request: ";
    cin >> size;
    cout << "Read/Write head starts on track: ";
    cin >> head;

    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        cout << "Enter request " << i + 1 << ": ";
        cin >> arr[i];
    }

    CLOOK(arr, size, head);
    delete[] arr;

    return 0;
}

//****************************************************************************************************

void CLOOK(int arr[], int size, int head) {
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;

    // Tracks on the left of the
    // head will be serviced when
    // once the head comes back
    // to the beginning (left end)
    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }

    // Sorting left and right vectors
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    // First service the requests
    // on the right side of the
    // head
    for (int i = 0; i < right.size(); i++) {
        cur_track = right[i];

        // Appending current track to seek sequence
        seek_sequence.push_back(cur_track);

        // Calculate absolute distance
        distance = abs(cur_track - head);

        // Increase the total count
        seek_count += distance;

        // Accessed track is now new head
        head = cur_track;
    }

    // Once reached the right end
    // jump to the last track that
    // is needed to be serviced in
    // left direction
    seek_count += abs(head - left[0]);
    head = left[0];

    // Now service the requests again
    // which are left
    for (int i = 0; i < left.size(); i++) {
        cur_track = left[i];

        // Appending current track to seek sequence
        seek_sequence.push_back(cur_track);

        // Calculate absolute distance
        distance = abs(cur_track - head);

        // Increase the total count
        seek_count += distance;

        // Accessed track is now the new head
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

C-LOOK
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
177
86
91
94
102
130

*/
