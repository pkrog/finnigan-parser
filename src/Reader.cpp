#include "Reader.hpp"

using namespace org::openscience::ms::finnigan;

// TODO Remove Factory, because Reader can read version from header.
// TODO Rename Property to Field.

/////////////////
// CONSTRUCTOR //
/////////////////

Reader::Reader(const std::string& file) :
	Element(file, std::shared_ptr<std::ifstream>(new std::ifstream(file.c_str(), std::ios::in | std::ios_base::binary)), 0)
{
	ADD_Field(Header, section);
	// TODO Test file existence (is it done by ifstream ?) --> throw exception

	// TODO Try/catch any exception
	// TODO Read header only when needed

	// TODO Check magic number
	// TODO Check signature
	// TODO Get version and instantiate a new Factory that is set as member into Section instances.

}
