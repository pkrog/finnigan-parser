#ifndef FINNIGAN_INTEGER_ARRAY
#define FINNIGAN_INTEGER_ARRAY

#include "Element.hpp"
#include <vector>

namespace org::openscience::ms::finnigan {

	template<typename T> class IntegerArray : public Element {

		public:

			IntegerArray(unsigned int length) : length(length) {}

		protected:

			int get_byte_size_in_file() const { return sizeof(T) * this->length; }

			void read() {
				this->get_stream().seekg(this->get_pos());
				T x[this->length];
				this->get_stream().read(reinterpret_cast<char*>(&x), sizeof(T) * this->length);
				this->value = std::vector<T>(x, x + this->length);
			}

		private:

			unsigned int length;
			std::vector<T> value;
	};
}

#endif // FINNIGAN_INTEGER_ARRAY
