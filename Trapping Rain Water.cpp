class Solution {
public:/*int maxWater(int arr[], int n)
{
    // To store the maximum water
    // that can be stored
    int res = 0;
 
    // For every element of the array
    for (int i = 1; i < n - 1; i++) {
 
        // Find the maximum element on its left
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);
 
        // Find the maximum element on its right
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);
 
        // Update the maximum water
        res = res + (min(left, right) - arr[i]);
    }
 
    return res;
}
*/
    int trap(vector<int>& h) {
        int max=-1;
        int max_index=-1;
        int count=0; // storing the water levels that can be filled; 
		
		// finding index of maximum height in the array; 
        for(int i=0;i<h.size();++i){
            if(max<h[i]) {
                max=h[i];
                max_index=i;
            }
        }
        int max_height=0; 
		//iterating from left to that max_index and updating value of max_height when we find  h[i]>max_height;
        for(int i=0;i<max_index;++i){
            if(max_height<h[i]){
                max_height=h[i];
            }
           
                count+=max_height-h[i];
            
        }
        max_height=0;
		//same as the above loop we are now iterating from right to max_index ;
        for(int j=h.size()-1;j>max_index;j--){
            if(max_height<h[j]){
                max_height=h[j];
            }
            
                count+=max_height-h[j];
            
        }
        return count;
    }
};
