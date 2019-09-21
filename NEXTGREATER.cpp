// https://www.interviewbit.com/problems/nextgreater/
vector<int> Solution::nextGreater(vector<int> &A) {
    stack<int> b;
    b.push(0);
    vector<int>r;
    r.push_back(-1);
    for(int i=1;i<A.size();i++){
        r.push_back(-1);
        int j=A[i];
        while(!b.empty()&&j>A[b.top()]){
            r[b.top()]=j;
            b.pop();
        }
        b.push(i);
    }
    return r;
}

