#pragma once

#include <QtWidgets/QWidget>
#include "./ui_GetDollarUI.h"
#include "ExchangeRate.h"

namespace Ui
{
    class GetDollarUI;
}

class GetDollarUI final : public QWidget
{
    Q_OBJECT

public:
    explicit GetDollarUI(QWidget* parent = nullptr);
    ~GetDollarUI() noexcept;

private:
    Ui::GetDollarUI* m_UI;

    void ShowCurrency(Currency id, double rate);
	void HideCurrency(Currency id);

signals:
	void CurrencyStateChanged(Currency id, int state);

private slots:
    void CurrencyChanged(Currency id, int state);
};

