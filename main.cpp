#include<iostream>
#include<string>
//#include "objects.h"
//#include "data_structure.h"
#include "file_manager.h"
using namespace std;

const int NUM_OF_STATION = 100;
Node STATION_NODE[NUM_OF_STATION] = {0};


int main()
{
    // 파일 읽는 부분
//    read_user_data();
//    read_metro_data();
    while(1)
    {
        string command;
        cin >> command;
        if(command == "4")
            break;
        else
        {
            // do something
        }
    }
    return 0;
}
