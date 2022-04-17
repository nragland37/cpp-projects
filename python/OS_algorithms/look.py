# Python3 program to demonstrate
# LOOK Disk Scheduling algorithm
size = 8
disk_size = 200


def LOOK(arr, head, direction):

    seek_count = 0
    distance = 0
    cur_track = 0

    left = []
    right = []

    seek_sequence = []

    # Appending values which are
    # currently at left and right
    # direction from the head.
    for i in range(size):
        if arr[i] < head:
            left.append(arr[i])
        if arr[i] > head:
            right.append(arr[i])

    # Sorting left and right vectors
    # for servicing tracks in the
    # correct sequence.
    left.sort()
    right.sort()

    # Run the while loop two times.
    # one by one scanning right
    # and left side of the head
    run = 2
    while run:
        if direction == "left":
            for i in range(len(left) - 1, -1, -1):
                cur_track = left[i]

                # Appending current track to
                # seek sequence
                seek_sequence.append(cur_track)

                # Calculate absolute distance
                distance = abs(cur_track - head)

                # Increase the total count
                seek_count += distance

                # Accessed track is now the new head
                head = cur_track

            # Reversing the direction
            direction = "right"

        elif direction == "right":
            for i in range(len(right)):
                cur_track = right[i]

                # Appending current track to
                # seek sequence
                seek_sequence.append(cur_track)

                # Calculate absolute distance
                distance = abs(cur_track - head)

                # Increase the total count
                seek_count += distance

                # Accessed track is now new head
                head = cur_track

            # Reversing the direction
            direction = "left"

        run -= 1

    print("Total number of seek operations =", seek_count)
    print("Seek Sequence is")

    for i in range(len(seek_sequence)):
        print(seek_sequence[i])


# Driver code

# Request array
arr = [176, 79, 34, 60, 92, 11, 41, 114]
head = 50

direction = "right"

print("Initial position of head:", head)

LOOK(arr, head, direction)

# This code is contributed by rag2127
