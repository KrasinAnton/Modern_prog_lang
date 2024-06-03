#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#define N 5

// Функция для печати матрицы
void printMatrix(float m[][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cout << std::setw(8) << std::setprecision(5) << m[i][j];
        }
        std::cout << std::endl;
    }
}

// Функция для нахождения минимума матрицы
float matrixMin(float m[][N]) {
    float min = m[0][0];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (m[i][j] < min) {
                min = m[i][j];
            }
        }
    }
    return min;
}

// Функция для нахождения максимума матрицы
float matrixMax(float m[][N]) {
    float max = m[0][0];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (m[i][j] > max) {
                max = m[i][j];
            }
        }
    }
    return max;
}

// Функция для нахождения максимума в нижнетреугольной части матрицы
float lowerTriangleMax(float m[][N]) {
    float max = m[1][0]; // Начинаем сравнение с элемента m[1][0], так как в нижнетреугольной части элементы выше главной диагонали равны 0
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if (m[i][j] > max) {
                max = m[i][j];
            }
        }
    }
    return max;
}

// Функция для нахождения минимума в нижнетреугольной части матрицы
float lowerTriangleMin(float m[][N]) {
    float min = m[1][0]; // Начинаем сравнение с элемента m[1][0], так как в нижнетреугольной части элементы выше главной диагонали равны 0
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if (m[i][j] < min) {
                min = m[i][j];
            }
        }
    }
    return min;
}

// Функция для нахождения максимума в верхнетреугольной части матрицы
float upperTriangleMax(float m[][N]) {
    float max = m[0][1]; // Начинаем сравнение с элемента m[0][1], так как в верхнетреугольной части элементы ниже главной диагонали равны 0
    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            if (m[i][j] > max) {
                max = m[i][j];
            }
        }
    }
    return max;
}

// Функция для нахождения минимума в верхнетреугольной части матрицы
float upperTriangleMin(float m[][N]) {
    float min = m[0][1]; // Начинаем сравнение с элемента m[0][1], так как в верхнетреугольной части элементы ниже главной диагонали равны 0
    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            if (m[i][j] < min) {
                min = m[i][j];
            }
        }
    }
    return min;
}

// Функция для нахождения минимума главной диагонали матрицы
float mainDiagonalMin(float m[][N]) {
    float min = m[0][0]; // Начинаем сравнение с элемента m[0][0], который принадлежит главной диагонали
    for(int i = 1; i < N; i++) {
        if (m[i][i] < min) {
            min = m[i][i];
        }
    }
    return min;
}

// Функция для нахождения максимума главной диагонали матрицы
float mainDiagonalMax(float m[][N]) {
    float max = m[0][0]; // Начинаем сравнение с элемента m[0][0], который принадлежит главной диагонали
    for(int i = 1; i < N; i++) {
        if (m[i][i] > max) {
            max = m[i][i];
        }
    }
    return max;
}

// Функция для нахождения минимума второстепенной диагонали матрицы
float secondaryDiagonalMin(float m[][N]) {
    float min = m[0][N - 1]; // Начинаем сравнение с элемента m[0][N - 1], который принадлежит второстепенной диагонали
    for(int i = 1; i < N; i++) {
        if (m[i][N - 1 - i] < min) {
            min = m[i][N - 1 - i];
        }
    }
    return min;
}

// Функция для нахождения максимума второстепенной диагонали матрицы
float secondaryDiagonalMax(float m[][N]) {
    float max = m[0][N - 1]; // Начинаем сравнение с элемента m[0][N - 1], который принадлежит второстепенной диагонали
    for(int i = 1; i < N; i++) {
        if (m[i][N - 1 - i] > max) {
            max = m[i][N - 1 - i];
        }
    }
    return max;
}

// Функция для вычисления среднего арифметического значения элементов матрицы
float average(float m[][N]) {
    float sum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            sum += m[i][j];
        }
    }
    return sum / (N * N);
}

// Функция для вычисления среднего арифметического значения части матрицы
float averagePart(float m[][N], int startRow, int endRow, int startCol, int endCol) {
    float sum = 0;
    int count = 0;
    for(int i = startRow; i <= endRow; i++) {
        for(int j = startCol; j <= endCol; j++) {
            sum += m[i][j];
            count++;
        }
    }
    return sum / count;
}

// Функция для вычисления суммы элементов в строке матрицы
float rowSum(float m[][N], int row) {
    float sum = 0;
    for (int j = 0; j < N; j++) {
        sum += m[row][j];
    }
    return sum;
}

// Функция для вычисления суммы элементов в столбце матрицы
float colSum(float m[][N], int col) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        sum += m[i][col];
    }
    return sum;
}

// Функция для нахождения минимального значения в строке матрицы
float minRowValue(float m[][N], int row) {
    float min = m[row][0];
    for (int j = 1; j < N; j++) {
        if (m[row][j] < min) {
            min = m[row][j];
        }
    }
    return min;
}

// Функция для нахождения минимального значения в столбце матрицы
float minColValue(float m[][N], int col) {
    float min = m[0][col];
    for (int i = 1; i < N; i++) {
        if (m[i][col] < min) {
            min = m[i][col];
        }
    }
    return min;
}

// Функция для нахождения максимального значения в строке матрицы
float maxRowValue(float m[][N], int row) {
    float max = m[row][0];
    for (int j = 1; j < N; j++) {
        if (m[row][j] > max) {
            max = m[row][j];
        }
    }
    return max;
}

// Функция для нахождения максимального значения в столбце матрицы
float maxColValue(float m[][N], int col) {
    float max = m[0][col];
    for (int i = 1; i < N; i++) {
        if (m[i][col] > max) {
            max = m[i][col];
        }
    }
    return max;
}

// Функция для вычисления среднего арифметического значения элементов в строке матрицы
float averageRowValue(float m[][N], int row) {
    float sum = rowSum(m, row);
    return sum / N;
}

// Функция для вычисления среднего арифметического значения элементов в столбце матрицы
float averageColValue(float m[][N], int col) {
    float sum = colSum(m, col);
    return sum / N;
}

// Функция для вычисления суммы элементов в нижнетреугольной части матрицы
float sumLowerTriangle(float m[][N]) {
    float sum = 0;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            sum += m[i][j];
        }
    }
    return sum;
}

// Функция для вычисления суммы элементов в верхнетреугольной части матрицы
float sumUpperTriangle(float m[][N]) {
    float sum = 0;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            sum += m[i][j];
        }
    }
    return sum;
}

// Функция для нахождения элемента матрицы, наиболее близкого к среднему арифметическому значению
float closestToAverage(float m[][N], float average) {
    float closest = m[0][0];
    float minDiff = std::abs(m[0][0] - average);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            float diff = std::abs(m[i][j] - average);
            if (diff < minDiff) {
                closest = m[i][j];
                minDiff = diff;
            }
        }
    }
    return closest;
}

int main() {
    float m[N][N];
    srand(time(NULL));

    // Заполнение матрицы случайными значениями
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            m[i][j] = rand() / 10.0;
        }
    }

    std::cout << "Матрица:" << std::endl;
    printMatrix(m);

    // Проверка работы функций
    std::cout << "Минимум матрицы: " << matrixMin(m) << std::endl;
    std::cout << "Максимум матрицы: " << matrixMax(m) << std::endl;
    std::cout << "Максимум нижнетреугольной части матрицы: " << lowerTriangleMax(m) << std::endl;
    std::cout << "Максимум верхнетреугольной части матрицы: " << upperTriangleMax(m) << std::endl;
    std::cout << "Минимум нижнетреугольной части матрицы: " << lowerTriangleMin(m) << std::endl;
    std::cout << "Минимум верхнетреугольной части матрицы: " << upperTriangleMin(m) << std::endl;
    std::cout << "Минимум главной диагонали матрицы: " << mainDiagonalMin(m) << std::endl;
    std::cout << "Максимум главной диагонали матрицы: " << mainDiagonalMax(m) << std::endl;
    std::cout << "Минимум второстепенной диагонали матрицы: " << secondaryDiagonalMin(m) << std::endl;
    std::cout << "Максимум второстепенной диагонали матрицы: " << secondaryDiagonalMax(m) << std::endl;
    std::cout << "Среднее арифметическое значение элементов матрицы: " << average(m) << std::endl;
    
    // Пример вызова функции для части матрицы (среднее арифметическое)
    int startRow = 0, endRow = N / 2, startCol = 0, endCol = N / 2;
    std::cout << "Среднее арифметическое значение части матрицы: " << averagePart(m, startRow, endRow, startCol, endCol) << std::endl;

    return 0;
}
