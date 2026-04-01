class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            graph[from].push_back({to, price});
        }

        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            int stopsUsed = current.first;
            int currentCity = current.second.first;
            int currentCost = current.second.second;

            if (stopsUsed > k) continue;

            for (auto neighbor : graph[currentCity]) {
                int nextCity = neighbor.first;
                int flightCost = neighbor.second;

                int newCost = currentCost + flightCost;

                if (newCost < minCost[nextCity]) {
                    minCost[nextCity] = newCost;
                    q.push({stopsUsed + 1, {nextCity, newCost}});
                }
            }
        }

        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};