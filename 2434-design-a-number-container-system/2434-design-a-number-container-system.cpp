class NumberContainers {
public:
map<int,int> ind;
unordered_map<int,int> fin;
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if(fin[ind[index]]==index){
            int count=1;
            bool flag=false;
            for(auto i: ind){
                if(i.second==ind[index]){
                    if(count==2){
                    fin[ind[index]]=i.first;
                    flag=true;
                    break;
                    }
                    else
                    count++;
                }
            }
            if(!flag)
            fin[ind[index]]=0;
        }
        ind[index]=number;
        if(fin[number]>index)
        fin[number]=index;
        else if(fin[number]==0)
        fin[number]=index;
    }
    
    int find(int number) {
        if(fin[number]==0)
        return -1;
        return fin[number];
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */