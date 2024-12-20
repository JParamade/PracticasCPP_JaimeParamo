#pragma once

class IComparable {
public:
	virtual ~IComparable() = default;

	virtual bool equals(const IComparable& other) const = 0;
};