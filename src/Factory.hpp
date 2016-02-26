#ifndef FINNIGAN_FACTORY
#define FINNIGAN_FACTORY

#include <list>
#include <string>

namespace org::openscience::ms::finnigan {

	class Reader;
	class Observer;

	class Factory {
		
		private:

			std::list<Observer*> observers;

		public:

			void add_observer(Observer*);

			Reader* make_reader(const std::string& file);
	};

}

#endif // FINNIGAN_FACTORY
