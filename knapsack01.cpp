#include<bits/stdc++.h>

using namespace std;

int knapsack01(vector<int>values, vector<int>weights, int capacity){
    
    int lines = values.size() + 1;
    vector<vector<int>>dp(lines, vector<int>(capacity + 1, 0));

    for(int line = 1; line < lines; line++){
        int w = weights[line-1]; int v = values[line-1];

        for(int col = 0; col <= capacity; col++){
            dp[line][col] = dp[line-1][col];
            if (w <= col){
                dp[line][col] = max(dp[line-1][col], dp[line-1][col-w] + v);
            } 
        }
    }

    return dp[lines-1][capacity];
}

int main(){

    freopen("testcases.txt", "r", stdin);
    int capacity, n_items;
    int test_cases;
    cin >> test_cases;

    while (test_cases -- > 0){
        cout << "--------------------------------------------------" << endl;
        cout << "test case: #" << test_cases << endl;
        cin >> capacity >> n_items;
        cout << "capacity:  " << capacity << endl; 
        // next lines have have n_items (value, weight) pairs
        cout << "value\t" << "weight" << endl; 
        vector<int>value(n_items); vector<int>weight(n_items);
        for(int i = 0; i < n_items; i++){
            cin >> value[i] >> weight[i];
            cout << value[i] << "\t" << weight[i] << endl;
        }
        cout << "max value:\t" << knapsack01(value, weight, capacity) << endl;
        cout << "--------------------------------------------------" << endl;
    }

    return 0;
}