// https://www.interviewbit.com/problems/gas-station/

int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost){
    int tank = 0, start = 0, sumGas = 0, sumCost = 0;
    for (auto i = 0; i<gas.size(); ++i){
        sumGas += gas[i];
        sumCost += cost[i];
        tank += (gas[i] - cost[i]);
        if (tank < 0){
            start = i + 1;
            tank = 0;
        }
    }
    if (sumGas < sumCost) return -1;
    return start;
}
