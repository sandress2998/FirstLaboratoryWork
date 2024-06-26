#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#include "Complex.h"
#include "VectorFunctions.h"
#include "Vector.h"

/// the start point

Vector* buildVector(int size, FieldInfo* typeOperationsService) {
    if (size <= 0) correctSizeError();
    // create vector
    Vector* vector = (Vector*) safemalloc(sizeof(Vector));
    vector -> size = size;
    vector -> fieldInfo = typeOperationsService;
    vector -> pointer = safemalloc ((vector -> fieldInfo -> elementSize) * size);

    // initialize vector
    void* buf = safemalloc (vector -> fieldInfo -> elementSize);
    vector -> pointer = safemalloc ((vector -> fieldInfo -> elementSize) * (vector -> size));
    for(int i = 1; i <= (vector -> size); ++i) {
        vector -> fieldInfo -> getValue(buf);
        setElementValue(vector, i, buf);
    }
    free(buf);

    return vector;
}

/// Support vector functions

void* getElementPtr(Vector* vector, int index) {
    if (vector == NULL) emptyError();
    if (index > getVectorSize(vector) || index < 1) correctIndexError();

    void* p = vector -> pointer + (index - 1) * (vector -> fieldInfo -> elementSize);
    return p;
}

int getVectorSize(Vector* vector) {
    return vector -> size;
}

void setElementValue(Vector* vector, int index, void* value) {
    if (vector == NULL) emptyError();
    if (index > getVectorSize(vector) || index < 1) correctIndexError();

    memcpy(vector -> pointer + (index - 1) * vector -> fieldInfo -> elementSize, value, vector -> fieldInfo -> elementSize);
    return;
}

void copyValue(void* from, void* to, int bytesToCopy) {
    memcpy(to, from, bytesToCopy);
}

void printVector(Vector* vector) {
    if (vector == NULL) emptyError();
    printf("vector:\n(");
    printElement(vector, 1);
    for (int i = 2; i <= getVectorSize(vector); i++) {
        printf(", ");
        printElement(vector, i);
    }
    printf(")\n");
};

void printElement(Vector* vector, int index) {
    if (vector == NULL) emptyError();
    if (index < 1 || index > vector -> size) correctIndexError();
    vector -> fieldInfo -> print(getElementPtr(vector, index));
}


void deleteVector(Vector** vectorPtr) {
    if (*vectorPtr == NULL) {
        printf("Vector is already free.\n");
        return;
    }
    free((*vectorPtr) -> pointer); // free memory where vector elements is stored
    free(*vectorPtr); // free vector memory
    *vectorPtr = NULL; // now the pointer to vector is equal to NULL
}


/// Main vector functions

void sumVectors(const Vector* leftVector, const Vector* rightVector, Vector* result) {
    if (leftVector == NULL || rightVector == NULL) emptyError();
    if(!(areSizesEqual(leftVector, rightVector) && areSizesEqual(leftVector, rightVector))) equalSizesError();// проверка на одинаковый размер векторов
    if(!(areTypesEqual(leftVector, rightVector) && areTypesEqual(leftVector, rightVector))) equalTypesError();// проверка на одинаковый тип векторов

    for (int i = 1; i <= getVectorSize(leftVector); i++) {
       leftVector -> fieldInfo -> sum(getElementPtr(leftVector, i), getElementPtr(rightVector, i), getElementPtr(result, i));
    }
}

void* scalarVectors(const Vector* leftVector, const Vector* rightVector, void* result) {
    if (leftVector == NULL || rightVector == NULL) emptyError();
    if(!areSizesEqual(leftVector, rightVector)) equalSizesError();
    if(!areTypesEqual(leftVector, rightVector)) equalTypesError();

    int bytesToCopy = leftVector -> fieldInfo -> elementSize;
    void* sum = safemalloc(bytesToCopy);
    void* product = safemalloc(bytesToCopy);

    leftVector -> fieldInfo -> multiply(getElementPtr(leftVector, 1), getElementPtr(rightVector, 1), product);
    copyValue(product, sum, bytesToCopy);
    copyValue(product, result, bytesToCopy);

    for (int i = 2; i <= getVectorSize(leftVector); i++) {
       leftVector -> fieldInfo -> multiply(getElementPtr(leftVector, i), getElementPtr(rightVector, i), product);
       leftVector -> fieldInfo -> sum(result, product, sum);
       copyValue(sum, result, bytesToCopy);
    }
    //leftVector -> fieldInfo -> print(result); // to print the dotProduct
    free(sum);
    free(product);
    return result;
}

/// "Check" function

int areSizesEqual(Vector* vector1, Vector* vector2) {
    if (vector1 -> size == vector2 -> size) {
        return 1;
    };
    return 0;
}

int areTypesEqual(Vector* vector1, Vector* vector2) {
    if (vector1 -> fieldInfo == vector2 -> fieldInfo) {
        return 1;
    }
    return 0;
}


/// Errors

void correctSizeError() {
    printf("ERROR: Vector size should be positive.\n");
    exit(1);
}

void correctIndexError() {
    printf("ERROR: Vector index should be in the allowed range.\n");
    exit(1);
}

void equalTypesError() {
    printf("ERROR: Vector types don't match\n");
    exit(1);
}

void equalSizesError() {
    printf("ERROR: Vector sizes should be the same.\n");
    exit(1);
}

void emptyError() {
    printf("ERROR: Vector is empty.\n");
    exit(1);
}

/// safemalloc

void* safemalloc(int size) {
    void* p = malloc(size);
    assert(p != NULL);
    return p;
}
