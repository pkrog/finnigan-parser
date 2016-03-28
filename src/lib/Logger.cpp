#include "Logger.hpp"
#include "constants.hpp"
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
	this->out << L"Add \"" << child->get_path() << L"\".\n";
}

///////////////
// DATA READ //
///////////////
//
void Logger::data_read(const Element *elem) {

	this->out << L"Read \"" << elem->get_path() << L"\" : " << *elem << L".\n";
}
