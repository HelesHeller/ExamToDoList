#include "TodoList.h"

void TodoList::addTask(const Task& item)
{
    items.push_back(item);
}

void TodoList::displayAll() const
{
    for (const Task& item : items)
    {
        item.display();
        cout << endl;
    }
}

void TodoList::deleteTask(int index)
{
    if (index >= 0 && index < items.size())
    {
        items.erase(items.begin() + index);
    }
}

void TodoList::editTask(int index, const string& task, int day, int month, int year)
{
    if (index >= 0 && index < items.size())
    {
        items[index].edit(task, day, month, year);
    }
}

void TodoList::sortByDate()
{
    sort(items.begin(), items.end(), [](const Task& a, const Task& b)
        {
            if (a.getYear() != b.getYear())
            {
                return a.getYear() < b.getYear();
            }
            if (a.getMonth() != b.getMonth())
            {
                return a.getMonth() < b.getMonth();
            }
            return a.getDay() < b.getDay();
        });
}

void TodoList::saveToFile(const string& filename) const
{
    ofstream file(filename, ios::binary);

    if (file.is_open())
    {
        size_t itemCount = items.size();

        file.write(reinterpret_cast<char*>(&itemCount), sizeof(itemCount));

        for (const Task& item : items)
        {
            file.write(reinterpret_cast<const char*>(&item), sizeof(item));
        }

        file.close();
    }
}

void TodoList::loadFromFile(const string& filename)
{
    ifstream file(filename, ios::binary);

    if (file.is_open())
    {
        items.clear();

        size_t itemCount;

        file.read(reinterpret_cast<char*>(&itemCount), sizeof(itemCount));

        for (size_t i = 0; i < itemCount; ++i)
        {
            Task item;
            file.read(reinterpret_cast<char*>(&item), sizeof(item));
            items.push_back(item);
        }

        file.close();
    }
}
