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

int main()
{
    vector<int> v1 = {1, 1, 2};
    vector<int> v2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    Leet22 d;
    cout << "unique elements v1: " << d.removeDuplicates(v1) << endl;
    cout << "unique elements v2: " << d.removeDuplicates(v2) << endl;

    

    return 0;
}