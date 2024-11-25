#include "Array.hpp"
#include <iostream>

#define MAX 100

int main(void)
{

    std::cout << "====CREATING INT ARRAY====" << std::endl;
    Array<int> intArray(MAX);
    int *base = new int[MAX];

    std::cout << "====FILLING INT ARRAY====" << std::endl;
    srand(time(NULL));
    for (int i = 0; i < MAX; i++)
    {
        const int value = rand() % 100;
        intArray[i] = value;
        base[i] = value;
    }
    std::cout << "====Chech if the same====" << std::endl;
    for (int i = 0; i < MAX; i++)
    {
        if (base[i] != intArray[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    std::cout << "====COPY and ASSIGN ARRAY====" << std::endl;
    Array<int> intArrayCopy(intArray);
    Array<int> intArrayAssign = intArrayCopy;

    std::cout << "====DISPLAYING INT[9] ARRAY====" << std::endl;
    std::cout << "base[9] = " << base[9] << std::endl;
    std::cout << "intArray[9] = " << intArray[9] << std::endl;
    std::cout << "intArrayCopy[9] = " << intArrayCopy[9] << std::endl;
    std::cout << "intArrayAssign[9] = " << intArrayAssign[9] << std::endl;

    std::cout << "====DISPLAYING INT[9], replace with 42 ARRAY====" << std::endl;
    intArray[9] = 42;
    std::cout << "base[9] = " << base[9] << std::endl;
    std::cout << "intArray[9] = " << intArray[9] << std::endl;
    std::cout << "intArrayCopy[9] = " << intArrayCopy[9] << std::endl;
    std::cout << "intArrayAssign[9] = " << intArrayAssign[9] << std::endl;

    std::cout << "====DISPLAYING INT[9]++, COPY====" << std::endl;
    intArrayCopy[9]++;
    std::cout << "base[9] = " << base[9] << std::endl;
    std::cout << "intArray[9] = " << intArray[9] << std::endl;
    std::cout << "intArrayCopy[9] = " << intArrayCopy[9] << std::endl;
    std::cout << "intArrayAssign[9] = " << intArrayAssign[9] << std::endl;

    std::cout << "====DISPLAYING INT[9]++, ASSIGN====" << std::endl;
    intArrayAssign[9]++;
    std::cout << "base[9] = " << base[9] << std::endl;
    std::cout << "intArray[9] = " << intArray[9] << std::endl;
    std::cout << "intArrayCopy[9] = " << intArrayCopy[9] << std::endl;
    std::cout << "intArrayAssign[9] = " << intArrayAssign[9] << std::endl;

    std::cout << "====OUT OF RANGE====" << std::endl;
    try
    {
        intArray[MAX] = 42;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        intArrayCopy[-42] = 42;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "====CREATING CHAR ARRAY====" << std::endl;
    Array<char> charArray(MAX);
    char *baseChar = new char[MAX];

    std::cout << "====FILLING CHAR ARRAY====" << std::endl;
    for (int i = 0; i < MAX; i++)
    {
        const char value = rand() % 26 + 'a';
        charArray[i] = value;
        baseChar[i] = value;
    }
    std::cout << "====Chech if the same====" << std::endl;
    for (int i = 0; i < MAX; i++)
    {
        if (baseChar[i] != charArray[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    std::cout << "====COPY and ASSIGN CHAR ARRAY====" << std::endl;
    Array<char> charArrayCopy(charArray);
    Array<char> charArrayAssign = charArrayCopy;

    std::cout << "====DISPLAYING CHAR[9] ARRAY====" << std::endl;
    std::cout << "baseChar[9] = " << baseChar[9] << std::endl;
    std::cout << "charArray[9] = " << charArray[9] << std::endl;
    std::cout << "charArrayCopy[9] = " << charArrayCopy[9] << std::endl;
    std::cout << "charArrayAssign[9] = " << charArrayAssign[9] << std::endl;

    std::cout << "====DISPLAYING CHAR[9], replace with 'z' ARRAY====" << std::endl;
    charArray[9] = 'z';
    std::cout << "baseChar[9] = " << baseChar[9] << std::endl;
    std::cout << "charArray[9] = " << charArray[9] << std::endl;
    std::cout << "charArrayCopy[9] = " << charArrayCopy[9] << std::endl;
    std::cout << "charArrayAssign[9] = " << charArrayAssign[9] << std::endl;

    std::cout << "====DISPLAYING CHAR[9], COPY====" << std::endl;
    charArrayCopy[9]++;
    std::cout << "baseChar[9] = " << baseChar[9] << std::endl;
    std::cout << "charArray[9] = " << charArray[9] << std::endl;
    std::cout << "charArrayCopy[9] = " << charArrayCopy[9] << std::endl;
    std::cout << "charArrayAssign[9] = " << charArrayAssign[9] << std::endl;

    std::cout << "====DISPLAYING CHAR[9], ASSIGN====" << std::endl;
    charArrayAssign[9]++;
    std::cout << "baseChar[9] = " << baseChar[9] << std::endl;
    std::cout << "charArray[9] = " << charArray[9] << std::endl;
    std::cout << "charArrayCopy[9] = " << charArrayCopy[9] << std::endl;
    std::cout << "charArrayAssign[9] = " << charArrayAssign[9] << std::endl;

    std::cout << "==== SIZE ====" << std::endl;
    std::cout << "intArray size = " << intArray.size() << std::endl;
    std::cout << "charArray size = " << charArray.size() << std::endl;

    std::cout << "==== CONST TEST =====" << std::endl;
    const Array<int> constArray(intArray);
    std::cout << "constArray[9] = " << constArray[9] << std::endl;
    std::cout << "constArray size = " << constArray.size() << std::endl;

    std::cout << "====TRY TO ASSIGN VALUE====" << std::endl;
    // constArray[9] = 42;

    delete[] base;
    delete[] baseChar;
}