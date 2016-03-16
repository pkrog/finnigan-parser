#ifndef FINNIGAN_INTEGER
#define FINNIGAN_INTEGER

#include "Element.hpp"

namespace org{ namespace openscience { namespace ms{ namespace finnigan {

	template<typename T> class Integer : public Element {

		public:
			int get_int() const { const_cast<Integer*>(this)->read(); return this->value; }

			void write(std::wostream& os) const { os << std::dec << this->get_int() << L" (" << std::hex << std::showbase << this->get_int() << L")" << std::dec; }

		protected:

			int get_byte_size_in_file() const { return sizeof(T); }

			void read() {
				if ( ! this->has_been_read) {
					this->get_stream().seekg(this->get_pos());
					T x;
					this->get_stream().read(reinterpret_cast<char*>(&x), sizeof(x));
					this->value = x;
					this->has_been_read = true;

					for(auto o: *(this->get_observers()))
						o->data_read(this);
				}
			}

		private:
			bool has_been_read = false;
			T value;
	};

}}}}

#endif // FINNIGAN_INTEGER
