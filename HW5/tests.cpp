//
// Created by IrinaT on 5/24/2019.
//
#include <iostream>
#include "tests.h"

const int RAND_SIZE = 20;

void print(int** a, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << '\n';
    }
}

void testSwapMin(int testCount)
{
    std::cout << "~~~ START TEST SWAP MIN ~~~\n\n";
    for (int cnt = 0; cnt < testCount; ++cnt)
    {
        int n = rand() % RAND_SIZE + 1;
        int m = rand() % RAND_SIZE + 1;
        int** a = new int* [n];
        for (int i = 0; i < n; i++)
        {
            a[i] = new int[m];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x = rand() % RAND_SIZE;
                int y = rand() % RAND_SIZE;
                a[i][j] = x - y;
            }
        }
        std::cout << "Before swapping\n";
        print(a, n, m);
        int minVal = RAND_SIZE;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                minVal = std::min(minVal, a[i][j]);
            }
        }
        swap_min(a, n, m);
        std::cout << "The min num is: " << minVal << '\n';
        std::cout << "After swapping\n";
        print(a, n, m);
        std::cout << "\n~~~\n";
        for (int i = 0; i < n; ++i)
        {
            delete[] a[i];
        }
        delete[] a;
    }
    std::cout << "\n\n~~~ END ~~~\n\n";
}

void testResize(int testCount)
{
    std::cout << "~~~ START TEST RESIZE ~~~\n\n";
    int passedTestsCount = 0;
    int currTestSize = 10;
    for (int i = 0; i < testCount; ++i)
    {
        char* correctAnswer = new char[currTestSize];
        char* testString = new char[currTestSize];
        int newSize = rand() % RAND_SIZE;
        for (int j = 0; j < currTestSize; ++j)
        {
            correctAnswer[j] = char(rand() % 26 + 97);
            testString[j] = correctAnswer[j];
        }
        testString = resize(testString, currTestSize, newSize);
        int bound = std::min(currTestSize, newSize);
        for (int j = 0; j < bound; ++j)
        {
            if (testString[j] != correctAnswer[j])
            {
                std::cout << "Test " << passedTestsCount + 1 << " failed.\n";
                std::cout << "Expected: " << correctAnswer << "actual: " << testString << '\n';
                delete[] testString;
                delete[] correctAnswer;
                return;
            }
        }
        delete[] testString;
        delete[] correctAnswer;
        ++currTestSize;
        ++passedTestsCount;
    }
    std::cout << "Finished testing resize. Passed: " << passedTestsCount << " tests out of " <<
              passedTestsCount << ".\n\n";
    std::cout << "~~~ END ~~~\n\n";
}
