#ifndef FINNIGAN_ELEMENT
#define FINNIGAN_ELEMENT

#include <msfinnigan/Exception.hpp>
#include <msfinnigan/Observer.hpp>
#include <list>
#include <vector>
#include <fstream>

namespace org{ namespace openscience { namespace ms{ namespace finnigan {

	class Reader;

	class Element {

		public:

			Element* get_child(const std::wstring& name);

			std::wstring get_name() const { return this->name; }

			virtual int get_int() const { throw CannotConvertToType(L"int"); }
			virtual double get_double() const { throw CannotConvertToType(L"float"); }
			virtual std::wstring get_string() const { throw CannotConvertToType(L"string"); }
			virtual void write(std::wostream&) const {}

			virtual void read();
			int get_version();

			virtual std::wstring get_path() const {
				return this->parent->get_path() + L"/" + (this->get_name().empty() ? L"???" : this->get_name());
			}

		protected:

			Element();
			Element(int64_t pos);

			// Children
			virtual void define_children() {}
			void add_child(const std::wstring& name, Element*);
			void add_child(Element*);

			// Top object (Reader)
			virtual Reader* get_top() { return this->parent->get_top(); }
			virtual std::ifstream& get_stream() { return this->parent->get_stream(); }
			virtual std::list<Observer*>* get_observers() { return this->parent->get_observers(); }

			// Position and size
			int64_t get_pos();
			virtual int get_byte_size_in_file() const;
			void compute_pos_of_child(Element *child);

			void set_name(const std::wstring& name) { this->name = name; }

			Element                         *parent;
			std::vector<Element*>           children;

		private:
			int64_t                         pos;
			std::wstring                    name;
	};

	////////////////////////////
	// OUTPUT STREAM OPERATOR //
	////////////////////////////

	std::wostream& operator << (std::wostream& os, const Element& e);
}}}}

#endif // FINNIGAN_ELEMENT
