//C++ solution for 3sum problem of leetcode

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if(nums.size()<3)
            return {};
        
        //Sorting the array
        sort(nums.begin(),nums.end());
        
        int start = 0;
        vector<vector<int>> ans;
        vector<int> temp;
        while(start < nums.size()-2 && nums[start] <= 0)
        {
            //using three pointers start,mid and high
            int mid = start + 1,high = nums.size() - 1;
            //if nums[start] exceeds 0 that means adding rest of will surely increase the value ,as the array is sorted
            if(nums[start] > 0)
                break;
            while(mid < high)
            {
                int sum = nums[start] + nums[mid] + nums[high];
                if(sum < 0)
                    mid++;
                else if(sum > 0)
                    high--;
                else
                {
                    //this checks if all the values from mid to high are same
                    if(nums[mid] == nums[high])
                    {
                        temp.push_back(nums[start]);
                        temp.push_back(nums[mid]);
                        temp.push_back(nums[high]);
                        ans.push_back(temp);
                        temp.clear();
                        break;
                    }
                    else
                    {
                        temp.push_back(nums[start]);
                        temp.push_back(nums[mid]);
                        temp.push_back(nums[high]);
                        ans.push_back(temp);
                        temp.clear();
                        //skipping duplicates from starting and from end
                        while(mid < nums.size() - 2 && nums[mid] == nums[mid+1])
                            mid++;
                        while(nums[high] == nums[high-1])
                            high--;
                         mid++;
                         high--;
                    }
                   
                }

            }
            while(start<nums.size()-2 && nums[start] == nums[start+1])
                start++;
            start++;
        }
        return ans;
    }
};
