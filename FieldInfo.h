#pragma once

typedef struct {
    void (*sum)(const void* a, const void* b, void* c);
    void (*multiply)(const void* a, const void* b, void* c);
    void (*getValue) (void* a);
    void (*print) (void* a);
    int elementSize;
} FieldInfo;

