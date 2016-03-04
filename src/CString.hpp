#ifndef FINNIGAN_CSTRING
#define FINNIGAN_CSTRING

#include "Element.hpp"
#include "common.hpp"

namespace org::openscience::ms::finnigan {

	class CString : public Element {

		public:

			CString(unsigned int length) : length(length) {}

			std::wstring get_string() const { const_cast<CString*>(this)->read(); return this->value; }

			void write(std::wostream& os) const { os << this->get_string(); }

		protected:

			int get_byte_size_in_file() { return sizeof(uint16_t) * this->length; }

			void read() {
				if ( ! this->has_been_read) {
					this->get_stream().seekg(this->get_pos());
					uint16_t x[this->length];
					this->get_stream().read(reinterpret_cast<char*>(&x), sizeof(uint16_t) * this->length);
					this->value = arr2wstring(x);
					this->has_been_read = true;

					for(auto o: *(this->get_observers()))
						o->data_read(this);
				}
			}

		private:
			bool has_been_read = false;
			unsigned int length;
			std::wstring value;
	};
}

#endif // FINNIGAN_CSTRING
