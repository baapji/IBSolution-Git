// https://www.interviewbit.com/problems/palindrome-partitioning/

bool isPalindrome(const string s, int i, int j){
    while (i<j){
        if (s[i] == s[j]){
            ++i; --j;
        }
        else return false;
    }
    return true;
}
void backtracking(const string& s, int i, vector<string>& row, vector<vector<string> >& res){
    if (i == s.length()){
        res.emplace_back(row); 
        return;
    }
    for (auto x = i; x < s.length(); ++x){
        if (isPalindrome(s, i, x)){
            row.emplace_back(s.substr(i, x-i+1));
            backtracking(s, x+1, row, res);
            row.pop_back();
        }
    }
}
vector<vector<string> > Solution::partition(string A) {
    vector<string> row;
    vector<vector<string> > res;
    backtracking(A, 0, row, res);
    return res;
}
