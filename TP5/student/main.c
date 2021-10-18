#include "student.h"
#include <stdio.h>

int main(void){
    Student *s;
    s=student_create();
    student_print(s);
    student_free(s);
}