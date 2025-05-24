#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;

struct Point {
    int x, y;
};

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
    set<II> s;
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++){
        int x,y; cin >> x >> y;
        s.insert({x,y});
    }
    int cnt = 0;
    while(s.size() > 0){
        vector<Point> points;
        for(II x : s) points.push_back({x.fi , x.se});
        vector<Point> check = convexHull(points);
        if(check.size() > 2) cnt++;
        if(check.size() <= 2){
            //cout << cnt;
            break;
        }
        for(Point p : check){
            //cout << p.x << ' ' << p.y << endl;
            s.erase({p.x , p.y});
        }
        //cout << endl;
    }
    cout << cnt;
}
