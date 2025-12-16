#include "exceptions/TaskNotFoundException.h"

TaskNotFoundException::TaskNotFoundException(int taskId)
    : AppException("Task not found with ID: " + std::to_string(taskId))
{
}

