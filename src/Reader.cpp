#include "Reader.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////
// CONSTRUCTOR //
/////////////////

Reader::Reader(const std::string& file) :
	file(file),
	ifs(file.c_str(), std::ios::in | std::ios_base::binary)
{
}

//////////////////
// ADD OBSERVER //
//////////////////

void Reader::add_observer(Observer* obs) {
	this->observers.push_back(obs);
}
