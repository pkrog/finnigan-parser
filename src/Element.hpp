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

	class Reader;

	class Element {

		public:
		
			Element* get_child(const std::wstring& name) {
				
				this->define_children();

				for (auto c: this->children)
					if (c->name == name)
						return c;

				return nullptr;
			}

			virtual int get_byte_size_in_file() {
				
				int sz = 0;

				this->define_children();

				for (auto c: this->children)
					sz += c->get_byte_size_in_file();

				return sz;
			}

			std::wstring get_name() const { return this->name; }

		protected:

			virtual void define_children() {}

			virtual Reader* get_top() {
				return this->parent->get_top();
			}

			virtual std::ifstream& get_stream() {
				return this->parent->get_stream();
			}

			void set_name(const std::wstring& name) { this->name = name; }

			Element();

			void add_child(const std::wstring& name, Element*);

//			boost::any read_field(const Field& field);

			std::wstring read_cstring(int size);

			Element                         *parent;
			std::vector<Element*>           children;
			std::wstring                    name;
			std::ifstream::pos_type         pos;
	};
}

#endif // FINNIGAN_ELEMENT
