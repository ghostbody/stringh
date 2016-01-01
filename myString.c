#include "myString.h"

#ifndef NULL
#define NULL 0
#endif // NULL

unsigned int myStrlen(const char s[]) {
    if(s == NULL) {
        return 0;
    }
    unsigned int len = 0;
    while(s[len++]);
    return len-1;
}

char * myStrcpy(char destination[], const char source[]) {
    if(destination == NULL || source == NULL) {
        return destination;
    }
    unsigned int index = 0;
    while((destination[index] = source[index]) != '\0') {
        index++;
    }
    return destination;
}

char * myStrcat(char destination[], const char source[]) {
    if(destination == NULL) {
        return NULL;
    }
    unsigned int index1 = 0, index2 = 0;
    while(destination[index1]) index1++;
    while((destination[index1++] = source[index2++]) != '\0');
    return destination;
}

int myStrcmp(const char str1[], const char str2[]) {
    if(myStrlen(str1) != myStrlen(str2)) {
        return myStrlen(str1) - myStrlen(str2);
    }
    unsigned int index1 = 0, index2 = 0;
    while(str1[index1] == str2[index2]) {
        if(str1[index1] == '\0') {
            return 0;
        }
        index1++;
        index2++;
    }
    return str1[index1] - str2[index2];
}

int MyStrfind(const char str1[], const char str2[]) {
    if(myStrlen(str1) == 0) {
        return -1;
    } else if(myStrlen(str2) == 0) {
        return 0;
    }
    unsigned int i, j;
    for(i = 0; i < myStrlen(str1); i++) {
        for(j = 0; j < myStrlen(str2); j++) {
            if(str1[i+j] != str2[j]) {
                break;
            }
        }
        if(j == myStrlen(str2)) {
            return i;
        }
    }
    return -1;
}

static void Reverse(char * buff, int begin, int end) {
  char temp;
  while(end > begin) {
    temp = buff[begin];
    buff[begin] = buff[end];
    buff[end] = temp;
    begin++;
    end--;
  }
}

void LeftRotateString(char * buff, int n) {
    if(n == 0) {
        return;
    }
    unsigned int len = myStrlen(buff);
    Reverse(buff, 0, n-1);
    Reverse(buff, n, len-1);
    Reverse(buff, 0, len-1);
}

static int isSpace(char c) {
    return (c == ' ');
}

static int isDigit(char c) {
    return (c >= '0') && (c <= '9');
}

int myParseInt(const char str[]) {
	static const int MAX_INT = (int)((unsigned)~0 >> 1);
	static const int MIN_INT = -(int)((unsigned)~0 >> 1) - 1;
	unsigned int n = 0;

	if (str == 0) {
		return 0;
	}

	while (isSpace(*str)) {
		++str;
    }

	int sign = 1;
	if (*str == '+' || *str == '-') {
		if (*str == '-')
			sign = -1;
		++str;
	}

	while (isDigit(*str)) {
		int c = *str - '0';
		if (sign > 0 && (n > MAX_INT / 10 || (n == MAX_INT / 10 && c > MAX_INT % 10))) {
			n = MAX_INT;
			break;
		} else if (sign < 0 && (n >(unsigned)MIN_INT / 10 || (n == (unsigned)MIN_INT / 10 && c > (unsigned)MIN_INT % 10))) {
			n = MIN_INT;
			break;
		}
		n = n * 10 + c;
		++str;
	}
	return sign > 0 ? n : -n;
}

int myStrcontain(const char str1[], const char str2[]) {
    int hash = 0;
    int i;
    for (i = 0; i < myStrlen(str1); ++i) {
        hash |= (1 << (str1[i] - 'A'));
    }
    for (i = 0; i < myStrlen(str2); ++i) {
        if ((hash & (1 << (str2[i] - 'A'))) == 0) {
            return 0;
        }
    }
    return 1;
}
