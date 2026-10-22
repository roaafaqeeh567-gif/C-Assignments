/*
=======================================================================
Name       : Ro'A Faqih
ID         : 1250139
Course     : Computer and Programming (COMP133)
Phase      : 1 - Menu Structure, Functions, Arrays and Data Management.
Description: Student Record Management System using Parallel Arrays.
=======================================================================
*/
#include <stdio.h>
#include <string.h>

                // (Global Variables)تعريف المصفوفات المتوازية كمتغيرات عامة
int studentsIDs[100];
int studentNames[100][50];
int ages[100];
double gpas[100];
int studentCount = 0; // عدد الطلاب الحاليين في النظام

                      // (Function Prototypes)الإعلان المسبق عن الدوال
void displayMainMenu();
void initializeStudentRecords();
void saveStudentRecords();
void addStudent();
void removeStudent();
void searchStudent();
void displayAllStudents();

int main()
{
   int choice;

   initializeStudentRecords();                      // استدعاء دالة التحميل عند تشغيل البرنامج أول مرة
   do {                                             //5 حلقة الدوران الأساسية التي تبقي البرنامج يعمل حتى يختار المستخدم
       displayMainMenu();
       printf("Enter your choice (1-5): ");

   if (scanf("%d", &choice) != 1){                  //التحقق من أن المدخل رقم صحيح لمنع الحلقات اللانهائية عند إدخال حروف
       printf("Invalid choice. Please enter 1-5\n");
       while (getchar() != '\n');                   //(Buffer)تنظيف الذاكرة المؤقتة
       continue;
   }

       getchar();                                   //  المتبقية في الذاكرة المؤقتةEnterحذف كبسة ال ال

       switch(choice){                              // توجيه الاختيار إلى الدالة المناسبة
         case 1:
           addStudent();
           break;
         case 2:
           removeStudent();
           break;
         case 3:
           searchStudent();
           break;
         case 4:
           displayAllStudents();
           break;
         case 5:
           saveStudentRecords();
           printf("Exiting System. Goodbye!\n");
           break;
         default:
            printf("Invalid choice. Please enter 1-5\n");
       }
       }while (choice != 5);

       return 0;
}
void displayMainMenu(){                                   //1. دالة طباعة القائمة الرئيسية
    printf("\n=== STUDENT RECORD MANAGMENT SYSTEM ===\n");
    printf("1- Add New Student\n");
    printf("2- Remove Student\n");
    printf("3- Search for Student\n");
    printf("4- Display All Students\n");
    printf("5- Exit System\n");
}
void initializeStudentRecords(){                         //2. دالة تحميل السجلات
    printf("Student records loaded successfully.\n");
}
void addStudent(){                                       // 3. دالة إضافة طالب جديد مع التحقق الصارم من المدخلات
    if(studentCount>=100){
        printf("Error:System is full Cannot add more students.\n");
        return;
    }
    printf("\n=== ADD NEW STUDENT ===\n");
    int id;
    int validID = 0;
    do{
       printf("Enter 4-digit Student ID(1000-9999):");
           if (scanf("%d", &id) != 1){
               printf("Invalid ID. It should be 4 digits.\n");
           }          while(getchar() != '\n');
                      continue;

           getchar();
           if (id < 1000 || id > 9999){
               printf("Invalid ID. It should be 4 digits.\n");
               continue;
           }
           int duplicate = 0;                      // فحص التكرار
           for (int i = 0; i < studentCount; i++){
                if (studentsIDs[i] == id){
                    duplicate = 1;
                    break;
                }
           }
           if (duplicate == 1){
               printf("Error: Student ID already exists. Try a different ID.\n");
           }
           else{
             validID = 1;
           }
          while (!validID);

          char name[50];
          int validName = 0;
    }
          do{
             printf("Enter Student name: ");
             fgets(name, sizeof(name), stdin);

             int len = strlen(name);
             if (len >0 && name[len - 1] == '\n'){
                  name[len - 1] = '\0'; // استبدال السطر الجديد بنهاية النص الفارغة
             }
          }
             if(strlen(name)== 0){
                printf("Invalid Name. Name cannot be empty.\n");
             }
             else{
                validName = 1;
             }
             while (!validName);
             int age;
             int validAge = 0;
             do{                        // التحقق من العمر
                 printf("Enter Student Age:");
                 if (scanf("%d", &age) != 1){
                     printf("Invalid input. Please enter a number.\n");
                     while (getchar() != '\n');
                     continue;
                 }
                  getchar();
                  if (age < 6 || age > 50){
                      printf("Invalid Age. It must be between 6 and 50.\n");
                  }
                  else{
                     vaildAge = 1;
                  }
             } while (!validAge);
             double gpa;
             int validGPA = 0;
             do{
                printf("Enter GPA:");
                if (scanf("%lf", &gpa) != 1)
                     printf("Invalid input. please enter a decimal number.\n");
                     while(getchar() != '\n');
                     continue;
}
                getchar();

                if (gpa < 0.0 || gpa > 4.0){
                    printf("Invalid GPA. It must be between 0.0 and 4.0.\n");
                }
                else{
                     validGPA = 1 ;
                }
               } while (!validGPA);
                                          //تخزين البيانات في المصفوفات بعد نجاح الفحص
                studentIDs[studentCount] = id;

                strcpy(studentNames[studentcount], name);
                 ages[studentCount] = age;
                 gpas[studentCount] = gpa;

                 studentCount++;         // زيادة العداد

                 printf("Student added successfully!\n");
                 }
                  }
                                             // 4. دالة حذف طالب وعمل إزاحة للعناصر
                  void removeStudent(){
                     if (studentCount == 0){
                        printf("No students in the system to remove.\n");
                        return;
                     }
                   printf("\n=== REMOVE STUDENT ===\n");
                   int id;
                   printf("Enter Student ID to remove:");

                   if(scanf("%d", &id) != 1){
                      printf("Invalid input.\n");
                      while (getchar()!= '\n');
                      return;
                   }

                   getchar;

                   int foundIndex = -1;
                   for (int i = 0; i < studentCount; i++){
                        if(studentIDs[i] == id){
                           foundIndex = i;
                           break;
                        }
                   }

                   if (foundIndex != -1) {
        printf("Student Found:\n");
        printf("Student ID: %d\n", studentIDs[foundIndex]);
        printf("Student Name: %s\n", studentNames[foundIndex]);
        printf("Student Age: %d\n", ages[foundIndex]);
        printf("GPA: %.2f\n", gpas[foundIndex]);
    } else {
        printf("Student not found.\n");
    }
}

// 6. دالة عرض كل الطلاب في جدول منسق وحساب المتوسط الحسابي
void displayAllStudents() {
    if (studentCount == 0) {
        printf("No students in the system.\n");
        return;
    }

    printf("\n=== ALL STUDENTS ===\n");
    printf("%-8s %-15s %-6s %-4s\n", "ID", "Name", "Age", "GPA");
    printf("----------------------------------\n");

    double totalGPA = 0.0;
    for (int i = 0; i < studentCount; i++) {
        printf("%-8d %-15s %-6d %.2f\n", studentIDs[i], studentNames[i], ages[i], gpas[i]);
        totalGPA += gpas[i];
    }

    printf("----------------------------------\n");
    double averageGPA = totalGPA / studentCount;

    printf("Total Students: %d\n", studentCount);
    printf("Average GPA: %.2f\n", averageGPA);
}

// 7. دالة حفظ السجلات الوهمية
void saveStudentRecords() {
    printf("All student records saved to file.\n");
}

