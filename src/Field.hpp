#ifndef FINNIGAN_FIELD
#define FINNIGAN_FIELD

#include "types.hpp"
#include <boost/any.hpp>
#include <fstream>
#include <typeindex>

namespace org::openscience::ms::finnigan {

	struct Char {
		uint16_t c;
	};

	class Field {

		public:
			Field(const std::wstring& name, std::type_index, const std::wstring& type_name, size_t);

			bool is_unknown() const { return this->name.length() == 0; }

			void set_value(boost::any v) { this->value = v; }

			std::wstring get_name() const { return this->name; }
			std::wstring get_type_name() const { return this->type_name; }

		private:
			std::wstring            name;
			std::type_index         type;
			std::wstring            type_name; // For human control
			size_t                  size;
			std::ifstream::pos_type pos;
			boost::any              value;
	};
}

#endif // FINNIGAN_FIELD
