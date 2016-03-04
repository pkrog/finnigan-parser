#ifndef FINNIGAN_FLOAT
#define FINNIGAN_FLOAT

#include "Element.hpp"

namespace org::openscience::ms::finnigan {

	template<typename T> class Float : public Element {

		public:
			double get_double() const { const_cast<Float*>(this)->read(); return this->value; }

			void write(std::wostream& os) const { os << this->get_double(); }

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

}

#endif // FINNIGAN_FLOAT

