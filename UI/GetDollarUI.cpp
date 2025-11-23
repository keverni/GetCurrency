#include "GetDollarUI.h"
#include "ExchangeRate.h"

GetDollarUI::GetDollarUI(QWidget *parent)
    : QWidget(parent),
	m_UI(new Ui::GetDollarUI())
{
    m_UI->setupUi(this);

	m_UI->eur_label->hide();
	m_UI->jpy_label->hide();
	m_UI->usd_label->hide();

	connect(m_UI->usd_checkbox, &QCheckBox::stateChanged, this, &GetDollarUI::UsdChanged);
	connect(m_UI->eur_checkbox, &QCheckBox::stateChanged, this, &GetDollarUI::EurChanged);
	connect(m_UI->jpy_checkbox, &QCheckBox::stateChanged, this, &GetDollarUI::JpyChanged);
}

GetDollarUI::~GetDollarUI()
{
	delete m_UI;
}

void GetDollarUI::UsdChanged(int state)
{
	if (state == Qt::Checked)
	{
		double rate = ExchangeRate::GetRate(Currency::USD);
		m_UI->usd_label->setText(QString("USD to RUB Rate: %1").arg(rate));
		m_UI->usd_label->show();
	}
	else
	{
		m_UI->usd_label->hide();
	}
}

void GetDollarUI::EurChanged(int state)
{
	if (state == Qt::Checked)
	{
		double rate = ExchangeRate::GetRate(Currency::EUR);
		m_UI->eur_label->setText(QString("EUR to RUB Rate: %1").arg(rate));
		m_UI->eur_label->show();
	}
	else
	{
		m_UI->eur_label->hide();
	}
}

void GetDollarUI::JpyChanged(int state)
{
	if (state == Qt::Checked)
	{
		double rate = ExchangeRate::GetRate(Currency::JPY);
		m_UI->jpy_label->setText(QString("JPY to RUB Rate: %1").arg(rate));
		m_UI->jpy_label->show();
	}
	else
	{
		m_UI->jpy_label->hide();
	}
}

