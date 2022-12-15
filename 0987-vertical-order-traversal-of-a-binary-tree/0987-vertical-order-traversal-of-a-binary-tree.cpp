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
        void fun(TreeNode* root,int vertical,int level,map<int,map<int,multiset<int>>>& mp){
                if(root==NULL) return;
                mp[vertical][level].insert(root->val);
                fun(root->left,vertical-1,level+1,mp);
                fun(root->right,vertical+1,level+1,mp);
        }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
            if(root==NULL) return ans;
            queue<pair<TreeNode*,pair<int, int>>> q;
            map<int,map<int,multiset<int>>> mp;
            q.push({root,{0,0}});
            fun(root,0,0,mp);
            
            for(auto p:mp){
                    vector<int> temp;
                    for(auto k:p.second){
                            temp.insert(temp.end(),k.second.begin(),k.second.end());
                    }
                    ans.push_back(temp);
            }
            
            return ans;
    }
};