#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> inputMatrix(int rows, int cols) {
    vector<vector<double>> matrix(rows, vector<double>(cols));
    for (int i = 0; i < rows; ++i) {
        cout << "Введите " << cols << " элементов для строки " << i + 1 << ":" << endl;
        for (int j = 0; j < cols; ++j) {
            while (true) {
                cout << "Элемент " << j + 1 << ": ";
                if (cin >> matrix[i][j]) {
                    break;
                } else {
                    cout << "Пожалуйста, введите число." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }
    }
    return matrix;
}

vector<double> averageOfRows(const vector<vector<double>>& matrix) {
    vector<double> averages;
    for (const auto& row : matrix) {
        double sum = 0;
        for (double element : row) {
            sum += element;
        }
        averages.push_back(sum / row.size());
    }
    return averages;
}

int main() {
    int rows = 3;
    int cols = 5;
    vector<vector<double>> matrix = inputMatrix(rows, cols);
    vector<double> rowAverages = averageOfRows(matrix);

    cout << "Средние арифметические элементов строк:" << endl;
    for (size_t i = 0; i < rowAverages.size(); ++i) {
        cout << "Строка " << i + 1 << ": " << rowAverages[i] << endl;
    }

    return 0;
}

