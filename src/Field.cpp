#include "Field.hpp"
#include "Exception.hpp"
#include "Element.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////
// CONSTRUCTOR //
/////////////////

Field::Field(const std::wstring& name, std::type_index type, const std::wstring& type_name, size_t size) :
	name(name),
	type(type),
	type_name(type_name),
	size(size),
	pos(0),
	pos_has_been_set(false),
	value_has_been_set(false)
{
}

///////////////////////////
// GET BYTE SIZE IN FILE //
///////////////////////////
#if 0
std::ifstream::pos_type Field::get_byte_size_in_file() const {

	// Basic types
	if (this->type == typeid(uint16_t))
		return 2;

	// If it has a value, try to use it as a subclass of Element
	if (this->has_value()) {
		try {
			Element *e = boost::any_cast<Element*>(this->value);
			return e->get_byte_size_in_file();
		}
 		catch (const boost::bad_any_cast&) {
		}
	}

	throw UnknownType(this->type_name);
}
#endif
