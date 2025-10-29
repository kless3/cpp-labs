#include "TrainingDiary.h"
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <algorithm>

TrainingDiary::TrainingDiary() : workouts(nullptr), workoutCount(0), workoutCapacity(10) {
    workouts = new Workout[workoutCapacity];
}

TrainingDiary::~TrainingDiary() {
    delete[] workouts;
}

bool TrainingDiary::isValidDate(const std::string& date) {
    if(date.length() != 10) return false;
    if(date[2] != '.' || date[5] != '.') return false;

    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6, 4));

    if(day < 1 || day > 31) return false;
    if(month < 1 || month > 12) return false;
    if(year < 2000 || year > 2100) return false;

    return true;
}

std::string TrainingDiary::getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    char buffer[11];
    strftime(buffer, sizeof(buffer), "%d.%m.%Y", ltm);
    return std::string(buffer);
}

bool TrainingDiary::isDateEarlier(const std::string& date1, const std::string& date2) {
    int day1 = std::stoi(date1.substr(0, 2));
    int month1 = std::stoi(date1.substr(3, 2));
    int year1 = std::stoi(date1.substr(6, 4));

    int day2 = std::stoi(date2.substr(0, 2));
    int month2 = std::stoi(date2.substr(3, 2));
    int year2 = std::stoi(date2.substr(6, 4));

    if(year1 != year2) return year1 < year2;
    if(month1 != month2) return month1 < month2;
    return day1 < day2;
}

void TrainingDiary::resizeWorkoutsArray() {
    workoutCapacity *= 2;
    Workout* newWorkouts = new Workout[workoutCapacity];
    for(int i = 0; i < workoutCount; i++) {
        newWorkouts[i] = workouts[i];
    }
    delete[] workouts;
    workouts = newWorkouts;
}

void TrainingDiary::addWorkout(const Workout& workout) {
    if(workoutCount >= workoutCapacity) {
        resizeWorkoutsArray();
    }
    workouts[workoutCount++] = workout;
    saveToFile();
}

std::vector<Workout> TrainingDiary::getAllWorkouts() {
    std::vector<Workout> result;
    for(int i = 0; i < workoutCount; i++) {
        result.push_back(workouts[i]);
    }

    std::sort(result.begin(), result.end(), [this](const Workout& a, const Workout& b) {
        return isDateEarlier(a.getDate(), b.getDate());
    });

    return result;
}

std::vector<Workout> TrainingDiary::getWorkoutsByDate(const std::string& date) {
    std::vector<Workout> result;
    for(int i = 0; i < workoutCount; i++) {
        if(workouts[i].getDate() == date) {
            result.push_back(workouts[i]);
        }
    }
    return result;
}

std::vector<Workout> TrainingDiary::getWorkoutsByPeriod(const std::string& startDate, const std::string& endDate) {
    std::vector<Workout> result;
    for(int i = 0; i < workoutCount; i++) {
        if(isDateEarlier(startDate, workouts[i].getDate()) &&
           isDateEarlier(workouts[i].getDate(), endDate)) {
            result.push_back(workouts[i]);
        }
    }

    std::sort(result.begin(), result.end(), [this](const Workout& a, const Workout& b) {
        return isDateEarlier(a.getDate(), b.getDate());
    });

    return result;
}

std::vector<Workout> TrainingDiary::getWorkoutsByType(const std::string& type) {
    std::vector<Workout> result;
    for(int i = 0; i < workoutCount; i++) {
        if(workouts[i].getType().find(type) != std::string::npos) {
            result.push_back(workouts[i]);
        }
    }
    return result;
}

Workout TrainingDiary::getLastWorkout() {
    if(workoutCount == 0) {
        return Workout();
    }

    int lastIndex = 0;
    for(int i = 1; i < workoutCount; i++) {
        if(isDateEarlier(workouts[lastIndex].getDate(), workouts[i].getDate())) {
            lastIndex = i;
        }
    }
    return workouts[lastIndex];
}

std::vector<std::string> TrainingDiary::getWeightProgress(const std::string& exerciseName) {
    std::vector<std::string> result;

    std::vector<std::pair<std::string, Exercise>> exercisesWithDates;

    for(int i = 0; i < workoutCount; i++) {
        for(int j = 0; j < workouts[i].getExerciseCount(); j++) {
            Exercise e = workouts[i].getExercise(j);
            if(e.name == exerciseName) {
                exercisesWithDates.push_back({workouts[i].getDate(), e});
            }
        }
    }

    std::sort(exercisesWithDates.begin(), exercisesWithDates.end(),
              [this](const auto& a, const auto& b) {
                  return isDateEarlier(a.first, b.first);
              });

    for(const auto& item : exercisesWithDates) {
        std::stringstream ss;
        ss << item.first << " | Вес: " << item.second.weight << " кг | "
           << item.second.sets << "x" << item.second.reps;
        result.push_back(ss.str());
    }

    return result;
}

std::vector<std::string> TrainingDiary::calculateTotalVolume() {
    std::vector<std::string> result;
    for(int i = 0; i < workoutCount; i++) {
        double totalVolume = 0;
        for(int j = 0; j < workouts[i].getExerciseCount(); j++) {
            Exercise e = workouts[i].getExercise(j);
            totalVolume += e.weight * e.sets * e.reps;
        }

        std::stringstream ss;
        ss << workouts[i].getDate() << " | Тоннаж: " << totalVolume << " кг";
        result.push_back(ss.str());
    }
    return result;
}

void TrainingDiary::saveToFile() {
    std::ofstream file(filename);
    for(int i = 0; i < workoutCount; i++) {
        file << workouts[i].getDate() << "|" << workouts[i].getType() << "|";
        for(int j = 0; j < workouts[i].getExerciseCount(); j++) {
            Exercise e = workouts[i].getExercise(j);
            file << e.name << ","
                 << e.sets << ","
                 << e.reps << ","
                 << e.weight << ";";
        }
        file << "\n";
    }
    file.close();
}

void TrainingDiary::loadFromFile() {
    std::ifstream file(filename);
    if(!file) {
        return;
    }

    workoutCount = 0;
    std::string line;
    while(std::getline(file, line) && workoutCount < workoutCapacity) {
        Workout w;
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);

        if(pos1 != std::string::npos) {
            w.setDate(line.substr(0, pos1));
            w.setType(line.substr(pos1 + 1, pos2 - pos1 - 1));

            std::string exercisesStr = line.substr(pos2 + 1);
            size_t start = 0;
            size_t end = exercisesStr.find(';');

            while(end != std::string::npos) {
                std::string exerciseStr = exercisesStr.substr(start, end - start);
                Exercise e;

                size_t comma1 = exerciseStr.find(',');
                size_t comma2 = exerciseStr.find(',', comma1 + 1);
                size_t comma3 = exerciseStr.find(',', comma2 + 1);

                if(comma1 != std::string::npos) {
                    e.name = exerciseStr.substr(0, comma1);
                    e.sets = std::stoi(exerciseStr.substr(comma1 + 1, comma2 - comma1 - 1));
                    e.reps = std::stoi(exerciseStr.substr(comma2 + 1, comma3 - comma2 - 1));
                    e.weight = std::stod(exerciseStr.substr(comma3 + 1));

                    w.addExercise(e);
                }

                start = end + 1;
                end = exercisesStr.find(';', start);
            }

            workouts[workoutCount++] = w;
        }
    }
    file.close();
}