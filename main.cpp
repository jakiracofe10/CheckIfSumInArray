#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

//Time = O(n^2) -> checking each index by every other index
//Time = O(nlogn) -> using ordered hash map & find

bool checkForSumOfX3(int *arr, int n, int x) {
    sort(arr, arr+n);
    int first = 0;
    int last = n-1;
    while (first < last) {
        if (arr[first]+arr[last] == x) {
            return true;
        }
        if (arr[first]+arr[last] < x) {
            first++;
        } else if (arr[first]+arr[last] > x) {
            last--;
        }
    }
    return false;

}

bool checkForSumOfXBetter(int *arr, int n, int x) {
    map<int,int> elements;
    for (int i=0; i<n; i++) {
        elements[arr[i]]++;
    }
    for (int i=0; i<n; i++) {
        map<int,int>::iterator it = elements.find(x-arr[i]);
        if (it == elements.end())
            continue;
        if (it->first + arr[i] == x) {
            if (it->first == arr[i]) {
                if (it->second > 1) {
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
    int x = 20;
    bool result = checkForSumOfX3(A,n,x);
    cout << to_string(result);
    return 0;
}