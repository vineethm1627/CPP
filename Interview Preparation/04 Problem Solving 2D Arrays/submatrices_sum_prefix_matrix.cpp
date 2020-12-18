/*
    instead of computing the sum every time we can make use of additoinal prefix sum array.

    prefix sum array: 1D

        arr --> [1 2 3 4 5]
        prefix_sum --> [1, 3, 6 ,10, 15] basically the cumulative sum

        sum of subarray from i to j = prefix_sum[j] - prefix_sum[i] + arr[i]

        ex : sum of subarray from 1 to 4 = prefix_sum[4] - prefix_sum[1] + arr[1] = 15 - 3 + 2 = 14.

    prefix sum array: 2D

        take the prefix sum column wise and then take it row wise.

        a b c                 a a+b a+b+c                 a a+b a+b+c
        d e f  --col wise-->  d d+e d+e+f  --row wise-->  a+d a+b+d+e a+b+c+d+e+f
        g h i                 g g+h g+h+i                 g+a+d g+h+a+b+d+e a+b+c+d+e+f+g+h+i


        prefix_sum(tl_x, tl_y) =  sum((0, 0) till (tl_x, tl_y))

        so total value ie sum((tl_x, tl_y) to (br_x, br_y)) = p(br_x, br_y) - p(tl_x - 1, br_y) - p(br_x, tl_y - 1) + p(tl_x - 1, tl_y - 1);

    for tl_x = 0 to n - 1:
        for tl_y = 0 to n - 1: // all possible top left values
            for br_x = tl_x to n - 1:
                for br_y = tl_y to n - 1: // all possible bottom right values wrt top left values
                    sum += p(br_x, br_y) - p(tl_x - 1, br_y) - p(br_x, tl_y - 1) + p(tl_x - 1, tl_y - 1);

    
    This approach uses O(n^4) time complexity and a space complexity of O(n^2).

*/