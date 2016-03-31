#include "RawFileInfo.hpp"
#include "PString.hpp"
#include "InfoPreamble.hpp"
#include "names.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////////
// DEFINE CHILDREN //
/////////////////////

void RawFileInfo::define_children() {
	if (this->children.empty()) {
        this->add_child(FEN_INFO_PREAMBLE,  new InfoPreamble());
        this->add_child(FEN_HEADING_1,  new PString());
        this->add_child(FEN_HEADING_2,  new PString());
        this->add_child(FEN_HEADING_3,  new PString());
        this->add_child(FEN_HEADING_4,  new PString());
        this->add_child(FEN_HEADING_5,  new PString());
        this->add_child(                new PString());
	}
}
