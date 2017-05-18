#pragma once
#include "TAObj.h"
#include <string>

class TAPort :
	public TAObj
{
public:
	TAPort(const std::string & name);
	virtual ~TAPort();

	std::string getName() const;
	void list(std::ostream & os);

protected:
	TAPort();

private:
	std::string m_name;
};

