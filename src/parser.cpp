#include "Factory.hpp"
#include "Logger.hpp"
#include <iostream>
#include "Reader.hpp"
#include "Integer.hpp"

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
//	Factory factory;
//	factory.add_observer(&logger);
//	// TODO try/catch errors from Reader constructor.
		Reader reader(file);
		reader.add_observer(&logger);
//		std::wcout << L"SIGNATURE = " << boost::any_cast<std::wstring>(reader.get_property(Property::Signature)) << L"\n";
		Element *header = reader.get_child(L"header");
		Element *magic = header->get_child(L"magic");
		std::wcout << L"MAGIC = " << std::hex << magic->get_int() << L"\n";
	}
	catch (Exception& e) {
		std::wcerr << e.what() << L"\n";
		return SOMETHING_WRONG_HAPPENED;
	}

	return 0;
}
