# Scheduling-Algorithms
This repository contains an implementation of various process scheduling algorithms. The goal of this project is to develop different scheduling variants and manage jobs using a queue. The scheduling algorithms include both non-preemptive and preemptive strategies.

## Contents

- [Description](#description)
- [Tasks](#tasks)
  - [Task 1: Queue](#task-1-queue)
  - [Task 2: Scheduler](#task-2-scheduler)
- [Scheduling Algorithms](#scheduling-algorithms)
- [Optional: Test Cases](#optional-test-cases)
- [Getting Started](#getting-started)
- [Memory Leaks](#memory-leaks)

## Description

In this project, various scheduling algorithms are implemented to manage the execution of processes. A queue data structure is used for managing jobs. The initial codebase includes a simple First-Come-First-Serve (FCFS) example.

## Tasks

### Task 1: Queue

Implement a queue data structure to manage processes. The necessary functions and structs are provided in the `queue.c` and `queue.h` files. Refer to the documentation in the header file for details.

### Task 2: Scheduler

Implement different scheduling algorithms as specified in the requirements. The following scheduling algorithms should be implemented:

- First Come First Served (FCFS)
- Priority with no preemption (PRIO-NP)
- Shortest Job Next (SJN)
- Highest Response Ratio Next (HRRN)
- Round Robin (RR)
- Multi-Level Feedback (MLF) with varying time slices
- Longest Current First Shortest Process Remaining (LCFSPR)

## Scheduling Algorithms

The scheduling algorithms aim to efficiently allocate CPU time to different processes based on their characteristics. Different algorithms provide various trade-offs between fairness and throughput.

## Optional: Test Cases

Additional test cases can be implemented to validate the correctness of the scheduling algorithms. The provided guidelines and examples can be followed to create meaningful test cases.

## Getting Started

To compile the project, use the provided Makefile in the root directory. Run the following command:

```bash
make
```

This will compile the project using the clang compiler. Make sure to have clang and make installed. On Ubuntu, you can install them using:

```bash
sudo apt install make clang
```

## Make Targets

### `make build`
Also `make all` or just `make`.
Compiles all the .c files to be built. However, no executable file is created yet.

### `make all_tests`
Builds all tests and executes them.

### `make list_tests`
Displays a list of all available tests.

### `make test_*`
Executes only the specified test. The name of the test file is also the same as the make target (without the `.c` extension).
Example: `make test_fcfs_simple`

### `make pack`
Packs the `src` folder with its contents into a submission-ready `zip` archive, which can then be uploaded to ISIS. This operation requires the `zip` tool, which can be installed on Debian Linux using the command `apt install zip`. This archive should not and need not be further modified!

### `make clean`
Cleans up the workspace.
