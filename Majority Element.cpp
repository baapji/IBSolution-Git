// https://www.interviewbit.com/problems/majority-element/

int Solution::majorityElement(const vector<int> &A) {
    int maj = A[0], maj_count = 1;
    for(int i = 1; i < A.size(); i++){
        if(A[i] == maj) maj_count++;
        else{
            maj_count--;
            if(maj_count == 0){
                maj = A[i];
                maj_count = 1;
            }
        }
    }
    return maj;
}
