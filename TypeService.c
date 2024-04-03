#include "Complex.h"
#include "FieldInfo.h"
#include "TypeService.h"

// перенести функции typeFunctions (implementation)
static const FieldInfo intOperationsService = {&sumInt, &multiplyInt, &getIntValue, &printInt, sizeof(int)};
static const FieldInfo floatOperationsService = {&sumFloat, &multiplyFloat, &getFloatValue, &printFloat, sizeof(float)};
static const FieldInfo doubleOperationsService = {&sumDouble, &multiplyDouble, &getDoubleValue, &printDouble, sizeof(double)};
static const FieldInfo complexOperationsService = {&sumComplex, &multiplyComplex, &getComplexValue, &printComplex, sizeof(Complex)};


// добавить const
FieldInfo* setIntOperationsService() { return &intOperationsService; };
FieldInfo* setFloatOperationsService() { return &floatOperationsService; };
FieldInfo* setDoubleOperationsService() { return &doubleOperationsService; };
FieldInfo* setComplexOperationsService() { return &complexOperationsService; };


/// Definition (Implementation)

// INT

void sumInt(const void* a, const void* b, void* c) {
    *(int*)c = (*((const int*)a))+(*((const int*)b));
}

void multiplyInt(const void* a, const void* b, void* c) {
    *(int*)c = *((const int*) a) * *((const int*) b);
}

void getIntValue(void* a) {
    scanf("%d", (int*)a);
}
void printInt(void* a) {
    printf("%d", *(int*)a);
}


// FLOAT

void sumFloat(const void* a, const void* b, void* c) {
    *(float*)c = (*((const float*) a)) + *((const float*) b);
}

void multiplyFloat(const void* a, const void* b, void* c) {
    *(float*)c = *((const float*) a) * *((const float*) b);
}

void getFloatValue(void* a) {
    scanf("%f", (float*)a);
}

void printFloat(void* a) {
    printf("%.2f", *(float*)a);
}

// DOUBLE

void sumDouble(const void* a, const void* b, void* c) {
    *(double*)c = *((const double*) a) + *((const double*) b);
}

void multiplyDouble(const void* a, const void* b, void* c) {
    *(double*)c = *((const double*) a) * *((const double*) b);
}

void getDoubleValue(void* a) {
    scanf("%lf", (double*)a);
}

void printDouble(void* a) {
    printf("%.2f", *(double*)a);
}

// COMPLEX

void sumComplex(const void* a, const void* b, void* c) {
    ((Complex*)c) -> x = (((const Complex*) a) -> x) + (((const Complex*) b) -> x);
    ((Complex*)c) -> y = (((const Complex*) a) -> y) + (((const Complex*) b) -> y);
}

void multiplyComplex(const void* a, const void* b, void* c) {
    ((Complex*)c) -> x = (((const Complex*) a) -> x) * (((const Complex*) b) -> x) - (((const Complex*) a) -> y) * (((const Complex*) b) -> y);
    ((Complex*)c) -> y = (((const Complex*) a) -> x) * (((const Complex*) b) -> y) + (((const Complex*) a) -> y) * (((const Complex*) b) -> x);
}

void getComplexValue(void* a) {
    scanf("%lf", &(((Complex*)a) -> x));
    scanf("%lf", &(((Complex*)a) -> y));
}

void printComplex(void* a) {
    printf("(%.2f; %.2f)", ((Complex*)a) -> x, ((Complex*)a) -> y);
}
