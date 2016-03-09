#include "SequencerRow.hpp"
#include "InjectionData.hpp"
#include "PString.hpp"
#include "Integer.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////////
// DEFINE CHILDREN //
/////////////////////

void SequencerRow::define_children() {
	if (this->children.empty()) {
		this->add_child(FEN_METHOD_FILE_PRESENT,new Integer<uint32_t>());
		this->add_child(                     new PString());
		this->add_child(                     new PString());
		this->add_child(FEN_ID,              new PString());
		this->add_child(FEN_COMMENT,         new PString());
		this->add_child(FEN_USER_LABEL_1,    new PString());
		this->add_child(FEN_USER_LABEL_2,    new PString());
		this->add_child(FEN_USER_LABEL_3,    new PString());
		this->add_child(FEN_USER_LABEL_4,    new PString());
		this->add_child(FEN_USER_LABEL_5,    new PString());
		this->add_child(FEN_INST_METHOD,     new PString());
		this->add_child(FEN_PROC_METHOD,     new PString());
		this->add_child(FEN_FILENAME,        new PString());
		this->add_child(FEN_PATH,            new PString());

		if (this->get_version() >= 57) {
			this->add_child(FEN_VIAL,            new PString());
			this->add_child(                     new PString());
			this->add_child(                     new PString());
			this->add_child(                     new Integer<uint32_t>()); // Or PString ?
		}

		if (this->get_version() >= 60) {
			this->add_child(                     new PString());
			this->add_child(                     new PString());
			this->add_child(                     new PString());
			this->add_child(                     new PString());
			this->add_child(                     new PString());
			this->add_child(                     new PString());
			this->add_child(                     new PString());
			this->add_child(                     new PString());
			this->add_child(                     new PString());
			this->add_child(                     new PString());
			this->add_child(                     new PString());
			this->add_child(                     new PString());
			this->add_child(                     new PString());
			this->add_child(                     new PString());
			this->add_child(                     new PString());
		}
	}
}

