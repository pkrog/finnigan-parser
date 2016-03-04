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

//////////
// READ //
//////////

void Element::read() {
	
	this->define_children();

	for (auto c: this->children)
		c->read();
}

////////////////////////////
// OUTPUT STREAM OPERATOR //
////////////////////////////

std::wostream& org::openscience::ms::finnigan::operator << (std::wostream& os, const Element& e) {
	e.write(os);
	return os;
}
