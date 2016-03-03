#ifndef FINNIGAN_ELEMENT
#define FINNIGAN_ELEMENT

#include "Field.hpp"
#include <list>
#include <vector>
#include <map>
#include <memory>
#include <fstream>

#define ADD_FIELD(name, type, size) this->add_field(name, typeid(type),  L###type, size)

namespace org::openscience::ms::finnigan {

	class Observer;

	class Element {

		public:

			void add_observer(Observer*);
		
			boost::any get_field(const std::wstring& name) {
				return boost::any();
			}

		protected:

			void read_all_fields();

			Element(const std::string& file, std::shared_ptr<std::ifstream>, std::ifstream::pos_type);

			void add_field(const std::wstring& name, std::type_index type, const std::wstring& type_name, size_t);

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
			std::ifstream::pos_type         start_pos;
			std::vector<Field>              fields;
	};
}

#endif // FINNIGAN_ELEMENT
