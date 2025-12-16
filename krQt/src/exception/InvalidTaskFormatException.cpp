#include "exceptions/InvalidTaskFormatException.h"

InvalidTaskFormatException::InvalidTaskFormatException(const std::string& details)
    : TaskParseFailedException("invalid format - " + details)
{
}

