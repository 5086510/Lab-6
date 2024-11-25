#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <utility>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <iostream>

// Type aliases
using range = std::pair<int, int>; // {start, size}
using alloc = std::pair<range, int>; // {allocated range, lease expiry}

// Constants for simulation parameters
const int MIN_LEASE = 40;
const int MAX_LEASE = 70;
const int MIN_SIZE = 50;
const int MAX_SIZE = 350;
const int TIME_LIMIT = 1000;
const int REQUEST_INTERVAL = 10;
const int MEMORY_SIZE = 1000;

// Global variables
extern std::vector<range> freeList;
extern std::vector<alloc> allocatedList;
extern int totalRequests, satisfiedRequests, unsatisfiedRequests;
extern int smallestBlock, largestBlock;
extern int shortestLease, longestLease;
extern double totalBlockSize, totalLeaseDuration;
extern int mergeCount;

// Function declarations
void mergeFreeBlocks();
bool allocateMemory(int size, int leaseExpiry);
void handleExpiredLeases(long clock);
void reportStatistics();

#endif // MEMORY_MANAGER_H

