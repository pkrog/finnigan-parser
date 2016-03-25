#include "Element.hpp"
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

// TODO factorize common code of two add_child()

void Element::add_child(const std::wstring& name, Element* child) {

	child->set_name(name);
	this->children.push_back(child);
	child->parent = this;

	// Call observers
	for (auto o: *(this->get_observers()))
		o->new_child_added(child);
}

void Element::add_child(Element* child) {

	this->children.push_back(child);
	child->parent = this;

	// Call observers
	for (auto o: *(this->get_observers()))
		o->new_child_added(child);
}

///////////////
// GET CHILD //
///////////////

Element* Element::get_child(const std::wstring& name) {
	
	this->define_children();

	for (auto c: this->children)
		if (c->name == name)
			return c;

	return nullptr;
}

/////////////
// GET POS //
/////////////

int64_t Element::get_pos() {

	if (this->pos < 0)
		this->parent->compute_pos_of_child(this);

	return this->pos;
}

///////////////////////////////
// COMPUTE POSITION OF CHILD //
///////////////////////////////

void Element::compute_pos_of_child(Element *child) {
	int64_t pos = this->get_pos();
	for (auto c: this->children) {
		if (c->pos < 0)
			c->pos = pos;
		if (c == child)
			break;
		pos += c->get_byte_size_in_file();
	}
}

///////////////////////////
// GET BYTE SIZE IN FILE //
///////////////////////////

int Element::get_byte_size_in_file() const {
	
	int sz = 0;

	const_cast<Element*>(this)->define_children();

	for (auto c: this->children)
		sz += c->get_byte_size_in_file();

	return sz;
}

//////////
// READ //
//////////

void Element::read() {
	
	this->define_children();

	for (auto c: this->children)
		c->read();
}

/////////////////
// GET VERSION //
/////////////////

int Element::get_version() {
	return this->get_top()->get_child(FEN_HEADER)->get_child(FEN_VERSION)->get_int();
}

////////////////////////////
// OUTPUT STREAM OPERATOR //
////////////////////////////

std::wostream& org::openscience::ms::finnigan::operator << (std::wostream& os, const Element& e) {
	e.write(os);
	return os;
}
