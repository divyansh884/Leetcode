class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> glass;
        for (double i = 1; i <= 100; i++) {
            vector<double> re(i, double(0));
            glass.push_back(re);
        }
            glass[0][0]+=double(poured);
           for( int i=0;i<100;i++){
                for (int index = 0; index < glass[i].size(); index++) {
                    if (glass[i][index] > double(1)) {
                        int left = index;
                        int right = index + 1;
                        if (i + 1 < 100) {
                            double dis = glass[i][index] - double(1);
                            glass[i][index]=1;
                            glass[i+1][left]+=dis/2;
                            glass[i+1][right]+=dis/2;
                        }
                    }
                   
                }
           }
        return min(double(1),glass[query_row][query_glass]);
    }
};