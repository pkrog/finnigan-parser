#include "Header.hpp"
#include "Integer.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////////
// DEFINE CHILDREN //
/////////////////////

void Header::define_children() {
	if (this->children.empty()) {
		this->add_child(L"magic", new Integer<uint16_t>());

//	ADD_FIELD(L"Magic",        uint16_t,    1);
//	ADD_FIELD(L"Signature",    Char,        9);
//	ADD_FIELD(L"",             uint32_t,    1);
//	ADD_FIELD(L"",             uint32_t,    1);
//	ADD_FIELD(L"",             uint32_t,    1);
//	ADD_FIELD(L"",             uint32_t,    1);
//	ADD_FIELD(L"Version",      uint32_t,    1);
	}
}
