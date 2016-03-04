#include "Reader.hpp"
#include "Header.hpp"
#include "common.hpp"
#include <iostream>

using namespace org::openscience::ms::finnigan;

// TODO Remove Factory, because Reader can read version from header.
// TODO Rename Property to Field.

/////////////////
// CONSTRUCTOR //
/////////////////

Reader::Reader(const std::string& file, Observer *obs) :
	file(file),
	ifs(file.c_str(), std::ios::in | std::ios_base::binary),
	Element(0)
{
	// Set observer
	if (obs)
		this->add_observer(obs);

	// TODO Test file existence (is it done by ifstream ?) --> throw exception

	// TODO Try/catch any exception

	// Check magic number
	int magic = this->get_child(L"header")->get_child(L"magic")->get_int();
	if (magic != FINNIGAN_MAGIC)
		throw WrongMagicNumber(file, magic);
	// TODO Check signature
	// TODO Get version and instantiate a new Factory that is set as member into Section instances.

}

/////////////////////
// DEFINE CHILDREN //
/////////////////////

void Reader::define_children() {
	if (this->children.empty()) {
		this->add_child(L"header", new Header());
	}
}

//////////////////
// ADD OBSERVER //
//////////////////

void Reader::add_observer(Observer* obs) {
	this->observers.push_back(obs);
}
