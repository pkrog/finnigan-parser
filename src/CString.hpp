#ifndef FINNIGAN_CSTRING
#define FINNIGAN_CSTRING

#include "Element.hpp"
#include "common.hpp"

namespace org::openscience::ms::finnigan {

	class CString : public Element {

		public:

			CString(unsigned int length) : length(length) {}

			std::wstring get_string() { this->read(); return this->value; }

		protected:

			int get_byte_size_in_file() { return sizeof(uint16_t) * this->length; }

			void read() {
				this->get_stream().seekg(this->get_pos());
				uint16_t x[this->length];
				this->get_stream().read(reinterpret_cast<char*>(&x), sizeof(uint16_t) * this->length);
				this->value = arr2wstring(x);
			}

		private:

			unsigned int length;
			std::wstring value;
	};
}

#endif // FINNIGAN_CSTRING
