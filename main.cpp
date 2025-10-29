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

// Add two matrices.
Matrix addMatrices(const Matrix& A, const Matrix& B) {
    int N = A.size();
    Matrix C(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Multiply two matrices.
Matrix multiplyMatrices(const Matrix& A, const Matrix& B) {
    int N = A.size();
    Matrix C(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

// Sum of main and secondary diagonal.
pair<int, int> diagonalSums(const Matrix& M) {
    int N = M.size();
    int mainDiag = 0, antiDiag = 0;
    for (int i = 0; i < N; ++i) {
        mainDiag += M[i][i];
        antiDiag += M[i][N - 1 - i];
    }
    return {mainDiag, antiDiag};
}

// Swap two rows.
bool swapRows(Matrix& M, int r1, int r2) {
    int N = M.size();
    if (r1 < 0 || r1 >= N || r2 < 0 || r2 >= N || r1 == r2)
        return false;
    swap(M[r1], M[r2]);
    return true;
}

// Swap two columns
bool swapColumns(Matrix&M, int c1, int c2) {
    int N = M.size();
    if (c1 < 0 || c1 >= N || c2 < 0 || c2 >= N || c1 == c2)
        return false;
    for (int i = 0; i < N; ++i)
        swap(M[i][c1], M[i][c2])
    return true;
}

