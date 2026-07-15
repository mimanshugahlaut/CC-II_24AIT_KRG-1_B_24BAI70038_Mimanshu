class Solution {
public:
    bool canplace(vector<int> &position,int m,int dist){
        int cnt=1;
        int lastpos=position[0];
        for(int i=0;i<position.size();i++){
            if(position[i]-lastpos>=dist){
                cnt++;
                lastpos=position[i];

                if(cnt==m) return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low=1;
        int high=position.back()-position.front();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canplace(position,m,mid)) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};
