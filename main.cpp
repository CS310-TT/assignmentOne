//
//  main.cpp
//  assignmentOne (Data Structures and Algorithms)
//
//  Created by Fahim Williams on 9/2/22.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

bool search(float myArray[], float SIZE, float myInput); // Question 1
int minValue(float myArray[], float n); // Question 2
void getArrayMinMax(float& min, float& max, float myArray[], float SIZE); // Question 3
void twoLargest(float& maxOne, float& maxTwo, float myArray[], float SIZE); // Question 4
void calculateSD(float myArray[], float SIZE); // Question 5
void lineOfText(string LOT); // LOT == Line of text | Question 6
void reversedString(string LOT1); // Question 7
void telephoneDictionaryForm(string LOT2); // Question 8
string integer_to_Roman(int integer); // Question 10
void reverseStr(string& str); // Question 11

int main()
{
    const int SIZE = 5;
    float myArray[SIZE] = {4, 8, 9, 3, 10}, myInput, result, result1, n;
    float min, max, maxOne, maxTwo;
    string LOT, LOT1, LOT2, str, result2, result3;
    int integer;
    
    cout << "Please input an integer: ";
    cin >> myInput;
    result = search(myArray, SIZE, myInput);
    cout << result << "\n";
    
    cout << "Please input the number of elements you want to scan within the array: ";
    cin >> n;
    result1 = minValue(myArray, n);
    cout << result1 << " is the minimum value amongst the first " << n << " elements of the array" << "\n";
    
    getArrayMinMax(min, max, myArray, SIZE);
    twoLargest(maxOne, maxTwo, myArray, SIZE);
    calculateSD(myArray, SIZE);
    
    cout << "Please input the line of text that will be transformed to uppercase: ";
    getline(cin, LOT);
    lineOfText(LOT);
    
    cout << "Please input the line of text that will be reversed: ";
    getline(cin, LOT1);
    reversedString(LOT1);
    
    telephoneDictionaryForm(LOT2);
    
    cout << "Please enter the integer you'll like to have converted: ";
    cin >> integer;
    result2 = integer_to_Roman(integer);
    cout << "Roman numeral conversion: " << result2 << "\n";
    
    cout << "Please enter the string you would like to have reversed: ";
    cin >> str;
    reverseStr(str);
    
    
    return 0;
}

bool search(float myArray[], float SIZE, float myInput)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (myArray[i] == myInput)
            return true;
    }
    return false;
}

int minValue(float myArray[], float n)
{
    float minimumValue = INT_MAX;
    
    for (int i = 0; i < n; i++)
    {
        if (myArray[i] < minimumValue)
        {
            minimumValue = myArray[i];
        }
    }
    return minimumValue;
}

void getArrayMinMax(float& min, float& max, float myArray[], float SIZE)
{
    min = INT_MAX;
    max = INT_MIN;
    
    for (int i = 0; i < SIZE; i++)
    {
        if (myArray[i] < min)
        {
            min = myArray[i];
        }
    }
    for (int j = 0; j < SIZE; j++)
    {
        if (myArray[j] > max)
        {
            max = myArray[j];
        }
    }
    cout << "The maximum value in myArray is " << max << "\n";
    cout << "The minimum value in myArray is " << min << "\n";
}

void twoLargest(float& maxOne, float& maxTwo, float myArray[], float SIZE)
{
    maxOne = INT_MIN;
    maxTwo = INT_MIN;
    for (int i = 0; i < SIZE; i++)
    {
        if (myArray[i] > maxOne)
        {
            maxOne = myArray[i];
        }
    }
    for (int j = 0; j < SIZE; j++)
    {
        if (myArray[j] > maxTwo && myArray[j] != maxOne)
        {
            maxTwo = myArray[j];
        }
    }
    cout << "The largest value in myArray is " << maxOne << "\n";
    cout << "The second largest value in myArray is " << maxTwo << "\n";
}

void calculateSD(float myArray[], float SIZE)
{
    float sum = 0.0, mean, standardDeviation = 0.0;
    
    for (int i = 0; i < SIZE; ++i)
    {
        sum += myArray[i];
    }
    
    mean = sum / SIZE;
    
    for (int i = 0; i < SIZE; ++i)
    {
        standardDeviation += pow(myArray[i] - mean, 2);
    }

    cout << "The standard deviation of myArray is " << sqrt(standardDeviation / SIZE) << "\n";
}

void lineOfText(string LOT)
{
    getline(cin, LOT);
    transform(LOT.begin(), LOT.end(), LOT.begin(), ::toupper);
    cout << LOT << "\n";
}

void reversedString(string LOT1)
{
    string result;
    int i = 0;
    float n = LOT1.length();
    
    while (i < n)
    {
        while (i < n && LOT1[i] == ' ') i++;
        if (i >= n)
            break;
        int j = i + 1;
        while (j < n && LOT1[j] != ' ')
            j++;
        string sub = LOT1.substr(i, j-i);
        if (result.length() == 0)
            result = sub;
        else
            result = sub + " " + result;
        i = j + 1;
    }
    cout << "This inputted text reversed is: " << result << "\n";
}

void telephoneDictionaryForm(string LOT2)
{
    string firstName, middleInitial, lastName;
    
    cout << "Please enter your first name: ";
    cin >> firstName;
    
    cout << "Please enter your second name: ";
    cin >> middleInitial;
    
    cout << "Please enter your third name: ";
    cin >> lastName;
    
    cout << "This is your name in telephone directory format: " << lastName << ", " << firstName << " " << middleInitial << "." << "\n";
}

string integer_to_Roman(int integer)
{

    string str_romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string result2 = "";

    for (int i = 0; i < 13; ++i)
    {
        while(integer - values[i] >= 0)
        {
            result2 += str_romans[i];
            integer -= values[i];
        }
    }
    return result2;
}

void reverseStr(string& str)
{
    float n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
    
    cout << "This is the reversed string: " << str << "\n";
}
