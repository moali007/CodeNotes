class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        if(source == target){
            return 0;
        }

        int n = routes.size();

        unordered_map<int, vector<int>> stopToBus;

        for(int bus = 0; bus < n; bus++){

            for(int stop : routes[bus]){

                stopToBus[stop].push_back(bus);
            }
        }

        queue<int> q;
        q.push(source);

        unordered_set<int> visitedStops;
        visitedStops.insert(source);

        unordered_set<int> visitedBus;

        int busCnt = 0;

        while(!q.empty()){

            int size = q.size();

            busCnt++;

            for(int i = 0; i < size; i++){

                int currStop = q.front();
                q.pop();

                for(int bus : stopToBus[currStop]){

                    if(visitedBus.count(bus)){
                        continue;
                    }

                    visitedBus.insert(bus);

                    for(int nextStop : routes[bus]){

                        if(nextStop == target){
                            return busCnt;
                        }

                        if(!visitedStops.count(nextStop)){

                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};