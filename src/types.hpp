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

	////////////////
	// PROPERTIES //
	////////////////

	enum class Property {
		Magic,
		Signature,
		Version,
		AuditStart,
		AuditEnd,
		Tag,

		Unknown1,
		Unknown2,
		Unknown3,
		Unknown4,
		Unknown5,
		Unknown6,

		LAST
	};

	////////////////////
	// PROPERTY TYPES //
	////////////////////

	enum class Type {
		uint8,
		uint16,
		uint32,
		uint64,
		cstring,
		pstring,

		NONE
	};

	/////////////////////////////
	// GET PROPERTY ATTRIBUTES //
	/////////////////////////////

	Type get_property_type_in_file(Property);

	int get_property_size(Property);

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
