#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void dfs(int emp, unordered_map<int, vector<int>> graph, vector<bool> visited, vector<int>& group) {
    group.push_back(emp);
    visited[emp] = true;
    for (auto frnd = graph[emp].begin(); frnd != graph[emp].end(); ++frnd) {
        if (visited[*frnd] == false)
            dfs(*frnd, graph, visited, group);
    }
}

int knapsack(int w, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int> (w + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (wt[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i -1][j - wt[i - 1]]);
        }
    }
    return dp[n][w];
}

int main() {
    int n, temp;
    cin>>n>>temp;
    vector<vector<int>> employee(n, vector<int>(temp, 0));
    for (int i = 0; i <n; i++) {
        int skill, salary;
        cin>>skill>>salary;
        employee[i][0] = skill;
        employee[i][1] = salary;
    }
    unordered_map<int, vector<int>> graph;
    for(int i = 1; i <= n; i++)
        graph[i] = vector<int>();
    int q, t;
    cin>>q>>t;
    for(int i = 0; i < q; i++) {
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int b;
    cin>>b;
    
    vector<vector<int>> groupwiseEmployee;
    vector<bool> visited(n + 1, false);
    
    for(int emp = 1; emp <= n; emp++) {
        if (visited[emp])
            continue;
        vector<int> group;
        dfs(emp, graph, visited, group);
        groupwiseEmployee.push_back(group);
    }
    
    int size = groupwiseEmployee.size();
    vector<int> skill(size, 0);
    vector<int> salary(size, 0);
    
    for(int grp = 0; grp < size; grp++) {
        for(int emp = 0; emp < groupwiseEmployee[grp].size(); emp++) {
            skill[grp] += employee[groupwiseEmployee[grp][emp] - 1][0];
            salary[grp] += employee[groupwiseEmployee[grp][emp] - 1][1];
        }
    }
    
    int profit = knapsack(b, salary, skill, size);
    cout<<profit<<endl;
	return 0;
}