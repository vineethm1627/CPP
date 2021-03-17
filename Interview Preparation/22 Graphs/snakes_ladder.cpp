/*
    Leetcode Problem: https://leetcode.com/problems/snakes-and-ladders/
*/
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int count = 0, r = board.size(), c = board[0].size();
        queue<int> q;
        // to store the set of visited nodes
        unordered_set<int> visited;
        // push the starting node
        q.push(1);
        visited.insert(1);
        visited.insert(-1);
        // perform BFS
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                int curr_pos = q.front();
                // if we have reached the destination
                if(curr_pos == r * c)
                    return count;
                q.pop();
                // calculate the dice moves from the current position
                for(int j = 1; j <= 6; j++) {
                    int next_pos = curr_pos + j;
                    // the move is not possible if the current dice move goes out of board
                    if(next_pos > r * c)
                        break;
                    
                    int next_row = r - 1 - (next_pos - 1) / r;
                    int next_col = (next_pos - 1) % c;
                    
                    if(next_row % 2 != (r - 1) % 2)
                        next_col = c - 1 - next_col;
                    
                    if(visited.find(next_pos) == visited.end()) {
                        visited.insert(next_pos);
                        // add the destination in the queue, if not already visited
                        // if the destination is a ladder / snake
                        if(visited.find(board[next_row][next_col]) == visited.end())
                            q.push(board[next_row][next_col]);
                        else if(board[next_row][next_col] == -1)
                            q.push(next_pos);
                    }    
                }
            }
            count++;
        }
        return -1;
    }
};