#include <iostream>

using namespace std;

const int ASCII_VALUES = 256;

bool checkForSumOfX(int *arr, int n, int x) {
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if ((arr[i]+arr[j]) == x) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n = 8; //# of elements in array
    int A[n] = {1,2,3,4,5,6,7,60};
    int x = 20;
    bool result = checkForSumOfX(A,n,x);
    cout << to_string(result);
    return 0;
}