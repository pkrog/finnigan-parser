#include "Reader.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////
// CONSTRUCTOR //
/////////////////

Reader::Reader(const std::string& file) :
	file(file),
	ifs(file.c_str(), std::ios::in | std::ios_base::binary)
{
	this->read_header();
}

//////////////////
// ADD OBSERVER //
//////////////////

void Reader::add_observer(Observer* obs) {
	this->observers.push_back(obs);
}

///////////////////
// READ PROPERTY //
///////////////////
#include <iostream>
void Reader::read_property(Property property) {
	switch(get_property_type_in_file(property)) {
//		case Type::uint16: { int i = read_int<uint16_t>(); std::wcerr << L"UINT16=" << i << "\n"; this->properties[property] = i; break; }
		case Type::uint16: this->properties[property] = read_int<uint16_t>(); break;
		case Type::cstring: this->properties[property] = read_cstring(get_property_size(property)); break;
	}
}

/////////////////
// READ HEADER //
/////////////////

void Reader::read_header() {

	// TODO do not read if already read => test property existence

	this->ifs.seekg(0);
	this->read_property(Property::Magic);
	this->read_property(Property::Signature);
}
