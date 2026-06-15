class Solution {
public:
    bool notDAG(map<char,set<char>> &adj, map<char,int>&visLetter , map<char,int> &pathLetter,char  letter,stack<char>&letters){
        visLetter[letter] = 1;
        pathLetter[letter] = 1;
        set<char>nextLetters = adj[letter];
        for(char nextLetter : nextLetters){
            if(pathLetter.find(nextLetter) == pathLetter.end()){
                if(visLetter.find(nextLetter) == visLetter.end()){
                    if(notDAG(adj,visLetter,pathLetter,nextLetter,letters)) return true;
                }
            }
            else return true;
        }
        // cout << letter << " ";
        letters.push(letter);
        pathLetter.erase(letter);
        return false;
    }
    string foreignDictionary(vector<string>& words) {
        // vector<vector<char>>adj(26);
        map<char,set<char>>adj;
        map<char,int>visLetter;
        map<char,int>pathLetter;
        // vector<int>existAndVisit(26,-1);  // -1 = doesn't exist,0 = exist, 1 = vis

         for (const auto& word : words) {
            for (char ch : word) {
                adj[ch];
            }
        }
        for(int i = 0 ; i < words.size() - 1 ; i++){
            string a = words[i],b = words[i+1];
            int idx = 0,n = a.size() , m = b.size();
            while(idx < n && idx < m && a[idx] == b[idx]){
                idx++;
            }
            if (idx < n && idx == m) return "";
            if(idx < min(n,m) && a[idx] != b[idx] ){
                set<char>&letters = adj[a[idx]];
                letters.insert(b[idx]);
                adj[a[idx]] = letters;   
            } 
        }
        stack<char>letters;
        for(auto letter : adj){
            if(visLetter.find(letter.first) == visLetter.end()){
                if(notDAG(adj,visLetter,pathLetter,letter.first ,letters)){
                    return "";
                }
            }
        }
        string alienOrder = "";
        while(!letters.empty()){
            alienOrder.push_back(letters.top());
            letters.pop();
        }
        return alienOrder;
    }
};
