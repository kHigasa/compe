class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int res;
        if(A.size()<3){
            return 0;
        }
        sort(A.begin(),A.end(),greater<int>());
        for(int i=0;i<A.size()-2;++i){
            if(A[i]<A[i+1]+A[i+2]){
                return A[i]+A[i+1]+A[i+2];
            }
            continue;
        }
        return 0;
    }
};
