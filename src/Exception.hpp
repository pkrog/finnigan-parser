#ifndef FINNIGAN_EXCEPTION
#define FINNIGAN_EXCEPTION 

#include <string>

namespace org::openscience::ms::finnigan {

	class Exception {
		public:
			virtual std::wstring what() const = 0;
	};

	class FieldNotFound : public Exception {
		public:
			FieldNotFound(const std::wstring& field_name) : field_name(field_name) {}
			std::wstring what() const {
				return std::wstring(L"Field \"") + this->field_name + L"\" not found.";
			}
		private:
			std::wstring field_name;
	};

	class UnknownType : public Exception {
		public:
			UnknownType(const std::wstring& type_name) : type_name(type_name) {}
			std::wstring what() const {
				return std::wstring(L"Unknown type \"") + this->type_name + L"\".";
			}
		private:
			std::wstring type_name;
	};
}

#endif // FINNIGAN_EXCEPTION
