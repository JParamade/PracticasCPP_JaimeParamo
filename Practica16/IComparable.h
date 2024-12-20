#pragma once

class IComparable {
public:
	virtual ~IComparable() = default;

	virtual bool Equals(const IComparable& _other) const = 0;
};