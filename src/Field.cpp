#include "Field.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////
// CONSTRUCTOR //
/////////////////

Field::Field(Id id, Type type, size_t size) :
	id(id),
	type(type),
	size(size),
	pos(0)
{
}
