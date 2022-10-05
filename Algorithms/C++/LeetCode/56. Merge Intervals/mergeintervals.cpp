 vector<vector<int>> merge(vector<vector<int>>& mat) {
        
         int n = mat.size();
        if(n == 1) return mat;
        
        vector<vector<int>> ans;
        sort(mat.begin(), mat.end());
        int x = mat[0][0], y = mat[0][1];
        
        for(int i=1; i<n; i++) {
            int f = mat[i][0], s = mat[i][1];
            if(y < f) {
                ans.push_back({x,y});
                x = f, y=s;
            }
            else {
                y = max(y,s);
            }
        }
        
        ans.push_back({x,y});
        
        return ans;
    }