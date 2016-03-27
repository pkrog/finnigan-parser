#include "Element.hpp"
#include "PString.hpp"
#include "RawFileInfo.hpp"
#include "Integer.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////////
// DEFINE CHILDREN //
/////////////////////

void RawFileInfo::define_children() {
	if (this->children.empty()) {
	    //Children common to all the version.
        this->add_child(FEN_METHOD_FILE_PRESENT,  new Integer<uint32_t>());
        this->add_child(FEN_YEAR,                 new Integer<uint16_t>());
		this->add_child(FEN_MONTH,                new Integer<uint16_t>());
		this->add_child(FEN_WEEKDAY,              new Integer<uint16_t>());
		this->add_child(FEN_DAY,                  new Integer<uint16_t>());
		this->add_child(FEN_HOUR,                 new Integer<uint16_t>());
		this->add_child(FEN_MINUTE,               new Integer<uint16_t>());
		this->add_child(FEN_SECOND,               new Integer<uint16_t>());
		this->add_child(FEN_MILLISECOND,          new Integer<uint16_t>());

		//Version superior to 57.
        if(this->get_version()>=57){
            this->add_child(                              new Integer<uint32_t>());
            this->add_child(FEN_DATA_ADRESS,              new Integer<uint32_t>());
            this->add_child(FEN_N_CONTROLLERS,            new Integer<uint32_t>());
            //The number of cotrollers is read directly.
            int nController=this->get_child(FEN_N_CONTROLLERS)->get_int();
            //Adding the correct number of child depending of the version.
            this->add_child(FEN_N_CONTROLLERS2,           new Integer<uint32_t>());
            this->get_top();


            //Getting the good version number.

            if(this->get_version()<64){

            }
        }

	}
}
