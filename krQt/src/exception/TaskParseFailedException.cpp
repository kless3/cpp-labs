#include "exceptions/TaskParseFailedException.h"

TaskParseFailedException::TaskParseFailedException(const std::string& reason)
    : AppException("Task parse failed: " + reason)
{
}

