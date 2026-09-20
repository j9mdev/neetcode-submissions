class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numidx;

        for (int i=0; i<(int)nums.size(); i++) {
            auto num = nums[i];
            auto it = numidx.find(num);
            if (it != numidx.end()) {
                if (num*2 == target) {
                    if (it->second != i)
                        return {it->second,i};
                } else {
                    // can ignore num[i]
                    // because 
                    // You may assume that every input has exactly one pair of indices i and j that satisfy the condition.
                }
            } else {
                numidx.insert({num,i});
                // cout << num << "," << i << "\n";
            }
        }

        for (int i=0; i<(int)nums.size(); i++) {
            auto it = numidx.find(target-nums[i]);
            if (it != numidx.end()) {
                if (it->second != i) return {i,it->second};   
            }
        }

        // unreachable
        return {0,0};
    }
};
