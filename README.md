# Nemanja Blagojevic
# Lab assignment 6
# Memory Allocation Simulation

## Overview
This project simulates a memory management system, where memory blocks are allocated and deallocated based on lease durations. The simulation maintains two lists:

- **Free List**: A list of available memory blocks (holes).

- **Allocated List**: A list of memory blocks that have been allocated to processes with lease expiry times.

The goal is to simulate memory allocation using a **First-Fit Allocation Scheme**, handle memory block lease expirations, and merge adjacent free blocks to prevent fragmentation.


## Key Features
- **Memory Request Simulation**: Memory requests are generated at regular intervals with randomly determined sizes and lease durations.

- **First-Fit Allocation**: Memory blocks are allocated using the first available block that satisfies the request size.

- **Lease Expiry Handling**: Once a memory block's lease expires, it is returned to the free list, and adjacent free blocks are merged to reduce fragmentation.

- **Statistics Collection**: The program tracks various statistics, including:

  - Total number of memory requests.

  - Number of satisfied and unsatisfied requests.

  - Smallest, largest, and average block sizes requested.

  - Shortest, longest, and average lease durations.

  - Number of times memory block merging occurred.


## Program Structure

### Files

- **`memory_manager.h`**: Contains constants, type definitions, and function declarations related to memory management.

- **`memory_manager.cpp`**: Contains the implementation of memory management functions such as memory allocation, handling expired leases, and merging adjacent free blocks.

- **`main.cpp`**: Contains the main simulation loop, where memory requests are generated, allocations are handled, and statistics are reported.


### Constants and Parameters

The program uses the following constants:

- **MIN_LEASE**: Minimum lease duration (40 time units).

- **MAX_LEASE**: Maximum lease duration (70 time units).

- **MIN_SIZE**: Minimum memory block size (50 units).

- **MAX_SIZE**: Maximum memory block size (350 units).

- **TIME_LIMIT**: The total time limit for the simulation (1000 time units).

- **REQUEST_INTERVAL**: The interval (in clock ticks) at which memory requests are generated (every 10 ticks).

- **MEMORY_SIZE**: Total available memory (1000 units).


### Simulation Process

1. **Memory Requests**: Memory requests are generated at regular intervals (every 10 clock ticks) with random sizes and lease durations.

2. **Memory Allocation**: Memory is allocated using a first-fit allocation scheme. If no suitable memory block is found, adjacent free blocks are merged, and the allocation is retried.

3. **Lease Expiry Handling**: Expired leases are returned to the free list, and adjacent free blocks are merged to reduce fragmentation.

4. **Statistics Reporting**: At the end of the simulation, various statistics are printed, including total requests, satisfied/unsatisfied requests, block sizes, lease durations, and memory merges.


### Final Output

At the end of the simulation, the program prints:

- **Statistics**:

  - Total number of requests.

  - Number of satisfied and unsatisfied requests.

  - Smallest, largest, and average block size requested.

  - Shortest, longest, and average lease duration.

  - Number of merges performed.

- **Final State of Free List**: Displays the remaining free memory blocks at the end of the simulation.

- **Final State of Allocated List**: Displays the allocated memory blocks, including their start address, size, and lease expiry time.


# LAB-6
# Lab-6
