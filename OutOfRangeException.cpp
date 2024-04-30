#include "OutOfRangeException.hpp"

OutOfRangeException::OutOfRangeException(std::string prob)
    : Exception("OutOfRange", prob)
{
    
}
