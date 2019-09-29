// https://www.interviewbit.com/problems/palindrome-integer/

int Solution::isPalindrome(int n) {
    if(n<0) return false;
    int x=n,s=0;
    while(x){
        s++;
        x/=10;
    }
    int j=s-1;
    while(n){
        int y=n/(pow(10,j));
        if(y!=(n%10)) return false;
        n=n-y*pow(10,j);
        n=n/10;
        j-=2;
    }
    return true;
}
