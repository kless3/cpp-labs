#ifndef TRAINING_DIARY_H
#define TRAINING_DIARY_H

#include "TrainingProgram.h"
#include <string>
#include <vector>
#include <map>

class TrainingDiary {
private:
    std::vector<TrainingProgram> programs;
    int currentProgramIndex;
    std::string filename = "training_programs.dat";

    bool isValidDate(const std::string& date);
    std::string getCurrentDate();
    bool isDateEarlier(const std::string& date1, const std::string& date2);

public:
    TrainingDiary();

    // Program management
    void addProgram(const TrainingProgram& program);
    void removeProgram(int index);
    void setCurrentProgram(int index);
    TrainingProgram& getCurrentProgram();
    TrainingProgram& getProgram(int index);
    const std::vector<TrainingProgram>& getAllPrograms() const;
    int getCurrentProgramIndex() const { return currentProgramIndex; }
    int getProgramCount() const { return programs.size(); }

    // Program operations
    void createProgram(const std::string& name);
    void duplicateProgram(int index, const std::string& newName);

    // Workout management for current program
    void setWorkoutForDate(const std::string& date, const Workout& workout);
    Workout getWorkoutForDate(const std::string& date) const;
    bool hasWorkoutForDate(const std::string& date) const;

    // Weekly schedule management
    void setWorkoutTemplateForDay(int dayOfWeek, const Workout& workout);
    Workout getWorkoutTemplateForDay(int dayOfWeek) const;
    void applyProgramToWeek(const std::string& startDate);

    // Utility functions
    std::vector<std::string> getWeekDates(const std::string& startDate) const;
    std::string getNextWeek(const std::string& currentStartDate) const;
    std::string getPreviousWeek(const std::string& currentStartDate) const;

    void saveToFile();
    void loadFromFile();
    void createTestPrograms();
};

#endif