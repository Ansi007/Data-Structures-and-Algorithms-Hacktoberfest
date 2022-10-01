class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                merged.push_back(nums1[i]);
                i++;
            }
            else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i < nums1.size()){
            merged.push_back(nums1[i++]);
        }
        
        while(j < nums2.size()){
            merged.push_back(nums2[j++]);
        }

        double median = 0;
        if(merged.size() % 2 == 0){
            int index = merged.size()/2;
            median = merged[index] + merged[index - 1];
            median = median / 2;
        }
        
        else {
            median = merged[(merged.size() - 1) / 2];
        }
        return median;
    }
};

//ANNS SHAHBAZ
//https://www.linkedin.com/in/annsshahbaz
//https://github.com/Ansi007