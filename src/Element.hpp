#ifndef FINNIGAN_ELEMENT
#define FINNIGAN_ELEMENT

#include "Field.hpp"
#include "Exception.hpp"
#include <list>
#include <vector>
#include <map>
#include <memory>
#include <fstream>
#include <algorithm>

#define ADD_FIELD(name, type, size) this->add_field(name, typeid(type),  L###type, size)

namespace org::openscience::ms::finnigan {

	class Observer;

	class Element {

		public:

			void add_observer(Observer*);
		
			/////////////////////
			// GET FIELD VALUE //
			/////////////////////

			template<typename T> T get_field_value(const std::wstring& name) {
				
				Field f(name, typeid(char), L"char", 0); // Fake Field object used for searching.

				auto i = std::find(this->fields.begin(), this->fields.end(), f);

				if (i == this->fields.end())
					throw FieldNotFound(name);

				if ( ! i->has_value()) {

					if ( ! i->has_pos())
						this->read_pos(*i);

					this->read_value(*i);
				}

				return i->get_value<T>();
			}

			std::ifstream::pos_type get_byte_size_in_file() { /* TODO */ return 0; }

		protected:

//			void read_all_fields();

			Element(const std::string& file, std::shared_ptr<std::ifstream>, std::ifstream::pos_type);

			void add_field(const std::wstring& name, std::type_index type, const std::wstring& type_name, size_t);
			void read_pos(Field&);
			void read_value(Field&);

			std::list<Observer*> observers;

			boost::any read_field(const Field& field);

			std::wstring read_cstring(int size);

			template<typename T> int read_int() {
				T x;
				this->ifs->read(reinterpret_cast<char*>(&x), sizeof(x));
				return static_cast<int>(x);
			}

			std::string                     file;
			std::shared_ptr<std::ifstream>  ifs;
			std::vector<Field>              fields;
			std::ifstream::pos_type         start_pos;
	};
}

#endif // FINNIGAN_ELEMENT
