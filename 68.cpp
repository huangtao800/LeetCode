#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
* General idea: Put as many words as possible into one line. And then assign spaces properly between words.
* Pay atthention to the last line, and the line which contains only one word. (They could be processed identically.)
* When packing words as many as possible, note that at least one space should be put bewteen words.
**/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> line;
        int currentWidth = 0;
        vector<string> result;

        int wordPointer = 0;
        while(wordPointer < words.size()){	// Still more words to process
        	currentWidth = 0;
        	line.clear();

        	line.push_back(words[wordPointer]);	// Push the first word
        	currentWidth += words[wordPointer].size();
        	wordPointer++;

        	// Push more words until no enough space.
        	// Note that at least one space should be put between words
        	while(wordPointer<words.size() && currentWidth+1+words[wordPointer].size() <= maxWidth){
        		line.push_back(words[wordPointer]);
        		currentWidth = currentWidth + 1 + words[wordPointer].size();
        		wordPointer++;
        	}
        	bool isLastLine = wordPointer == words.size();
        	result.push_back(assignSpace(line, currentWidth, maxWidth, isLastLine));	// Assign spaces properly
        }
        return result;
    }

    string assignSpace(vector<string>& line, int currentWidth, int maxWidth, bool isLastLine){
    	int wordNum = line.size();
    	string result;

    	int wordPointer = 0;
    	// If the current line contains only one word, or the current line is the last line.
    	if(wordNum==1 || isLastLine){
    		result += line[wordPointer++];
    		while(wordPointer < line.size()){
    			result += ' ';
    			result += line[wordPointer++];
    		}
    		result.append(maxWidth - currentWidth, ' ');
    		return result;
    	}

    	int spaceNum = maxWidth - currentWidth;
    	int eachSpace = spaceNum / (wordNum - 1);	// space numbers evenly distributed
    	int extraSpaceNum = spaceNum % (wordNum - 1);	// extra spaces

    	
    	while(wordPointer < line.size()){
    		result += line[wordPointer++];
    		if(wordPointer==line.size())	break;
    		if(extraSpaceNum){
    			result.append(1+eachSpace+1,' ');
    			extraSpaceNum--;
    		}else{
    			result.append(1+eachSpace,' ');
    		}
    	}
    	return result;
    }

};

int main(){
	string wordArray[] = {"This", "is", "an", "example", "of", "text", "justification."};
	vector<string> words;
	// for(int i=0;i<7;i++){
	// 	words.push_back(wordArray[i]);
	// }
	int maxWidth = 2;

	Solution s;
	vector<string> result = s.fullJustify(words, maxWidth);
	for(int i=0;i<result.size();i++){
		cout << result[i].size() << endl;
	}
	return 0;
}