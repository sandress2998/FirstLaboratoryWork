#pragma once

#include "FieldInfo.h"

// Помещаем Vector в отдельный файл, т.к. его определение используется в двух .c файлах - TestVectorFunctions.c, VectorFunctions.c

typedef struct Vector {

    int size;

    FieldInfo* fieldInfo; // указатель на сервис, обрабатывающий функции типов.

    void* pointer; // указатель на первый элемент вектора

} Vector;
