/*
    Count number of distinct pairs whose sum exists in the given array
    Given an array of N positive integers. Count the number of pairs whose sum exists in the given array. While repeating pairs will not be counted again. And we can’t make a pair using same position element. Eg : (2, 1) and (1, 2) will be considered as only one pair.
    Please read all examples carefully.

    Examples:

    Input : arr[] = {1, 2, 3, 5, 10}
    Output : 2
    Explanation : Here there are two such pairs:
    (1 + 2) = 3, (2 + 3) = 5.
    Note : Here we can't take pair (5, 5) as 
    we can see 5 is not coming twice

    Input : arr[] = {1, 5, 6, 4, -1, 5} 
    Output : 4
    Explanation : (1 + 5) = 6, (1 + 4) = 5, 
    (5 + -1) = 4, (6 + -1) = 5
    Note : Here (1, 5) comes twice will be 
    considered as only one pair. 

    Input : arr[] = {5, 5, 5, 5, 10} 
    Output : 1
    Explanation : (5 + 5) = 10
    Note : Here (5, 5) comes twice will be
    considered as only one pair. 
*/
#include <iostream>
#include <map>
using namespace std;

int uniquePairs(int *arr, int n) {
    int count = 0;
    map<int, int> m;
    for(int i = 0; i < n; i++) {
        m[arr[i]]++;
    }
    map< pair<int, int>, int> pairs;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(m[arr[i] + arr[j]] > 0 and pairs[{arr[i], arr[j]}] == 0) {
                count++;
            }
            // insert pairs both ways to avoid duplicates
            pairs[{arr[i], arr[j]}]++;
            pairs[{arr[j], arr[i]}]++;
        }
    }   
    return count;
}
 
int main() {

    int arr[] = {1, 5, 6, 4, -1, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << uniquePairs(arr, n);

    return 0;
}

