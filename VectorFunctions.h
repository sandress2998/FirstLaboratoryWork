#pragma once

typedef struct Vector Vector;


Vector* buildVector(int size, void (*setVectorInfo) (Vector* vectorPtr));
void initializeVector(Vector* vectorPtr); /* ��������� �������� ������������ ������� � buildVector
�� ��� ��������� ����������� ������, ���������� ��������*/


void setVectorIntInfo(Vector* vectorPtr);
void setVectorFloatInfo(Vector* vectorPtr);
void setVectorDoubleInfo(Vector* vectorPtr);
void setVectorComplexInfo(Vector* vectorPtr);

void sumVectors(const Vector* firstVectorPtr, const Vector*  secondVectorPtr, Vector* resultVectorPtr);
void* scalarVectors(const Vector* firstVectorPtr, const Vector* secondVectorPtr, void* result);

// functions to support sumVector and scalarVector;
void setVectorValue(Vector* vectorPtr, int index, void* from);
void* getElementPtr(Vector* vectorPtr, int index);
int getVectorSize(Vector* vectorPtr);
void printVector(Vector* vectorPtr);
void printElement(Vector* vectorPtr, int index);
void deleteVector(Vector** vectorDoublePtr);


int areSizesEqual(Vector* firstVectorPtr, Vector* secondVectorPtr);
int areTypesEqual(Vector* firstVectorPtr, Vector* secondVectorPtr);


void equalSizesError();
void equalTypesError();
void correctSizeError();
void correctIndexError();
void emptyError();


void* safemalloc(int);
