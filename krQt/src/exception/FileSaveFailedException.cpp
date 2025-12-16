#include "exceptions/FileSaveFailedException.h"

FileSaveFailedException::FileSaveFailedException(const std::string& filename)
    : FileAccessFailedException(filename, "save")
{
}

