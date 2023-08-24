#pragma once
#include "TodoList.h"
#include <iostream>

using namespace std;

class Menu
{
private:
    TodoList todoList;

public:
    void displayMenu();
};