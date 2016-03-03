#include "Field.hpp"
#include "Exception.hpp"

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

std::ifstream::pos_type Field::get_byte_size_in_file() const {

	if (this->type == typeid(uint16_t))
		return 2;

	throw UnknownType(this->type_name);
}
