#ifndef FINNIGAN_FLOAT
#define FINNIGAN_FLOAT

#include "Element.hpp"

namespace org::openscience::ms::finnigan {

	template<typename T> class Float : public Element {

		public:
			double get_double() { this->read(); return this->value; }

		protected:

			int get_byte_size_in_file() { return sizeof(T); }

			void read() {
				this->get_stream().seekg(this->get_pos());
				T x;
				this->get_stream().read(reinterpret_cast<char*>(&x), sizeof(x));
				this->value = x;
			}

		private:

			T value;
	};

}

#endif // FINNIGAN_FLOAT

