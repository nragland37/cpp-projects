# Python program to demonstrate
# FCFS Disk Scheduling algorithm

size = 8


def FCFS(arr, head):

    seek_count = 0
    distance, cur_track = 0, 0

    for i in range(size):
        cur_track = arr[i]

        # calculate absolute distance
        distance = abs(cur_track - head)

        # increase the total count
        seek_count += distance

        # accessed track is now new head
        head = cur_track

    print("Total number of seek operations = ", seek_count)

    # Seek sequence would be the same
    # as request array sequence
    print("Seek Sequence is")

    for i in range(size):
        print(arr[i])


# Driver code
if __name__ == "__main__":

    # request array
    arr = [176, 79, 34, 60, 92, 11, 41, 114]
    head = 50

    print("Initial position of head:", head)
    
    FCFS(arr, head)

# This code contributed by Rajput-Ji
