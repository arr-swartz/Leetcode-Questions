class Solution {
public:
    
    struct job{
        int s;
        int e;
        int p;
    };
    
    static bool compare(struct job a, struct job b){
        return a.e <= b.e;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)      {
        vector<struct job> v;
        for(int i = 0;i < startTime.size();i++){
            struct job j;
            j.s = startTime[i];
            j.e = endTime[i];
            j.p = profit[i];
            v.push_back(j);
        }
        sort(v.begin(), v.end(), compare);
        int n = startTime.size();
        int dp[n];
        dp[0] = v[0].p;
        for(int i = 1;i < n;i++){
            int include = v[i].p;
            int low = 0;
            int high = i-1;
            int index = -1;
            while(low <= high){
                int mid = (low + high)/2;
                if(v[mid].e <= v[i].s){
                    if(mid != n-1){
                        if(v[mid+1].e <= v[i].s){
                            low = mid + 1;
                        }else{
                            index = mid;
                            break;
                        }
                    }else{
                        index = mid;
                        break;
                    }
                }else{
                    high = mid-1;
                }
            }
            if(index == -1){
                dp[i] = max(dp[i-1], include);
            }else{
                dp[i] = max(dp[i-1], include + dp[index]);
            }
        }
        return dp[n-1];
    }
};