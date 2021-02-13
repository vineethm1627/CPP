/*
    Given n points in 2D cartesian plane, find the number of rectangles having sides parallel to x or y axis.

    a rectangle can be constructed by two opposite points.
*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;
 
class Point {
    public:
        int x;
        int y;

        Point() {

        }

        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }
};

class compare {
    public:
        bool operator()(Point p1, Point p2) {
            if(p1.x == p2.x)
                return p1.y < p2.y;
            return p1.x < p2.x;
        }
};

int countRectangles(vector<Point> pts) {
    int n = pts.size();
    // insert all points in the set
    set<Point, compare> s(pts.begin(), pts.end());

    int count = 0;
    // outer loop goes till the second last point
    for(auto it = s.begin(); it != prev(s.end()); it++) {
        for(auto jt = next(it); jt != s.end(); jt++) {
            Point p1 = *it;
            Point p2 = *jt;

            if(p1.x == p2.x or p1.y == p2.y)
                continue;
            
            // p1 and p2 are opposite to each other, construct the other 2 points.
            Point p3(p2.x, p1.y);
            Point p4(p1.x, p2.y);

            if(s.find(p3) != s.end() and s.find(p4) != s.end())
                count++;
        }
    }
    return count / 2;
}
 
int main() {
 
    int n;
    cin >> n;
    vector<Point> pts;
    while(n--) {
        int x, y;
        cin >> x >> y;
        Point p(x, y);
        pts.push_back(p);
    }
    cout << countRectangles(pts) << endl;
 
    return 0;
}