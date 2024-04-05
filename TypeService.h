#pragma once
#include "FieldInfo.h"
#include "Complex.h"

void sumInt(const void* a, const void* b, void* res);
void multiplyInt(const void* a, const void* b, void* res);
void getIntValue(void* value);
void printInt(void* value);


void sumFloat(const void* a, const void* b, void* res);
void multiplyFloat(const void* a, const void* b, void* res;
void getFloatValue(void* value);
void printFloat(void* value);


void sumDouble(const void* a, const void* b, void* res);
void multiplyDouble(const void* a, const void* b, void* res);
void getDoubleValue(void* value);
void printDouble(void* value);


void sumComplex(const void* a, const void* b, void* res);
void multiplyComplex(const void* a, const void* b, void* res);
void getComplexValue(void* value);
void printComplex(void* value);

static const FieldInfo intOperationsService = {&sumInt, &multiplyInt, &getIntValue, &printInt, sizeof(int)};
static const FieldInfo floatOperationsService = {&sumFloat, &multiplyFloat, &getFloatValue, &printFloat, sizeof(float)};
static const FieldInfo doubleOperationsService = {&sumDouble, &multiplyDouble, &getDoubleValue, &printDouble, sizeof(double)};
static const FieldInfo complexOperationsService = {&sumComplex, &multiplyComplex, &getComplexValue, &printComplex, sizeof(Complex)};
