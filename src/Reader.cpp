#include "Reader.hpp"

using namespace org::openscience::ms::finnigan;

///////////////
// CONSTANTS //
///////////////

static Property PROP_LIST[] = {
	Magic,
	Signature,
	Unknown1,
	Unknown2,
	Unknown3,
	Unknown4,
	Version,
	AuditStart,
	AuditEnd,
	Unknown5,
	Unknown6,
	Tag,
	LAST
};

/////////////////
// CONSTRUCTOR //
/////////////////

Reader::Reader(const std::string& file) :
	file(file),
	ifs(file.c_str(), std::ios::in | std::ios_base::binary),
	Section(PROP_LIST)
{
	// TODO Read header only when needed
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

void Reader::read_property(Property property) {

	boost::any value;
	
	// Read property from file
	switch(get_property_type_in_file(property)) {
		case Type::uint16:   value = read_int<uint16_t>(); break;
		case Type::cstring:  value = read_cstring(get_property_size(property)); break;
// TODO case Type::audittag: value = new AuditTag(this->ifs); 
	}

	// Set property if known
	if (property < Property::Unknown1)
		this->properties[property] = value;
}

/////////////////
// READ HEADER //
/////////////////

void Reader::read_header() {

	// TODO Remove this method and define an std::list<Property> that gives all the properties defined in this class in the order written in the file.

	this->ifs.seekg(0);
	this->read_property(Property::Magic);
	this->read_property(Property::Signature);
}
