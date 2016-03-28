#include "InjectionData.hpp"
#include "Integer.hpp"
#include "Float.hpp"
#include "CString.hpp"
#include "names.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////////
// DEFINE CHILDREN //
/////////////////////

void InjectionData::define_children() {
	if (this->children.empty()) {
		this->add_child(                        new Integer<uint32_t>());
		this->add_child(FEN_ROW_NUMBER,         new Integer<uint32_t>());
		this->add_child(                        new Integer<uint32_t>());
		this->add_child(FEN_VIAL,               new CString(6));
		this->add_child(FEN_INJECTION_VOLUME,   new Float<double>());
		this->add_child(FEN_SAMPLE_WEIGHT,      new Float<double>());
		this->add_child(FEN_SAMPLE_VOLUME,      new Float<double>());
		this->add_child(FEN_INT_STD_AMOUNT,     new Float<double>());
		this->add_child(FEN_DILUTION_FACTOR,    new Float<double>());
	}
}

