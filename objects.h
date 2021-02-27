#ifndef OBJECTS_H
#define OBJECTS_H

#include<string>
#include<vector>
#include<list>
#include<array>

using namespace std;

class Schedule
{
    private :
        string name; // 스케쥴 이름
        int start_time; // 시작 시간, HHMM 형식
        int end_time; // 종료 시간, HHMM 형식
        int station_code; // 역 코드
    public :
        Schedule(string param_name, int param_start_time, int param_end_time, int param_station_code);
        void print_schedule();
};

class User
{
    private :
        string name; // 유저 이름
        int id; // 유저 아이디
        int station_code; // 유저의 역, 스케쥴의 언제나 맨 처음이고 언제나 맨 마지막이다. 변하면 안됨
        list<Schedule> schedule; // 스케쥴의 백터
    public :
        User(string param_string, int param_main_station_code);
        void print();
        void insert_schedule(Schedule schedule);
		int get_id();
        void print_my_schedule();
        string find_optimized_schedule_path();
};

class Departure
{
	private:
		int destination_code;
		int line;	
		int departure_time;
	public:	
        Departure(int destination_code, int line, int departure_time);
        void print();
};

class Metro
{
    private :
        string station_name;
        int station_code;
		list<Departure> departure_info_list;
        //vector<array<int,3>> departure_time;
    public :
        Metro(string param_station_name, int param_station_code);
        int find_maximum_time(int param_time);
		int get_id();
		void insert_departure_info(Departure departure_info);
		void print();
};

#endif
