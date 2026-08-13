class MedianFinder {
    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq1.empty())
        pq1.push(num);
        else if(pq2.empty()){
            if(num>pq1.top())
            pq2.push(num);
            else{
                int temp=pq1.top();
                pq1.pop();
                pq2.push(temp);
                pq1.push(num);
            }
        }
        else if(num<=pq1.top()){
            if(pq1.size()>pq2.size()){
                int temp=pq1.top();
                pq1.pop();
                pq2.push(temp);
                pq1.push(num);
            }
            else{
                pq1.push(num);
            }
        }
        else if(num>=pq2.top()){
             if(pq2.size()>pq1.size()){
                int temp=pq2.top();
                pq2.pop();
                pq1.push(temp);
                pq2.push(num);
            }
            else{
                pq2.push(num);
            }
        }
        else{
            if(pq2.size()>=pq1.size())
            pq1.push(num);
            else
            pq2.push(num);
        }
    }
    
    double findMedian() {
        cout<<pq1.size()<<pq2.size()<<endl;
        if(pq1.size()==pq2.size()){
            double temp1=pq1.top();
            double temp2=pq2.top();
            double tt=(temp1+temp2)/2;
        return tt;
        }
        else if(pq2.size()>pq1.size())
        return double(pq2.top());
        return double(pq1.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */