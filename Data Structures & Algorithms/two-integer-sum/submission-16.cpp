class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort-based solution
        vector<pair<int,int>> numidx;
        for (int i = 0; i<(int)nums.size(); i++) {
            numidx.push_back({nums[i],i});
        }
        sort(numidx.begin(), numidx.end());

        int i = 0, j = (int)nums.size()-1;
        while (i<j) {
            if (numidx[i].first + numidx[j].first == target) {
                int idx1 = min(numidx[i].second,numidx[j].second);
                int idx2 = max(numidx[i].second,numidx[j].second);
                return {idx1,idx2};
            } else if (numidx[i].first + numidx[j].first < target) {
                i++;
            } else {
                j--;
            }
        }
        return {};
    }
};
