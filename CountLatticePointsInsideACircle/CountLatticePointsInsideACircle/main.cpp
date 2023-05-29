//
//  main.cpp
//  CountLatticePointsInsideACircle
//
//  Created by Arpit Batra on 10/05/23.
//

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

struct Point{
    int x;
    int y;
    Point(int x,int y):x(x),y(y){};

    bool operator==(const Point& other)const{
        return x==other.x && y==other.y;
    }

    bool operator<(const Point& other)const{
        if (x == other.x) {
                return y < other.y;
            }
            return x < other.x;
    }

//    bool operator>(const Point& other)const{
//        return  y>other.y;
//    }

//    bool operator<=(const Point& other)const{
//        return x<=other.x || y<=other.y;
//    }
//
//    bool operator>=(const Point& other)const{
//        return x>=other.x || y>=other.y;
//    }
//
};

double distance(Point a ,Point b){
   return sqrt(pow((double)(a.x-b.x), 2)+pow((double)(a.y-b.y), 2));
}

bool isInsideCircle(Point a, Point centre, int radius){
    return distance(a,centre)<=((double)radius);
}

int countLatticePoints(vector<vector<int>>& circles) {
    set<Point> s;
    s.clear();
    for(int i=0;i<circles.size();i++){
        Point centre = Point(circles[i][0],circles[i][1]);
        int radius = circles[i][2];
        for(int j=(centre.x-radius);j<=(centre.x+radius);j++){
            for(int k=(centre.y-radius);k<=(centre.y+radius);k++){
                if(isInsideCircle(Point(j,k), centre, radius)){
//                    cout << "j -> " << j << " k -> " << k << endl;
                    s.insert(Point(j,k));
                }
            }
        }
    }
//    set<Point>::iterator it;
//    for(it=s.begin();it!=s.end();it++){
//        cout << "x -> " << it->x << " y -> " << it->y << endl;
//    }
    return (int)s.size();
}

//double distance(pair<int,int> a ,pair<int,int> b){
//   return sqrt(pow((double)(a.first-b.first), 2)+pow((double)(a.second-b.second), 2));
//}
//
//bool isInsideCircle(pair<int,int> a, pair<int,int> centre, int radius){
//    return distance(a,centre)<=((double)radius);
//}
//
//int countLatticePoints(vector<vector<int>>& circles) {
//        set<pair<int,int>> s;
//        s.clear();
//    for(int i=0;i<circles.size();i++){
//        pair centre = make_pair(circles[i][0],circles[i][1]);
//        int radius = circles[i][2];
//        for(int j=(centre.first-radius);j<=(centre.first+radius);j++){
//            for(int k=(centre.second-radius);k<=(centre.second+radius);k++){
//                if(isInsideCircle(make_pair(j,k), centre, radius)){
//                    //                    cout << "j -> " << j << " k -> " << k << endl;
//                    s.insert(make_pair(j,k));
//                }
//            }
//        }
//    }
//    set<set<int,int>>::iterator it;
//        for(it=s.begin();it!=s.end();it++){
//            cout << "x -> " << it->first << " y -> " << it->second << endl;
//        }
//    return (int)s.size();
//}

int main(int argc, const char * argv[]) {
    int n;
    cout << "Enter Number of Circles" << endl;
    cin >> n;
    vector<vector<int>>input(n,vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> input[i][j];
        }
    }
    cout << countLatticePoints(input) << endl;
    return 0;
}
