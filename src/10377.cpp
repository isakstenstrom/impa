#include <iostream>
#include <math.h>

using namespace std;


enum Direction{
    NORTH = 'N',
    EAST = 'E',
    SOUTH = 'S',
    WEST = 'W',
};


struct Point{
    int x;
    int y;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};


Direction turnRight(const Direction dir) {
    if (dir == NORTH) return EAST;
    else if (dir == EAST) return SOUTH;
    else if (dir == SOUTH) return WEST;
    else return NORTH;
}


Direction turnLeft(const Direction dir) {
    if (dir == NORTH) return WEST;
    else if (dir == EAST) return NORTH;
    else if (dir == SOUTH) return EAST;
    else return SOUTH;
}


Point goForward(const Direction dir, const Point p) {
    int x = p.x;
    int y = p.y;
    if (dir == NORTH) y--;
    if (dir == EAST) x++;
    if (dir == SOUTH) y++;
    if (dir == WEST) x--;
    return Point(x, y);
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        int y_size, x_size;
        cin >> y_size;
        cin >> x_size;
        bool board[62][62];

        for (int y = 0; y < y_size; y++) {
            for (int x = 0; x < x_size; x++) {
                board[y][x] = true;
            }
        }
        string junk;
        getline(cin, junk);
        for (int y = 0; y < y_size; y++) {
            string row;
            getline(cin, row);
            for (int x = 0; x < row.size(); x++) {
                char cell = row[x];
                if (cell == '*') board[y][x] = false;
            }
        }

        int y, x;
        cin >> y;
        cin >> x;
        Point pos = Point(x, y);
        Direction dir = NORTH;

        getline(cin, junk);
        bool handleCommands = true;
        while (handleCommands) {
            string commands;
            getline(cin, commands);
            for (char command : commands) {
                if (command == 'R') {
                    dir = turnRight(dir);
                }
                else if (command == 'L') {
                    dir = turnLeft(dir);
                }
                else if (command == 'F') {
                    Point newPos = goForward(dir, pos);
                    if (board[newPos.y -1][newPos.x -1]) {
                        pos = newPos;
                    }
                    else {
                    }
                }
                if (command == 'Q') {
                    handleCommands = false;
                    break;
                }
            }
        }
        cout << pos.y << " " << pos.x << " " << char(dir) << endl;
        if (T != 0) cout << endl;
    }
    return 0;
}
