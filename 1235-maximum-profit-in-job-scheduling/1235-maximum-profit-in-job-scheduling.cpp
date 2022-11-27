class Solution {
public:
    int dp[100001];
    int solve(int idx,vector<tuple<int,int,int>> &job){
        if(idx == job.size()) return 0;
        if(dp[idx] != -1) return dp[idx];

        auto &[curr_st_time, curr_en_time, curr_profit] = job[idx];
        
        int next_jump = job.size(), low = idx+1, high = job.size()-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            auto &[mid_st_time, mid_en_time, mid_profit] = job[mid];
            if(mid_st_time >= curr_en_time){
                next_jump = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        int op1 = curr_profit + solve(next_jump,job);
        int op2 = solve(idx+1,job);

        return dp[idx] = max(op1,op2);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tuple<int,int,int>> job; // st_time, en_time, profit
        for(int i=0;i<startTime.size();i++){
            job.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(job.begin(),job.end());
        memset(dp,-1,sizeof dp);
        return solve(0,job);
    }
};