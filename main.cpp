#include <iostream>
#include <map>

using namespace std;

//Time = O(n^2) -> checking each index by every other index
//Time = O(nlogn) -> using hash map find

const int MAX=65535;

bool checkForSumOfXBetter(int *arr, int n, int x) {
    map<int,int> elements;
    for (int i=0; i<n; i++) {
        elements[arr[i]]++;
    }
    for (int i=0; i<n; i++) {
        if (elements.find(x-arr[i])->first + arr[i] == x) {
            if (elements.find(x-arr[i])->first == arr[i]) {
                if (elements.find(x-arr[i])->second > 1) {
                    return true;
                }
            } else {
                return true;
            }
        }
    }
    return false;
}

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
    int A[n] = {1,2,3,4,5,4,4,5};
    int x = 11;
    bool result = checkForSumOfXBetter(A,n,x);
    cout << to_string(result);
    return 0;
}