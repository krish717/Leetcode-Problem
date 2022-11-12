class MedianFinder {
public:
        // vector<int> v;
        priority_queue<int> maxpq;
        priority_queue<int, vector<int>, greater<int>> minpq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // v.push_back(num);
            if(maxpq.empty() || maxpq.top() > num)
                    maxpq.push(num);
           else 
                   minpq.push(num);
            
            if(maxpq.size() > minpq.size()+1){
                    minpq.push(maxpq.top());
                    maxpq.pop();
            }else if(minpq.size() > maxpq.size()+1){
                    maxpq.push(minpq.top());
                    minpq.pop();
            }
                   
        
    }
    
    double findMedian() {
            if(maxpq.size()==minpq.size()){
                    return (maxpq.top()+minpq.top())/2.0;
            }else if(maxpq.size() > minpq.size()){
                    return maxpq.top();
            }else{
                    return minpq.top();
            }
//             sort(v.begin(), v.end());
//         int n = v.size()-1;
//             double ans;
//             if(n%2==0){
//                     ans= v[n/2];
                  
//             }else{
                   
//                     ans = (v[n/2]+v[(n/2)+1])/2.0;
                   
//             }
//             return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */