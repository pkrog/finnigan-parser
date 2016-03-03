#include "Header.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////
// CONSTRUCTOR //
/////////////////

Header::Header(const std::string& file, std::shared_ptr<std::ifstream> ifs) :
	Element(file, ifs, 0)
{
	ADD_FIELD(L"Magic",        uint16_t,    1);
	ADD_FIELD(L"Signature",    Char,        9);
	ADD_FIELD(L"",             uint32_t,    1);
	ADD_FIELD(L"",             uint32_t,    1);
	ADD_FIELD(L"",             uint32_t,    1);
	ADD_FIELD(L"",             uint32_t,    1);
	ADD_FIELD(L"Version",      uint32_t,    1);
}
