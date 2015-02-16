#pragma once

#include "RakNetDefines.h"
#include "RakNetTypes.h"

namespace RakNet {
class BitStream {
public:
	BitSize_t numberOfBitsUsed;
	BitSize_t numberOfBitsAllocated;
	BitSize_t readOffset;

	unsigned char *data;
	bool copyData;
	unsigned char stackData[BITSTREAM_STACK_ALLOCATION_SIZE];

	BitStream();
	BitStream(unsigned int initialBytesToAllocate);
	void WriteBits(const unsigned char *inByteArray, unsigned int numberOfBitsToWrite, bool rightAlignedBits = true);

	template <class templateType>
		void Write(const templateType &inTemplateVar);

	template <class templateType>
		bool Read(templateType &outTemplateVar);

	void PrintBits(char *out) const;
	static bool IsNetworkOrder();
	static bool IsNetworkOrderInternal();
	static void ReverseBytes(unsigned char *inByteArray, unsigned char *inOutByteArray, const unsigned int length);
	bool ReadBits(unsigned char *inOutByteArray, BitSize_t numberOfBitsToRead, const bool alignBitsToRight = true);
	void Write0();
	void Write1();
};
}
