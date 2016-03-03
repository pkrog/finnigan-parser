#include "Factory.hpp"
#include "Logger.hpp"
#include <iostream>
#include "Reader.hpp"

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
//	Factory factory;
//	factory.add_observer(&logger);
//	// TODO try/catch errors from Reader constructor.
		Reader reader(file, &logger);
//		std::wcout << L"MAGIC = " << std::hex << boost::any_cast<int>(reader.get_property(Property::Magic)) << L"\n";
//		std::wcout << L"SIGNATURE = " << boost::any_cast<std::wstring>(reader.get_property(Property::Signature)) << L"\n";

	return 0;
}
