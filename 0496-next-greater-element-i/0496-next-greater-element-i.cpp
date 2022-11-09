class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // stack<int> s;
        //     unordered_map<int,int> umpp;
        //     for(int i=nums2.size()-1; i>=0; i--){
        //             if(s.size()==0) umpp[nums2[i]] = -1;
        //             else if(s.size()>0 && s.top()>nums2[i]) umpp[nums2[i]] = s.top();
        //             else if(s.size()>0 && s.top()<=nums2[i]){
        //                     while(s.size()>0 && s.top()<=nums2[i]) s.pop();
        //                     if(s.size()==0) umpp[nums2[i]] = -1;
        //                     else umpp[nums2[i]] = s.top();
        //             }
        //             s.push(nums2[i]);
        //     }
        //     vector<int> v;
        //     for(int i=0; i<nums1.size(); i++){
        //             if(umpp.find(nums1[i])!=umpp.end()){
        //                     v.push_back(umpp[nums1[i]]);
        //             }
        //     }
        //     return v;
            
           unordered_map<int,int> umpp;
            for(int i=nums2.size()-1; i>=0; i--){
                    int c = 0;
                    for(int j=i+1; j<nums2.size(); j++){
                            if(nums2[j]>nums2[i]){
                                    c=1;
                                    umpp[nums2[i]] = nums2[j];
                                  break;
                            }
                    }
                    if(c==0) umpp[nums2[i]] = -1;
            }
             vector<int> v;
            for(int i=0; i<nums1.size(); i++){
                    if(umpp.find(nums1[i])!=umpp.end()){
                            v.push_back(umpp[nums1[i]]);
                    }
            }
            return v;
    }
};