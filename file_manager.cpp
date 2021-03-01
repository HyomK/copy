#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include "json/json.h"
#include "data_structure.h"


std::map<int, User> userMap;
std::map<int, Metro> metroMap;

/* 
JSON파일 읽고 User Object들로 만든다. 
만들고 data_structure에 정의된 함수들을 이용해 tree를 구성한다.
    (힌트 1. tree가 구현이 잘 되어있고, parsing이 잘 되어있다면 parsing한 object를 insert만 계속 하면 된다 )
    (힌트 2. Custom tree를 구현하기 전에 STL의 map을 이용하여 미리 구현하면 협업이 쉬울것이다.)
*/

template <typename T>
void travel_map(std::map<int, T>& map) {
	for(auto obj : map)
		cout << obj.first << " >> ";	
	cout << endl;
}

template <typename T>
void find_item(std::map<int, T>& map, string item) {
	int id=hash<string>{}(item);
	typename std::map<int, T>::iterator it = map.find(id);
	if(it != map.end()) {
		it->second.print();
	} else 
		cout << "can't find" << endl;
}

UserTreeNode* read_user_data()
{
	std::ifstream jsonFile("user.json");
	
	Json::Value jsonData;
	Json::CharReaderBuilder jsonReader;
	std::string err;	

	if(Json::parseFromStream(jsonReader, jsonFile, &jsonData, &err)) {
		Json::Value userData = jsonData;

		for(auto user : userData) {
			std::string name = user["name"].asString();
			int id = user["id"].asInt(); 
			int station_code = user["station_code"].asInt();

			User userObj = User(name, station_code);

			for(auto schedule : user["schedules"]) {
				std::string name = schedule["name"].asString();
				int start_time = schedule["start_time"].asInt(); 
				int end_time = schedule["end_time"].asInt(); 
				int station_code = schedule["station_code"].asInt();

				Schedule scheduleObj = Schedule(name, start_time, end_time, station_code);
				userObj.insert_schedule(scheduleObj);
			}

			userMap.insert(std::pair<int, User>(userObj.get_id(), userObj));
		}
	}
	else
		std::cerr << "Failed to parse Json";
	
	UserTreeNode* temp;
	return temp;
}

// 위와 같다, Metro 객체인것만 제외한다면
MetroTreeNode* read_metro_data()
{
	std::ifstream jsonFile("metro.json");
	
	Json::Value jsonData;
	Json::CharReaderBuilder jsonReader;
	std::string err;	

	if(Json::parseFromStream(jsonReader, jsonFile, &jsonData, &err)) {
		Json::Value metroData = jsonData;

		for(auto metro : metroData) {
			std::string station_name = metro["station_name"].asString();
			int station_code = metro["station_code"].asInt(); 

			Metro metroObj = Metro(station_name, station_code);

			for(auto departure : metro["departure_list"]) {
				int destination_code = departure["station_code"].asInt(); 
				int line = departure["line"].asInt(); 
				int departure_time = departure["departure_time"].asInt();

				Departure scheduleObj = Departure(destination_code, line, departure_time);
				metroObj.insert_departure(scheduleObj);
			}

			metroMap.insert(std::pair<int, Metro>(metroObj.get_station_code(), metroObj));
		}
	}
	else
		std::cerr << "Failed to parse Json";
	
	MetroTreeNode* temp;
	return temp;
}

void save_user_data() {
	Json::Value root;

	for(auto pair : userMap) {
		User userObj = pair.second;

		Json::Value jsonObj;
		
		
	}
}

//void save_metro_data(UserTreeNode* rootNode) {
//	Json::Value root;
//
//	for(auto metroPair : userMap) {
//		User metroObj = metroPair.second;
//
//		Json::Value metroValue;
//		metroValue["station_name"] = metroObj.get_station_code();
//		
//		
//	}
//}


int main() {
	read_user_data();
	read_metro_data();

	travel_map(userMap);
	travel_map(metroMap);

	find_item(userMap, "James");
	find_item(metroMap, "고속터미널");

	//save_user_data();

	return 0;
}



