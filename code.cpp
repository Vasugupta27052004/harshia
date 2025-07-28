


#include <iostream>
#include <map>
#include <string>
#include<vector>
#include <utility>
#include <cmath>

using namespace std;


int decodeY(string value, int base) {
    int result = 0;
    for (char ch : value) {
        result *= base;
        result += ch - '0';
    }
    return result;
}


double lagrangeInterpolationAtZero(const vector<pair<int, int>>& points) {
    double result = 0.0;
    int k = points.size();

    for (int j = 0; j < k; ++j) {
        int xj = points[j].first;
        int yj = points[j].second;

        double numerator = 1.0;
        double denominator = 1.0;

        for (int m = 0; m < k; ++m) {
            if (m != j) {
                int xi = points[m].first;
                numerator *= -xi;
                denominator *= (xj - xi);
            }
        }

        result += yj * (numerator / denominator);
    }

    return round(result); 
}

int main() {
  
    map<int, pair<int, string>> input = {
        {1, {10, "4"}},
        {2, {2, "111"}},
        {3, {10, "12"}},
        {6, {4, "213"}}
    };

    int k = 3; 

    
    vector<pair<int, int>> points;
    int count = 0;
    for (auto& item : input) {
        if (count >= k) break;
        int x = item.first;
        int base = item.second.first;
        string val = item.second.second;
        int y = decodeY(val, base);
        points.push_back({x, y});
        count++;
    }

    
    int secret = lagrangeInterpolationAtZero(points);

    
    cout << "Secret (constant term c) = " << secret << endl;

    return 0;
}
