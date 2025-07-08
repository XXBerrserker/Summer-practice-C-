#include "search.h"

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int findSmallestMissing(int arr[], int n) {
    int left = 0;
    int right = n - 1;
    int answer = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] != mid) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer;
}

void runSearchTask() {
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* arr = new int[n]; 

    cout << "Введите элементы массива (неотрицательные числа): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int smallestMissing = findSmallestMissing(arr, n);
    cout << "Наименьший недостающий элемент: " << smallestMissing << endl;

    delete[] arr;
}