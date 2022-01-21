class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        int gas_cost = 0;
        int start = 0;
        for(int i = 0; i < n; i++){
            sum += (gas[i]-cost[i]);
            gas_cost += (gas[i]-cost[i]);
            if(gas_cost < 0){
                gas_cost = 0;
                start = i+1;
            }
        }
        return sum < 0 ? -1 : start;
    }
};