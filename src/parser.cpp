#include "Factory.hpp"
#include "Logger.hpp"
#include <iostream>

using namespace org::openscience::ms::finnigan;

///////////////
// CONSTANTS //
///////////////

#define NOT_A_FINNIGAN_FILE 1

//////////
// MAIN //
//////////

int main(int argc, char* argv[]) {

	// Get input raw file path
	// TODO Test that there's at least one arg
	// TODO use some getopt lib
	const std::string file(argv[1]);

	// Create reader instance from factory.
	Logger logger(std::wcerr);
	Factory factory;
	factory.add_observer(&logger);
	Reader* reader = factory.make_reader(file);
	if ( ! reader)
		return NOT_A_FINNIGAN_FILE;

	return 0;
}
