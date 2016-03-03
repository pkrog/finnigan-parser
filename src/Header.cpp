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
		this->add_child(L"magic",       new Integer<uint16_t>());
		this->add_child(L"signature",   new CString(9));
		this->add_child(                new Integer<uint32_t>());
		this->add_child(                new Integer<uint32_t>());
		this->add_child(                new Integer<uint32_t>());
		this->add_child(                new Integer<uint32_t>());
		this->add_child(L"version",     new Integer<uint32_t>());
		this->add_child(L"auditstart",  new AuditTag());
		this->add_child(L"auditend",    new AuditTag());
		this->add_child(                new Integer<uint32_t>());
		this->add_child(                new IntegerArray<uint8_t>(60));
		this->add_child(L"tag",         new CString(514));
	}
}
