#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool noilien(bool p, bool q){
    return p && q;
}
bool keotheo(bool p, bool q){
    return !p || q;
}
string center(string s, int w){
    int len = s.length();
    int left = (w - len)/2;
    int right = w - len - left;
    return string(left, ' ') + s + string(right, ' ');
}

void line(){
    cout << "+-----+-----+-----+-------+----------+\n";
}
void hangDung(){
    cout << "BANG CHAN TRI\n";
    cout << "p\tq\tk\tGiaTri\n";

    bool hangDung = true;

    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
        for (int k = 0; k<= 1; k++) {
            bool p = (i == 1);
            bool q = (j == 1);
            bool r = (k ==1 );
            bool ketQua = noilien(keotheo(p, q), r);
            cout << i << "\t" << j << "\t" << k << "\t" << ketQua << endl;

            if (!ketQua)
                hangDung = false;
        }
    }
}
    cout << endl;
    if (hangDung)
       cout << "Bieu thuc la hang dung." << endl;
    else
        cout << "Bieu thuc khong phai hang dung." << endl;
}
int main(){
    int n = 3;
    int rows = 1<<n; 
    vector<vector<bool>> matrix(n, vector<bool>(rows));
    // sinh bảng chân trị
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < n; j++) {
            matrix[j][i] = (i >> (n - j - 1)) & 1;
        }
    }

    line();
    cout << "|"
         << center("p",5) << "|"
         << center("q",5) << "|"
         << center("r",5) << "|"
         << center("p->q",7) << "|"
         << center("(p->q)^r",10) << "|\n";
    line();

    for (int i = rows - 1; i >= 0; i--) {
        bool p = matrix[0][i];
        bool q = matrix[1][i];
        bool r = matrix[2][i];

        cout << "|"
             << center(to_string(p),5) << "|"
             << center(to_string(q),5) << "|"
             << center(to_string(r),5) << "|"
             << center(to_string(keotheo(p,q)),7) << "|"
             << center(to_string(noilien(keotheo(p,q), r)),10) << "|\n";
    }

    line();
    hangDung();
    return 0;
}