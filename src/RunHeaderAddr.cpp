#include "RunHeaderAddr.cpp"
#include "Integer.hpp"

using namespace org::openscience::ms::finnigan;


/////////////////////
// DEFINE CHILDREN //
/////////////////////

void RunHeaderAddr::define_children() {
	if (this->children.empty()) {
                if(this->get_version()<64){
		    this->add_child(L"Addr",    new Integer<uint32_t>());
		    this->add_child(            new Integer<uint32_t>());
		    this->add_child(            new Integer<uint32_t>());
                }
                else{
                 this->add_child(L"Addr",       new Integer<uint64_t>());
                 this->add_child(               new Integer<uint64_t>());
                }
	}
}
