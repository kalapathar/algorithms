#include <iostream>
using namespace std;

bool ** visited;

bool explore(int x, int y) {
    int z = 11 - x - y;
    if (x == 2 || y == 2) {
        cout << "Solution " <<  x << ", " << y << ", " << z << " reached" << endl;
        return true;
    } else if (visited[x][y]) {
        return false;
    }
    visited[x][y] = true;

    // Pour water!
    if (x < 7) {
        if(y > 0) {
            // Pour y into x
            if (y <= 7 - x) {
                if (explore(x + y, 0)) {
                    cout << x << ", " << y << ", " << z << endl;
                    return true;
                }
            } else if (y > 7 - x) {
                if (explore(7, y - (7 - x))) {
                    cout << x << ", " << y << ", " << z << endl;
                    return true;
                }
            }
        }
        if(z > 0) {
            // Pour z into x
            if (z <= 7 - x) {
                if (explore(x + z, y)) {
                    cout << x << ", " << y << ", " << z << endl;
                    return true;
                }
            } else if (z > 7 - x) {
                if (explore(7, y)) {
                    cout << x << ", " << y << ", " << z << endl;
                    return true;
                }
            }
        }
    }    
    if (y < 4) {
        if (x > 0) {
            // Pour x into y
            if (x <= 4 - y) {
                if (explore(0, y + x)) {
                    cout << x << ", " << y << ", " << z << endl;
                    return true;
                }
            } else if (x > 4 - y) {
                if (explore(x - (4 - y), 4)) {
                    cout << x << ", " << y << ", " << z << endl;
                    return true;
                }
            }
        }
        if (z > 0) {
            // Pour z into y
            if (z <= 4 - y) {
                if (explore(0, y + z)) {
                    cout << x << ", " << y << ", " << z << endl;
                    return true;
                }
            } else if (z > 4 - y) {
                if (explore(z - (4 - y), 4)) {
                    cout << x << ", " << y << ", " << z << endl;
                    return true;
                }
            }
        }
    }
    if (z < 10) {
        if (x > 0) {
            // Pour x into z
            if (x <= 10 - z) {
                if (explore(0, y)) {
                    cout << x << ", " << y << ", " << z << endl;
                    return true;
                }
            } else if (x > 10 - z) {
                if (explore(x - (10 - z), y)) {
                    cout << x << ", " << y << ", " << z << endl;
                    return true;
                }
            }
        }
        if (y > 0) {
            // Pour y into z
            if (y <= 10 - z) {
                if (explore(x, 0)) {
                    cout << x << ", " << y << ", " << z << endl;
                    return true;
                }
            } else if (y > 10 - z) {
                if (explore(x, y - (10 - z))) {
                    cout << x << ", " << y << ", " << z << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    visited = new bool * [8];
    for (int i = 0; i < 8; i++) {
        visited[i] = new bool [5];
        for (int j = 0; j < 5; j++) {
            visited[i][j] = false;
        }
    }
    explore(7,4);
    cout << "7-jar, 4-jar, 10-jar" << endl;

    return 0;
}
