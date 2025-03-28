class LRUCache {
    vector<int> dq;
    unordered_map<int,int> mp;
    int cap;
public:
    LRUCache(int capacity) {
        this->cap=capacity;
    }
    
    int get(int key) {
        auto it= find(dq.begin(),dq.end(),key);
        if(it!=dq.end()){
            int ans=mp[key];
            dq.erase(it);
            dq.push_back(key);
            return ans;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto it= find(dq.begin(),dq.end(),key);
        if(it!=dq.end()){
            dq.erase(it);
            dq.push_back(key);
            mp[key]=value;
        }
        else{
            if(dq.size()!=cap){
                dq.push_back(key);
                mp[key]=value;
            }
            else{
                int temp=dq.front();
                dq.erase(dq.begin());
                mp.erase(temp);
                dq.push_back(key);
                mp[key]=value;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */