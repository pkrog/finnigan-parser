#ifndef FINNIGAN_TYPES
#define FINNIGAN_TYPES

#include <cstdint>

#define MAGIC 0xa101
#define SIGNATURE L"Finnigan"

namespace org::openscience::ms::finnigan {

	typedef uint16_t    magic_t;
	typedef uint32_t    version_t;

	struct Header {
		magic_t     magic;
		uint16_t    signature[9];
		uint32_t    unknown1;
		uint32_t    unknown2;
		uint32_t    unknown3;
		uint32_t    unknown4;
		version_t   version;
	//	AuditStart AuditTag  //112 bytes
	//	AuditEnd   AuditTag  //112 bytes
	//	Unknown5   uint32    //4 bytes
	//	Unknown6   [60]byte  //60 bytes
	//	Tag        headertag //1028 bytes
	};

}

#endif // FINNIGAN_TYPES
