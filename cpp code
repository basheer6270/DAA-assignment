#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

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
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void measureSortTime(void (*sortFunc)(vector<int>&), vector<int> arr, const string& sortName, const string& caseType) {
    auto start = high_resolution_clock::now();
    sortFunc(arr);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << sortName << " on " << caseType << " case: " << duration.count() << " microseconds" << endl;
}

void measureMergeSortTime(vector<int> arr, const string& caseType) {
    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Merge Sort on " << caseType << " case: " << duration.count() << " microseconds" << endl;
}

void measureQuickSortTime(vector<int> arr, const string& caseType) {
    auto start = high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Quick Sort on " << caseType << " case: " << duration.count() << " microseconds" << endl;
}

int main() {
    const int n = 1000; 

    
    vector<int> bestCase(n), averageCase(n), worstCase(n);
    for (int i = 0; i < n; i++) {
        bestCase[i] = i;
        averageCase[i] = rand() % 1000;
        worstCase[i] = n - i;
    }

    measureSortTime(bubbleSort, bestCase, "Bubble Sort", "best");
    measureSortTime(bubbleSort, averageCase, "Bubble Sort", "average");
    measureSortTime(bubbleSort, worstCase, "Bubble Sort", "worst");

    measureSortTime(selectionSort, bestCase, "Selection Sort", "best");
    measureSortTime(selectionSort, averageCase, "Selection Sort", "average");
    measureSortTime(selectionSort, worstCase, "Selection Sort", "worst");

    measureMergeSortTime(bestCase, "best");
    measureMergeSortTime(averageCase, "average");
    measureMergeSortTime(worstCase, "worst");

    measureQuickSortTime(bestCase, "best");
    measureQuickSortTime(averageCase, "average");
    measureQuickSortTime(worstCase, "worst");

    return 0;
}
