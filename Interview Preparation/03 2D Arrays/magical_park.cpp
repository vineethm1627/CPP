/*
    Piyush is lost in a magical park which contains N rows and M columns.In order to get out of park safely and return home, he needs 
    atleast K amount of strength.Given a N by M pattern, your task is to find weather Piyush can ever escape the park.

    Piyush enters the park with strength S. The park is filled with some obstacles denoted by ‘.’ , some magical beans denoted by ‘*’ 
    and some blockades denoted as ‘#’. If he encounters an obstacle (.) , strength decreases by 2. If he encounters a magic bean (' * ')
    , his strength increases by 5. Piyush can only walk row wise, so he starts from left of a row and moves towards right and he does 
    this for every row. However when he encounters a blockade (#) , he cannot go any further in his current row and simply jumps to 
    the start of a new line without losing any strength. Piyush requires a strength of 1 for every step. His strength should always be 
    greater than K while traversing or else Piyush will get lost. Assume that Piyush can shift immediately from last of one row to the 
    start of next one without loss of any strength, help out Piyush to escape the park. His escape is successful if he is able to 
    return home with atleast K strength.

    Input Format
    First line of input contains four integers – N,M,K and S. Next N lines contains M space separated characters which can be '.', '*' 
    or '#'.

    Constraints
    1 <= N,M,K,S <= 100

    Output Format
    Print "Yes" or "No" depending on whether Piyush can escape or not. If the answer is "Yes", also print the amount of strength he 
    escaped with.

    Sample Input
    4 4 5 20
    . . * .
    . # . .
    * * . .
    . # * *
    Sample Output
    Yes
    13
    Explanation
    Piyush starts with strength S=20.
    For first row, he encounters a obstacle ‘.’ and his strength reduces by 3 ( 2+1 ( 1 for taking the step) ). Similarly after the 
    second obstacle , his strength reduces by 3 again and becomes S=14. Then he encounters a '*' , and his strength increases by 5 but 
    decreases by 1 for taking the step. Then his strength reduces by 2 (Not 3 as he will jump with no extra strength from here) after 
    the last '.' . At the end of the first row his strength is S=16.

    In the second row, he encounters a ‘.’ and his strength reduces by 3( 2+1 for the '.' ). Then he encounters a '#' and without losing
    any extra strength simply jumps to the first cell of the next row.
    Similarly, his strength at the beginning of the third row is 13 and after completing it, his strength is 16.
    In the fourth row, he first encounters a '.' and his strength reduces to 13. Then he encounters a '#' at the second position and 
    jumps to the next row. Since this is the last row, when he jumps he escapes from the park .
    His strength left is 13. Since this is clearly greater than K=5, his escape was successful.
    Piyush escaped with final strength = 13.
*/
#include<iostream>
using namespace std;

void magicalPark(char *arr[], int m, int n, int k, int s) {
	// piyush can get out of the park
	bool success = true;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			char ch = arr[i][j];

			// check the strength
			if(s < k) {
				success = false;
				break;
			}
			if(ch == '*')
				s += 5;
			else if(ch == '.')
				s -= 2;
			else 
				break; 
			
			// we loose 1 point when we move right except for the last column
			if(j != n - 1)
				s -= 1;
		}
	}
	if(success) {
		cout << "Yes" << endl;
		cout << s << endl;
	}
	else {
		cout << "No" << endl;
	}

}

int main() {
	
	int m, n, k, s;
	cin >> m >> n >> k >> s;

	char *arr[m];
	for(int i = 0; i < m; i++) 
		arr[i] = new char[n];
	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	magicalPark(arr, m, n, k, s);

	return 0;
}