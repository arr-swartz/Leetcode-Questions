class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& num2) {
        unordered_map<int, int> m;
        stack<int> s;
        for(int i = num2.size()-1;i >= 0;i--){
            if(s.empty()){
                s.push(num2[i]);
                m[num2[i]] = -1;
            }else{
                while(!s.empty() && num2[i] > s.top()){
                    s.pop();
                }
                if(s.empty()){
                    m[num2[i]] = -1;
                }else{
                    m[num2[i]] = s.top();
                }
                s.push(num2[i]);
            }
        }
        vector<int> v;
        for(int i = 0;i < nums1.size();i++){
            v.push_back(m[nums1[i]]);
        }
        return v;
    }
};