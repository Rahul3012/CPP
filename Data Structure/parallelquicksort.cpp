#include <iostream>
#include <vector>
#include <thread>
#include <algorithm> // For std::swap

void swap(int& a, int& b) {
    std::swap(a, b);
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortParallel(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        std::thread leftThread([&arr, low, pivotIndex]() {
            quickSortParallel(arr, low, pivotIndex - 1);
        });

        std::thread rightThread([&arr, pivotIndex, high]() {
            quickSortParallel(arr, pivotIndex + 1, high);
        });

        leftThread.join();
        rightThread.join();
    }
}

int main() {
    std::vector<int> arr = {5, 2, 8, 1, 9, 4, 7};
    quickSortParallel(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
