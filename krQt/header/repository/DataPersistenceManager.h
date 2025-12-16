#pragma once

#include "core/Task.h"

#include <vector>
#include <string>

class DataPersistenceManager {
public:
    static bool saveToFile(const std::vector<Task>& tasks, const std::string& filename);
    static bool loadFromFile(std::vector<Task>& tasks, const std::string& filename);

private:
    static Task parseTaskLine(const std::string& line);
    static std::string taskToLine(const Task& task);
};
