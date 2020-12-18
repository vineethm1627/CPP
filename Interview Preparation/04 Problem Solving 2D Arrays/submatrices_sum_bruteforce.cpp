/*
    To find the sum of all sub-matrices of a given matrix.

    ex:
    2x2 matrix --> 1 1
                   1 1
    
    solution : 
        4 sub matrices (1x1) --> 4 * 1 = 4
        2 sub matrices (1x2) --> 2 * 2 = 4
        2 sub matrices (2x1) --> 2 * 2 = 4
        1 sub matrix (2x2) --> 1 * 4 = 4

    output : 
    16 (the sum of all sub matrices that can be derived from the given matrix)

    Bruteforce approach:

    To find all the submatrices we will exploit the properties of rectangle.

    To define a retangle we just need 2 points : top left and bottom right.

    if top left = (x1, y1)
    and bottom right = (x2, y2)

    then x2 >= x1 and y2 >= y1 as bottom right should always be towards the bottom and right.

    so given x1, x2 --> x1 to n - 1
    given y1, y2 --> y1 to n - 1

    this defines the set of all bottom right coordinates for a given top left value.

    for tl_x = 0 to n - 1:
        for tl_y = 0 to n - 1: // all possible (tl_x, tl_y) top left pairs
            for br_x = tl_x to n - 1:
                for br_y = tl_y to n - 1: // all possible (br_x, br_y) bottom right pairs corresponding to (tl_x, tl_y)
                    for i = tl_x to br_x:
                        for j = tl_y to br_y: // sum of the rectangle (could be square, single point too).
                            sum += arr[i][j];
    
    ex:
    n = 4;
    if (tl_x, tl_y) = (1, 2)
    then (br_x, br_y) --> (1, 2), (1, 3), (2, 2), (2, 3), (3,2), (3, 3)

    This bruteforce has a time complexity of O(n^6).

*/                      
