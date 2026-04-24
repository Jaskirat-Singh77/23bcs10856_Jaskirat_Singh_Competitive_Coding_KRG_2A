#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    vector<vector<int>> adj(26);
    vector<int> indegree(26, 0);

    // Step 1: Build graph
    for (int i = 0; i < n - 1; i++) {
        string s1 = names[i];
        string s2 = names[i + 1];

        int len = min(s1.size(), s2.size());
        bool found = false;

        for (int j = 0; j < len; j++) {
            if (s1[j] != s2[j]) {
                int u = s1[j] - 'a';
                int v = s2[j] - 'a';

                adj[u].push_back(v);
                indegree[v]++;
                found = true;
                break;
            }
        }

        // Special case: prefix problem
        if (!found && s1.size() > s2.size()) {
            cout << "Impossible\n";
            return 0;
        }
    }

    // Step 2: Topological Sort (Kahn's Algorithm)
    queue<int> q;

    for (int i = 0; i < 26; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    string result = "";

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        result += (char)(u + 'a');

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Step 3: Check cycle
    if (result.size() != 26) {
        cout << "Impossible\n";
    } else {
        cout << result << "\n";
    }

    return 0;
}