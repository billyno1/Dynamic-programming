
/*
What:
Given an array.
1 means can pass
0 means can't pass
9 means target.
Start from top-left corner.

Output: number of step from start to target. -1 if no path.

visited is to memorize which cell is visited. 
Running time is O(row*column)
*/
#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

vector <pair<int, int>> visited;

bool notVisited(int x, int y) {
    for(int i = 0; i < visited.size(); i++) {
        if (visited[i].first == x && visited[i].second == y) {
            return false;
        }
    }
    return true;
}

void printvisited() {
    for(int i = 0; i < visited.size(); i++) {
        cout << visited[i].first << " " << visited[i].second<<endl;
    }
}

int findit(int r, int c, int **area, int x, int y) {
    cout << "Called with " << x << " " << y << endl;
    pair<int, int> temp (x, y);
    visited.push_back(temp);
    //printvisited();
    if (area[x][y] == 9) {
        cout << "FOUND IT" << endl;
        return 0;
    }
    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;
    vector <int> possible;
    if (x - 1 >= 0 && notVisited(x-1, y) && area[x-1][y] >= 1) {
        int temp = findit(r, c, area, x-1, y);
        if (temp != -1) {
            up = 1 + temp;
            possible.push_back(up);
        }
    }
    if (x + 1 < r && notVisited(x+1, y) && area[x+1][y] >= 1) {
         
        int temp = findit(r, c, area, x+1, y);
        if (temp != -1) {
            down = 1 + temp;
            possible.push_back(down);
        }
    }
    if (y - 1 >= 0 && notVisited(x, y-1) && area[x][y-1] >= 1) {
        int temp = findit(r, c, area, x, y-1); 
        if (temp != -1) {
            left = 1 + temp;
            possible.push_back(left);
        }
    }
    if (y + 1 < c && notVisited(x, y+1) && area[x][y+1] >= 1) {
        int temp = findit(r, c, area, x, y+1);
        if (temp != -1) {
            right = 1 + temp;
            possible.push_back(right);
        }
    }
    
    if(possible.empty()) {
        return -1;
    } else {
        int retval = -1;
        for(int i = 0; i < possible.size(); i++) {
            if (possible[i] > retval) {
                retval = possible[i];
            }
        }
        return retval;
    }
}

int minimumDistance2(int numRows, int numColumns, int **area) {
    return findit(numRows, numColumns, area, 0, 0);
}


int main()
{
    int array[4][5] = {{1,0,1,1,1},
                       {1,0,9,0,1},
                       {1,0,0,0,1}, 
                       {1,1,1,1,1}};
    int * arr[4];
    for(int i = 0; i < 4; i++) {
        arr[i] = array[i];
    }
    
    cout << minimumDistance2(4, 5, arr) <<endl;
    return 0;
}
