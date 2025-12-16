#include "exceptions/FileOpenFailedException.h"

FileOpenFailedException::FileOpenFailedException(const std::string& filename)
    : FileAccessFailedException(filename, "open")
{
}

