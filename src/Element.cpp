#include "Element.hpp"
#include "common.hpp"
#include "Observer.hpp"

using namespace org::openscience::ms::finnigan;

//////////////////
// CONSTRUCTORS //
//////////////////

Element::Element(const std::string& file, std::shared_ptr<std::ifstream> ifs, std::ifstream::pos_type pos) :
	file(file),
	ifs(ifs),
	start_pos(pos)
{
}

//////////////////
// ADD OBSERVER //
//////////////////

void Element::add_observer(Observer* obs) {
	this->observers.push_back(obs);
}

///////////////
// ADD FIELD //
///////////////

void Element::add_field(Field::Id id, const std::wstring& name, Field::Type type, size_t size) {
	this->fields.push_back(Field(id, name, type, size));
}

/////////////////////
// READ ALL FIELDS //
/////////////////////

#include <iostream>
void Element::read_all_fields() {
	std::wcout << L"COUCOU\n";
	this->ifs->seekg(this->start_pos);
	// TODO How to add a pos attr to Field and update it ? Can we access the Field instance in vector and modify it ?
	// TODO Do the same for value ?
	for (auto f: this->fields) {
		auto v = this->read_field(f);
		if (f.id < Field::Id::Unknown) {
			f.value = v;
			for (auto o: this->observers)
				o->field_value_changed(f);
		}
	}
}

////////////////
// READ FIELD //
////////////////

boost::any Element::read_field(const Field& field) {

	boost::any value;
	
	// Read field from file
	switch(field.type) {
		case Field::Type::uint8:    value = read_int<uint8_t>();  break;
		case Field::Type::uint16:   value = read_int<uint16_t>(); break;
		case Field::Type::uint32:   value = read_int<uint32_t>(); break;
		case Field::Type::uint64:   value = read_int<uint64_t>(); break;
		case Field::Type::cstring:  value = read_cstring(field.size); break;
		default: break;
// TODO case FieldType::audittag: value = new AuditTag(this->ifs); 
	}

	return value;
}

//////////////////
// READ CSTRING //
//////////////////

std::wstring Element::read_cstring(int size) {
	uint16_t buf[size];
	this->ifs->read(reinterpret_cast<char*>(buf), sizeof(buf));
	return arr2wstring(buf);
}
