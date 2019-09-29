// https://www.interviewbit.com/problems/excel-column-number/

int Solution::titleToNumber(string s) {
    int n=s.size(); int res=0,j=n-1;
    for(int i=0;i<n;i++){
        int x=s[i]-'A'+1;
        res=res+pow(26,j)*x;
        j--;
    }
    return res;
}

