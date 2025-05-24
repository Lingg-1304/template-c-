#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
};
//check c (AB)
int crossProduct(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int distanceSquared(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool polarCompare(Point a, Point b, Point origin) {
    int cp = crossProduct(origin, a, b);
    if (cp == 0)
        return distanceSquared(origin, a) < distanceSquared(origin, b);
    return cp > 0;
}

vector<Point> convexHull(vector<Point>& points) {
    Point start = *min_element(points.begin(), points.end(), [](Point a, Point b) {
        return (a.y < b.y) || (a.y == b.y && a.x < b.x);
    });

    sort(points.begin(), points.end(), [&](Point a, Point b) {
        return polarCompare(a, b, start);
    });

    stack<Point> hull;
    hull.push(points[0]);
    hull.push(points[1]);

    for (size_t i = 2; i < points.size(); ++i) {
        while (hull.size() > 1) {
            Point top = hull.top();
            hull.pop();
            Point nextToTop = hull.top();
            if (crossProduct(nextToTop, top, points[i]) > 0) {
                hull.push(top);
                break;
            }
        }
        hull.push(points[i]);
    }

    vector<Point> result;
    while (!hull.empty()) {
        result.push_back(hull.top());
        hull.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<Point> points , v;
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++){
        int x,y; cin >> x >> y;
        points.push_back({x,y});
    }
    int m; cin >> m;
    for(int i = 0 ; i < m ; i++){
        int x,y; cin >> x >> y;
        v.push_back({x,y});
    }
    vector<Point> hull = convexHull(points);

    for (int i = 0 ; i < hull.size() ; i++){
        Point p = hull[i];
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    // for(Point p : v){
    //     int c = 0;
    //     for(int i = 0 ; i < hull.size() - 1 ; i++){
    //         if(crossProduct(hull[i] , hull[i+1] , p) < 0){
    //             cout << "NO \n";
    //             c = 1;
    //             break;
    //         }
    //     }
    //     if(crossProduct(hull[0] , hull[hull.size() - 1] , p) < 0){
    //         cout << "NO \n";
    //         c = 1;
    //     }
    //     if(c == 0) cout << "YES \n";
    // }

    cout << crossProduct(hull[1] , hull[2] , v[0]);

    return 0;
}
