#include "MyString.h"
#include <iostream>

using namespace std;

int MyString::count = 0;

int StrLen(const char* s) {
    if (!s) return 0;
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

void StrCpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

MyString::MyString() {
    length = 80;
    str = new char[length + 1];
    for (int i = 0; i < length; i++) str[i] = ' ';
    str[length] = '\0';
    count++;
}

MyString::MyString(int size) {
    length = size;
    str = new char[length + 1];
    for (int i = 0; i < length; i++) str[i] = ' ';
    str[length] = '\0';
    count++;
}

MyString::MyString(const char* initStr) {
    length = StrLen(initStr);
    str = new char[length + 1];
    StrCpy(str, initStr);
    count++;
}

MyString::MyString(const MyString& obj) {
    length = obj.length;
    str = new char[length + 1];
    StrCpy(str, obj.str);
    count++;
}

MyString::~MyString() {
    delete[] str;
    count--;
}

void MyString::Input() {
    char buffer[256];
    cin >> buffer;
    delete[] str;
    length = StrLen(buffer);
    str = new char[length + 1];
    StrCpy(str, buffer);
}

void MyString::Output() {
    cout << str << "\n";
}

bool MyString::MyStrStr(const char* s) {
    if (!s || StrLen(s) == 0) return true;
    int sLen = StrLen(s);
    for (int i = 0; i <= length - sLen; i++) {
        bool match = true;
        for (int j = 0; j < sLen; j++) {
            if (str[i + j] != s[j]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false;
}

int MyString::MyChr(char c) {
    for (int i = 0; i < length; i++) {
        if (str[i] == c) return i;
    }
    return -1;
}

int MyString::MyStrLen() {
    return length;
}

void MyString::MyStrCat(MyString& b) {
    int newLen = length + b.length;
    char* newStr = new char[newLen + 1];
    StrCpy(newStr, str);
    for (int i = 0; i < b.length; i++) {
        newStr[length + i] = b.str[i];
    }
    newStr[newLen] = '\0';
    delete[] str;
    str = newStr;
    length = newLen;
}

void MyString::MyDelChr(char c) {
    int removeCount = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == c) removeCount++;
    }
    if (removeCount == 0) return;

    int newLen = length - removeCount;
    char* newStr = new char[newLen + 1];
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] != c) {
            newStr[j] = str[i];
            j++;
        }
    }
    newStr[newLen] = '\0';
    delete[] str;
    str = newStr;
    length = newLen;
}

int MyString::MyStrCmp(MyString& b) {
    int minLen = length < b.length ? length : b.length;
    for (int i = 0; i < minLen; i++) {
        if (str[i] < b.str[i]) return -1;
        if (str[i] > b.str[i]) return 1;
    }
    if (length < b.length) return -1;
    if (length > b.length) return 1;
    return 0;
}

int MyString::GetCount() {
    return count;
}

MyString MyString::operator+(char c) {
    MyString res(length + 1);
    StrCpy(res.str, str);
    res.str[length] = c;
    res.str[res.length] = '\0';
    return res;
}

MyString operator+(char c, MyString& obj) {
    MyString res(obj.length + 1);
    res.str[0] = c;
    for (int i = 0; i < obj.length; i++) {
        res.str[i + 1] = obj.str[i];
    }
    res.str[res.length] = '\0';
    return res;
}

MyString operator+(int n, MyString& obj) {
    MyString res(obj.length + n);
    for (int i = 0; i < n; i++) {
        res.str[i] = '*';
    }
    for (int i = 0; i < obj.length; i++) {
        res.str[i + n] = obj.str[i];
    }
    res.str[res.length] = '\0';
    return res;
}

MyString MyString::operator+(int n) {
    MyString res(length + n);
    StrCpy(res.str, str);
    for (int i = 0; i < n; i++) {
        res.str[length + i] = '*';
    }
    res.str[res.length] = '\0';
    return res;
}

MyString& MyString::operator++() {
    if (length < 0) return *this;
    int newLen = length + 1;
    char* newStr = new char[newLen + 1];
    newStr[0] = '*';
    StrCpy(newStr + 1, str);
    delete[] str;
    str = newStr;
    length = newLen;
    return *this;
}

MyString MyString::operator++(int) {
    MyString temp(*this);
    int newLen = length + 1;
    char* newStr = new char[newLen + 1];
    StrCpy(newStr, str);
    newStr[length] = '*';
    newStr[newLen] = '\0';
    delete[] str;
    str = newStr;
    length = newLen;
    return temp;
}
