#include "Header.hpp"
#include "Integer.hpp"
#include "IntegerArray.hpp"
#include "CString.hpp"
#include "AuditTag.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////////
// DEFINE CHILDREN //
/////////////////////

void Header::define_children() {
	if (this->children.empty()) {
		this->add_child(FEN_MAGIC,          new Integer<uint16_t>());
		this->add_child(FEN_SIGNATURE,      new CString(9));
		this->add_child(                    new Integer<uint32_t>());
		this->add_child(                    new Integer<uint32_t>());
		this->add_child(                    new Integer<uint32_t>());
		this->add_child(                    new Integer<uint32_t>());
		this->add_child(FEN_VERSION,        new Integer<uint32_t>());
		this->add_child(FEN_AUDIT_START,    new AuditTag());
		this->add_child(FEN_AUDIT_END,      new AuditTag());
		this->add_child(                    new Integer<uint32_t>());
		this->add_child(                    new IntegerArray<uint8_t>(60));
		this->add_child(FEN_TAG,            new CString(514));
	}
}
