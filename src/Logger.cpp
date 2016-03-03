#include "Logger.hpp"
#include "common.hpp"
#include "Element.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////
// CONSTRUCTOR //
/////////////////

Logger::Logger(std::wostream& o) : out(o) {
}

///////////////
// ERROR TAG //
///////////////

void Logger::errortag(const std::string& file) {
	this->out << L"Error in file \"" << arr2wstring(file.c_str()) << "\".";
}

/////////////////////////
// FIELD VALUE CHANGED //
/////////////////////////
#if 0
void Logger::field_value_changed(const Field& field) {
	this->out << L"Field \"" << field.get_name() << L"\" is now " /*<< field.as_string()*/ << "\n";
}
#endif
/////////////////////
// NEW CHILD ADDED //
/////////////////////

void Logger::new_child_added(const Element* child) {
	this->out << L"Child \"" << child->get_name() << L"\" added.\n";
}

/////////////////////////////
// FIELD POSITION COMPUTED //
/////////////////////////////
#if 0
void Logger::field_pos_computed(const Field& field) {
	this->out << L"Position of field \"" << field.get_name() << L"\" has been computed to \"" << field.get_pos() << L"\".\n";
}
#endif
////////////////////////
// WRONG MAGIC NUMBER //
////////////////////////

#if 0
void Logger::wrong_magic_number(const std::string& file, magic_t magic) {
	this->errortag(file);
	this->out << L" Wrong magic number " << std::hex << std::showbase << magic << L" ; should be " << MAGIC << L". This is not a Finnigan file.\n";
}
#endif
/////////////////////
// WRONG SIGNATURE //
/////////////////////

#if 0
void Logger::wrong_signature(const std::string& file, const std::wstring& signature) {
	this->errortag(file);
	this->out << L" Wrong signature \"" << signature << L"\" ; should be \"" << SIGNATURE << L"\". This is not a Finnigan file.\n";
}
#endif
//////////////////
// FILE VERSION //
//////////////////

#if 0
void Logger::file_version(const std::string& file, version_t version) {
	this->out << L"INFO file \"" << arr2wstring(file.c_str()) << "\".";
	this->out << L" Version is " << version << L".\n";
}
#endif
