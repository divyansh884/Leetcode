#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

// Custom hash for pair<int, int>
struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
public:
    bool solve(int index, int row, int col, vector<vector<char>>& board,
               string& word, int n, unordered_map<pair<int, int>, bool, pair_hash>& mp) {
        if (index >= n) return true;

        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (auto& d : dirs) {
            int newRow = row + d[0];
            int newCol = col + d[1];
            if (newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board[0].size()) {
                if (board[newRow][newCol] == word[index] && !mp[{newRow, newCol}]) {
                    mp[{newRow, newCol}] = true;
                    if (solve(index + 1, newRow, newCol, board, word, n, mp))
                        return true;
                    mp[{newRow, newCol}] = false;
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = word.size();
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    unordered_map<pair<int, int>, bool, pair_hash> mp;
                    mp[{i, j}] = true;
                    if (solve(1, i, j, board, word, n, mp))
                        return true;
                }
            }
        }
        return false;
    }
};
