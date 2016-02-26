#include "Factory.hpp"
#include "Reader66.hpp"
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

Reader* Factory::make_reader(const std::string& file) {

	// Read header
	Header header;
	std::ifstream ifs(file.c_str(), std::ios::in | std::ios_base::binary);
	ifs.read(reinterpret_cast<char*>(&header), sizeof(header));

	// Check magic number
	if (header.magic != MAGIC) {
		for(auto o: this->observers)
			o->wrong_magic_number(file, header.magic);
		return nullptr;
	}

	// Check signature
	std::wstring signature = arr2wstring(header.signature);
	if (signature.compare(SIGNATURE) != 0) {
		for(auto o: this->observers)
			o->wrong_signature(file, signature);
		return nullptr;
	}

	// Found version
	for(auto o: this->observers)
		o->file_version(file, header.version);

	// Create parser instance
	Reader* reader = nullptr;
	switch(header.version) {
		case 66: reader = new Reader66(file); break;
		default: reader = header.version > 66 ? new Reader66(file) : new Reader(file);
	}

	// Add observers
	if (reader)
		for(auto o: this->observers)
			reader->add_observer(o);

	return reader;
}
