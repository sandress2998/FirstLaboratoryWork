#pragma once
#include "FieldInfo.h"

FieldInfo* setIntOperationsService();
FieldInfo* setFloatOperationsService();
FieldInfo* setDoubleOperationsService();
FieldInfo* setComplexOperationsService();


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
