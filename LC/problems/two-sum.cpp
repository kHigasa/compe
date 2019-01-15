#include <vector>

class Solution {
private:
    std::vector<int> answer;
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        for (int i=0;i<nums.size()-1;++i) {
            for (int j=i+1;j<nums.size();++j) {
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
