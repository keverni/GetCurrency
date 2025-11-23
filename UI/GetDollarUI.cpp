#include "GetDollarUI.h"

GetDollarUI::GetDollarUI(QWidget* parent)
    : QWidget(parent),
	m_UI(new Ui::GetDollarUI())
{
    m_UI->setupUi(this);

	m_UI->eur_label->hide();
	m_UI->jpy_label->hide();
	m_UI->usd_label->hide();

	connect(this, &GetDollarUI::CurrencyStateChanged, &GetDollarUI::CurrencyChanged);

	connect(m_UI->usd_checkbox, &QCheckBox::checkStateChanged, this, [this](int state) { emit CurrencyStateChanged(Currency::USD, state); });
	connect(m_UI->eur_checkbox, &QCheckBox::checkStateChanged, this, [this](int state) { emit CurrencyStateChanged(Currency::EUR, state); });
	connect(m_UI->jpy_checkbox, &QCheckBox::checkStateChanged, this, [this](int state) { emit CurrencyStateChanged(Currency::JPY, state); });
}

GetDollarUI::~GetDollarUI() noexcept
{
	delete m_UI;
}

void GetDollarUI::ShowCurrency(Currency id, double rate)
{
	if (id == Currency::USD)
	{
		m_UI->usd_label->setText(QString("USD to RUB Rate: %1").arg(rate));
		m_UI->usd_label->show();
	}
	else if (id == Currency::EUR)
	{
		m_UI->eur_label->setText(QString("EUR to RUB Rate: %1").arg(rate));
		m_UI->eur_label->show();
	}
	else if (id == Currency::JPY)
	{
		m_UI->jpy_label->setText(QString("JPY to RUB Rate: %1").arg(rate));
		m_UI->jpy_label->show();
	}
}

void GetDollarUI::CurrencyChanged(Currency id, int state)
{
	if (state == Qt::Checked)
	{
		double rate = ExchangeRate::GetRate(id);
		ShowCurrency(id, rate);
	}
	else
	{
		HideCurrency(id);
	}
}

void GetDollarUI::HideCurrency(Currency id)
{
	if (id == Currency::USD)
	{
		m_UI->usd_label->hide();
	}
	else if (id == Currency::EUR)
	{
		m_UI->eur_label->hide();
	}
	else if (id == Currency::JPY)
	{
		m_UI->jpy_label->hide();
	}
}
