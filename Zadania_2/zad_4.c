#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    float grade;
} Student;

void sortStudents(Student *students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (students[j].grade < students[j + 1].grade) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    Student students[100];
    for (int i = 0; i < 100; i++) {
        snprintf(students[i].name, 50, "Student%d", i + 1);
        students[i].grade = (float)(rand() % 101) / 10;
    }

    sortStudents(students, 100);

    for (int i = 0; i < 100; i++) {
        printf("Imię: %s, Ocena: %.2f\n", students[i].name, students[i].grade);
    }

    return 0;
}
