#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
#define ll long long
#include <iomanip>

void change(int& x, int y) {
   x = x+1;
   y = y+1;
}

int main() {
   int x, y; cin >> x >> y;
   change(x,y);
   cout << x << " " << y;
    
    return 0;
}