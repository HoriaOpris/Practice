#include <iostream>
#include <vector>

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

        for (int i = 0; i < height.size(); i++)
        {
            for (int j = 0; j < height.size(); j++)
            {
                int length = j - i;
                int water_height = (height[i] < height[j]) ? height[i] : height[j];
                int current_area = length * water_height;

                if (current_area > max)
                {
                    max = current_area;
                }
            }
        }

        return max;
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

    return 0;
}