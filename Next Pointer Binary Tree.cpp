// https://www.interviewbit.com/problems/next-pointer-binary-tree/
TreeLinkNode* nextRight(TreeLinkNode* current){
    TreeLinkNode* currNext = current->next;
    while (currNext){
        if (currNext->left) return currNext->left;
        else if (currNext->right) return currNext->right;
        currNext = currNext->next;
    }
    return NULL;
}
void Solution::connect(TreeLinkNode* A) {
    if (!A) return;
    A->next = NULL;
    while (A) {
        TreeLinkNode *B = A;
        while (B) {
            if (B->left) {
                if (B->right) B->left->next = B->right;
                else B->left->next = nextRight(B);
            }
            if (B->right) B->right->next = nextRight(B);
            B = B->next;
        }
        if (A->left) A = A->left;
        else if (A->right) A = A->right;
        else A = nextRight(A);
    }
}
