#include <iostream>
#include <cstring>
using namespace std;

// Example program
#include <iostream>
#include <string>
using namespace std;
const char MAX_LENGTH = 26;

void PrintDown(int &down, char *CharArr){
    for (int i = down; i < MAX_LENGTH; ++i)
        if(CharArr[i] == 1){
            cout << char(i + 'a') << "\t";
            down = i+1;
            return;
        }
        down = MAX_LENGTH;
            
}

void PrintUp(int &up, char *CharArr){
    for (int i = up; i >=0; --i)
        if(CharArr[i] == 1){
            cout << char(i + 'a') << "\t";
            up = i-1;
            return;
        }
        up = -1;
            
}

int main()
{
    
    char CharArr[MAX_LENGTH]={0};
    std::string str;
    std::cout << "Please enter a string:";
    getline (std::cin, str);


  
    for(int i = 0; i < str.length(); ++i){
        CharArr[tolower(str[i]) - 'a']++;  
    }
    int down = 0, up = MAX_LENGTH-1;
    while(down < MAX_LENGTH && up >= 0){
        if (down < MAX_LENGTH){
            cout << "Down: ";
            PrintDown(down, CharArr);
        }
            
        if (up >= 0){
            cout << "UP: ";
            PrintUp(up, CharArr);
        }
            
    }
  return 0;
  
}
