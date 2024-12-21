#pragma once

class IComparable {
public:
	virtual ~IComparable() = default;

	virtual IComparable* Clone() const = 0;
	virtual bool Equals(const IComparable& _other) const = 0;
};