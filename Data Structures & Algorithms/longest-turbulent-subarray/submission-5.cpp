class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n < 2) return n;
        vector<int>turbFactor(n,0);
        for(int i = 0 ; i < n-1 ; i++){
            if(arr[i] < arr[i+1] ){
                turbFactor[i] = -1;
            }
            else if(arr[i] > arr[i+1]){
                turbFactor[i] = 1;
            }
            else turbFactor[i] = 0;
        }
        if(turbFactor[n-2] == -1) turbFactor[n-1] = 1;
        else if(turbFactor[n-2] == 1) turbFactor[n-1] = -1;
        else turbFactor[n-1] = 0;

        for(int i = 0 ; i < n ; i++) cout << turbFactor[i] << " " ;
        int i=0;
        while(i < n && turbFactor[i] == 0){
            i++;
        }
        if(i == n) return 1;
        int prev = turbFactor[i],size = 1,maxSize = 0;
        i++;
        // for(int i = 1; i < n-1 ; i++){
        while(i < n){
            if(turbFactor[i] == 0) {
                maxSize = max(maxSize,size+1);
                size = 1;
                if(i+1 != n)prev = turbFactor[i+1];
                i += 2;
            }
            else{
                if(prev == turbFactor[i]){
                    maxSize = max(maxSize,size+1);
                    prev = turbFactor[i];
                    size = 1;
                }
                else{
                    size++;
                    prev = turbFactor[i];
                }
                // cout << size << " ";
                maxSize = max(maxSize,size);
                i++;
            }
        }
        return maxSize;
    }
};