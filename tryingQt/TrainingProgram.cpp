#include "TrainingProgram.h"
#include <algorithm>

void TrainingProgram::setWorkoutForDay(int dayOfWeek, const Workout& workout) {
    // Сохраняем день недели как есть (1-7)
    weeklyWorkouts[std::to_string(dayOfWeek)] = workout;
}

Workout TrainingProgram::getWorkoutForDay(int dayOfWeek) const {
    auto it = weeklyWorkouts.find(std::to_string(dayOfWeek));
    if (it != weeklyWorkouts.end()) {
        return it->second;
    }
    return Workout();
}

bool TrainingProgram::hasWorkoutForDay(int dayOfWeek) const {
    return weeklyWorkouts.find(std::to_string(dayOfWeek)) != weeklyWorkouts.end();
}

void TrainingProgram::removeWorkoutForDay(int dayOfWeek) {
    weeklyWorkouts.erase(std::to_string(dayOfWeek));
}

void TrainingProgram::setWorkoutForDate(const std::string& date, const Workout& workout) {
    datedWorkouts[date] = workout;
}

Workout TrainingProgram::getWorkoutForDate(const std::string& date) const {
    auto it = datedWorkouts.find(date);
    if (it != datedWorkouts.end()) {
        return it->second;
    }
    return Workout();
}

bool TrainingProgram::hasWorkoutForDate(const std::string& date) const {
    return datedWorkouts.find(date) != datedWorkouts.end();
}

void TrainingProgram::removeWorkoutForDate(const std::string& date) {
    datedWorkouts.erase(date);
}

std::vector<std::string> TrainingProgram::getAllDates() const {
    std::vector<std::string> dates;
    for (const auto& pair : datedWorkouts) {
        dates.push_back(pair.first);
    }
    return dates;
}

std::vector<int> TrainingProgram::getScheduledDays() const {
    std::vector<int> days;
    for (const auto& pair : weeklyWorkouts) {
        days.push_back(std::stoi(pair.first));
    }
    std::sort(days.begin(), days.end());
    return days;
}