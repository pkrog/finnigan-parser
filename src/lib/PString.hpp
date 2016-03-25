#ifndef FINNIGAN_PSTRING
#define FINNIGAN_PSTRING

#include "Element.hpp"
#include "constants.hpp"

namespace org{ namespace openscience { namespace ms{ namespace finnigan {

	class PString : public Element {

		public:

			PString() : length(0) {}

			std::wstring get_string() const { const_cast<PString*>(this)->read(); return this->value; }

			void write(std::wostream& os) const { os << this->get_string(); }

		protected:

			int get_byte_size_in_file() const { const_cast<PString*>(this)->read(); return sizeof(uint32_t) + sizeof(uint16_t) * this->length; }

			void read() {
				if ( ! this->has_been_read) {

					// Go to position in file
					this->get_stream().seekg(this->get_pos());

					// Read length
					uint32_t length;
					this->get_stream().read(reinterpret_cast<char*>(&length), sizeof(length));
					this->length = length;

					if (length) {
						uint16_t x[length];
						this->get_stream().read(reinterpret_cast<char*>(&x), sizeof(uint16_t) * length);
						this->value = std::wstring(x, x + length);
					}
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
}}}}

#endif // FINNIGAN_PSTRING
