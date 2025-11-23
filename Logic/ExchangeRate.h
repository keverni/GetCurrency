#pragma once

enum class Currency
{
	USD,
	EUR,
	JPY
};

class ExchangeRate final
{
public:
	static double GetRate(Currency id) noexcept;
};

