// https://www.interviewbit.com/problems/valid-binary-search-tree/
int checkValid(TreeNode* root, int min, int max){
    if(root == NULL) return 1;
    else if((root->val < max) &&
            (root->val > min) &&
            (checkValid(root->left, min, root->val)) &&
            (checkValid(root->right, root->val, max))) return 1;
    return 0;
}

int Solution::isValidBST(TreeNode* A) {
    return checkValid(A, INT_MIN, INT_MAX);
}
