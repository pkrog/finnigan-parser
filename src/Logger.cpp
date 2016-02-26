#include "Logger.hpp"
#include "common.hpp"

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

////////////////////////
// WRONG MAGIC NUMBER //
////////////////////////

void Logger::wrong_magic_number(const std::string& file, magic_t magic) {
	this->errortag(file);
	this->out << L" Wrong magic number " << std::hex << std::showbase << magic << L" ; should be " << MAGIC << L". This is not a Finnigan file.\n";
}

/////////////////////
// WRONG SIGNATURE //
/////////////////////

void Logger::wrong_signature(const std::string& file, const std::wstring& signature) {
	this->errortag(file);
	this->out << L" Wrong signature \"" << signature << L"\" ; should be \"" << SIGNATURE << L"\". This is not a Finnigan file.\n";
}

//////////////////
// FILE VERSION //
//////////////////

void Logger::file_version(const std::string& file, version_t version) {
	this->out << L"INFO file \"" << arr2wstring(file.c_str()) << "\".";
	this->out << L" Version is " << version << L".\n";
}
