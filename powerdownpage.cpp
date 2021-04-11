#include "powerdownpage.h"

PowerDownPage::PowerDownPage(QWidget* parent): Page(parent)
{
this->label = new QLabel();
    label->setText("recharging...");
    QLayout *layout = new QVBoxLayout();
    layout->addWidget(label);
    setLayout(layout);

}
