# Python3 program to illustrate
# Banker's Algorithm

# Number of processes
P = 5

# Number of resources
R = 3

# Function to find the need of each process
def calculateNeed(need, maxm, allot):

    # Calculating Need of each P
    for i in range(P):
        for j in range(R):

            # Need of instance = maxm instance -
            # allocated instance
            need[i][j] = maxm[i][j] - allot[i][j]


# Function to find the system is in
# safe state or not
def isSafe(processes, avail, maxm, allot):
    need = []
    for i in range(P):
        l = []
        for j in range(R):
            l.append(0)
        need.append(l)

    # Function to calculate need matrix
    calculateNeed(need, maxm, allot)

    # Mark all processes as infinish
    finish = [0] * P

    # To store safe sequence
    safeSeq = [0] * P

    # Make a copy of available resources
    work = [0] * R
    for i in range(R):
        work[i] = avail[i]

    # While all processes are not finished
    # or system is not in safe state.
    count = 0
    while count < P:

        # Find a process which is not finish
        # and whose needs can be satisfied
        # with current work[] resources.
        found = False
        for p in range(P):

            # First check if a process is finished,
            # if no, go for next condition
            if finish[p] == 0:

                # Check if for all resources
                # of current P need is less
                # than work
                for j in range(R):
                    if need[p][j] > work[j]:
                        break

                # If all needs of p were satisfied.
                if j == R - 1:

                    # Add the allocated resources of
                    # current P to the available/work
                    # resources i.e.free the resources
                    for k in range(R):
                        work[k] += allot[p][k]

                    # Add this process to safe sequence.
                    safeSeq[count] = p
                    count += 1

                    # Mark this p as finished
                    finish[p] = 1

                    found = True

        # If we could not find a next process
        # in safe sequence.
        if found == False:
            print("System is not in safe state")
            return False

    # If system is in safe state then
    # safe sequence will be as below
    print("System is in safe state.", "\nSafe sequence is: ", end=" ")
    print(*safeSeq)

    return True


# Driver code
if __name__ == "__main__":

    processes = [0, 1, 2, 3, 4]

    # Available instances of resources
    avail = [3, 3, 2]

    # Maximum R that can be allocated
    # to processes
    maxm = [[7, 5, 3], [3, 2, 2], [9, 0, 2], [2, 2, 2], [4, 3, 3]]

    # Resources allocated to processes
    allot = [[0, 1, 0], [2, 0, 0], [3, 0, 2], [2, 1, 1], [0, 0, 2]]

    # Check system is in safe state or not
    isSafe(processes, avail, maxm, allot)
