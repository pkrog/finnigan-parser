#ifndef FINNIGAN_ELEMENT
#define FINNIGAN_ELEMENT

#include "Exception.hpp"
#include "Observer.hpp"
#include <list>
#include <vector>
#include <map>
#include <memory>
#include <fstream>
#include <algorithm>

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

			virtual int get_int() const { throw CannotConvertToType(L"int"); }
			virtual double get_double() const { throw CannotConvertToType(L"float"); }
			virtual std::wstring get_string() const { throw CannotConvertToType(L"string"); }
			virtual void write(std::wostream&) const {}

			virtual void read() {
				for (auto c: this->children)
					c->read();
			}

			virtual std::wstring get_path() const {
				return this->parent->get_path() + L"/" + (this->get_name().empty() ? L"???" : this->get_name());
			}

		protected:

			virtual void define_children() {}

			virtual Reader* get_top() {
				return this->parent->get_top();
			}

			virtual std::ifstream& get_stream() {
				return this->parent->get_stream();
			}

			virtual std::list<Observer*>* get_observers() {
				return this->parent->get_observers();
			}

			int64_t get_pos() {

				if (this->pos < 0)
					this->parent->compute_pos_of_child(this);

				return this->pos;
			}

			void compute_pos_of_child(Element *child) {
				int64_t pos = this->get_pos();
				for (auto c: this->children) {
					if (c->pos < 0)
						c->pos = pos;
					if (c == child)
						break;
					pos += c->get_byte_size_in_file();
				}
			}

			void set_name(const std::wstring& name) { this->name = name; }

			Element();
			Element(int64_t);

			void add_child(const std::wstring& name, Element*);
			void add_child(Element*);

//			boost::any read_field(const Field& field);

			std::wstring read_cstring(int size);

			Element                         *parent;
			std::vector<Element*>           children;
			std::wstring                    name;

		private:
			int64_t                         pos;
	};

	////////////////////////////
	// OUTPUT STREAM OPERATOR //
	////////////////////////////

	std::wostream& operator << (std::wostream& os, const Element& e);
}

#endif // FINNIGAN_ELEMENT
