/*
    given a set of directions {N,S,E,E}.
    find the displacement to reach the coordinates of the final destination in terms of these symbols

    let the final coordinate be (x, y)
    initial position = origin (0, 0)
    N -> y++; 
    S -> y--;
    E -> x++;
    W -> x--;

    final shortest steps taken is x + y. 
    Note: diagonal is not allowed

    input: 
    NNNSSEEWE

    output: 
    3

    explanation:
    final coordinate = (2, 1)
    2 + 1 = 3 is the required displacement from the origin

*/

#include <iostream>
using namespace std;

int displacement() {
    char ch;
    ch = cin.get();
    int x = 0, y = 0;

    while(ch != '\n') {
        switch(ch) {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            default:
                x--;
                break;
        }
        ch = cin.get(); //fetch the next character from the input buffer
    }
    return x + y;
}

int main() {

    int ans = displacement();
    cout << "displacement : " << ans;
    return 0;
}