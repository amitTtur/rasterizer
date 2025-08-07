#pragma once
#ifndef MYEXCEPTION_HPP
#define MYEXCEPTION_HPP

#include <exception>
#include <string>

// saved numbers that indicate an error
enum {
	GENERAL_ERROR = 1,
	// add more if needed

	// raise error to get to error handler fast
	CALL_BACK = 0
};

class GeneralException : public std::exception // basic exception class
{
public:
	GeneralException(const std::string& message, const int code = 1) noexcept :
		_message(message)
	{
		_message = "Error code: " + std::to_string(code) + " ,Description: " + _message;
	};

	virtual ~GeneralException() noexcept = default;
	virtual const char* what() const noexcept { return _message.c_str(); };

protected:
	std::string _message;
};
#endif