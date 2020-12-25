/*
    Prateek Bhaiya decided to give 100% scholarships to the needy students by taking an admission test. However in order to avoid any 
    losses at the institute, he came up with a solution. Coding Blocks has N students and M discount coupons. A student will get 100% 
    waiver if he gets X discount coupons.
    However in order to get more discount coupons in addition to those M , Bhaiya decided that some students who perform badly in the 
    admission tests, need to pay additional amount equivalent to Y discount coupons, i.e. good students earn discount coupons and weak 
    students need to pay coupons to get admission.

    Find out the maximum number of students who can get 100% waiver in their admission fees.
    Note : Bhaiya will try his best to give 100% discount to maximum students possible.

    Input Format
    The first line contains 4 integers N M X Y

    Constraints
    1 ≤ N,M,X,Y ≤ 10^9​​

    Output Format
    The output should contain a single integer representing the maximum number of students who can get 100% discount.

    Sample Input
    5 10 2 1
    Sample Output
    5
    Explanation
    File 1: Since there are 5 students, and 10 available coupons, and each student needs just 2 coupons to get 100% discount, so Bhaiya 
    already has the needed number of coupons, so all 5 students will get 100% waiver on their fees.
*/
#include <iostream>
using namespace std;

bool canGetCoupons(long n, long m, long x, long y, long cur_students) {
	// give x coupons to students and take y coupons from remaining students
	// total_req = cur_students * x;
	// arrange_req = m + (n - cur_students) * y;
	
	return cur_students * x <= (m + (n - cur_students) * y);
}

long findStudents(long n, long m, long x, long y) {
    // monotonic search space
	long start = 0, end = n, ans = 0;
	while(start <= end) {
		long mid = start + (end - start) / 2;
		// check can 'mid' students can avail the scholarship
		bool success = canGetCoupons(n, m, x, y, mid);
		if(success) {
			ans = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return ans;
}

int main() {

	long n, m, x, y;
	cin >> n >> m >> x >> y;

	cout << findStudents(n, m, x, y);

	return 0;
}