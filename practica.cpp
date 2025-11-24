#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cstring>

const std::string RESET = "\033[0m";
const std::string GREEN = "\033[32m";  // Зелёный — перемещённые элементы
const std::string RED = "\033[31m";  // Красный — текущий элемент/индикатор
const std::string BLUE = "\033[34m";  // Синий — для отладки
const std::string YELLOW = "\033[33m";  // Жёлтый — для индексов


std::vector<int> generateArray(int n, int minVal, int maxVal) {
    std::vector<int> arr(n);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minVal, maxVal);

    for (int i = 0; i < n; ++i) {
        arr[i] = dis(gen);
    }
    return arr;
}


void printArray(const std::vector<int>& arr, const std::vector<int>& movedIndices = {}) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (!movedIndices.empty() && std::find(movedIndices.begin(), movedIndices.end(), static_cast<int>(i)) != movedIndices.end()) {
            std::cout << GREEN << arr[i] << RESET << " ";
        } else {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}


bool isValidIndex(int index, int n) {
    return (index % 3 == 0) && (index >= n / 2);
}

std::vector<int> getValidIndices(int n) {
    std::vector<int> indices;
    for (int i = n / 2; i < n; ++i) {
        if (i % 3 == 0) {
            indices.push_back(i);
        }
    }
    return indices;
}







void selectionSort(std::vector<int>& arr) {
    constexpr size_t n = 100;
    int a[n];
    std::copy(arr.begin(), arr.end(), a);

    std::vector<int> moved;
    std::vector<int> validIndices = getValidIndices(n);

    for (size_t i = 0; i < validIndices.size() - 1; i++) {
        int minIndex = i;
        for (size_t j = i + 1; j < validIndices.size(); j++) {
            if (a[validIndices[j]] < a[validIndices[minIndex]]) {
                minIndex = j;
            }
        }
        if (minIndex != static_cast<int>(i)) {
            std::swap(a[validIndices[i]], a[validIndices[minIndex]]);
            moved.push_back(validIndices[i]);
            moved.push_back(validIndices[minIndex]);
        }
    }

    std::copy(a, a + n, arr.begin());
    std::cout << "\nSelection Sort:\n";
    printArray(arr, moved);
}





void insertionSort1(std::vector<int>& arr) {
    constexpr size_t n = 100;
    int a[n];
    std::copy(arr.begin(), arr.end(), a);

    std::vector<int> moved;
    std::vector<int> validIndices = getValidIndices(n);

    for (size_t i = 1; i < validIndices.size(); i++) {
        for (int j = i; j > 0 && a[validIndices[j]] < a[validIndices[j - 1]]; j--) {
            std::swap(a[validIndices[j - 1]], a[validIndices[j]]);
            moved.push_back(validIndices[j - 1]);
            moved.push_back(validIndices[j]);
        }
    }

    std::copy(a, a + n, arr.begin());
    std::cout << "\nInsertion Sort1:\n";
    printArray(arr, moved);
}




void insertionSort2(std::vector<int>& arr) {
    constexpr size_t n = 100;
    int a[n];
    std::copy(arr.begin(), arr.end(), a);

    std::vector<int> moved;
    std::vector<int> validIndices = getValidIndices(n);

    for (size_t i = 1; i < validIndices.size(); i++) {
        int tmp = a[validIndices[i]];
        int j = i;
        while (j > 0 && tmp < a[validIndices[j - 1]]) {
            a[validIndices[j]] = a[validIndices[j - 1]];
            moved.push_back(validIndices[j]);
            j--;
        }
        a[validIndices[j]] = tmp;
        if (j != static_cast<int>(i)) {
            moved.push_back(validIndices[j]);
        }
    }

    std::copy(a, a + n, arr.begin());
    std::cout << "\nInsertion Sort2:\n";
    printArray(arr, moved);
}






void bubbleSort(std::vector<int>& arr) {
    constexpr size_t n = 100;
    int a[n];
    std::copy(arr.begin(), arr.end(), a);

    std::vector<int> moved;
    std::vector<int> validIndices = getValidIndices(n);

    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (size_t i = 0; i < validIndices.size() - 1; ++i) {
            if (a[validIndices[i]] > a[validIndices[i + 1]]) {
                std::swap(a[validIndices[i]], a[validIndices[i + 1]]);
                moved.push_back(validIndices[i]);
                moved.push_back(validIndices[i + 1]);
                swapped = true;
            }
        }
    }

    std::copy(a, a + n, arr.begin());
    std::cout << "\nBubble Sort:\n";
    printArray(arr, moved);
}






int main() {
    const int n = 100;
    const int minVal = 0;
    const int maxVal = 10000;

    std::vector<int> arr = generateArray(n, minVal, maxVal);

    std::cout << "Original array:\n";
    printArray(arr);

    std::vector<int> validIndices = getValidIndices(n);
    std::cout << "\nIndices to be sorted (multiple of 3 in second half): ";
    for (int idx : validIndices) {
        std::cout << idx << " ";
    }
    std::cout << std::endl;

    std::vector<int> arr1 = arr;
    std::vector<int> arr2 = arr;
    std::vector<int> arr3 = arr;
    std::vector<int> arr4 = arr;

    selectionSort(arr1);
    insertionSort1(arr2);
    insertionSort2(arr3);
    bubbleSort(arr4);

    return 0;
}








