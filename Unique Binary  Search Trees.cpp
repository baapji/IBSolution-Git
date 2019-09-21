// https://www.interviewbit.com/problems/unique-binary-search-trees/
vector<TreeNode*>generate(int st, int ed){
    vector<TreeNode*> v;
    if(st > ed){
        v.push_back(nullptr);
        return v;
    }
    if(st==ed){
        v.push_back(new TreeNode(st));
        return v;
    }
    for(auto i=st; i<=ed; i++){
        vector<TreeNode *> lft = generate(st, i-1);
        vector<TreeNode *> rgt = generate(i+1, ed);
        for(auto l : lft){
            for(auto r : rgt){
                TreeNode *root = new TreeNode(i);
                root->left = l;
                root->right = r;
                v.push_back(root);
            }
        }
    }
    return v;
}
vector<TreeNode*> Solution::generateTrees(int n) {
    if(n == 0) return vector<TreeNode*>();
    else return generate(1, n);
}

