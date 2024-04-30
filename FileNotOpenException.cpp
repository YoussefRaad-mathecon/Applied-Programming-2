#include "FileNotOpenException.hpp"

FileNotOpenException::FileNotOpenException(std::string prob)
    : Exception("FileNotOpen", prob)
{

}
