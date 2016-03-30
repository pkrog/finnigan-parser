#include "SequencerRow.hpp"
#include "InjectionData.hpp"
#include "PString.hpp"
#include "Integer.hpp"
#include "InfoPreamble.hpp"
#include "names.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////////
// DEFINE CHILDREN //
/////////////////////

void InfoPreamble::define_children() {
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
            this->add_child(FEN_N_CONTROLLERS2,           new Integer<uint32_t>());
            this->add_child(                              new Integer<uint32_t>());
            this->add_child(                              new Integer<uint32_t>());
            //The number of cotrollers is read.
            if(this->get_version()<64){
                int nController=this->get_child(FEN_N_CONTROLLERS)->get_int();
                for(int i=0;i<nController;i++){
                //Reading the adress
                    std::wstring nameadress = FEN_RUN_HEADER_ADR;
                    nameadress += L"_";
                    nameadress += std::to_wstring(i);
                    this->add_child(nameadress,            new Integer<uint32_t>());
                    this->add_child(                       new Integer<uint32_t>());
                    this->add_child(                       new Integer<uint32_t>());
                    uint64_t addr_run_header=(uint64_t)this->get_child(nameadress)->get_int();
                //putting the pos of the child.
                    std::wstring namechild = FEN_RUN_HEADER;
                    namechild += L"_";
                    namechild += std::to_wstring(i);
                    this->get_top()->add_child(namechild,          new RunHeader());
                    this->get_top()->get_child(namechild)->set_pos(nadress);
                }
            }
            //Adding the correct number of child depending of the version.
            this->add_child(FEN_N_CONTROLLERS2,           new Integer<uint32_t>());

            this->get_top();


            //Getting the good version number.

            if(this->get_version()<64){

            }
        }

	}
}

