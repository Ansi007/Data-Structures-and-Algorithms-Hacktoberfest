class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(nums[i] == nums[j] && i < j) {
                             x++;       
                }
            }
        }
        return x;
    }
};

//ANNS SHAHBAZ
//https://www.linkedin.com/in/annsshahbaz
//https://github.com/Ansi007