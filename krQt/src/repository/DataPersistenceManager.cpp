#include "repository/DataPersistenceManager.h"
#include "exceptions/InvalidTaskFormatException.h"
#include "exceptions/NumericConversionFailedException.h"

#include <fstream>
#include <sstream>

bool DataPersistenceManager::saveToFile(const std::vector<Task>& tasks, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    for (const auto& task : tasks) {
        file << taskToLine(task) << "\n";
        if (!file.good()) {
            return false;
        }
    }

    file.flush();
    return file.good();
}

bool DataPersistenceManager::loadFromFile(std::vector<Task>& tasks, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    tasks.clear();
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        try {
            Task task = parseTaskLine(line);
            tasks.push_back(task);
        } catch (const TaskParseFailedException&) {
            continue;
        }
    }

    return true;
}

Task DataPersistenceManager::parseTaskLine(const std::string& line) {
    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(ss, token, ',')) {
        tokens.push_back(token);
    }

    if (tokens.size() != 6) {
        throw InvalidTaskFormatException("expected 6 fields, got " + std::to_string(tokens.size()));
    }

    try {
        int id = std::stoi(tokens[0]);
        std::string description = tokens[1];
        std::string date = tokens[2];
        std::string time = tokens[3];
        int priority = std::stoi(tokens[4]);
        bool completed = (tokens[5] == "1");

        Task task(description, date, time, priority);
        task.setId(id);
        task.setCompleted(completed);

        return task;
    } catch (const std::invalid_argument&) {
        throw NumericConversionFailedException("id or priority");
    } catch (const std::out_of_range&) {
        throw NumericConversionFailedException("id or priority");
    }
}

std::string DataPersistenceManager::taskToLine(const Task& task) {
    return std::to_string(task.getId()) + "," +
           task.getDescription() + "," +
           task.getDate() + "," +
           task.getTime() + "," +
           std::to_string(task.getPriority()) + "," +
           (task.isCompleted() ? "1" : "0");
}
