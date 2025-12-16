#include "exceptions/FileAccessFailedException.h"

FileAccessFailedException::FileAccessFailedException(const std::string& filename, const std::string& operation)
    : AppException("File access failed (" + operation + "): " + filename)
{
}

