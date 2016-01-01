#include <stdio.h>
#include "myString.h"
#include <string.h>

int print(int correct, const char * message) {
    if(correct == 1) {
        printf("[RIGHT] %s\n", message);
    } else {
        printf("[WRONG] %s\n", message);
    }
    return correct;
}

int test_MyStrlen() {
    const char * s1 = "";
    const char * s2 = "abcde";
    const char * s3 = NULL;
    const char * s4 = "cdefg\0abcde";
    const char * s5 = "\0\0\0\0\0";
    int correctCount = 0;

    correctCount += myStrlen(s1) == 0 ? print(1, "Passed Case 1") : print(0, "Failed Case 1");
    correctCount += myStrlen(s2) == 5 ? print(1, "Passed Case 2") : print(0, "Failed Case 2");
    correctCount += myStrlen(s3) == 0 ? print(1, "Passed Case 3") : print(0, "Failed Case 3");
    correctCount += myStrlen(s4) == 5 ? print(1, "Passed Case 4") : print(0, "Failed Case 4");
    correctCount += myStrlen(s5) == 0 ? print(1, "Passed Case 5") : print(0, "Failed Case 5");

    return correctCount;
}

int test_myStrcpy() {
    const char * src1 = "";
    const char * src2 = "abcdefg";
    char destination1[10];
    int correctCount = 0;

    correctCount += 5 * (myStrcpy(destination1, src1)[0] == '\0' ? print(1, "Passed Case 1") : print(0, "Failed Case 1"));
    myStrcpy(destination1, src2);
    correctCount += 5 * (strcmp(destination1, "abcdefg") == 0 ? print(1, "Passed Case 2") : print(0, "Failed Case 2"));
    return correctCount;
}

int test_myStrcat() {
    const char * src1 = "";
    const char * src2 = "abc";
    const char destination1[10] = "abdef";
    int correctCount = 0;

    myStrcat(destination1, src1);
    correctCount += 5 * (strcmp(destination1, "abdef") == 0 ? print(1, "Passed Case 1") : print(0, "Failed Case 1"));
    myStrcat(destination1, src2);
    correctCount += 5 * (strcmp(destination1, "abdefabc") == 0 ? print(1, "Passed Case 2") : print(0, "Failed Case 2"));
    return correctCount;
}

int test_myStrcmp() {
    const char * s1 = "abcde";
    const char * s2 = "abcdef";
    const char * s3 = "abcdeg";
    const char * s4 = "abcdef";
    int correctCount = 0;

    correctCount += 2 * (myStrcmp(s1, s2) < 0 ? print(1, "Passed Case 1") : print(0, "Failed Case 1"));
    correctCount += 2 * (myStrcmp(s3, s2) > 0 ? print(1, "Passed Case 2") : print(0, "Failed Case 2"));
    correctCount += 2 * (myStrcmp(s2, s4) == 0 ? print(1, "Passed Case 3") : print(0, "Failed Case 3"));
    correctCount += 2 * (myStrcmp(s4, s1) > 0 ? print(1, "Passed Case 4") : print(0, "Failed Case 4"));

    return correctCount;
}

int test_MyStrfind() {
    const char * s1 = "abcdefghijklmn";
    int correctCount = 0;

    correctCount += 2 * (MyStrfind(s1, "abcde") == 0  ? print(1, "Passed Case 1") : print(0, "Failed Case 1"));
    correctCount += 2 * (MyStrfind(s1, "bcdef") == 1  ? print(1, "Passed Case 2") : print(0, "Failed Case 2"));
    correctCount += 2 * (MyStrfind(s1, "abcfk") == -1 ? print(1, "Passed Case 3") : print(0, "Failed Case 3"));
    correctCount += 2 * (MyStrfind(s1, "jklmn") == 9  ? print(1, "Passed Case 4") : print(0, "Failed Case 4"));
    correctCount += 2 * (MyStrfind(s1, "sssss") == -1 ? print(1, "Passed Case 5") : print(0, "Failed Case 5"));

    return correctCount;
}

int test_LeftRotateString() {
    char s1[20] = "abcdefghijklmn";
    int correctCount = 0;

    LeftRotateString(s1, 0);
    correctCount += 2 * (strcmp(s1, "abcdefghijklmn") == 0 ? print(1, "Passed Case 1") : print(0, "Failed Case 1"));
    LeftRotateString(s1, 2);
    correctCount += 3 * (strcmp(s1, "cdefghijklmnab") == 0 ? print(1, "Passed Case 2") : print(0, "Failed Case 2"));
    LeftRotateString(s1, 4);
    correctCount += 2 * (strcmp(s1, "ghijklmnabcdef") == 0 ? print(1, "Passed Case 3") : print(0, "Failed Case 3"));
    LeftRotateString(s1, 14);
    correctCount += 3 * (strcmp(s1, "ghijklmnabcdef") == 0 ? print(1, "Passed Case 4") : print(0, "Failed Case 4"));
    LeftRotateString(s1, 3);
    correctCount += 3 * (strcmp(s1, "jklmnabcdefghi") == 0 ? print(1, "Passed Case 5") : print(0, "Failed Case 5"));

    return correctCount;
}

int test_myParseInt() {
    const char * number1 = NULL;
    const char * number2 = "100";
    const char * number3 = "+100";
    const char * number4 = "-100";
    const char * number5 = "0";
    const char * number6 = "-0";
    const char * number7 = "123456789abcdef123";
    const char * number8 = "2147483648";
    const char * number9 = "-2147483649";
    int correctCount = 0;

    correctCount += 2 * (myParseInt(number1) == 0 ? print(1, "Passed Case 1") : print(0, "Failed Case 1"));
    correctCount += 2 * (myParseInt(number2) == 100 ? print(1, "Passed Case 2") : print(0, "Failed Case 2"));
    correctCount += 2 * (myParseInt(number3) == 100 ? print(1, "Passed Case 3") : print(0, "Failed Case 3"));
    correctCount += 3 * (myParseInt(number4) == -100 ? print(1, "Passed Case 4") : print(0, "Failed Case 4"));
    correctCount += 2 * (myParseInt(number5) == 0 ? print(1, "Passed Case 5") : print(0, "Failed Case 5"));
    correctCount += 2 * (myParseInt(number6) == 0 ? print(1, "Passed Case 6") : print(0, "Failed Case 6"));
    correctCount += 3 * (myParseInt(number7) == 123456789 ? print(1, "Passed Case 7") : print(0, "Failed Case 7"));
    correctCount += 3 * (myParseInt(number8) == 2147483647 ? print(1, "Passed Case 8") : print(0, "Failed Case 8"));
    correctCount += 3 * (myParseInt(number9) == -2147483648 ? print(1, "Passed Case 9") : print(0, "Failed Case 9"));

    return correctCount;
}

int test_myStrcontain() {
    const char * src1 = "ABCDEFGHIJK";
    const char * sub1 = "ABDEFG";
    const char * src2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char * sub2 = "ABJK";
    int correctCount = 0;

    correctCount += 2 * (myStrcontain(src1, sub1) == 1 ? print(1, "Passed Case 1") : print(0, "Failed Case 1"));
    correctCount += 2 * (myStrcontain(src1, sub2) == 1 ? print(1, "Passed Case 2") : print(0, "Failed Case 2"));
    correctCount += 2 * (myStrcontain(src2, sub1) == 1 ? print(1, "Passed Case 3") : print(0, "Failed Case 3"));
    correctCount += 2 * (myStrcontain(src2, sub2) == 1 ? print(1, "Passed Case 4") : print(0, "Failed Case 4"));
    correctCount += 2 * (myStrcontain(src2, sub1) == 1 ? print(1, "Passed Case 5") : print(0, "Failed Case 5"));
    correctCount += 2 * (myStrcontain(sub1, sub2) == 0 ? print(1, "Passed Case 5") : print(0, "Failed Case 5"));

    return correctCount;
}

int main() {
    int total = 0;
    printf("Report\n");

    printf("\nTesting myStrlen\n");
    total += test_MyStrlen();

    printf("\nTesting myStrcpy\n");
    total += test_myStrcpy();

    printf("\nTesting myStrcat\n");
    total += test_myStrcat();

    printf("\nTesting myStrcmp\n");
    total += test_myStrcmp();

    printf("\nTesting myStrfind\n");
    total += test_MyStrfind();

    printf("\nTesting LeftRotateString\n");
    total += test_LeftRotateString();

    printf("\nTesting myParseInt\n");
    total += test_myParseInt();

    printf("\nTesting myStrcontain\n");
    total += test_myStrcontain();

    printf("Total: %d\n/90", total);

    return 0;
}
