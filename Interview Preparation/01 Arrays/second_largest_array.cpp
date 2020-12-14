#include <iostream>
#include <climits>
using namespace std;

int findSecondLargest(int arr[], int n){

    int first = INT_MIN, second = INT_MIN;
    
    if(n < 2) {
        return -2147483648;
    }
    
    for(int i = 0; i < n; i++) {
        if(arr[i] > first) {
            second = first;
            first = arr[i];
        }
        else if(arr[i] > second and arr[i] != first) { // to get a unique second largest element
        	second = arr[i];
        }
    }
    if(second == INT_MIN) {
        return -2147483648;
    }
    else {
        return second;
    } 
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findSecondLargest(input, size) << endl;

		delete[] input;
	}

	return 0;
}