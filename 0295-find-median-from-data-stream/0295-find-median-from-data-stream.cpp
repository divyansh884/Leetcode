class MedianFinder {
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxheap.push(num);
        minheap.push(maxheap.top());
        maxheap.pop();
        if(minheap.size()>maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }

    }
    
    double findMedian() {
        if(maxheap.size()!=minheap.size()) return maxheap.top();
        return (maxheap.top()+minheap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */