/*
    Given an array S of size N , check if it is possible to split sequence into two sequences -
    s1 to si and si+1 to sN such that first sequence is strictly decreasing and second is strictly increasing. Print true/false as output.

    Input Format
    First line contains a single integer N denoting the size of the input.
    Next N lines contain a single integer each denoting the elements of the array S.

    Constraints
    0 < N < 1000 Each number in sequence S is > 0 and < 1000000000

    Output Format
    Print boolean output - "true" or "false" defining whether the sequence is increasing - decreasing or not.

    Sample Input
    5 
    1 
    2 
    3 
    4 
    5
    Sample Output
    true
    Explanation
    Carefully read the conditions to judge which all sequences may be valid. Don't use arrays or lists.
	About the input, you need not to take array, one can also perform the question without using array. As every time we just check two consecutive numbers to tell whether the seqeunce is increasing or decreasing, so why should we store all of the numbers.
	
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	A sequence is true if you can split it into two sub sequence such that first sequence is strictly increasing and second sequence is strictly decreasing.
	For e.g.,
	1 2 3 4 5
	This sequence is also true as we can split it into two sequence like., sequence one is empty and sequence two is 1 2 3 4 5.
	Let's take another example.,
	5 4 3 2 1
	This is also true as we can split it such that sequence one is5 4 3 2 1 and sequence two is empty.
	According to the problem statement, we can say the if the sequence decreases then it should not increase, if this is the case one can directly print false else print true.

	The third case is when the sequence is first strictly decreasing then strictly increasing.
	For example :
	9 5 2 7 10
	The sequence first decreases starting from 9 to 2 - { 9, 5, 2 } and then starts increasing - { 7, 10}. Note that it can also be broken as { 9, 5} and { 2, 7, 10} .
	Since the sequence fulfills the required condition , we would also print "true" for this.
	If a sequence does not meet any of the above criteria , we return "false" for it.

	Implementation : First we assume that our sequence is decreasing only. We also assume that our sequence is initially valid and only try to disprove it during the course.
	We compare our current element with the previous element and based on that comparison make our decision.
	If the curr element is equal to the prev element , we see that the sequence is neither strictly increasing or decreasing so we mark our sequence as invalid.
	If the curr element is greater than the prev element, then we realise that the sequence has started increasing and we mark it so using a flag variable "goingUp" which we had initially marked as false based on our assumption that the sequence is decreasing.
	If the curr element is less than the previous element and the current sequence is also proceeding as decreasing , we are to do nothing. However if the current sequence is increasing and we get a pair for a decreasing sequence then we mark our sequence as invalid since we cannot have a decreasing part after the increasing sequence.
	After each iteration , store the value of the curr element into the prev element so that we can compare it with the next input element.


	Editorial Code


	// C++ Code 
	bool increasingDecreasing(int n)
	{
		int prev;
		cin >> prev;

		bool isValid = true;
		bool isDecreasing = true;

		while (--n)
		{
			int curr;
			cin >> curr;
			if (curr == prev)
			{
				isValid = false;
				break;
			}
			else if (curr > prev)
			{
				isDecreasing = false;
			}
			else if (!isDecreasing && curr < prev)
			{
				isValid = false;
				break;
			}

			prev = curr;
		}

		return isValid;
	}
*/

// My Code
#include <iostream>
using namespace std;

int main() {
	int n, num, prev, flag = 1;
	bool incr = true, decr = true;
	cin >> n >> prev;
	
	for(int i = 0; i < n - 1; i++) {
		cin >> num;
		if(num > prev and incr) {
			prev = num;
			incr = true;
			decr = false;
		}
		else if(num < prev and decr) {
			prev = num;
			incr = true;
			decr = true;
		}
		else {
			flag = 0;
			break;
		}
	}
	if(flag) {
		cout << "true" << endl;
	}
	else { 
		cout << "false" << endl;
	}

	return 0;
}