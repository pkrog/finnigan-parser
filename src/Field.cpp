#include "Field.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////
// CONSTRUCTOR //
/////////////////

Field::Field(Id id, const std::wstring& name, Type type, size_t size) :
	id(id),
	name(name),
	type(type),
	size(size),
	pos(0)
{
}
