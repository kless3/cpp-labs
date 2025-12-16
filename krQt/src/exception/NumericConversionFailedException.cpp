#include "exceptions/NumericConversionFailedException.h"

NumericConversionFailedException::NumericConversionFailedException(const std::string& fieldName)
    : TaskParseFailedException("cannot convert numeric field '" + fieldName + "'")
{
}

