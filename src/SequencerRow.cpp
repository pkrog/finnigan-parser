#include "SequencerRow.hpp"
#include "InjectionData.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////////
// DEFINE CHILDREN //
/////////////////////

void SequencerRow::define_children() {
	if (this->children.empty()) {
		this->add_child(FEN_INJECTION,       new InjectionData());
	}
}
