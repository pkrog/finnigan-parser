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
	    //Children common to all the version.
		this->add_child(FEN_METHOD_FILE_PRESENT,  new Integer<uint32_t>());
		this->add_child(FEN_YEAR                  new Integer<uint16_t>());
		this->add_child(FEN_MONTH                 new Integer<uint16_t>());
		this->add_child(FEN_WEEKDAY,              new Integer<uint16_t>());
		this->add_child(FEN_DAY,                  new Integer<uint16_t>());
		this->add_child(FEN_HOUR,                 new Integer<uint16_t>());
		this->add_child(FEN_MINUTE,               new Integer<uint16_t>());
		this->add_child(FEN_SECOND,               new Integer<uint16_t>());
		this->add_child(FEN_MILLISECOND,          new Integer<uint16_t>());

        if(this->get_version()>=57){
            this->add_child(                              new Integer<uint32_t>());
            this->add_child(FEN_DATA_ADRESS,              new Integer<uint32_t>());
            this->add_child(FEN_N_CONTROLLERS,            new Integer<uint32_t>());
            this->add_child(FEN_N_CONTROLLERS2,           new Integer<uint32_t>());
            if(this->get_version()<64){

            }
        }


		//Version superior to 57.
		this->add_child(FEN)


		this->add_child(                     new PString());
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

