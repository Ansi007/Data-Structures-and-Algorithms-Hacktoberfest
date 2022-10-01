// https://leetcode.com/problems/two-sum/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

/*  Hashmap Solution
    Time Complexity - O(n)
    Space Complexity - O(n)
*/
var twoSum = function(nums, target) {
    // edge case for empty array
    if (!nums) return []

    let map = new Map()

    for (let i = 0; i < nums.length; i++) {
        if(map.has(target - nums[i])){
            return [map.get(target - nums[i]), i ]
        }else{
            map.set(nums[i], i)
        }   
    }

    return []
};


/*  Iterative Approach 
    Time Complexity - O(n^2)
    Space Comlexity - O(n)
*/

var twoSum = function(nums, target) {
    const len = nums.length    
    for(var i=0; i< len ; i++){
        for(var j=i+1; j< len; j++){
            if(nums[i]+nums[j] === target){
                return[i,j]                
            }
        }
    }    
};