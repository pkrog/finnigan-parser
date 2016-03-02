#include "Header.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////
// CONSTRUCTOR //
/////////////////

Header::Header(const std::string& file, std::shared_ptr<std::ifstream> ifs) :
	Element(file, ifs, 0)
{
	ADD_FIELD(Magic,        uint16);
	ADD_FIELD(Signature,    cstring);
	ADD_FIELD(Unknown,      uint32);
	ADD_FIELD(Unknown,      uint32);
	ADD_FIELD(Unknown,      uint32);
	ADD_FIELD(Unknown,      uint32);
	ADD_FIELD(Version,      uint32);
	this->read_all_fields();
}
