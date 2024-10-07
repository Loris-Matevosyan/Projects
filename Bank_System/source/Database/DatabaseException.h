#ifndef _DATABASEEXCEPTION_
#define _DATABASEEXCEPTION_

#include <ios>
#include <string>



class FileOpenException : public std::ios_base::failure
{
public:
    FileOpenException() : std::ios_base::failure("ERROR: Database file can't be open") {}

    FileOpenException(const char* text) : std::ios_base::failure(text) {}
    FileOpenException(std::string text) : std::ios_base::failure(text) {}

    FileOpenException(const FileOpenException& exceptionObject) = default;
    FileOpenException& operator=(const FileOpenException& exceptionObject) = default;

};



#endif //_DATABASEEXCEPTION_