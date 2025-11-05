// TrainingDiary.cpp
#include "TrainingDiary.h"
#include <fstream>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <QDate>

TrainingDiary::TrainingDiary() : currentProgramIndex(-1) {
    loadFromFile();
    if (programs.empty()) {
        // Создаем тестовые программы тренировок
        createTestPrograms();
        currentProgramIndex = 0;
        saveToFile();
    }
}

void TrainingDiary::createTestPrograms() {
    // Программа 1: Набор массы
    TrainingProgram massGainProgram("💪 Набор массы");

    // Понедельник - Грудь, Трицепс
    Workout mondayWorkout("", "Грудь + Трицепс");
    mondayWorkout.addExercise(Exercise{"Жим штанги лежа", 4, 8, 80});
    mondayWorkout.addExercise(Exercise{"Разводки гантелей", 3, 12, 20});
    mondayWorkout.addExercise(Exercise{"Жим гантелей на наклонной", 3, 10, 25});
    mondayWorkout.addExercise(Exercise{"Французский жим", 3, 12, 25});
    mondayWorkout.addExercise(Exercise{"Отжимания на брусьях", 3, 15, 0});
    massGainProgram.setWorkoutForDay(1, mondayWorkout);

    // Среда - Спина, Бицепс
    Workout wednesdayWorkout("", "Спина + Бицепс");
    wednesdayWorkout.addExercise(Exercise{"Становая тяга", 4, 6, 100});
    wednesdayWorkout.addExercise(Exercise{"Тяга штанги в наклоне", 3, 8, 60});
    wednesdayWorkout.addExercise(Exercise{"Подтягивания", 3, 10, 0});
    wednesdayWorkout.addExercise(Exercise{"Тяга верхнего блока", 3, 12, 50});
    wednesdayWorkout.addExercise(Exercise{"Подъем штанги на бицепс", 3, 10, 30});
    wednesdayWorkout.addExercise(Exercise{"Молотки с гантелями", 3, 12, 12});
    massGainProgram.setWorkoutForDay(3, wednesdayWorkout);

    // Пятница - Ноги, Плечи
    Workout fridayWorkout("", "Ноги + Плечи");
    fridayWorkout.addExercise(Exercise{"Приседания со штангой", 4, 8, 90});
    fridayWorkout.addExercise(Exercise{"Жим ногами", 3, 10, 120});
    fridayWorkout.addExercise(Exercise{"Выпады с гантелями", 3, 12, 15});
    fridayWorkout.addExercise(Exercise{"Армейский жим", 3, 10, 35});
    fridayWorkout.addExercise(Exercise{"Махи гантелями в стороны", 3, 15, 8});
    fridayWorkout.addExercise(Exercise{"Подъемы на носки", 4, 20, 50});
    massGainProgram.setWorkoutForDay(5, fridayWorkout);

    programs.push_back(massGainProgram);

    // Программа 2: Похудение и рельеф
    TrainingProgram cuttingProgram("🔥 Сушка и рельеф");

    // Понедельник - Верх тела + Кардио
    Workout cuttingMonday("", "Верх тела + Кардио");
    cuttingMonday.addExercise(Exercise{"Жим гантелей лежа", 3, 15, 20});
    cuttingMonday.addExercise(Exercise{"Тяга вертикального блока", 3, 15, 40});
    cuttingMonday.addExercise(Exercise{"Жим гантелей сидя", 3, 15, 12});
    cuttingMonday.addExercise(Exercise{"Сгибания на бицепс", 3, 15, 10});
    cuttingMonday.addExercise(Exercise{"Разгибания на трицепс", 3, 15, 15});
    cuttingMonday.addExercise(Exercise{"Беговая дорожка", 1, 20, 0});
    cuttingProgram.setWorkoutForDay(1, cuttingMonday);

    // Вторник - Кардио и пресс
    Workout tuesdayWorkout("", "Кардио + Пресс");
    tuesdayWorkout.addExercise(Exercise{"Велотренажер", 1, 30, 0});
    tuesdayWorkout.addExercise(Exercise{"Скручивания", 3, 20, 0});
    tuesdayWorkout.addExercise(Exercise{"Планка", 3, 60, 0});
    tuesdayWorkout.addExercise(Exercise{"Подъем ног в висе", 3, 15, 0});
    cuttingProgram.setWorkoutForDay(2, tuesdayWorkout);

    // Четверг - Низ тела + Кардио
    Workout thursdayWorkout("", "Низ тела + Кардио");
    thursdayWorkout.addExercise(Exercise{"Приседания с гантелями", 3, 15, 15});
    thursdayWorkout.addExercise(Exercise{"Выпады", 3, 12, 10});
    thursdayWorkout.addExercise(Exercise{"Ягодичный мост", 3, 15, 40});
    thursdayWorkout.addExercise(Exercise{"Сгибания ног", 3, 15, 30});
    thursdayWorkout.addExercise(Exercise{"Эллипсоид", 1, 25, 0});
    cuttingProgram.setWorkoutForDay(4, thursdayWorkout);

    // Пятница - Круговая тренировка
    Workout fridayCircuit("", "Круговая тренировка");
    fridayCircuit.addExercise(Exercise{"Берпи", 4, 15, 0});
    fridayCircuit.addExercise(Exercise{"Прыжки на скакалке", 4, 100, 0});
    fridayCircuit.addExercise(Exercise{"Отжимания", 4, 20, 0});
    fridayCircuit.addExercise(Exercise{"Приседания", 4, 20, 0});
    fridayCircuit.addExercise(Exercise{"Планка", 4, 45, 0});
    cuttingProgram.setWorkoutForDay(5, fridayCircuit);

    programs.push_back(cuttingProgram);

    // Программа 3: Силовая
    TrainingProgram strengthProgram("🏋️ Силовая программа");

    // Понедельник - Жимовой день
    Workout strengthMonday("", "Жимовой день");
    strengthMonday.addExercise(Exercise{"Жим штанги лежа", 5, 5, 85});
    strengthMonday.addExercise(Exercise{"Жим штанги на наклонной", 4, 6, 60});
    strengthMonday.addExercise(Exercise{"Отжимания на брусьях", 3, 8, 20});
    strengthMonday.addExercise(Exercise{"Французский жим", 3, 8, 30});
    strengthProgram.setWorkoutForDay(1, strengthMonday);

    // Среда - Тяговой день
    Workout strengthWednesday("", "Тяговой день");
    strengthWednesday.addExercise(Exercise{"Становая тяга", 5, 3, 120});
    strengthWednesday.addExercise(Exercise{"Подтягивания с весом", 4, 6, 10});
    strengthWednesday.addExercise(Exercise{"Тяга штанги в наклоне", 4, 6, 70});
    strengthWednesday.addExercise(Exercise{"Тяга Т-грифа", 3, 8, 50});
    strengthProgram.setWorkoutForDay(3, strengthWednesday);

    // Пятница - Приседания и плечи
    Workout strengthFriday("", "Ноги + Плечи");
    strengthFriday.addExercise(Exercise{"Приседания со штангой", 5, 5, 100});
    strengthFriday.addExercise(Exercise{"Жим ногами", 4, 6, 140});
    strengthFriday.addExercise(Exercise{"Армейский жим", 4, 6, 40});
    strengthFriday.addExercise(Exercise{"Тяга штанги к подбородку", 3, 8, 30});
    strengthProgram.setWorkoutForDay(5, strengthFriday);

    programs.push_back(strengthProgram);

    // Программа 4: Фуллбади 3 раза в неделю
    TrainingProgram fullbodyProgram("🔄 Фуллбади 3 раза");

    Workout fullbodyWorkout("", "Фуллбади тренировка");
    fullbodyWorkout.addExercise(Exercise{"Приседания", 3, 10, 70});
    fullbodyWorkout.addExercise(Exercise{"Жим штанги лежа", 3, 10, 60});
    fullbodyWorkout.addExercise(Exercise{"Тяга штанги в наклоне", 3, 10, 50});
    fullbodyWorkout.addExercise(Exercise{"Армейский жим", 3, 12, 30});
    fullbodyWorkout.addExercise(Exercise{"Подтягивания", 3, 8, 0});
    fullbodyWorkout.addExercise(Exercise{"Сгибания на бицепс", 3, 12, 15});
    fullbodyWorkout.addExercise(Exercise{"Разгибания на трицепс", 3, 12, 20});

    // Устанавливаем на понедельник, среду, пятницу
    fullbodyProgram.setWorkoutForDay(1, fullbodyWorkout);
    fullbodyProgram.setWorkoutForDay(3, fullbodyWorkout);
    fullbodyProgram.setWorkoutForDay(5, fullbodyWorkout);

    programs.push_back(fullbodyProgram);

    // Программа 5: Для начинающих
    TrainingProgram beginnerProgram("🌟 Для начинающих");

    Workout beginnerWorkout("", "Базовая тренировка");
    beginnerWorkout.addExercise(Exercise{"Приседания с собственным весом", 3, 15, 0});
    beginnerWorkout.addExercise(Exercise{"Отжимания от пола", 3, 10, 0});
    beginnerWorkout.addExercise(Exercise{"Тяга гантелей в наклоне", 3, 12, 8});
    beginnerWorkout.addExercise(Exercise{"Жим гантелей сидя", 3, 12, 6});
    beginnerWorkout.addExercise(Exercise{"Планка", 3, 30, 0});
    beginnerWorkout.addExercise(Exercise{"Скручивания", 3, 15, 0});

    // Устанавливаем на понедельник и четверг
    beginnerProgram.setWorkoutForDay(1, beginnerWorkout);
    beginnerProgram.setWorkoutForDay(4, beginnerWorkout);

    programs.push_back(beginnerProgram);

    // Программа 6: Подготовка к бегу
    TrainingProgram runningProgram("🏃 Подготовка к бегу");

    // Понедельник - Силовая для бегунов
    Workout runningMonday("", "Силовая для бегунов");
    runningMonday.addExercise(Exercise{"Приседания с гантелями", 3, 12, 12});
    runningMonday.addExercise(Exercise{"Выпады", 3, 10, 8});
    runningMonday.addExercise(Exercise{"Ягодичный мост", 3, 15, 20});
    runningMonday.addExercise(Exercise{"Подъемы на носки", 4, 20, 0});
    runningMonday.addExercise(Exercise{"Планка", 3, 45, 0});
    runningProgram.setWorkoutForDay(1, runningMonday);

    // Среда - Интервальный бег
    Workout runningWednesday("", "Интервальный бег");
    runningWednesday.addExercise(Exercise{"Разминка 10 мин", 1, 1, 0});
    runningWednesday.addExercise(Exercise{"Интервалы 30/30", 8, 30, 0});
    runningWednesday.addExercise(Exercise{"Заминка 5 мин", 1, 1, 0});
    runningProgram.setWorkoutForDay(3, runningWednesday);

    // Пятница - Темповый бег + ОФП
    Workout runningFriday("", "Темповый бег + ОФП");
    runningFriday.addExercise(Exercise{"Бег 5 км в темпе", 1, 1, 0});
    runningFriday.addExercise(Exercise{"Отжимания", 3, 15, 0});
    runningFriday.addExercise(Exercise{"Приседания", 3, 20, 0});
    runningFriday.addExercise(Exercise{"Пресс", 3, 20, 0});
    runningProgram.setWorkoutForDay(5, runningFriday);

    // Суббота - Длительный бег
    Workout runningSaturday("", "Длительный бег");
    runningSaturday.addExercise(Exercise{"Бег 8-10 км", 1, 1, 0});
    runningSaturday.addExercise(Exercise{"Растяжка", 1, 10, 0});
    runningProgram.setWorkoutForDay(6, runningSaturday);

    programs.push_back(runningProgram);
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

void TrainingDiary::addProgram(const TrainingProgram& program) {
    programs.push_back(program);
    if (currentProgramIndex == -1) {
        currentProgramIndex = 0;
    }
    saveToFile();
}

void TrainingDiary::removeProgram(int index) {
    if (index >= 0 && index < programs.size()) {
        programs.erase(programs.begin() + index);
        if (currentProgramIndex >= programs.size()) {
            currentProgramIndex = programs.size() - 1;
        }
        saveToFile();
    }
}

void TrainingDiary::setCurrentProgram(int index) {
    if (index >= 0 && index < programs.size()) {
        currentProgramIndex = index;
        saveToFile();
    }
}

TrainingProgram& TrainingDiary::getCurrentProgram() {
    if (currentProgramIndex >= 0 && currentProgramIndex < programs.size()) {
        return programs[currentProgramIndex];
    }
    static TrainingProgram emptyProgram;
    return emptyProgram;
}

TrainingProgram& TrainingDiary::getProgram(int index) {
    if (index >= 0 && index < programs.size()) {
        return programs[index];
    }
    static TrainingProgram emptyProgram;
    return emptyProgram;
}

const std::vector<TrainingProgram>& TrainingDiary::getAllPrograms() const {
    return programs;
}

void TrainingDiary::createProgram(const std::string& name) {
    programs.push_back(TrainingProgram(name));
    currentProgramIndex = programs.size() - 1;
    saveToFile();
}

void TrainingDiary::duplicateProgram(int index, const std::string& newName) {
    if (index >= 0 && index < programs.size()) {
        TrainingProgram newProgram = programs[index];
        newProgram.setName(newName);
        programs.push_back(newProgram);
        currentProgramIndex = programs.size() - 1;
        saveToFile();
    }
}

void TrainingDiary::setWorkoutForDate(const std::string& date, const Workout& workout) {
    if (currentProgramIndex >= 0 && currentProgramIndex < programs.size()) {
        programs[currentProgramIndex].setWorkoutForDate(date, workout);
        saveToFile();
    }
}

Workout TrainingDiary::getWorkoutForDate(const std::string& date) const {
    if (currentProgramIndex >= 0 && currentProgramIndex < programs.size()) {
        return programs[currentProgramIndex].getWorkoutForDate(date);
    }
    return Workout();
}

bool TrainingDiary::hasWorkoutForDate(const std::string& date) const {
    if (currentProgramIndex >= 0 && currentProgramIndex < programs.size()) {
        return programs[currentProgramIndex].hasWorkoutForDate(date);
    }
    return false;
}

void TrainingDiary::setWorkoutTemplateForDay(int dayOfWeek, const Workout& workout) {
    if (currentProgramIndex >= 0 && currentProgramIndex < programs.size()) {
        programs[currentProgramIndex].setWorkoutForDay(dayOfWeek, workout);
        saveToFile();
    }
}

Workout TrainingDiary::getWorkoutTemplateForDay(int dayOfWeek) const {
    if (currentProgramIndex >= 0 && currentProgramIndex < programs.size()) {
        return programs[currentProgramIndex].getWorkoutForDay(dayOfWeek);
    }
    return Workout();
}

void TrainingDiary::applyProgramToWeek(const std::string& startDate) {
    if (currentProgramIndex >= 0 && currentProgramIndex < programs.size()) {
        // Получаем даты недели
        auto weekDates = getWeekDates(startDate);

        // Очищаем существующие тренировки для этой недели
        for (const auto& date : weekDates) {
            programs[currentProgramIndex].removeWorkoutForDate(date);
        }

        // Применяем шаблоны тренировок к каждому дню недели
        // weekDates[0] = понедельник, weekDates[1] = вторник, ..., weekDates[6] = воскресенье
        for (int dayOfWeek = 1; dayOfWeek <= 7; dayOfWeek++) {
            Workout templateWorkout = programs[currentProgramIndex].getWorkoutForDay(dayOfWeek);
            if (!templateWorkout.getType().empty()) {
                // Создаем новую тренировку для конкретной даты
                // dayOfWeek = 1 (понедельник) -> weekDates[0]
                // dayOfWeek = 2 (вторник) -> weekDates[1]
                // ...
                // dayOfWeek = 7 (воскресенье) -> weekDates[6]
                std::string date = weekDates[dayOfWeek - 1];
                Workout newWorkout(date, templateWorkout.getType());

                // Копируем все упражнения
                for (int i = 0; i < templateWorkout.getExerciseCount(); i++) {
                    newWorkout.addExercise(templateWorkout.getExercise(i));
                }

                programs[currentProgramIndex].setWorkoutForDate(date, newWorkout);
            }
        }
        saveToFile();
    }
}

std::vector<std::string> TrainingDiary::getWeekDates(const std::string& startDate) const {
    std::vector<std::string> weekDates;

    int startDay = std::stoi(startDate.substr(0, 2));
    int startMonth = std::stoi(startDate.substr(3, 2));
    int startYear = std::stoi(startDate.substr(6, 4));

    QDate qStartDate(startYear, startMonth, startDay);

    // Проверяем, что startDate - это понедельник
    // Если нет, корректируем до понедельника
    if (qStartDate.dayOfWeek() != 1) {
        int daysToMonday = qStartDate.dayOfWeek() - 1;
        qStartDate = qStartDate.addDays(-daysToMonday);
    }

    for (int i = 0; i < 7; i++) {
        QDate currentDate = qStartDate.addDays(i);
        weekDates.push_back(currentDate.toString("dd.MM.yyyy").toStdString());
    }

    return weekDates;
}

std::string TrainingDiary::getNextWeek(const std::string& currentStartDate) const {
    int startDay = std::stoi(currentStartDate.substr(0, 2));
    int startMonth = std::stoi(currentStartDate.substr(3, 2));
    int startYear = std::stoi(currentStartDate.substr(6, 4));

    QDate qStartDate(startYear, startMonth, startDay);
    QDate nextWeek = qStartDate.addDays(7);

    return nextWeek.toString("dd.MM.yyyy").toStdString();
}

std::string TrainingDiary::getPreviousWeek(const std::string& currentStartDate) const {
    int startDay = std::stoi(currentStartDate.substr(0, 2));
    int startMonth = std::stoi(currentStartDate.substr(3, 2));
    int startYear = std::stoi(currentStartDate.substr(6, 4));

    QDate qStartDate(startYear, startMonth, startDay);
    QDate prevWeek = qStartDate.addDays(-7);

    return prevWeek.toString("dd.MM.yyyy").toStdString();
}

void TrainingDiary::saveToFile() {
    std::ofstream file(filename, std::ios::binary);
    if (!file) return;

    // Save program count and current index
    int programCount = programs.size();
    file.write(reinterpret_cast<const char*>(&programCount), sizeof(programCount));
    file.write(reinterpret_cast<const char*>(&currentProgramIndex), sizeof(currentProgramIndex));

    for (const auto& program : programs) {
        // Save program name
        std::string name = program.getName();
        size_t nameLength = name.length();
        file.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
        file.write(name.c_str(), nameLength);

        // Save workout templates (weekly schedule)
        auto scheduledDays = program.getScheduledDays();
        int templateCount = scheduledDays.size();
        file.write(reinterpret_cast<const char*>(&templateCount), sizeof(templateCount));

        for (int dayOfWeek : scheduledDays) {
            file.write(reinterpret_cast<const char*>(&dayOfWeek), sizeof(dayOfWeek));
            Workout workout = program.getWorkoutForDay(dayOfWeek);

            // Save workout type
            std::string type = workout.getType();
            size_t typeLength = type.length();
            file.write(reinterpret_cast<const char*>(&typeLength), sizeof(typeLength));
            file.write(type.c_str(), typeLength);

            // Save exercises
            int exerciseCount = workout.getExerciseCount();
            file.write(reinterpret_cast<const char*>(&exerciseCount), sizeof(exerciseCount));

            for (int j = 0; j < exerciseCount; j++) {
                Exercise e = workout.getExercise(j);

                // Save exercise name
                size_t exerciseNameLength = e.name.length();
                file.write(reinterpret_cast<const char*>(&exerciseNameLength), sizeof(exerciseNameLength));
                file.write(e.name.c_str(), exerciseNameLength);

                // Save exercise data
                file.write(reinterpret_cast<const char*>(&e.sets), sizeof(e.sets));
                file.write(reinterpret_cast<const char*>(&e.reps), sizeof(e.reps));
                file.write(reinterpret_cast<const char*>(&e.weight), sizeof(e.weight));
            }
        }

        // Save dated workouts
        auto dates = program.getAllDates();
        int datedWorkoutCount = dates.size();
        file.write(reinterpret_cast<const char*>(&datedWorkoutCount), sizeof(datedWorkoutCount));

        for (const auto& date : dates) {
            Workout workout = program.getWorkoutForDate(date);

            // Save date
            size_t dateLength = date.length();
            file.write(reinterpret_cast<const char*>(&dateLength), sizeof(dateLength));
            file.write(date.c_str(), dateLength);

            // Save workout type
            std::string type = workout.getType();
            size_t typeLength = type.length();
            file.write(reinterpret_cast<const char*>(&typeLength), sizeof(typeLength));
            file.write(type.c_str(), typeLength);

            // Save exercises
            int exerciseCount = workout.getExerciseCount();
            file.write(reinterpret_cast<const char*>(&exerciseCount), sizeof(exerciseCount));

            for (int j = 0; j < exerciseCount; j++) {
                Exercise e = workout.getExercise(j);

                // Save exercise name
                size_t exerciseNameLength = e.name.length();
                file.write(reinterpret_cast<const char*>(&exerciseNameLength), sizeof(exerciseNameLength));
                file.write(e.name.c_str(), exerciseNameLength);

                // Save exercise data
                file.write(reinterpret_cast<const char*>(&e.sets), sizeof(e.sets));
                file.write(reinterpret_cast<const char*>(&e.reps), sizeof(e.reps));
                file.write(reinterpret_cast<const char*>(&e.weight), sizeof(e.weight));
            }
        }
    }

    file.close();
}

void TrainingDiary::loadFromFile() {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        return;
    }

    programs.clear();

    int programCount, currentIndex;
    file.read(reinterpret_cast<char*>(&programCount), sizeof(programCount));
    file.read(reinterpret_cast<char*>(&currentIndex), sizeof(currentIndex));

    for (int i = 0; i < programCount; i++) {
        // Load program name
        size_t nameLength;
        file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
        std::string programName(nameLength, ' ');
        file.read(&programName[0], nameLength);

        TrainingProgram program(programName);

        // Load workout templates
        int templateCount;
        file.read(reinterpret_cast<char*>(&templateCount), sizeof(templateCount));

        for (int j = 0; j < templateCount; j++) {
            int dayOfWeek;
            file.read(reinterpret_cast<char*>(&dayOfWeek), sizeof(dayOfWeek));

            // Load workout type
            size_t typeLength;
            file.read(reinterpret_cast<char*>(&typeLength), sizeof(typeLength));
            std::string type(typeLength, ' ');
            file.read(&type[0], typeLength);

            Workout workout;
            workout.setType(type);

            // Load exercises
            int exerciseCount;
            file.read(reinterpret_cast<char*>(&exerciseCount), sizeof(exerciseCount));

            for (int k = 0; k < exerciseCount; k++) {
                Exercise e;

                // Load exercise name
                size_t exerciseNameLength;
                file.read(reinterpret_cast<char*>(&exerciseNameLength), sizeof(exerciseNameLength));
                e.name.resize(exerciseNameLength);
                file.read(&e.name[0], exerciseNameLength);

                // Load exercise data
                file.read(reinterpret_cast<char*>(&e.sets), sizeof(e.sets));
                file.read(reinterpret_cast<char*>(&e.reps), sizeof(e.reps));
                file.read(reinterpret_cast<char*>(&e.weight), sizeof(e.weight));

                workout.addExercise(e);
            }

            program.setWorkoutForDay(dayOfWeek, workout);
        }

        // Load dated workouts
        int datedWorkoutCount;
        file.read(reinterpret_cast<char*>(&datedWorkoutCount), sizeof(datedWorkoutCount));

        for (int j = 0; j < datedWorkoutCount; j++) {
            // Load date
            size_t dateLength;
            file.read(reinterpret_cast<char*>(&dateLength), sizeof(dateLength));
            std::string date(dateLength, ' ');
            file.read(&date[0], dateLength);

            // Load workout type
            size_t typeLength;
            file.read(reinterpret_cast<char*>(&typeLength), sizeof(typeLength));
            std::string type(typeLength, ' ');
            file.read(&type[0], typeLength);

            Workout workout(date, type);

            // Load exercises
            int exerciseCount;
            file.read(reinterpret_cast<char*>(&exerciseCount), sizeof(exerciseCount));

            for (int k = 0; k < exerciseCount; k++) {
                Exercise e;

                // Load exercise name
                size_t exerciseNameLength;
                file.read(reinterpret_cast<char*>(&exerciseNameLength), sizeof(exerciseNameLength));
                e.name.resize(exerciseNameLength);
                file.read(&e.name[0], exerciseNameLength);

                // Load exercise data
                file.read(reinterpret_cast<char*>(&e.sets), sizeof(e.sets));
                file.read(reinterpret_cast<char*>(&e.reps), sizeof(e.reps));
                file.read(reinterpret_cast<char*>(&e.weight), sizeof(e.weight));

                workout.addExercise(e);
            }

            program.setWorkoutForDate(date, workout);
        }

        programs.push_back(program);
    }

    if (currentIndex >= 0 && currentIndex < programs.size()) {
        currentProgramIndex = currentIndex;
    } else if (!programs.empty()) {
        currentProgramIndex = 0;
    } else {
        currentProgramIndex = -1;
    }

    file.close();
}