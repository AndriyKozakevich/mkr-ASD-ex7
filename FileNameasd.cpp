#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>   

using namespace std;


void swapRows(vector<vector<int>>& arr, int row1, int row2) {
    vector<int> temp = arr[row1];
    arr[row1] = arr[row2];
    arr[row2] = temp;
}


void heapify(vector<vector<int>>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2; 

    
    if (left < n && abs(arr[left][0]) < abs(arr[smallest][0]))
        smallest = left;

    if (right < n && abs(arr[right][0]) < abs(arr[smallest][0]))
        smallest = right;

   
    if (smallest != i) {
        swapRows(arr, i, smallest);
        heapify(arr, n, smallest);
    }
}


void heapSort(vector<vector<int>>& arr, int rows, int cols) {
    
    for (int i = rows / 2 - 1; i >= 0; i--)
        heapify(arr, rows, i);

    
    for (int i = rows - 1; i > 0; i--) {
    
        swapRows(arr, 0, i);
       
        heapify(arr, i, 0);
    }
}

int main() {
    srand(time(nullptr)); 

    vector<vector<int>> arr(7, vector<int>(9)); 

    
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 9; ++j) {
            arr[i][j] = rand() % 100 - 50; 
        }
    }

   
    heapSort(arr, 7, 9);

    
    cout << "Sorted Array:" << endl;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 9; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
