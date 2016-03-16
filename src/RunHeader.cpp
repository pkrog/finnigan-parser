#include "SequencerRow.hpp"
#include "InjectionData.hpp"
#include "PString.hpp"
#include "Integer.hpp"
#include "InfoPreamble.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////////
// DEFINE CHILDREN //
/////////////////////

void InfoPreamble::define_children() {
	if (this->children.empty()) {
	    //Children common to all the version.
        this->add_child(FEN_SAMPLE_INFO,          new Integer<uint32_t>());// TO CHANGE TO SAMPLE INFO CLASS
        this->add_child(FEN_FILENAME_1,           new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_2,           new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_3,           new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_4,           new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_5,           new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_6,           new IntegerArray<uint16_t>(260));
        this->add_child(                          new Float<double>();
        this->add_child(                          new Float<double>();
        this->add_child(FEN_FILENAME_7,           new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_8,           new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_9,           new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_10,          new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_11,          new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_12,          new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_13,          new IntegerArray<uint16_t>(260));

	}
}


