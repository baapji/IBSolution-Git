// https://www.interviewbit.com/problems/prettyprint/
vector<vector<int> > Solution::prettyPrint(int n) {
    int arr[20][20];
    vector<vector<int>> narr;
    int count=n;
    int run=(2*n)-1;
    int div=0;
    div=(run/2)+1;
    arr[div-1][div-1]=1;
    for(int x=0; x<n-1; x++){
        for(int i=x; i<run-x; i++){
            for(int j=x; j<run-x; j++){
                if(i==x || j==x || i==run-1-x || j==run-1-x) arr[i][j]=n-x;
                else continue;
            }
        }
    }
    for(int i=0; i<run; i++){
        vector<int> row;
        for(int j=0; j<run; j++){
            int input=arr[i][j];
            row.push_back(input);
        }
        narr.push_back(row);
        row.clear();
    }
    return narr;
}

