#pragma once
#include <string>
namespace instruments {

class memoryNode
{
	size_t m_bytesAllocated;
	size_t m_lineNo;
	unsigned long m_address;
	std::string m_fileName;
public:
	memoryNode(size_t bytesAllocated ,size_t lineNumber,unsigned long address,std::string fileName);
	virtual ~memoryNode(void);
	const unsigned long getAddress() const;
	const size_t getLineNo() const;
	const size_t getBytesAllocated() const;
	const std::string& getFileName() const; 
	void printMemoryBlock() const;
};

}

