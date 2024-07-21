/* Create a 'MATRIX' class of size m X n. Overload the ‘+’ operator to
Add Two MATRIX objects. Write a main function to implement it. */

#include <iostream>
using namespace std;

    class MATRIX {
    private:
        int m; 
        int n; 
        int** mat;

    public:
        MATRIX(int rows, int cols) : m(rows), n(cols) {
            mat = new int*[m];
            for (int i = 0; i < m; ++i) {
                mat[i] = new int[n];
                for (int j = 0; j < n; ++j) {
                    mat[i][j] = 0; 
                }
            }
        }

        ~MATRIX() {
            for (int i = 0; i < m; ++i) {
                delete[] mat[i];
            }
            delete[] mat;
        }

        void set(int i, int j, int value) {
            mat[i][j] = value;
        }

        MATRIX operator+(const MATRIX& other) const {
            if (!dimensionsMatch(other)) {
                cerr << "Error: Matrix dimensions must match for addition." << endl;
                exit(1); 
            }

            MATRIX result(m, n); 

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    result.mat[i][j] = mat[i][j] + other.mat[i][j];
                }
            }

            return result;
        }


        void display() const {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    cout << mat[i][j] << " ";
                }
                cout << endl;
            }
        }

        void inputMatrix() {
            cout << "Enter elements of the matrix:" << endl;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    cout << "Enter element at (" << i << ", " << j << "): ";
                    cin >> mat[i][j];
                }
            }
        }

        bool dimensionsMatch(const MATRIX& other) const {
            return (m == other.m && n == other.n);
        }
    };

int main() {
    int m, n;
    
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;

    MATRIX mat1(m, n); 
    MATRIX mat2(m, n); 

    cout << "Matrix 1:" << endl;
    mat1.inputMatrix();

    cout << "Matrix 2:" << endl;
    mat2.inputMatrix();

    MATRIX result = mat1 + mat2;

    cout << "Sum 2:" << endl;
    result.display();
    cout << endl;

    return 0;

}