#include "types.hpp"

using namespace org::openscience::ms;

///////////////////////////////
// PROPERTY ATTRIBUTES CLASS //
///////////////////////////////

struct PropAttr {
	Type type;
	int  size;
	PropAttr() : type(Type::NONE), size(0) {}
	PropAttr(Type t, int s) : type(t), size(s) {}
};

/////////////////////////////
// GET PROPERTY ATTRIBUTES //
/////////////////////////////

PropAttr* get_prop_attr(Property property) {

	static std::vector<PropAttr>* prop_attr = nullptr;

	// Define attributes
	if ( ! prop_attr) {
		prop_attr = new std::vector<PropAttr>(Property::LAST);
		prop_attr[Property::Magic]      = PropAttr(Type::uint16,    1);
		prop_attr[Property::Signature]  = PropAttr(Type::cstring,   9);
	}

	// Return attributes
	return &(*prop_attr)[property];
}

///////////////////////
// GET PROPERTY TYPE //
///////////////////////

finnigan::Type finnigan::get_property_type_in_file(Property property) {
	return get_prop_attr(property)->type;
}

///////////////////////
// GET PROPERTY SIPE //
///////////////////////

int finnigan::get_property_size(Property property) {
	return get_prop_attr(property)->size;
}
