#ifndef FINNIGAN_TYPES
#define FINNIGAN_TYPES

#include <cstdint>

#define MAGIC 0xa101
#define SIGNATURE L"Finnigan"

namespace org::openscience::ms::finnigan {

	/////////////////
	// BASIC TYPES //
	/////////////////

	typedef uint16_t    magic_t;
	typedef uint32_t    version_t;

	///////////////
	// AUDIT TAG //
	///////////////

	struct AuditTag { //112 bytes
		uint64_t    time; // 8 bytes Windows 64-bit timestamp.
		uint16_t    tag1[25];
		uint16_t    tag2[25];
		uint32_t    unknown;
	};

	////////////
	// HEADER //
	////////////

	struct Header {
		magic_t     magic;
		uint16_t    signature[9];
		uint32_t    unknown1;
		uint32_t    unknown2;
		uint32_t    unknown3;
		uint32_t    unknown4;
		version_t   version;
		AuditTag    audit_start;
		AuditTag    audit_end;
		uint32_t    unknown5;
		uint8_t     unknown6[60];
		uint16_t    tag[514];
	};

}

#endif // FINNIGAN_TYPES
