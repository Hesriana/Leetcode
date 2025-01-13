class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int sum = gas[gas.size() - 1] - cost[cost.size() - 1];
        int station = 0,tank = gas[0];

        for(int i = 0 ; i < gas.size() - 1 ; i++){
            
            sum += gas[i] - cost[i];

            tank -= cost[i];
            if(tank < 0){
                station = i+1;
                tank = 0;
            }
            tank += gas[i+1];
        }

        if(sum < 0)
            return -1;
        else
            return station;
    }
};
