    void reverseString(vector<char>& s) {
        
        int length, size = s.size();
        if(size % 2 == 0)
            length = size / 2;
        else
            length = (size-1) / 2;
        
        for(int i = 0; i < length; i++){
            
            swap(s[i], s[(size--)-1]);
        }
    }