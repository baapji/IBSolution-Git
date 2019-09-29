// https://www.interviewbit.com/problems/evaluate-expression/

int Solution::evalRPN(vector<string> &A) {
    stack<int> st;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/"){
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            if(A[i] == "+") st.push(second+first);
            else if(A[i] == "-") st.push(second-first);
            else if(A[i] == "*") st.push(second*first);
            else st.push(second/first);
        }
        else st.push(atoi(A[i].c_str()));
    }
    return st.top();
}
