class MedianFinder {
    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(pq1.empty())
        pq1.push(num);
        else if(pq2.empty() && num>=pq1.top())
        pq2.push((num));
        else if(pq2.empty() && num<pq1.top()){
            int tp=pq1.top();
            pq1.pop();
            pq1.push(num);
            pq2.push(tp);
        }
        else if(num>=pq2.top() && pq1.size()==pq2.size())
        pq2.push(num);
        else if(num>=pq2.top()&& pq1.size()!=pq2.size()){
            if(pq1.size()>pq2.size())
            pq2.push(num);
            else{
            int tp=pq2.top();
            pq2.pop();
            pq2.push(num);
            pq1.push(tp);
            }
        }
        else if(num>pq1.top() && num<pq2.top() && pq1.size()==pq2.size()){
            pq1.push(num);
        }
        else{
            if(pq2.size()>pq1.size())
            pq1.push(num);
            else{
            int tp=pq1.top();
            pq1.pop();
            pq1.push(num);
            pq2.push(tp);
            }
        }
    }
    
    double findMedian() {
        if(pq1.size()==pq2.size())
        return (double(pq1.top())+double(pq2.top()))/2;
        if(pq1.size()>pq2.size())
        return (double)pq1.top();
        return (double)pq2.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */