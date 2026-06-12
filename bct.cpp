#include <iostream>
#include <vector>
#include <string>
using namespace std;

string center(string s, int w) {
    int len = s.length();
    int left = (w - len) / 2;
    int right = w - len - left;
    return string(left, ' ') + s + string(right, ' ');
}

void line(int n) {
    for (int i = 0; i < n; i++)
        cout << "+-----";
    cout << "+------------+\n";
}

bool phepVa(bool x, bool y) {
    return x && y;
}

bool phepHoac(bool x, bool y) {
    return x || y;
}

bool phepPhuDinh(bool x) {
    return !x;
}

bool phepKeoTheo(bool x, bool y) {
    return phepHoac(phepPhuDinh(x), y);
}

bool phepTuongDuong(bool x, bool y) {
    return phepKeoTheo(x, y) && phepKeoTheo(y, x);
}

// (p -> q) ^ p
bool bieuThuc(bool p, bool q) {
    return phepVa(phepKeoTheo(p, q), p);
}

int main() {

    int n = 4;
    int rows = 1 << n;

    vector<vector<bool>> matrix(n, vector<bool>(rows));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < n; j++) {
            matrix[j][i] = (i >> (n - j - 1)) & 1;
        }
    }

    bool hangDung = true;

    cout << "\nBANG CHAN TRI\n";

    line(n);

    cout << "|";
    for (int i = 0; i < n; i++) {
        string var(1, 'p' + i);
        cout << center(var, 5) << "|";
    }
    cout << center("(p->q)^p", 12) << "|\n";

    line(n);

    for (int i = rows - 1; i >= 0; i--) {

        bool p = matrix[0][i];
        bool q = matrix[1][i];

        bool result = bieuThuc(p, q);

        cout << "|";

        for (int j = 0; j < n; j++) {
            cout << center(to_string(matrix[j][i]), 5) << "|";
        }

        cout << center(to_string(result), 12) << "|\n";

        if (!result)
            hangDung = false;
    }

    line(n);

    if (hangDung)
        cout << "\nBieu thuc la hang dung.\n";
    else
        cout << "\nBieu thuc khong phai hang dung.\n";

    return 0;
}