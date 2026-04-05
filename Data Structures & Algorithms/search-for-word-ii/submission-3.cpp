class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord;

    TrieNode(): isWord(false) {}

    void addWord(const string& word) {
        TrieNode* cur = this;
        for (char c : word) {
            if (!cur->children.count(c)) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur -> isWord = true;
    }
};

class Solution {
    unordered_set<string> res;
    vector<vector<bool>> visited;
    int ROWS, COLS;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(const string& word: words) {
            root->addWord(word);
        }

        ROWS = board.size();
        COLS = board[0].size();
        visited = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                dfs(board, r, c, root, "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }
private:
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* cur, string word) {
        if (r < 0 or r == ROWS or c < 0 or c == COLS or visited[r][c] or !cur->children.count(board[r][c])) {
            return;
        }

        cur = cur->children[board[r][c]];
        word += board[r][c];
        if (cur->isWord) {
            res.insert(word);
        }

        visited[r][c] = true;

        dfs(board, r - 1, c, cur, word);
        dfs(board, r, c - 1, cur, word);
        dfs(board, r, c + 1, cur, word);
        dfs(board, r + 1, c, cur, word);

        visited[r][c] = false;
    }
};
