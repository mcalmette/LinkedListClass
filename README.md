# LinkedListClass


## Class Setup
```
cmake CMakeLists.txt
make
```
To use the test file:
```
./linkedtest
```

To use the performance test:
```
./linkedperf rand-10k.txt
```

## About this project
Linked list with each node holding a key-value pair.  The project implements these functions to the list:
- add
- remove
- find
- range find
- keys (returns all keys by reference)
- sort (ascending order)
- size


The test file is used as a way to ensure that each function works with different test cases.  The performance file is used to find the speed and number of calls for each function. This can be used with a randomly generated key-value pairs that ranges from 10k pairs to 50k pairs.

Note: When pulling this repository, you will need to delete the CmakeFiles & cmake_install which are associated with my computer
