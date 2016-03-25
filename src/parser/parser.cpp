#include <iostream>
#include <msfinnigan/Logger.hpp>
#include <msfinnigan/Reader.hpp>

using namespace org::openscience::ms::finnigan;

///////////////
// CONSTANTS //
///////////////

#define NOT_A_FINNIGAN_FILE 1
#define SOMETHING_WRONG_HAPPENED 100

//////////
// MAIN //
//////////

int main(int argc, char* argv[]) {

	// Get input raw file path
	// TODO Test that there's at least one arg
	// TODO use some getopt lib
	const std::string file(argv[1]);

	// Create reader instance from factory.
	try {
		Logger logger(std::wcerr);
		Reader reader(file, &logger);
		reader.read();
	}
	catch (Exception& e) {
		std::wcerr << e.what() << L"\n";
		return SOMETHING_WRONG_HAPPENED;
	}

	return 0;
}
