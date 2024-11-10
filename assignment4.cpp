#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

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

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

//Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Hybrid Sort function: Quick Sort with a switch to Merge Sort
void hybridSort(vector<int>& arr, int low, int high, int depth) {
    const int THRESHOLD = 32;

    if (high - low <= THRESHOLD) {
        // Switch to Merge Sort for small subarrays
        mergeSort(arr, low, high);
    } else if (depth > log2(arr.size())) {
        // Switch to Merge Sort if recursion depth exceeds log(n)
        mergeSort(arr, low, high);
    } else {
        // Use Quick Sort for partitioning
        int pivot = partition(arr, low, high);
        hybridSort(arr, low, pivot - 1, depth + 1);
        hybridSort(arr, pivot + 1, high, depth + 1);
    }
}

// Helper function to call Hybrid Sort
void hybridSort(vector<int>& arr) {
    hybridSort(arr, 0, arr.size() - 1, 0);
}

// Main function to test the hybrid sort
int main() {
    vector<int> arr = {34, 7, 23, 32, 5, 62, 32, 63, 45, 2, 14, 52};

    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    hybridSort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}

