//backtracking
class Solution {
public:
    void dfs(int node,vector<vector<int>>&graph,vector<int>&path,vector<vector<int>>&ans){

        int n = graph.size();

        //終止條件
        if(node == n - 1){
            ans.push_back(path);
            return;
        }
        //dfs全部的node
        for(auto it:graph[node]){
            path.push_back(it);
            dfs(it,graph,path,ans);
            path.pop_back();//回到上一層
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;//記住瀏覽過的路徑
        vector<vector<int>> ans;
        path.push_back(0);//由0開始
        dfs(0,graph,path,ans);
        return ans;
    }
};
