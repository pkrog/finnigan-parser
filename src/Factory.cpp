#include "Factory.hpp"
//#include "Reader66.hpp"
#include <fstream>
#include "types.hpp"
#include "common.hpp"
#include "Observer.hpp"

using namespace org::openscience::ms::finnigan;

//////////////////
// ADD OBSERVER //
//////////////////

void Factory::add_observer(Observer* obs) {
	this->observers.push_back(obs);
}

/////////////////
// MAKE READER //
/////////////////

Reader* Factory::make_reader(const char* file) {

	std::wstring f = arr2wstring(file);

	// Read header
	Header header;
	std::ifstream ifs(file, std::ios::in | std::ios_base::binary);
	ifs.read(reinterpret_cast<char*>(&header), sizeof(header));

	// Check magic number
	if (header.magic != MAGIC) {
		for(auto o: this->observers)
			o->wrong_magic_number(f, header.magic);
		return nullptr;
	}

	// Check signature
	std::wstring signature = arr2wstring(header.signature);
	if (signature.compare(SIGNATURE) != 0) {
		for(auto o: this->observers)
			o->wrong_signature(f, signature);
		return nullptr;
	}

	// Create parser instance

	return nullptr;
}
