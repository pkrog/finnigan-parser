#include "FinniganFileReaderFactory.hpp"

using namespace org::openscience::ms;

//////////
// MAIN //
//////////

int main(int argc, char* argv[]) {

	// Get input raw file path
	// TODO Test that there's at least one arg
	// TODO use some getopt lib
	const char* file = argv[0];

	// Create reader instance from factory.
	FinniganFileReader* reader = make_finnigan_file_reader(file);

	return 0;
}
