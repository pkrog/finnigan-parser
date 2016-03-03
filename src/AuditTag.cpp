#include "AuditTag.hpp"
#include "Integer.hpp"
#include "CString.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////////
// DEFINE CHILDREN //
/////////////////////

void AuditTag::define_children() {
	if (this->children.empty()) {
		this->add_child(L"time",    new Integer<uint64_t>());
		this->add_child(L"tag1",    new CString(25));
		this->add_child(L"tag2",    new CString(25));
		this->add_child(            new Integer<uint32_t>());
	}
}
