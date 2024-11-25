#include "memory_manager.h"

std::vector<range> freeList = {{0, MEMORY_SIZE}};
std::vector<alloc> allocatedList;

int totalRequests = 0, satisfiedRequests = 0, unsatisfiedRequests = 0;
int smallestBlock = MAX_SIZE, largestBlock = MIN_SIZE;
int shortestLease = MAX_LEASE, longestLease = MIN_LEASE;
double totalBlockSize = 0, totalLeaseDuration = 0;
int mergeCount = 0;

void mergeFreeBlocks() {
    if (freeList.empty()) return;
    std::sort(freeList.begin(), freeList.end());
    std::vector<range> merged;
    range current = freeList[0];

    for (size_t i = 1; i < freeList.size(); ++i) {
        if (current.first + current.second == freeList[i].first) {
            current.second += freeList[i].second;
        } else {
            merged.push_back(current);
            current = freeList[i];
        }
    }
    merged.push_back(current);
    freeList = merged;
    mergeCount++;
}

bool allocateMemory(int size, int leaseExpiry) {
    for (auto it = freeList.begin(); it != freeList.end(); ++it) {
        if (it->second >= size) {
            range allocatedBlock = {it->first, size};
            allocatedList.push_back({allocatedBlock, leaseExpiry});
            it->first += size;
            it->second -= size;
            if (it->second == 0) freeList.erase(it);
            return true;
        }
    }
    return false;
}

void handleExpiredLeases(long clock) {
    while (!allocatedList.empty() && allocatedList.front().second <= clock) {
        range block = allocatedList.front().first;
        allocatedList.erase(allocatedList.begin());
        freeList.push_back(block);
        mergeFreeBlocks();
    }
}

void reportStatistics() {
    std::cout << "Simulation Results:\n";
    std::cout << "Total requests: " << totalRequests << "\n";
    std::cout << "Satisfied requests: " << satisfiedRequests << "\n";
    std::cout << "Unsatisfied requests: " << unsatisfiedRequests << "\n";
    std::cout << "Smallest block requested: " << smallestBlock << "\n";
    std::cout << "Largest block requested: " << largestBlock << "\n";
    std::cout << "Average block size requested: " << (totalBlockSize / totalRequests) << "\n";
    std::cout << "Shortest lease duration: " << shortestLease << "\n";
    std::cout << "Longest lease duration: " << longestLease << "\n";
    std::cout << "Average lease duration: " << (totalLeaseDuration / totalRequests) << "\n";
    std::cout << "Number of merges performed: " << mergeCount << "\n";

    std::cout << "\nFinal Free List:\n";
    for (const auto& hole : freeList) {
        std::cout << "Start: " << hole.first << ", Size: " << hole.second << "\n";
    }

    std::cout << "\nFinal Allocated List:\n";
    for (const auto& alloc : allocatedList) {
        std::cout << "Start: " << alloc.first.first << ", Size: " << alloc.first.second
                  << ", Lease Expiry: " << alloc.second << "\n";
    }
}

