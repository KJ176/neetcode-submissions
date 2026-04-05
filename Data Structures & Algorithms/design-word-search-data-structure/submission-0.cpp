class TrieNode {
    public:
        vector<TrieNode*> children;
        bool isEnd;
        TrieNode() : children(26, nullptr), isEnd(false) {}
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c: word) {
            if(cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c-'a'];
        }
        cur -> isEnd = true;
    }
    
    bool search(string word) {
        return dfs(root, 0, word);
    }

private:
    bool dfs(TrieNode* root, int index, string word) {
        TrieNode* cur = root;
        for(int i = index; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for(TrieNode* child : cur->children) {
                    if (child != nullptr and dfs(child, i + 1, word)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (cur -> children[c - 'a'] == nullptr) {
                    return false;
                }
                cur = cur->children[c - 'a'];
            }
        }
        return cur->isEnd;
    }
};
