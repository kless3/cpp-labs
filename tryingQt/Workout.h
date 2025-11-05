// Workout.h
#ifndef WORKOUT_H
#define WORKOUT_H

#include "Exercise.h"
#include <string>
#include <vector>

class Workout {
private:
    std::string date;
    std::string type;
    std::vector<Exercise> exercises;

public:
    Workout() = default;
    Workout(const std::string& date, const std::string& type) : date(date), type(type) {}

    std::string getDate() const { return date; }
    std::string getType() const { return type; }
    int getExerciseCount() const { return exercises.size(); }
    Exercise getExercise(int index) const { return exercises[index]; }
    const std::vector<Exercise>& getExercises() const { return exercises; }

    void setDate(const std::string& newDate) { date = newDate; }
    void setType(const std::string& newType) { type = newType; }

    void addExercise(const Exercise& ex) { exercises.push_back(ex); }
    void clearExercises() { exercises.clear(); }

    std::string toString() const;
};

#endif