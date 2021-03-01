#include "objects.h"
#include "data_structure.h"
#include <iostream>
#include <list>
using namespace std;

// Schedule Class

Schedule::Schedule(string param_name, int param_start_time, int param_end_time, int param_station_code)
{
	// 생성자 코드
	this->name = param_name;
	this->start_time = param_start_time;
	this->end_time = param_end_time;
	this->station_code = param_station_code;
}

void Schedule::print()
{
	// 스케쥴 프린트
	cout << "[Schedule]" << endl;
	cout << this->name << endl;
	cout << this->start_time << endl;
	cout << this->end_time << endl;
	cout << this->station_code << endl;
}

// User Class

User::User(string param_string, int param_main_station_code)
{
	// 생성자 코드, id는 string hash로 할당해주기
	this->name = param_string;
	this->id = hash<string>{}(param_string);
	this->station_code = param_main_station_code;
}
void User::print()
{
	// 내 정보 출력
	cout << "[User Info]" << endl;
	cout << this->name << endl;
	cout << this->id << endl;
	cout << this->station_code << endl;
	for(Schedule schedule : schedule_list) {
		cout << "\t";
		schedule.print();
	}
}           

void User::insert_schedule(Schedule schedule)
{
	this->schedule_list.push_back(schedule);
	// 스케쥴 삽입
}

int User::get_id()
{
	return this->id;	
}


// Metro Class

Metro::Metro(string param_station_name, int param_station_code)
{
	// 생성자
	this->station_name = param_station_name;
	this->station_code = hash<string>{}(param_station_name);
}
int Metro::find_maximum_time(int param_time)
{
	// param_time보다 같거나 큰 departure_time 중 가장 가까운 값 리턴
	return 0;
}
int Metro::get_station_code() {
	return this->station_code;	
}
void Metro::insert_departure(Departure departure)
{
	this->departure_list.push_back(departure);	
}
void Metro::print() {
	cout << "[Metro]" << endl;
	cout << station_name << endl;
	cout << station_code << endl;
	for(auto departure_info : this->departure_list) {
		departure_info.print();
	}
}

// Departure Class

Departure::Departure(int destination_code, int line, int departure_time)
{
	this->destination_code = destination_code;
	this->line = line;
	this->departure_time = departure_time;
};

void Departure::print() {
	cout << "[Departure]" << endl;	
	cout << destination_code << endl;
	cout << line << endl;
	cout << departure_time << endl;
}

void init_graph()
{
    // STATION_NODE의 초기화
    // tree의 모든 노드를 순회하면서 graph를 만든다. 
}

string find_optimized_schedule_path(Node A, Node B)
{
    // 스케쥴에 따라 최적화 된 path 출력
    // 여기서 최적화된 내용은 station A -> station B의 최소시간을 갖는 최단거리여야 한다.
    // 리턴 string은 다음과 같다.
    /*
    스케쥴 : A -> B
    최단경로의 시간 : X분
    가장 늦게 출발하는 시간 : HH:MM
    Path : xx(a호선) -> xx_1(a호선) -> (a->b환승) ->  xx_2(b호선) ...
    */
   /*
    Node 그래프에서 dijstra를 통해 최단경로를 얻는다.
    Metro 트리에서 출발역의 find_maximum_time를 이용하여 최소 출발시간을 구한다
        -방법 1. 최대 출발시간 = 도착예정시간 - 최단경로의 시간 (난이도 1)
        -방법 2. 최대 출발시간 = A역의 가장 가까운 출발 시간(도착예정시간 - 최단경로의 시간) (난이도 2)
            즉, 걸리는 시간과 출발역의 스케쥴까지 고려하는 것
        -방법 3. 방법2에서 환승역의 스케쥴까지 고려하는 것
   */
	string s;

	return s;
};
