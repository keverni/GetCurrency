#include "ExchangeRate.h"

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

double ExchangeRate::GetRate(Currency id) noexcept
{
	cpr::Response resp{ cpr::Get(cpr::Url{ "https://www.cbr-xml-daily.ru/daily_json.js" }) };

	if(resp.status_code != 200)
	{
		return -1.0;
	}

	json j = json::parse(resp.text);

	if (id == Currency::USD)
	{
		return j["Valute"]["USD"]["Value"].get<double>();
	}
	else if (id == Currency::EUR)
	{
		return j["Valute"]["EUR"]["Value"].get<double>();
	}
	else if(id == Currency::JPY )
	{
		return j["Valute"]["JPY"]["Value"].get<double>();
	}
}
