#pragma once
#include <string>
#include <iostream>

using namespace std;

class Task
{
private:
    string task;
    int day;
    int month;
    int year;

public:
    Task();
    Task(const string& task, int day, int month, int year);

    int getYear() const;
    int getMonth() const;
    int getDay() const;

    void display() const;
    void edit(const string& newTask, int newDay, int newMonth, int newYear);

    friend ostream& operator<<(ostream& os, const Task& item);
};