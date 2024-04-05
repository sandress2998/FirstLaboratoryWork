#pragma once
#include "FieldInfo.h"
#include "Complex.h"

void sumInt(const void*, const void*, void*);
void multiplyInt(const void*, const void*, void*);
void getIntValue(void*);
void printInt(void*);

void sumFloat(const void*, const void*, void*);
void multiplyFloat(const void*, const void*, void*);
void getFloatValue(void*);
void printFloat(void*);

void sumDouble(const void*, const void*, void*);
void multiplyDouble(const void*, const void*, void*);
void getDoubleValue(void*);
void printDouble(void*);

void sumComplex(const void*, const void*, void*);
void multiplyComplex(const void*, const void*, void*);
void getComplexValue(void*);
void printComplex(void*);

static const FieldInfo intOperationsService = {&sumInt, &multiplyInt, &getIntValue, &printInt, sizeof(int)};
static const FieldInfo floatOperationsService = {&sumFloat, &multiplyFloat, &getFloatValue, &printFloat, sizeof(float)};
static const FieldInfo doubleOperationsService = {&sumDouble, &multiplyDouble, &getDoubleValue, &printDouble, sizeof(double)};
static const FieldInfo complexOperationsService = {&sumComplex, &multiplyComplex, &getComplexValue, &printComplex, sizeof(Complex)};
