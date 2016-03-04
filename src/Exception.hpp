#ifndef FINNIGAN_EXCEPTION
#define FINNIGAN_EXCEPTION 

#include <string>
#include <sstream>
#include "common.hpp"

namespace org::openscience::ms::finnigan {

	class Exception {
		public:
			virtual std::wstring what() const = 0;
	};

	class WrongType : public Exception {
		public:
			WrongType(const std::wstring& type_name) : type_name(type_name) {}
			std::wstring what() const {
				return std::wstring(L"Wrong type \"") + this->type_name + L"\".";
			}
		private:
			std::wstring type_name;
	};

	class WrongMagicNumber : public Exception {
		public:
			WrongMagicNumber(const std::string& file, int magic) : file(file), magic(magic) {}
			std::wstring what() const {
				std::wstringstream wss;
				wss << L"File \"" << arr2wstring(file.c_str()) << L"\" is not a Finnigan file or has been corrupted. Its magic number is " << std::hex << magic << L" instead of " << FINNIGAN_MAGIC << L"\".";
				return wss.str();
			}
		private:
			std::string file;
			int magic;
	};
}

#endif // FINNIGAN_EXCEPTION
