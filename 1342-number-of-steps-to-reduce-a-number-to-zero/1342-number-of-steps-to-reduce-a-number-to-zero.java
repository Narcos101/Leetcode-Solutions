class Solution {
    public int numberOfSteps(int n) {
        int steps = 0;
        int cnt = solve(n,steps);
        return cnt;
    }
    
    int solve(int n, int steps){
        if(n == 0){
            return steps;
        }
        if(n%2 == 0){
            return solve(n /2, steps + 1);
        }
        return solve(n-1,steps+1);
    }
    
    
}