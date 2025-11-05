// Workout.cpp
#include "Workout.h"
#include <sstream>

std::string Workout::toString() const {
    std::stringstream ss;
    ss << date << " | " << type << "\n";
    for(const auto& exercise : exercises) {
        ss << "  " << exercise.name
           << " | " << exercise.sets << "x" << exercise.reps
           << " | " << exercise.weight << " кг\n";
    }
    return ss.str();
}