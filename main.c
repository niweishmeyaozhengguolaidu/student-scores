#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义学生结构体（每节车厢长什么样）
typedef struct Student {
    char name[50];
    float score;
    struct Student* next; // 挂钩，指向下一节车厢
} Student;

Student* head = NULL; // 火车头，一开始是空的

// 1. 新增学生（插入链表）
void addStudent() {
    Student* newStu = (Student*)malloc(sizeof(Student));
    printf("请输入学生姓名: ");
    scanf("%s", newStu->name);
    printf("请输入学生成绩: ");
    scanf("%f", &newStu->score);
    newStu->next = head;
    head = newStu;
    printf("添加成功！\n\n");
}

// 2. 删除学生
void deleteStudent() {
    char name[50];
    printf("请输入要删除的学生姓名: ");
    scanf("%s", name);
    Student *curr = head, *prev = NULL;
    while (curr != NULL && strcmp(curr->name, name) != 0) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("没找到这个学生。\n\n");
        return;
    }
    if (prev == NULL) head = curr->next;
    else prev->next = curr->next;
    free(curr);
    printf("删除成功！\n\n");
}

// 3. 查找学生
void searchStudent() {
    char name[50];
    printf("请输入要查找的姓名: ");
    scanf("%s", name);
    Student* curr = head;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            printf("找到了！姓名: %s, 成绩: %.2f\n\n", curr->name, curr->score);
            return;
        }
        curr = curr->next;
    }
    printf("没找到。\n\n");
}

// 4. 按分数排序（简单的冒泡排序）
void sortStudents() {
    if (head == NULL) return;
    int swapped;
    Student* ptr1;
    Student* lptr = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->score < ptr1->next->score) { // 降序
                float tempScore = ptr1->score;
                char tempName[50];
                strcpy(tempName, ptr1->name);
                
                ptr1->score = ptr1->next->score;
                strcpy(ptr1->name, ptr1->next->name);
                
                ptr1->next->score = tempScore;
                strcpy(ptr1->next->name, tempName);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    printf("排序完成！\n\n");
}

// 5. 算平均分
void averageScore() {
    Student* curr = head;
    float sum = 0;
    int count = 0;
    while (curr != NULL) {
        sum += curr->score;
        count++;
        curr = curr->next;
    }
    if (count > 0) printf("平均分: %.2f\n\n", sum / count);
    else printf("目前没有学生。\n\n");
}

// 6. 展示所有学生
void display() {
    Student* curr = head;
    if (curr == NULL) {
        printf("暂无数据。\n\n");
        return;
    }
    printf("--- 学生列表 ---\n");
    while (curr != NULL) {
        printf("姓名: %s, 成绩: %.2f\n", curr->name, curr->score);
        curr = curr->next;
    }
    printf("----------------\n\n");
}

int main() {
    int choice;
    while (1) {
        printf("====== 学生成绩管理系统 ======\n");
        printf("1. 新增学生\n2. 删除学生\n3. 查找学生\n4. 按分数排序\n5. 算平均分\n6. 查看所有\n0. 退出\n");
        printf("请选择: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: searchStudent(); break;
            case 4: sortStudents(); break;
            case 5: averageScore(); break;
            case 6: display(); break;
            case 0: printf("再见！\n"); return 0;
            default: printf("输入错误。\n\n");
        }
    }
    return 0;
}
