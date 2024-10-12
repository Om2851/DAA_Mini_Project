#include <iostream>
#include <vector>
#include <thread>

using namespace std;

const int THRESHOLD = 1000; // Threshold for when to switch to single-threaded

// Function to merge two subarrays
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    // Merge the temp arrays back into arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[] if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[] if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function implementing multithreaded merge sort
void mergeSortMultiThreaded(vector<int>& arr, int left, int right) {
    if (right - left <= THRESHOLD) {
        // If size is small enough, use single-threaded merge sort
        mergeSort(arr, left, right);
    } else {
        int mid = left + (right - left) / 2;

        // Launch two threads to sort the left and right halves
        thread leftThread(mergeSortMultiThreaded, ref(arr), left, mid);
        thread rightThread(mergeSortMultiThreaded, ref(arr), mid + 1, right);

        // Wait for both threads to complete
        leftThread.join();
        rightThread.join();

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arr_size = arr.size();

    cout << "Given array: ";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSortMultiThreaded(arr, 0, arr_size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
