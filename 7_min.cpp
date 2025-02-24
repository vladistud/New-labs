#include <iostream>

using namespace std;

int min(int count, int* numbers) {
    if (count <= 0) return 0;
    int min_value = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] < min_value) {
            min_value = numbers[i];
        }
    }
    return min_value;
}

int main() {
    int arr1[] = {7, 3, 9, 1, 4};
    int arr2[] = {12, 34, 23, 1, 8, 45, 67, 89, 10, 2};
    int arr3[] = {56, 34, 12, 78, 90, 1, 45, 23, 67, 89, 22, 4};

    cout << "Min (5 elements): " << min(5, arr1) << endl;
    cout << "Min (10 elements): " << min(10, arr2) << endl;
    cout << "Min (12 elements): " << min(12, arr3) << endl;

    return 0;
}
