#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50

struct Student {
	int id;
    char name[MAX_NAME_LENGTH];
    int age;
    float GPA;
};

void displayStudent(struct Student s) {
    printf("ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("GPA: %.2f\n", s.GPA);
    printf("\n");
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;
    int i;
    int choice;

    do {
        printf("Menu:\n");
        printf("1. Them sinh vien\n");
        printf("2. Hien thi thong tin sinh vien\n");
        printf("3. Cap nhat thong tin sinh vien\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numStudents < MAX_STUDENTS) {
                    struct Student newStudent;
                    printf("Nhap ID: ");
                    scanf("%d", &newStudent.id);
                    printf("Nhap ten: ");
                    scanf("%s", newStudent.name);
                    printf("Nhap tuoi: ");
                    scanf("%d", &newStudent.age);
                    printf("Nhap GPA: ");
                    scanf("%f", &newStudent.GPA);

                    students[numStudents] = newStudent;
                    numStudents++;
                    printf("Sinh vien da duoc them!\n\n");
                } else {
                    printf("Danh sach sinh vien da day!\n\n");
                }
                break;
            case 2:
                if (numStudents > 0) {
                    printf("Danh sach sinh vien:\n");
                    for (i = 0; i < numStudents; i++) {
                        printf("Sinh vien %d:\n", i + 1);
                        displayStudent(students[i]);
                    }
                } else {
                    printf("Khong co sinh vien nao trong danh sach!\n\n");
                }
                break;
            case 3:
                if (numStudents > 0) {
                    int updateID;
                    printf("Nhap ID cua sinh vien can cap nhat: ");
                    scanf("%d", &updateID);

                    int found = 0;
                    for (i = 0; i < numStudents; i++) {
                        if (students[i].id == updateID) {
                            printf("Nhap thong tin cap nhat cho sinh vien:\n");
                            printf("Ten: ");
                            scanf("%s", students[i].name);
                            printf("Tuoi: ");
                            scanf("%d", &students[i].age);
                            printf("GPA: ");
                            scanf("%f", &students[i].GPA);
                            found = 1;
                            printf("Thong tin sinh vien da duoc cap nhat!\n\n");
                            break;
                        }
                    }
                    if (!found) {
                        printf("Khong tim thay sinh vien co ID tuong ung!\n\n");
                    }
                } else {
                    printf("Khong co sinh vien nao trong danh sach!\n\n");
                }
                break;
            case 0:
                printf("Thoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("Chuc nang khong hop le! Vui long chon lai.\n\n");
        }
    } while (choice != 0);

    return 0;
}
