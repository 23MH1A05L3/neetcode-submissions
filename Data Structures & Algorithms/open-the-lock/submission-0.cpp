class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,int>m;
        for(int i = 0 ; i < deadends.size() ; i++){
            m[deadends[i]]++;
        }

        if(m.count("0000") > 0) return -1;\
        queue<pair<string,int>>q;
        q.push({"0000",0});
        int minMoves = INT_MAX;
        while(!q.empty()){
            auto curLock = q.front();
            q.pop();
            string lock = curLock.first;
            int moves = curLock.second;
            if(lock == target) minMoves = min(minMoves,moves);
            for(int i = 0 ; i < 4 ; i++){
                char ch = lock[i];
                if(lock[i] == '0'){
                    lock[i] = '1';
                    if(m.find(lock) == m.end()){
                        m[lock]++;
                        q.push({lock,moves+1});
                    }
                    lock[i] = '9';
                    if(m.find(lock) == m.end()){
                        m[lock]++;
                        q.push({lock,moves+1});
                    }
                }
                else if(lock[i] == '9'){
                    lock[i] = '8';
                    if(m.find(lock) == m.end()){
                        m[lock]++;
                        q.push({lock,moves+1});
                    }
                    lock[i] = '0';
                    if(m.find(lock) == m.end()){
                        m[lock]++;
                        q.push({lock,moves+1});
                    }
                }
                else{
                    lock[i] = ch+1;
                    if(m.find(lock) == m.end()){
                        m[lock]++;
                        q.push({lock,moves+1});
                    }
                    lock[i] = ch-1;
                    if(m.find(lock) == m.end()){
                        m[lock]++;
                        q.push({lock,moves+1});
                    }
                }
                lock[i] = ch;
            }
        }
        if(minMoves == INT_MAX) return -1;
        return minMoves;
    }
};