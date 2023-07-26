#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class Leet22
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums.erase(nums.begin() + i + 1);
                i--;
            }
        }

        return nums.size();
    }
};

class WaterContainer
{
public:
    int maxArea(vector<int> &height)
    {
        int max = 0;
        int i = 0, j = height.size() - 1;

        while (i < j)
        {
            int length = j - i;
            int current_area = length * min(height[i], height[j]);

            if (current_area > max)
            {
                max = current_area;
            }

            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return max;
    }
};

class ValidSudoku
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // check rows
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                for (int k = j + 1; k < 9; k++)
                {
                    if (board[i][j] != '.')
                    {
                        if (board[i][j] == board[i][k])
                        {
                            return false;
                        }
                    }
                }
            }
        }

        // check columns
        for (int col = 0; col < 9; col++)
        {
            for (int row = 0; row < 9; row++)
            {
                for (int k = row + 1; k < 9; k++)
                {
                    if (board[row][col] != '.')
                    {
                        if (board[row][col] == board[k][col])
                        {
                            return false;
                        }
                    }
                }
            }
        }

        cout << endl;
        // sub_box
        vector<vector<char>> sub_box = board;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                sub_box[i][j] = board[((i / 3) * 3) + (j / 3)][(j % 3) + (3 * (i % 3))];
            }
            cout << endl;
        }

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                for (int k = j + 1; k < 9; k++)
                {
                    if (sub_box[i][j] != '.')
                    {
                        if (sub_box[i][j] == sub_box[i][k])
                        {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
    vector<int> v1 = {1, 1, 2};
    vector<int> v2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Leet22 d;
    cout << "unique elements v1: " << d.removeDuplicates(v1) << endl;
    cout << "unique elements v2: " << d.removeDuplicates(v2) << endl;

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    WaterContainer Water;
    cout << "Max water area: " << Water.maxArea(height) << endl;

    auto t1 = std::chrono::high_resolution_clock::now();
    vector<vector<char>> board =
        {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    ValidSudoku Sudoku;
    cout << "Sudoku: " << Sudoku.isValidSudoku(board) << endl;
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";

    return 0;
}