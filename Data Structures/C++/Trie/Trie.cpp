class Trie {
     Trie *prefixTree[26] {};
     bool isWord = false;
     
     public:
     Trie() {}
     
     void insert(string word) {
          Trie *curr = this;
          for(char &ch : word){
               ch -= 'a';
               if(curr->prefixTree[ch] == nullptr)
                    curr->prefixTree[ch] = new Trie();
               
               curr = curr->prefixTree[ch];
          }
          
          curr->isWord = true;
     }
     
     bool search(string word) {
          Trie *curr = this;
          for(char &ch : word){
               ch -= 'a';
               if(curr->prefixTree[ch] == nullptr) return false;
               curr = curr->prefixTree[ch];
          }
          
          return curr->isWord;
     }
     
     bool startsWith(string prefix) {
          Trie *curr = this;
          for(char &ch : prefix){
               ch -= 'a';
               if(curr->prefixTree[ch] == nullptr) return false;
               curr = curr->prefixTree[ch];
          }
          
          return true;
     }
};