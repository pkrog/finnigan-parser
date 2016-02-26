#include "types.hpp"

using namespace org::openscience::ms;

///////////////////////
// GET PROPERTY TYPE //
///////////////////////

finnigan::Type finnigan::get_property_type_in_file(Property property) {

	switch(property) {
		case Property::Magic:     return Type::uint16;
		case Property::Signature: return Type::cstring;
	}
}

///////////////////////
// GET PROPERTY SIPE //
///////////////////////

int finnigan::get_property_size(Property property) {

	switch(property) {
		case Property::Magic:     return 1;
		case Property::Signature: return 9;
	}
}
