#pragma once
#include "FieldInfo.h"

FieldInfo* setIntOperationsService();
FieldInfo* setFloatOperationsService();
FieldInfo* setDoubleOperationsService();
FieldInfo* setComplexOperationsService();


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
