#include "Logger.hpp"
#include "common.hpp"
#include "Element.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////
// CONSTRUCTOR //
/////////////////

Logger::Logger(std::wostream& o) : out(o) {
}

/////////////////////
// NEW CHILD ADDED //
/////////////////////

void Logger::new_child_added(const Element* child) {
	this->out << L"Child \"" << child->get_name() << L"\" added.\n";
}

///////////////
// DATA READ //
///////////////
//
void Logger::data_read(const Element *elem) {

	this->out << L"Element \"" << elem->get_name() << L"\" has been read from file : " << *elem << L".\n";
}
