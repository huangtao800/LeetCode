class Solution {
public:
    vector<vector<string> > partition(string s) {
       vector<vector<string> > result;
       vector<string> already;
       if(s.size()==0)  return result;
       partitionSub(s, already, result);
       return result;
    }
    
    void partitionSub(string s, vector<string> &already, vector<vector<string> > &result){
        if(s.size()==0) result.push_back(already);
        for(int i=1;i<=s.size();i++){
            string former = s.substr(0,i);
            if(isPalindrome(former)){
                already.push_back(former);
                partitionSub(s.substr(i), already, result);
                already.pop_back();
            }
        }
    }

    bool isPalindrome(string s){
    	if(s.size()==0)	return true;
    	for(int i=0,j=s.size()-1;i<j;i++,j--){
    		if(s[i]!=s[j])	return false;
    	}
    	return true;
    }
};