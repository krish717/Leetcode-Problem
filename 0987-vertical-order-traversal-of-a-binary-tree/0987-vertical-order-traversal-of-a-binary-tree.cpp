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
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
            if(root==NULL) return ans;
            queue<pair<TreeNode *,pair<int,int>>> q;
            q.push({root,{0,0}});
            map<int,map<int,multiset<int>>> mp;
            while(!q.empty()){
                    auto p = q.front();
                    q.pop();
                    root = p.first;
                    int vertical = p.second.first;
                    int level = p.second.second;
                    mp[vertical][level].insert(root->val);
                    if(root->left) q.push({root->left,{vertical-1,level+1}});
                    if(root->right) q.push({root->right,{vertical+1,level+1}});
            }
            
            for(auto p:mp){
                    vector<int> v;
                    for(auto k:p.second){
                            v.insert(v.end(), k.second.begin(),k.second.end());
                    }
                    ans.push_back(v);
            }
            return ans;
    }
};