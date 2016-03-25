#include "RunHeader.hpp"
#include "Integer.hpp"
#include "IntegerArray.hpp"
#include "Float.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////////
// DEFINE CHILDREN //
/////////////////////

void RunHeader::define_children() {
	if (this->children.empty()) {
	    //Children common to all the version.
        this->add_child(FEN_SAMPLE_INFO,          new Integer<uint32_t>());// TO CHANGE TO SAMPLE INFO CLASS
        this->add_child(FEN_FILENAME_1,           new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_2,           new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_3,           new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_4,           new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_5,           new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_6,           new IntegerArray<uint16_t>(260));
        this->add_child(                          new Float<double>());
        this->add_child(                          new Float<double>());
        this->add_child(FEN_FILENAME_7,           new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_8,           new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_9,           new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_10,          new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_11,          new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_12,          new IntegerArray<uint16_t>(260));
        this->add_child(FEN_FILENAME_13,          new IntegerArray<uint16_t>(260));
        if(this->get_version()<64){
            this->add_child(FEN_SCAN_TRAILER_ADR,         new Integer<uint32_t>());
            this->add_child(FEN_SCAN_PARAMS_ADR,          new Integer<uint32_t>());
            this->add_child(                              new Integer<uint32_t>());
            this->add_child(                              new Integer<uint32_t>());
            this->add_child(FEN_NSEGS,                    new Integer<uint32_t>());
            this->add_child(                              new Integer<uint32_t>());
            this->add_child(                              new Integer<uint32_t>());
            this->add_child(FEN_OWN_ADRESS,               new Integer<uint32_t>());
            this->add_child(                              new Integer<uint32_t>());
            this->add_child(                              new Integer<uint32_t>());
            // TO DO when adding hte sample info, whild need to be added here.
        }else{
            this->add_child(                              new Integer<uint32_t>());
            this->add_child(                              new Integer<uint32_t>());
            this->add_child(                              new Integer<uint32_t>());
            this->add_child(                              new Integer<uint32_t>());
            this->add_child(                              new Integer<uint32_t>());
            this->add_child(                              new Integer<uint32_t>());
            this->add_child(                              new Integer<uint32_t>());
            this->add_child(                              new Integer<uint32_t>());
            this->add_child(                              new Integer<uint32_t>());
            this->add_child(                              new Integer<uint32_t>());


        }

	}
}


