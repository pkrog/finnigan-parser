#ifndef FINNIGAN_FIELD
#define FINNIGAN_FIELD

#include "types.hpp"
#include <boost/any.hpp>
#include <fstream>

namespace org::openscience::ms::finnigan {

	struct Field {

		enum class Id {
			Magic,
			Signature,
			Version,
			AuditStart,
			AuditEnd,
			Tag,

			Unknown
		};

		enum class Type {
			uint8,
			uint16,
			uint32,
			uint64,
			cstring,
			pstring
		};

		Id                      id;
		std::wstring            name;
		Type                    type;
		size_t                  size;
		std::ifstream::pos_type pos;
		boost::any              value;

		Field(Id, const std::wstring&, Type, size_t);
	};
}

#endif // FINNIGAN_FIELD
