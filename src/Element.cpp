#include "Element.hpp"
#include "common.hpp"
#include "Observer.hpp"
#include "Reader.hpp"

using namespace org::openscience::ms::finnigan;

//////////////////
// CONSTRUCTORS //
//////////////////

Element::Element() :
	pos(-1)
{
}

Element::Element(int64_t pos) : pos(pos) {}

///////////////
// ADD CHILD //
///////////////

void Element::add_child(const std::wstring& name, Element* child) {

	child->set_name(name);
	this->children.push_back(child);
	child->parent = this;

	// Call observers
	for (auto o: this->get_top()->observers)
		o->new_child_added(child);
}

void Element::add_child(Element* child) {

	this->children.push_back(child);
	child->parent = this;

	// Call observers
	for (auto o: this->get_top()->observers)
		o->new_child_added(child);
}

/////////////////////
// READ ALL FIELDS //
/////////////////////

#if 0
#include <iostream>
void Element::read_all_fields() {
	std::wcout << L"READ ALL FIELDS\n";
	this->ifs->seekg(this->start_pos);
	// TODO How to add a pos attr to Field and update it ? Can we access the Field instance in vector and modify it ?
	// TODO Do the same for value ?
	for (auto f: this->fields) {
		auto v = this->read_field(f);
		if ( ! f.is_unknown()) {
			f.set_value(v);
			for (auto o: this->observers)
				o->field_value_changed(f);
		}
	}
}
#endif

/////////////////////////
// READ FIELD POSITION //
/////////////////////////
#if 0
void Element::read_pos(Field& field) {
	
	std::ifstream::pos_type cur_pos = start_pos;
	// Compute position of all fields until this field
	for (Field& f: this->fields) {

		// Set missing position
		if ( ! f.has_pos())
			f.set_pos(cur_pos);

		// Stop when the field has been found
		if (f == field) {
			for (auto o: this->observers)
				o->field_pos_computed(field);
			break;
		}

		// Update current position
		cur_pos += f.get_byte_size_in_file();
	}

	// Read field from file
//	switch(field.type) {
//		case Field::Type::uint8:    value = read_int<uint8_t>();  break;
//		case Field::Type::uint16:   value = read_int<uint16_t>(); break;
//		case Field::Type::uint32:   value = read_int<uint32_t>(); break;
//		case Field::Type::uint64:   value = read_int<uint64_t>(); break;
//		case Field::Type::cstring:  value = read_cstring(field.size); break;
//		default: break;
//// TODO case FieldType::audittag: value = new AuditTag(this->ifs); 
//	}
}
#endif
//////////////////////
// READ FIELD VALUE //
//////////////////////
#if 0
void Element::read_value(Field& field)  {

	// Basic types
	this->ifs->seekg(field.get_pos());
	if (field.get_type() == typeid(uint16_t)) {
		field.set_value(this->read_int<uint16_t>());
		return;
	}

	if (field.get_type() == typeid(Header)) {
		field.set_value(new Header(this->file, this->ifs));
		return;
	}


	throw UnknownType(field.get_type_name());
}
#endif
//////////////////
// READ CSTRING //
//////////////////
#if 0
std::wstring Element::read_cstring(int size) {
	uint16_t buf[size];
	this->ifs->read(reinterpret_cast<char*>(buf), sizeof(buf));
	return arr2wstring(buf);
}
#endif
