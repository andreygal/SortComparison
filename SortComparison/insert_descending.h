#pragma once
template <typename T>
class InsertDescending {
public:
	bool operator() (const T& x, const T& y) const {
		return x > y;
	}
};
