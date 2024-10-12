# DAA_Mini_Project
Implement Merge Sort and Multithreaded Merge Sort. Compare Time Required by Both the Algorithms. Also, Analyze the Performance of Each Algorithm for the Best Case and the Worst Case.

Problem Statement:
Write a program to implement the merge sort algorithm. Additionally, implement a
multithreaded version of merge sort. Compare and analyze the time complexity and
performance of both algorithms in the best-case and worst-case scenarios.

Objectives:
• To implement a single-threaded merge sort algorithm.
• To develop a multithreaded merge sort algorithm where different parts of the array
are sorted concurrently.
• To analyze and compare the execution time and efficiency of the single-threaded and
multithreaded merge sort implementations.
• To evaluate the impact of input size and structure (best and worst cases) on the
performance of both implementations.
• To assess the computational overhead introduced by thread management and
synchronization in multithreaded merge sort.

Introduction:
Merge sort is a classic divide-and-conquer sorting algorithm with a time complexity of O(n
log n) for both the best-case and worst-case scenarios. It is widely used for its efficiency
with large datasets, especially when stable sorting is required. However, the inherent
sequential nature of merge sort limits its speed-up in single-threaded environments as the
array is divided and merged in a strictly linear sequence. By leveraging multithreading, the
sorting process can be parallelized, allowing different parts of the array to be sorted
simultaneously, which can lead to significant improvements in execution time, particularly
on modern multi-core processors.
In this project, we implement both the traditional single-threaded merge sort and a
multithreaded version where multiple threads are used to sort different segments of the array
concurrently. The project aims to analyze and compare the time required for both algorithms
under different input conditions (best and worst cases), highlighting the advantages and
challenges of using multithreading for this problem.
