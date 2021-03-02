#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <iostream>
#include "data_structure.h"
#include "json/json.h"
#include "objects.h"

extern std::map<int, User> userMap;
extern std::map<int, Metro> metroMap;

template <typename T>
void travel_map(std::map<int, T>& map) {
	for(auto pair : map)
		std::cout << pair.first << " >> ";	
	std::cout << std::endl;
}

template <typename T>
void find_item(std::map<int, T>& map, std::string item) {
	int id=hash<string>{}(item);
	typename std::map<int, T>::iterator it = map.find(id);
	if(it != map.end()) {
		it->second.print();
	} else 
		std::cout << "can't find" << std::endl;
}

UserTreeNode* read_user_data();
MetroTreeNode* read_metro_data();

void save_user_data(UserTreeNode* root);
void save_metro_data(MetroTreeNode* root);
#endif
