#include "memoryNode.h"
#include <iostream>
using namespace instruments; 
memoryNode::memoryNode(size_t bytesAllocated, size_t lineNo, unsigned long address,std::string fileName):
					m_bytesAllocated(bytesAllocated),  m_lineNo(lineNo), m_address(address),m_fileName(fileName)
{
	
}

memoryNode::~memoryNode(void)
{

}

const unsigned long memoryNode::getAddress() const
{
	return m_address;
}

const size_t memoryNode::getLineNo() const
{
	return m_lineNo;
}

const size_t memoryNode::getBytesAllocated() const
{
	return m_bytesAllocated;
}

const std::string& memoryNode::getFileName() const
{
	return m_fileName;
}

void memoryNode::printMemoryBlock() const
{
	std::cout<< std::endl <<"Number of bytes allocated : "<< m_bytesAllocated;
	std::cout <<" at line : " <<m_lineNo;
	std::cout <<" in file : " << m_fileName<<std::endl;
}
