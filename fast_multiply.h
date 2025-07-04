#pragma once

#include "matrix.h"

// Варианты:
// - изменить обход, для чтения матрицы последовательно
// - кэширование
// 

inline matrix fast_multiply(matrix const &a, matrix const &b) {
    auto [a_cols, a_rows] = a.size();
    auto [b_cols, b_rows] = b.size();
    matrix result(a_rows, b_cols, true);
    for (size_t i = 0; i < a_rows; ++i) {
        for (size_t k = 0; k < b_rows; ++k) {
            float val = a[i][k]; // кэширование a[i][k]
            for (size_t j = 0; j < b_cols; ++j) { // изменение обхода i-k-j вместо i-j-k
                result[i][j] += val * b[k][j];
            }
        }
    }
    return result;
}