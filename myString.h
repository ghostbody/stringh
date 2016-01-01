#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

/*
    function: myStrlen
    @input: const string s
    @output: the length of the string
*/
unsigned int myStrlen(const char s[]);

/*
    function: myStrcpy
    @input: const string source
    @output: string destination
*/
char * myStrcpy(char destination[], const char source[]);

/*
    function: myStrcat
    @input: const string source
    @output: string destination
*/
char * myStrcat(char destination[], const char source[]);

/*
    function: myStrcmp
    @input: const string1 and const string2
    @output: if string1 is euqal to string2, output 0
             if string1 is greater than string2 ouput an integer > 0
             if string2 is greater than string1 output an integer < 0
*/
int myStrcmp(const char str1[], const char str2[]);

/*
    function: Mystrfind
    @input: cosnt string1 and const string2
    @output: if str2 is a substring of str1, output the first index in str1
             otherwise, ouput -1 which indicates can not find
*/
int MyStrfind(const char str1[], const char str2[]);

/*
    function: LeftRotateString
    @input: string buff, an integer n which indicates the first n
    @output: put the first n chars to the end of the string
*/
void LeftRotateString(char *buff, int n);

/*
    function: myParseInt
    @input: a const string
    @output: an integer parse from a string
*/
int myParseInt(const char str[]);

/*
    function: myStrcontain
    @input: const string1 and const string2
    @output: a boolean value. id all chars in str2 are in str1, output true
             else output flase
*/
int myStrcontain(const char str1[], const char str2[]);

#endif // STRING_H_INCLUDED
