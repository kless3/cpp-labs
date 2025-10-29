#ifndef TRAINING_DIARY_H
#define TRAINING_DIARY_H

#include "Workout.h"
#include <string>
#include <vector>

class TrainingDiary {
private:
    Workout* workouts;
    int workoutCount;
    int workoutCapacity;
    std::string filename = "workouts.txt";

    bool isValidDate(const std::string& date);
    std::string getCurrentDate();
    bool isDateEarlier(const std::string& date1, const std::string& date2);
    void resizeWorkoutsArray();

public:
    TrainingDiary();
    ~TrainingDiary();

    void addWorkout(const Workout& workout);
    std::vector<Workout> getAllWorkouts();
    std::vector<Workout> getWorkoutsByDate(const std::string& date);
    std::vector<Workout> getWorkoutsByPeriod(const std::string& startDate, const std::string& endDate);
    std::vector<Workout> getWorkoutsByType(const std::string& type);
    Workout getLastWorkout();
    std::vector<std::string> getWeightProgress(const std::string& exerciseName);
    std::vector<std::string> calculateTotalVolume();

    void saveToFile();
    void loadFromFile();

    int getWorkoutCount() const { return workoutCount; }
};

#endif