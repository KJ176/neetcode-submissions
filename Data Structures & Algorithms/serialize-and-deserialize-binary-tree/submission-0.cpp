/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
private:
    string join(vector<string> arr) {
        if (!arr.size()) return "";
        string res = arr[0];
        for(int i = 1; i< arr.size(); i++) {
            res += "," + arr[i];
        }
        return res;
    }

    vector<string> split(string data) {
        vector<string> res;
        int i = 0, n = data.size();

        for (int j = 0; j <= n; j++) {
            if (j == n || data[j] == ',') {
                res.push_back(data.substr(i, j - i));
                i = j + 1;
            }
        }
        return res;
    }

    void dfsSerialize(TreeNode* root, vector<string> &res) {
        if (!root) {
            res.push_back("N");
            return;
        };
        res.push_back(to_string(root->val));
        dfsSerialize(root->left, res);
        dfsSerialize(root->right, res);
    }

    TreeNode* dfsDeserialize(vector<string> vals, int &i) {
        if (vals[i] == "N") {
            i++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;
        node->left = dfsDeserialize(vals, i);
        node->right = dfsDeserialize(vals, i);
        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsSerialize(root, res);
        return join(res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data);
        int i = 0;
        return dfsDeserialize(vals, i);
    }
};
