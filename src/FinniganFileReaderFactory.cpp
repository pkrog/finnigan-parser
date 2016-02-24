#include "FinniganFileReaderFactory.hpp"
//#include "FinniganFileReader66.hpp"
#include <iostream>
#include <fstream>
#include <cstdint>

using namespace org::openscience::ms;

///////////////////////////////
// MAKE FINNIGAN FILE READER //
///////////////////////////////

FinniganFileReader* make_finnigan_file_reader(const char* file) {

	/* Read file type in header */
	uint16_t magic;
	uint32_t version;
	std::ifstream ifs(file, std::ios_base::binary);
	ifs >> magic;
	std::wcout << L"MAGIC = " << magic << std::endl;

	/* Read version in header */

	/* Create parser instance */
}
