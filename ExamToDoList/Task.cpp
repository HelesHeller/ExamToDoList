#include "Task.h"

Task::Task() : day(0), month(0), year(0) {}

Task::Task(const string& task, int day, int month, int year)
    : task(task), day(day), month(month), year(year) {}

int Task::getYear() const
{
    return year;
}

int Task::getMonth() const
{
    return month;
}

int Task::getDay() const
{
    return day;
}

void Task::display() const
{
    cout << "Task: " << task << "\nDate: " << day << "/" << month << "/" << year << endl;
}

void Task::edit(const string& newTask, int newDay, int newMonth, int newYear)
{
    task = newTask;
    day = newDay;
    month = newMonth;
    year = newYear;
}

ostream& operator<<(ostream& os, const Task& item)
{
    os << "Task: " << item.task << "\nDate: " << item.day << "/" << item.month << "/" << item.year << endl;

    return os;
}
