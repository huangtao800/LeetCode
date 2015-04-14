#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int height = grid.size();
        if(height==0) return 0;
        int width = grid[0].size();
        
        int result = 0, uniqueResult=0;
        vector<vector<int>> flag;
        for(int i=0;i<height;i++){
            flag.push_back(vector<int>());
            for(int j=0;j<width;j++){
                flag[i].push_back(0);
            }
        }
        
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(grid[i][j]=='1'){
                    if(i==0 && j==0){   //first node;
                        result++;
                        uniqueResult++;
                        flag[i][j] = uniqueResult;
                    }else if(i==0){     //first line;
                        if(grid[i][j-1]=='0'){
                            result++;
                            uniqueResult++;
                            flag[i][j] = uniqueResult;
                        }else{
                            flag[i][j] = flag[i][j-1];
                        }
                    }else if(j==0){     //first column;
                        if(grid[i-1][j]=='0'){
                            result++;
                            uniqueResult++;
                            flag[i][j]=uniqueResult;
                        }else{
                            flag[i][j]=flag[i-1][j];
                        }
                    }else{      //internal nodes;
                        if(grid[i-1][j]=='0' && grid[i][j-1]=='0'){
                            result++;
                            uniqueResult++;
                            flag[i][j] = uniqueResult;
                        }else{
                            if(grid[i-1][j]!='0' && grid[i][j-1]!='0' && (flag[i-1][j]!=flag[i][j-1])){
                                result--;
                                mergeIslands(i,j,flag);
                            }else{
                                flag[i][j] = (flag[i-1][j]!=0?flag[i-1][j]:flag[i][j-1]);
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
    
private:
    void mergeIslands(int i, int j, vector<vector<int>> &flag){
        int minVal = min(flag[i-1][j],flag[i][j-1]);
        int maxVal = max(flag[i-1][j],flag[i][j-1]);
        int width = flag[0].size();
        for(int x=0;x<=i;x++){
            for(int y=0;y<=width;y++){
                if(x==i && y==j){
                    flag[x][y] = minVal;
                    break;
                }                
                if(flag[x][y]==maxVal){
                    flag[x][y] = minVal;
                }
            }
        }
    }
    
};

int main(){
    vector<vector<char> > grid;
    ifstream infile("test");

    string line;
    while(getline(infile,line)){
        std::vector<char> v;
        for(int i=0;i<line.length();i++){
            if(line[i]=='0'||line[i]=='1'){
                v.push_back(line[i]);
            }
        }
        grid.push_back(v);
    }

    infile.close();

    Solution s;
    int r = s.numIslands(grid);
    cout << r << endl;
    return 0;
}