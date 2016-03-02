#include "Header.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////
// CONSTRUCTOR //
/////////////////

Header::Header(const std::string& file, std::shared_ptr<std::ifstream> ifs) :
	Element(file, ifs, 0)
{
	this->add_field(Field::Id::Magic,        Field::Type::uint16);
	this->add_field(Field::Id::Signature,    Field::Type::cstring);
	this->add_field(Field::Id::Unknown,      Field::Type::uint32);
	this->add_field(Field::Id::Unknown,      Field::Type::uint32);
	this->add_field(Field::Id::Unknown,      Field::Type::uint32);
	this->add_field(Field::Id::Unknown,      Field::Type::uint32);
	this->add_field(Field::Id::Version,      Field::Type::uint32);
	this->read_all_fields();
}
