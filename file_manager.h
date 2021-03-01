#ifndef FILE_READ_H
#define FILE_READ_H

#include "data_structure.h"
UserTreeNode* read_user_data();
MetroTreeNode* read_metro_data();
void save_user_data(UserTreeNode* root);
void save_metro_data(MetroTreeNode* root);
#endif
