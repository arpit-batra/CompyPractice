//
//  main.cpp
//  FindTheCityWithTheSmallestNumberOfNeighborsAtAThresholdDistance
//
//  Created by Arpit Batra on 03/05/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Aproach 1

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    //Initializing distances matrix with all values as INT_MAX
    vector<vector<int>> distances(n,vector<int>(n,INT_MAX));

    //Allocating distance of a node from itself as 0 O(n)
    for(int i=0;i<n;i++){
        distances[i][i]=0;
    }

    //Allocating distances from the edges array given O(edges)
    for(int i=0;i<edges.size();i++){
        distances[edges[i][0]][edges[i][1]]=edges[i][2];
        distances[edges[i][1]][edges[i][0]]=edges[i][2];
    }

    //printing the distances matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << distances[i][j] << " ";
        }
        cout << endl;
    }

    //Finding the minimum distances O(n^3)
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(distances[i][k]!=INT_MAX && distances[k][j]!=INT_MAX && distances[i][j]>distances[i][k]+distances[k][j]){
                        distances[i][j]=distances[i][k]+distances[k][j];
                    }
                }
            }
        }
    }
    


    //printing the distances matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << distances[i][j] << " ";
        }
        cout << endl;
    }

    //Finding the city with least cities in reach
    int ans = 0,minimumCitiesInReach=INT_MAX;
    for(int i=0;i<n;i++){
        int citiesWithinReach = 0;
        for(int j=0;j<n;j++){
            if(distances[i][j]<=distanceThreshold) citiesWithinReach++;
        }
        if(citiesWithinReach<=minimumCitiesInReach){
            ans = i;
            minimumCitiesInReach = citiesWithinReach;
        }
    }
    return ans;
}

//struct NeighbourCity{
//    int cityIndex;
//    int distance;
//    NeighbourCity(int a,int b):cityIndex(a),distance(b){}
//
//};


// Approach 2
//int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//    int ans=0,minCitiesReachable=INT_MAX;
//    map<int,vector<NeighbourCity>> cities;
//    for(int i=0;i<edges.size();i++){
//        cities[edges[i][0]].push_back(NeighbourCity(edges[i][1],edges[i][2]));
//    }
//    for(int i=0;i<n;i++){
//        int currentDistance = 0;
//        int currCities Reached = 0;
//    }
//
//    return 0;
//}


int main(int argc, const char * argv[]) {
    while(true){
        int numberOfCities,numberOfEdges,threshold;
        cout << "Enter Number of Cities\n";
        cin >> numberOfCities;
        cout << "Enter Number of Edges\n";
        cin >> numberOfEdges;
        cout << "Enter the Edges with Weights\n";
        vector<vector<int>> edges(numberOfEdges,vector<int>(3));
        for(int i=0;i<numberOfEdges;i++){
            for(int j=0;j<3;j++){
                cin >> edges[i][j];
            }
        }
        cout << "Enter Threshold\n";
        cin >> threshold;
        cout << findTheCity(numberOfCities, edges, threshold) << endl;
    }
    return 0;
}
