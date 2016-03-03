#include "Field.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////
// CONSTRUCTOR //
/////////////////

Field::Field(const std::wstring& name, std::type_index type, const std::wstring& type_name, size_t size) :
	name(name),
	type(type),
	type_name(type_name),
	size(size),
	pos(0)
{
}
