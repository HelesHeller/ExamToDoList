#pragma once;
#include "Task.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class TodoList
{
private:
    vector<Task> items;

public:
    void addTask(const Task& item);
    void displayAll() const;
    void deleteTask(int index);
    void editTask(int index, const string& task, int day, int month, int year);
    void sortByDate();
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};