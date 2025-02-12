#include <iostream>
#include <vector>
#include <cstdlib>  // For generating random numbers
#include <ctime>    // For seeding random numbers

using namespace std;

// Bubble Sort with Step Count
int bubbleSort(vector<int>& arr) {
    int steps = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            steps++; 
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                steps++; 
            }
        }
    }
    return steps;
}

// Selection Sort with Step Count
int selectionSort(vector<int>& arr) {
    int steps = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            steps++; 
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            steps++; 
        }
    }
    return steps;
}

// Insertion Sort with Step Count
int insertionSort(vector<int>& arr) {
    int steps = 0;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        steps++; 

        while (j >= 0 && arr[j] > key) {
            steps++; 
            arr[j + 1] = arr[j];
            steps++; 
            j--;
        }
        arr[j + 1] = key;
        steps++; 
    }
    return steps;
}

// Function to generate test cases
vector<int> generateInput(int size, string caseType) {
    vector<int> arr(size);
    if (caseType == "best") {  // Already sorted
        for (int i = 0; i < size; i++)
            arr[i] = i + 1;
    } else if (caseType == "worst") {  // Reverse sorted
        for (int i = 0; i < size; i++)
            arr[i] = size - i;
    } else {  // Random case
        srand(time(0));
        for (int i = 0; i < size; i++)
            arr[i] = rand() % 100;  
    }
    return arr;
}

// Function to display array
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

// Main function to test sorting
int main() {
    vector<int> sizes = {10, 20, 30, 40};  
    string cases[] = {"best", "worst", "random"};

    for (string caseType : cases) {
        cout << "\nTesting " << caseType << " case:\n";

        for (int size : sizes) {
            vector<int> arr = generateInput(size, caseType);

            // Bubble Sort
            vector<int> temp = arr;
            int bubbleSteps = bubbleSort(temp);

            // Selection Sort
            temp = arr;
            int selectionSteps = selectionSort(temp);

            // Insertion Sort
            temp = arr;
            int insertionSteps = insertionSort(temp);

            cout << "Size: " << size
                 << " | Bubble: " << bubbleSteps
                 << " | Selection: " << selectionSteps
                 << " | Insertion: " << insertionSteps << endl;
        }
    }
    return 0;
}