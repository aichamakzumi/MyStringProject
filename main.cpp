#include <iostream>
#include <utility>
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

    
    cout << "\n=== 1. Test initializer_list ===\n";
    MyString initObj{ 'H', 'e', 'l', 'l', 'o' };
    cout << "initObj {'H','e','l','l','o'}: ";
    initObj.Output();
    cout << "Length of initObj: " << initObj.MyStrLen() << "\n";

    
    cout << "\n=== 2. Test Move Constructor ===\n";
    MyString toMove("Hello Move Constructor");
    cout << "toMove before move: ";
    toMove.Output();

    MyString movedTarget(std::move(toMove));
    cout << "movedTarget after move constructor: ";
    movedTarget.Output();
    cout << "toMove after move constructor: ";
    toMove.Output();

    
    cout << "\n=== 3. Test Move Assignment ===\n";
    MyString sourceAssign("Hello Move Assignment");
    MyString destAssign("Old Destination Value");
    cout << "destAssign before assignment: ";
    destAssign.Output();
    cout << "sourceAssign before assignment: ";
    sourceAssign.Output();

    destAssign = std::move(sourceAssign);
    cout << "destAssign after move assignment: ";
    destAssign.Output();
    cout << "sourceAssign after move assignment: ";
    sourceAssign.Output();

    cout << "\nTotal object count: " << MyString::GetCount() << "\n";

    return 0;
}
