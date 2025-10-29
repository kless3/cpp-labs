#include "Workout.h"
#include <sstream>

Workout::Workout() : exercises(nullptr), exerciseCount(0), exerciseCapacity(10) {
    exercises = new Exercise[exerciseCapacity];
}

Workout::~Workout() {
    delete[] exercises;
}

Workout::Workout(const Workout& other) {
    date = other.date;
    type = other.type;
    exerciseCount = other.exerciseCount;
    exerciseCapacity = other.exerciseCapacity;

    exercises = new Exercise[exerciseCapacity];
    for(int i = 0; i < exerciseCount; i++) {
        exercises[i] = other.exercises[i];
    }
}

Workout& Workout::operator=(const Workout& other) {
    if(this != &other) {
        delete[] exercises;

        date = other.date;
        type = other.type;
        exerciseCount = other.exerciseCount;
        exerciseCapacity = other.exerciseCapacity;

        exercises = new Exercise[exerciseCapacity];
        for(int i = 0; i < exerciseCount; i++) {
            exercises[i] = other.exercises[i];
        }
    }
    return *this;
}

void Workout::addExercise(const Exercise& ex) {
    if(exerciseCount >= exerciseCapacity) {
        exerciseCapacity *= 2;
        auto* newExercises = new Exercise[exerciseCapacity];
        for(int i = 0; i < exerciseCount; i++) {
            newExercises[i] = exercises[i];
        }
        delete[] exercises;
        exercises = newExercises;
    }
    exercises[exerciseCount++] = ex;
}

std::string Workout::toString() const {
    std::stringstream ss;
    ss << date << " | " << type << "\n";
    for(int j = 0; j < exerciseCount; j++) {
        ss << "  " << exercises[j].name
           << " | " << exercises[j].sets << "x" << exercises[j].reps
           << " | " << exercises[j].weight << " кг\n";
    }
    return ss.str();
}