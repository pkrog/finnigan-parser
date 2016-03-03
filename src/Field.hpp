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

			void set_value(boost::any v) { this->value = v; this->value_has_been_set = true; }
			template<typename T> T get_value() const { return boost::any_cast<T>(this->value); }
			bool has_value() const { return this->value_has_been_set; }

			void set_pos(std::ifstream::pos_type pos) { this->pos = pos; this->pos_has_been_set = true; }
			std::ifstream::pos_type get_pos() const { return this-> pos; }
			bool has_pos() const { return this->pos_has_been_set; }

			std::ifstream::pos_type get_byte_size_in_file() const;

			std::wstring get_name() const { return this->name; }

			std::wstring get_type_name() const { return this->type_name; }

			std::type_index get_type() const { return this->get_type(); }
			bool operator == (const Field& f) const { return this->name == f.name; }

		private:
			std::wstring            name;
			std::type_index         type;
			std::wstring            type_name; // For human control
			size_t                  size;
			std::ifstream::pos_type pos;
			boost::any              value;
			bool                    pos_has_been_set;
			bool                    value_has_been_set;
	};
}

#endif // FINNIGAN_FIELD
