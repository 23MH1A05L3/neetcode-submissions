class Solution {
public:
    bool checkValidString(string s) {
        // int stars = 0;
        // int brackets = 0;
        // for(int i = 0 ; i < s.size() ; i++){
        //     if(s[i] == '(') brackets++;
        //     else if(s[i] == ')' ) { 
        //         if(brackets > 0)  brackets--;
        //         else if(stars > 0) stars--;
        //         else return false;
        //     }
        //     else stars++;
        // }
        // stars = 0;
        //  brackets = 0;
        // for(int i = s.size()-1 ; i >= 0 ; i--){
        //     if(s[i] == ')') brackets++;
        //     else if(s[i] == '(' ) {
                
        //         if(brackets > 0)  brackets--;
        //         else if(stars > 0) stars--;
        //         else return false;
        //     }
        //     else stars++;
        // }

        // // if(brackets > 0 && stars< brackets) return false;
        // return true;

        stack<int>opens;
        stack<int>stars;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '(') opens.push(i);
            else if(s[i] == ')'){
                if(!opens.empty()) opens.pop();
                else{
                    if(!stars.empty()){
                        stars.pop();
                    }
                    else return false;
                }
            }
            else stars.push(i);
        }
        while(!opens.empty() && !stars.empty()){
            if(opens.top() < stars.top()){
                opens.pop();
                stars.pop();
            }
            else return false;
        }
        if(opens.size() == 0) return true;
        return false;
    }
};
