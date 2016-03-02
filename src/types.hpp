#ifndef FINNIGAN_TYPES
#define FINNIGAN_TYPES

#include <cstdint>

//#define MAGIC 0xa101
//#define SIGNATURE L"Finnigan"

namespace org::openscience::ms::finnigan {

	/////////////////
	// BASIC TYPES //
	/////////////////
#if 0
	typedef uint16_t    magic_t;
	typedef uint32_t    version_t;
#endif

	////////////////
	// PROPERTIES //
	////////////////
#if 0
	enum class FieldId {
		Magic,
		Signature,
		Version,
		AuditStart,
		AuditEnd,
		Tag,

		Unknown
	};
#endif
	/////////////////
	// FIELD TYPES //
	/////////////////
#if 0
	enum class FieldType {
		uint8,
		uint16,
		uint32,
		uint64,
		cstring,
		pstring
	};
#endif
	///////////////
	// AUDIT TAG //
	///////////////
#if 0
	struct AuditTag { //112 bytes
		uint64_t    time; // 8 bytes Windows 64-bit timestamp.
		uint16_t    tag1[25];
		uint16_t    tag2[25];
		uint32_t    unknown;
	};
#endif
	////////////
	// HEADER //
	////////////

#if 0
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
#endif
}

#endif // FINNIGAN_TYPES
