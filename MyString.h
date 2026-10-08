#ifndef MYSTRING_H
#define MYSTRING_H

class MyString {
    char* str;
    int length;
    static int count;

public:
    MyString();
    MyString(int size);
    MyString(const char* initStr);
    MyString(const MyString& obj);
    ~MyString();

    void Input();
    void Output();

    bool MyStrStr(const char* s);
    int MyChr(char c);
    int MyStrLen();
    void MyStrCat(MyString& b);
    void MyDelChr(char c);
    int MyStrCmp(MyString& b);

    static int GetCount();

    MyString operator+(char c);
    friend MyString operator+(char c, MyString& obj);
    friend MyString operator+(int n, MyString& obj);
    MyString operator+(int n);
    MyString& operator++();
    MyString operator++(int);
};

#endif
