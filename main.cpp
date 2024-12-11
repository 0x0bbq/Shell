#include <iostream>
#include <vector>

using namespace std;

void shellSort(vector<int>& arr) {
    int arraySize = arr.size();

    for (int step = arraySize / 2; step > 0; step /= 2) {
        for (int i = step; i < arraySize; i++) {
            int tempArrayItem = arr[i];
            int j = i;

            while (j >= step && arr[j - step] > tempArrayItem) {
                arr[j] = arr[j - step];
                j -= step;
            }

            arr[j] = tempArrayItem;
        }
    }
}

bool isArraySorted(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    vector arr = {12, 34, 54, 2, 3};

    cout << "Source array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    shellSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Array is " << (isArraySorted(arr) ? "sorted" : "not sorted") << "!" << endl;

    return 0;
}