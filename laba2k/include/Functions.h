#pragma once
#include "Matrix.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void clearInputBuffer();

void addMatrices(Matrix &matrix1, Matrix &matrix2, Matrix &result);

void showResult(const Matrix &result);

#endif