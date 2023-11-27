#include <stdio.h>

#define MAX_STUDENTS 50
#define MAX_GRADES 10  

int main() {
    int numStudents, numSubjects, i, j;

    printf("Nhap so luong sinh vien trong lop: ");
    scanf("%d", &numStudents);

    printf("Nhap so luong mon hoc: ");
    scanf("%d", &numSubjects);

    float grades[MAX_STUDENTS][MAX_GRADES];

    for (i = 0; i < numStudents; i++) {
        printf("\nSinh vien %d:\n", i + 1);
        float total = 0;

        for (j = 0; j < numSubjects; j++) {
            printf("Nhap diem mon hoc %d: ", j + 1);
            scanf("%f", &grades[i][j]);
            total += grades[i][j];
        }

        float average = total / numSubjects;
        printf("Diem trung binh cua sinh vien %d la: %.2f\n", i + 1, average);
    }

    float classTotal = 0;

    for (i = 0; i < numStudents; i++) {
        float total = 0;

        for (j = 0; j < numSubjects; j++) {
            total += grades[i][j];
        }

        classTotal += total / numSubjects;
    }

    float classAverage = classTotal / numStudents;
    printf("\nDiem trung binh cua ca lop la: %.2f\n", classAverage);

    return 0;
}
