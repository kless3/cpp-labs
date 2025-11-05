#ifndef TRAININGPROGRAM_H
#define TRAININGPROGRAM_H

#include "Workout.h"
#include <string>
#include <vector>
#include <map>

class TrainingProgram {
private:
    std::string name;
    std::map<std::string, Workout> weeklyWorkouts; // key: day of week (1-7), value: workout template
    std::map<std::string, Workout> datedWorkouts;  // key: date in format "dd.MM.yyyy"

public:
    TrainingProgram() = default;
    TrainingProgram(const std::string& programName) : name(programName) {}

    std::string getName() const { return name; }
    void setName(const std::string& newName) { name = newName; }

    // Workout templates for days of week (1-7 where 1=Monday, 7=Sunday)
    void setWorkoutForDay(int dayOfWeek, const Workout& workout);
    Workout getWorkoutForDay(int dayOfWeek) const;
    bool hasWorkoutForDay(int dayOfWeek) const;
    void removeWorkoutForDay(int dayOfWeek);

    // Dated workouts
    void setWorkoutForDate(const std::string& date, const Workout& workout);
    Workout getWorkoutForDate(const std::string& date) const;
    bool hasWorkoutForDate(const std::string& date) const;
    void removeWorkoutForDate(const std::string& date);

    std::vector<std::string> getAllDates() const;

    // Get all workout templates
    std::vector<int> getScheduledDays() const;
};

#endif