#include "exceptions/TaskNotFoundException.h"
#include <format>

TaskNotFoundException::TaskNotFoundException(int taskId)
    : AppException(std::format("Task not found with ID: {}", taskId))
{
}

