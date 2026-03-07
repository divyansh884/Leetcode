class MedianFinder {
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (pq1.empty())
            pq1.push(num);
        else if (pq2.empty() && num >= pq1.top())
        pq2.push(num);
        else if(pq2.empty() && num<pq1.top()){
                int tt = pq1.top();
                pq1.pop();
                pq2.push(tt);
                pq1.push(num);
        }
        else if(num>=pq2.top() && pq2.size()==pq1.size()){
                pq2.push(num);
        }
        else if(num>=pq2.top() && pq2.size()!=pq1.size()){
                if (pq1.size() > pq2.size())
                    pq2.push(num);
                else {
                    int tt = pq2.top();
                    pq2.pop();
                    pq1.push(tt);
                    pq2.push(num);
                }
        }
        else if(num>pq1.size() && num<pq2.size() && pq1.size()==pq2.size()){
                pq1.push(num);
        }
        else{
                if (pq2.size() > pq1.size())
                    pq1.push(num);
                else {
                    int tt = pq1.top();
                    pq1.pop();
                    pq2.push(tt);
                    pq1.push(num);
                }
        }
    }

    double findMedian() {
        if (pq1.size() == pq2.size())
            return (double(pq1.top()) + double(pq2.top())) / 2;
        if (pq1.size() > pq2.size())
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