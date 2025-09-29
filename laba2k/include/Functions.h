#include <iostream>
#include <limits>
#include "Matrix.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void clearInputBuffer();

void showMatrixInfo(const Matrix &matrix, const std::string &name);

void enterMatrices(Matrix &matrix1, Matrix &matrix2);

void addMatrices(const Matrix &matrix1, const Matrix &matrix2, Matrix &result);

void showResult(const Matrix &result);

#endif