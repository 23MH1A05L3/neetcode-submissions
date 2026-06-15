class Solution {
public:
    bool checkValidString(string s) {
        int stars = 0;
        int brackets = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '(') brackets++;
            else if(s[i] == ')' ) {
                
                if(brackets > 0)  brackets--;
                else if(stars > 0) stars--;
                else return false;
            }
            else stars++;
        }
        stars = 0;
         brackets = 0;
        for(int i = s.size()-1 ; i >= 0 ; i--){
            if(s[i] == ')') brackets++;
            else if(s[i] == '(' ) {
                
                if(brackets > 0)  brackets--;
                else if(stars > 0) stars--;
                else return false;
            }
            else stars++;
        }
        return true;
    }
};
