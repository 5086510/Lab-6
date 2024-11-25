#include "memory_manager.h"

int main() {
    long clock = 0;
    while (clock < TIME_LIMIT) {
        if (clock % REQUEST_INTERVAL == 0) {
            totalRequests++;
            int size = rand() % (MAX_SIZE - MIN_SIZE + 1) + MIN_SIZE;
            int leaseDuration = rand() % (MAX_LEASE - MIN_LEASE + 1) + MIN_LEASE;
            int leaseExpiry = clock + leaseDuration;

            smallestBlock = std::min(smallestBlock, size);
            largestBlock = std::max(largestBlock, size);
            shortestLease = std::min(shortestLease, leaseDuration);
            longestLease = std::max(longestLease, leaseDuration);
            totalBlockSize += size;
            totalLeaseDuration += leaseDuration;

            if (!allocateMemory(size, leaseExpiry)) {
                mergeFreeBlocks();
                if (!allocateMemory(size, leaseExpiry)) {
                    unsatisfiedRequests++;
                } else {
                    satisfiedRequests++;
                }
            } else {
                satisfiedRequests++;
            }
        }

        handleExpiredLeases(clock);
        clock++;
    }

    reportStatistics();
    return 0;
}

