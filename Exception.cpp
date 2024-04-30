#include <iostream>
#include "Exception.hpp"
#include "OutOfRangeException.hpp"
#include "FileNotOpenException.hpp"

Exception::Exception(std::string tagString, std::string probString)
{
    mTag = tagString;
    mProblem = probString;
}

void Exception::PrintDebug() const
{
    std::cerr << "**  Error ("<<mTag<<") **\n";
    std::cerr << "Problem: " << mProblem << "\n\n";
}

// function to show error handling!?
void ExceptionHandling() {
    try {
    } catch (const OutOfRangeException& e) {
        std::cerr << "Out of Range Exception: ";
        e.PrintDebug();
    } catch (const FileNotOpenException& e) {
        std::cerr << "File Not Open Exception: ";
        e.PrintDebug();
    } catch (const Exception& e) {
        std::cerr << "General exception: ";
        e.PrintDebug();
    } catch (...) {
        std::cerr << "Caught an unknown exception\n";
    }
}
