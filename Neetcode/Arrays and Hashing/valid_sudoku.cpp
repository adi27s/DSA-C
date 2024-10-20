class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int box[9][9] = {0};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '1';          // 0 to 8 indexing
                    int boxIndex = (i / 3) * 3 + (j / 3); // VERYY IMP IMPORTANT

                    // Check for presence in row,col,box
                    if (row[i][num] || col[j][num] || box[boxIndex][num])
                    {
                        return false; // Invalid Sudoku
                    }

                    // Mark it true
                    row[i][num] = 1;
                    col[j][num] = 1;
                    box[boxIndex][num] = 1;
                }
            }
        }
        return true;
    }
};