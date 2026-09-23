class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(),1);
        for (int i=0; i<(int)nums.size(); i++) {
            if (i==0) prefix[i] = nums[i];
            else prefix[i] = prefix[i-1] * nums[i];
        }
        vector<int> postfix(nums.size(),1);
        for (int i=(int)nums.size()-1; i>=0; i--) {
            if (i==(int)nums.size()-1) postfix[i] = nums[i];
            else postfix[i] = postfix[i+1] * nums[i];
        }
        vector<int> out(nums.size(),0);
        for (int i=0; i<(int)nums.size(); i++) {
            int pre = 1, post = 1;
            if (i-1 >= 0) pre = prefix[i-1];
            if (i+1 < nums.size()) post = postfix[i+1];
            out[i] = pre * post;
        }
        return out;
    }
};
