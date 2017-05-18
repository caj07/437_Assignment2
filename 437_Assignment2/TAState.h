#pragma once
#include "TAObj.h"
#include <string>
#include <ostream>

class TAState :
	public TAObj
{
public:
	TAState(const std::string & name);
	virtual ~TAState();

	std::string getName() const;

	void list(std::ostream & os) const;

protected:
	TAState();

private:
	std::string m_name;


	// Inherited via TAObj
	virtual const TAType & getType() const override;

};

