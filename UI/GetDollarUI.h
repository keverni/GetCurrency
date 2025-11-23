#pragma once

#include <QtWidgets/QWidget>
#include "./ui_GetDollarUI.h"

namespace Ui
{
    class GetDollarUI;
}

class GetDollarUI final : public QWidget
{
    Q_OBJECT

public:
    GetDollarUI(QWidget *parent = nullptr);
    ~GetDollarUI();

private:
    Ui::GetDollarUI* m_UI;

private slots:
	void UsdChanged(int state);
	void EurChanged(int state);
	void JpyChanged(int state);
};

