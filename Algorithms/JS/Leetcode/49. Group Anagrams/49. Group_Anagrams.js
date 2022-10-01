// Time Complexity - O(N)
// Space Complexity - O(N)
// https://leetcode.com/problems/group-anagrams/description/
const letters = {
    a: 0,
   b: 1,
   c: 2,
   d: 3,
   e: 4,
   f: 5,
   g: 6,
   h: 7,
   i: 8,
   j: 9,
   k: 10,
   l: 11,
   m: 12,
   n: 13,
   o: 14,
   p: 15,
   q: 16,
   r: 17,
   s: 18,
   t: 19,
   u: 20,
   v: 21,
   w: 22,
   x: 23,
   y: 24,
   z: 25,
}
var groupAnagrams = function(strs) {
   let strmap = Object.create(null)
   
   for (let i of strs){
       let wordId = hash(i);
       if (!(wordId in strmap)) {
           strmap[wordId] = [];
       }
       strmap[wordId].push(i);
   }

   const groups = [];
   for (const j in strmap) {
       groups.push(strmap[j]);
   }
   return groups;
   
};

function hash(word){
   let hash = new Array(26).fill(0)
   
   for (let k of word){
       ++hash[letters[k]]
   }
   
   return hash.toString()
}