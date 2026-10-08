#include <iostream>
#include "MyString.h"

using namespace std;

int main() {
    MyString s1;
    cout << "Default constructor length: " << s1.MyStrLen() << "\n";

    MyString s2(10);
    cout << "Constructor with size length: " << s2.MyStrLen() << "\n";

    MyString s3("Hello World");
    cout << "Init constructor: ";
    s3.Output();

    MyString s4(s3);
    cout << "Copy constructor: ";
    s4.Output();

    cout << "Enter string without spaces: ";
    MyString s5;
    s5.Input();
    cout << "You entered: ";
    s5.Output();

    cout << "Search 'World' in 'Hello World': " << s3.MyStrStr("World") << "\n";
    cout << "Search 'abc' in 'Hello World': " << s3.MyStrStr("abc") << "\n";

    cout << "Index of 'W' in 'Hello World': " << s3.MyChr('W') << "\n";
    cout << "Index of 'z' in 'Hello World': " << s3.MyChr('z') << "\n";

    MyString strA("Apple");
    MyString strB("Banana");
    strA.MyStrCat(strB);
    cout << "Concatenation: ";
    strA.Output();

    MyString strC("Mississippi");
    strC.MyDelChr('s');
    cout << "Deleted 's': ";
    strC.Output();

    MyString c1("abc");
    MyString c2("abd");
    cout << "Compare abc and abd: " << c1.MyStrCmp(c2) << "\n";

    MyString obj("Test");
    MyString res1 = obj + 'A';
    cout << "obj + 'A': ";
    res1.Output();

    MyString res2 = 'A' + obj;
    cout << "'A' + obj: ";
    res2.Output();

    MyString res3 = 10 + obj;
    cout << "10 + obj: ";
    res3.Output();

    MyString res4 = obj + 10;
    cout << "obj + 10: ";
    res4.Output();

    obj++;
    cout << "obj++: ";
    obj.Output();

    ++obj;
    cout << "++obj: ";
    obj.Output();

    cout << "Object count: " << MyString::GetCount() << "\n";

    return 0;
}
