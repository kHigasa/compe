#include <vector>

class Solution {
private:
    int num_size, i, j;
    std::vector<int> answer;
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        num_size = sizeof(nums) / sizeof(nums[0]);
        for (i = 0; i < num_size; ++i) {
            for (j = i + 1; j < num_size; ++j) {
                if (nums[i] + nums[j] == target) {
                    answer.push_back(i);
                    answer.push_back(j);
                    return answer;
                }
            }
        }
        return answer;
    }
};
