#ifndef FINNIGAN_READER
#define FINNIGAN_READER

#include <list>
#include <string>
#include <fstream>

namespace org::openscience::ms::finnigan {

	class Observer;

	class Reader {
		
		private:

			std::string file;
			std::list<Observer*> observers;
			std::ifstream        ifs;

		public:

			Reader(const std::string& file);

			void add_observer(Observer*);
	};
}

#endif // FINNIGAN_READER
