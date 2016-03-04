#ifndef FINNIGAN_READER
#define FINNIGAN_READER

#include "Element.hpp"
#include <string>
#include <fstream>

namespace org::openscience::ms::finnigan {

	class Observer;

	class Reader : public Element {

		friend class Element;

		public:

			Reader(const std::string& file, Observer* obs = nullptr);

			void add_observer(Observer*);

		protected:

			std::ifstream& get_stream() { return this->ifs; }
			Reader* get_top() { return this; }
			void define_children();

		private:
			std::list<Observer*> observers;
			std::string    file;
			std::ifstream  ifs;
	};

}

#endif // FINNIGAN_READER
