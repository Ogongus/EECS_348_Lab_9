// main.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

using Matrix = vector<vector<int>>;

// Read matrices from file.
bool readMatrices(const string& filename, int& N, Matrix& A, Matrix& B) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Cannot open file" << filename << endl;
        return false;
    }

    file >> N;
    A.assign(N, vector<int>(N));
    B.assign(N, vector<int>(N));

    // Read matrix A.
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            file >> A[i][j];

    // Read matrix B.
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            file >> B[i][j];

    file.close();
    return true;
}

// Print matrix with aligned columns.
void printMatrix(const Matrix& M, const string& name) {
    cout << name << ":\n";
    for (const auto& row : M) {
        for (size_t j = 0; j < row.size(); ++j) {
            cout << setw(4) << row[j];
        }
        cout << endl;
    }
    cout << endl;
}