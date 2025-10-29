#ifndef WORKOUT_H
#define WORKOUT_H

#include "Exercise.h"
#include <string>

class Workout {
private:
    std::string date;
    std::string type;
    Exercise* exercises;
    int exerciseCount;
    int exerciseCapacity;

public:
    Workout();
    ~Workout();
    Workout(const Workout& other);
    Workout& operator=(const Workout& other);

    std::string getDate() const { return date; }
    std::string getType() const { return type; }
    int getExerciseCount() const { return exerciseCount; }
    Exercise getExercise(int index) const { return exercises[index]; }

    void setDate(const std::string& newDate) { date = newDate; }
    void setType(const std::string& newType) { type = newType; }

    void addExercise(const Exercise& ex);
    void displayWorkout() const;

    std::string toString() const;
};

#endif