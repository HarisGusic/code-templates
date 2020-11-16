#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "../logic/Implicant.h"
#include "../logic/McCluskey.h"

typedef std::vector<std::string> arglist;
typedef decltype(arglist().begin()) arglist_iter;

#define is_opt(s, o1, o2) ((s) == (o1) || (s) == (o2))
/**
 * Execute 'function'. If it returns a non-zero value, an error has
 * occurred, exit the calling function with the same error code.
 *
 * This is to be used when a command calls a sub-command.
 */
#define eval(function) { auto error_code = function; if (error_code) return error_code; }

/**
 * Read a line from std::cin and parse it into a vector of strings
 * Delimiter used for parsing is any type of whitespace.
 *
 * Text enclosed in double quotes is considered
 * a single word even if it contains whitespace,
 * and the quotes are not included in the result.
 */
arglist read_line();

/**
 * Print a message indicating that the specified command/option is unrecognized,
 * whilst informing the user whether it is a command or an option.
 */
void unrecognized_opt_cmd(const std::string &opt);


/**
 * Execute a command, or print a message if it does not exist.
 * @param it_arg Iterator to the first argument in the list.
 * @param end - End of the argument list
 * @return Status code of the executed command.
 */
int execute_command(const arglist_iter &it_arg, const arglist_iter &end)

/**
 * Extract variable count from string.
 * @tparam Int - any integral type
 * @return Whether the operation was successful.
 */
template<class Int>
bool extract_n(const std::string &s, Int &n)
{
	if (s.empty())
		return false;
	auto stream = std::istringstream(s);
	long long x;
	if (stream >> x && (n = x, stream.get(), stream.eof()))
		return true;
	n = 0;
	return false;
}
